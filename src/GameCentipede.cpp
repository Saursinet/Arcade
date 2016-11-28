//
// Game.cpp for arcade in /home/wilmot_g/Rendu/cpp_arcade/leHaineux/src
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Mar 10 20:17:34 2016 guillaume wilmot
// Last update Sun Apr  3 23:29:56 2016 Florian Saurs
//

#include <unistd.h>
#include "GameCentipede.hpp"

GameCentipede::GameCentipede() : Game()
{
  setOldDirection(RIGHT);
  _centi.push_back(createCenti());
  _pos.push_back(new HeroCenti(40, 28, Entity::e_type::SHIP));
  _direction = 11;
  _nbCenti = 10;
  _name = GameName::CENTIPEDE;
  _newShot = false;
  srand(time(NULL));
  generateMap();
}

GameCentipede::~GameCentipede() {}

GameCentipede::GameCentipede(const GameCentipede &src) : Game()
{
  this->_map = src.getMap();
  this->_pos = src.getPos();
  this->_entities = src.getEntities();
  this->_finito = src.getFinish();
  this->_width = src.getWidth();
  this->_height = src.getHeight();
  this->_direction = src.getDirection();
}

GameCentipede		&GameCentipede::operator=(const GameCentipede &src)
{
  if (&src != this)
    {
      this->_map = src.getMap();
      this->_pos = src.getPos();
      this->_entities = src.getEntities();
      this->_finito = src.getFinish();
      this->_width = src.getWidth();
      this->_height = src.getHeight();
      this->_direction = src.getDirection();
    }
  return (*this);
}

std::vector<Entity *>	GameCentipede::createCenti()
{
  std::vector<Entity *>	tmp;

  tmp.push_back(new Centipede(9, 1, Entity::e_type::BODY));
  tmp.push_back(new Centipede(8, 1, Entity::e_type::BODY));
  tmp.push_back(new Centipede(7, 1, Entity::e_type::BODY));
  tmp.push_back(new Centipede(6, 1, Entity::e_type::BODY));
  tmp.push_back(new Centipede(5, 1, Entity::e_type::BODY));
  tmp.push_back(new Centipede(4, 1, Entity::e_type::BODY));
  tmp.push_back(new Centipede(3, 1, Entity::e_type::BODY));
  tmp.push_back(new Centipede(2, 1, Entity::e_type::BODY));
  tmp.push_back(new Centipede(1, 1, Entity::e_type::TAIL));
  tmp.at(0)->setDirection(RIGHT);
  return (tmp);
}

void			GameCentipede::generateMap()
{
  std::vector<Entity *>	tmp;
  int			limit;
  int			maxLimit;
  int			x;
  int			y;

  _map = new std::string[30];
  for (unsigned int i = 0; i < 30; ++i)
    for (unsigned int j = 0; j < 60; ++j)
      {
	if (i == 0 || j == 0 || i == 29 || j == 59)
	  _map[i] += (char)1;
	else
	  _map[i] += (char)0;
      }
  limit = 0;
  while (limit < 20)
    {
      maxLimit = 0;
      y = (rand() % 27) + 1;
      x = (rand() % 58) + 1;
      while (_map[y][x] != 0 && maxLimit < 100)
	{
	  y = (rand() % 27) + 1;
	  x = (rand() % 58) + 1;
	  ++maxLimit;
	}
      _map[y][x] = 15;
      ++limit;
    }
  for (unsigned int c = 0; c < _centi.size(); ++c)
    {
      tmp = _centi.at(c);
      for (unsigned int d = 0; d < tmp.size(); ++d)
	_map[tmp.at(d)->getY()][tmp.at(d)->getX()] = 3;
    }
  _map[_pos.at(0)->getY()][_pos.at(0)->getX()] = 7;
}

void			GameCentipede::updateMap()
{
  std::vector<Entity *>	tmp;

  for (int i = 0; i < 30; i++)
    for (int j = 0; j < 60; j++)
      if (_map[i][j] == 7 || _map[i][j] == 3 || _map[i][j] == 4)
  	_map[i][j] = 0;
  _map[_pos.at(0)->getY()][_pos.at(0)->getX()] = 7;
  for (unsigned int c = 0; c < _centi.size(); ++c)
    {
      tmp = _centi.at(c);
      for (unsigned int d = 0; d < tmp.size(); ++d)
	_map[tmp.at(d)->getY()][tmp.at(d)->getX()] = 3;
    }
  if (_shot.size() != 0)
    for (unsigned int i = 0; i < _shot.size(); ++i)
      _map[_shot.at(i)->getY()][_shot.at(i)->getX()] = 4;
}

void			GameCentipede::timer(int i)
{
  clock_t		time;

  time = clock();
  while (time - _time < 8000)
    time = clock();
  _time = time;
  _lib->print(static_cast<Game * const>(this));
  if (i < 2)
    timer(i + 1);
}

void			GameCentipede::changeDirection(int &tmpDir, int &tmpDir2)
{
  int			received;

  received = _lib->getEvent(STOP);
  if (tmpDir != UP && tmpDir != DOWN && tmpDir != LEFT && tmpDir != RIGHT)
    tmpDir = tmpDir2;
  else if (received)
    {
      _direction = tmpDir;
      _pos[0]->setDirection(_direction);
    }
  else
    {
      _direction = -1;
      _pos[0]->setDirection(-1);
    }
}

void			GameCentipede::updateEnum()
{
  unsigned int		i;
  unsigned int		j;

  for (i = 0; i < _centi.size(); i++)
    {
      _centi[i][0]->setType(Entity::e_type::HEAD);
      for (j = 1; j < _centi[i].size(); j++)
	_centi[i][j]->setType(Entity::e_type::BODY);
      if (_centi[i].size() > 1)
	_centi[i][_centi[i].size() - 1]->setType(Entity::e_type::TAIL);
    }
}

int			GameCentipede::play(int opt)
{
  if (opt == 2)
    _newShot = true;
  if (move() == -1)
    return (1);
  updateEnum();
  return (0);
}

int			GameCentipede::moveHero(Entity *e)
{
  int			i = e->getY();
  int			j = e->getX();

  if (e->getDirection() == LEFT)
    {
      e->setY(i);
      e->setX(j - 1);
    }
  else if (e->getDirection() == UP && e->getY() > 23)
    {
      e->setY(i - 1);
      e->setX(j);
    }
  else if (e->getDirection() == DOWN)
    {
      e->setY(i + 1);
      e->setX(j);
    }
  else if (e->getDirection() == RIGHT)
    {
      e->setY(i);
      e->setX(j + 1);
    }
  if (e->getY() >= _height)
    e->setY(0);
  if (e->getX() >= _width)
    e->setX(0);
  if (e->getY() < 0)
    e->setY(_height - 1);
  if (e->getX() < 0)
    e->setX(_width - 1);
  return (0);
}

int			GameCentipede::moveCentipede(Entity *e)
{
  int			i = e->getY();
  int			j = e->getX();

  if (e->getDirection() == LEFT)
    {
      if (_map[i][j - 1] == EMPTY)
	{
	  e->setY(i);
	  e->setX(j - 1);
	}
      else if (_map[i][j - 1] == 4)
      	return (-1);
      else if (_map[i][j - 1] == 7)
      	return (-3);
      else
	{
	  e->setDirection(DOWN);
	  setOldDirection(RIGHT);
	}
    }
  if (e->getDirection() == RIGHT)
    {
      if (_map[i][j + 1] == EMPTY)
	{
	  e->setY(i);
	  e->setX(j + 1);
	}
      else if (_map[i][j + 1] == 4)
      	return (-1);
      else if (_map[i][j + 1] == 7)
      	return (-3);
      else
	{
	  e->setDirection(DOWN);
	  setOldDirection(LEFT);
	}
    }
  if (e->getDirection() == DOWN)
    {
      if (_map[i + 1][j] == 1)
	{
	  _score -= 100;
	  return (-2);
	}
      e->setY(i + 1);
      e->setX(j);
      e->setDirection(getOldDirection());
    }
  if (e->getY() >= _height)
    e->setY(0);
  if (e->getX() >= _width)
    e->setX(0);
  if (e->getY() < 0)
    e->setY(_height - 1);
  if (e->getX() < 0)
    e->setX(_width - 1);
  return (0);
}

int			GameCentipede::canMove(Entity *e)
{
  int			i = e->getY();
  int			j = e->getX();

  if ((e->getDirection() == LEFT && _map[i][(j - 1) < 0 ? _width - 1: j - 1] != EMPTY && _map[i][(j - 1) < 0 ? _width - 1: j - 1] != FOOD) ||
      (e->getDirection() == RIGHT && _map[i][j + 1 >= _width ? 0 : j + 1] != EMPTY && _map[i][j + 1 >= _width ? 0 : j + 1] != FOOD) ||
      (e->getDirection() == UP && _map[i - 1 < 0 ? _height - 1 : i - 1][j] != EMPTY && _map[i - 1 < 0 ? _height - 1 : i - 1][j] != FOOD) ||
      (e->getDirection() == DOWN && _map[i + 1 >= _height ? 0 : i + 1][j] != EMPTY && _map[i + 1 >= _height ? 0 : i + 1][j] != FOOD))
    return (0);
  return (1);
}

void			GameCentipede::findEntity(int x, int y)
{
  std::vector<Entity *>	tmp;
  std::vector<Entity *>	save;
  std::vector<Entity *>	newCenti;
  int			divide;
  int			saveX;
  unsigned int		saveY;

  saveX = -1;
  saveY = -1;
  for (unsigned int i = 0; i < _centi.size(); ++i)
    {
      tmp = _centi.at(i);
      divide = 0;
      for (unsigned int j = 0; j < tmp.size(); ++j)
	{
	  if ((tmp.at(j)->getX() == y && tmp.at(j)->getY() == x) || divide == 1)
	    {
	      if (tmp.size() == 1)
		{
		  _map[x][y] = 15;
		  _centi.erase(_centi.begin() + i);
		  return ;
		}
	      if (divide == 0)
		{
		  _lib->playSound(SNAKEEATS);
		  _map[x][y] = 15;
		  saveX = i;
		  saveY = j;
		}
	      if (divide == 1)
		{
		  newCenti.push_back(tmp.at(j));
		  newCenti.at(0)->setDirection(tmp.at(0)->getDirection());
		}
	      divide = 1;
	    }
	}
      if (divide == 1 && tmp.size() <= 1)
	{
	  _centi.erase(_centi.begin() + saveX);
	  return ;
	}
    }
  if (saveX != -1)
    {
      tmp = _centi.at(saveX);
      for (std::vector<Entity *>::iterator it = tmp.begin(); it != tmp.end(); it++)
	{
	  if (saveY > 0)
	    {
	      --saveY;
	      save.push_back(*it);
	    }
	}
      if (save.size() != 0)
	_centi.at(saveX) = save;
      else
	if (newCenti.size() != 0)
	  _centi.erase(_centi.begin() + saveX);
      if (newCenti.size() != 0)
	_centi.push_back(newCenti);
    }
}

void			GameCentipede::moveShot()
{
  std::vector<Shot *>	tmp;

  if (_shot.size() != 0)
    for (std::vector<Shot *>::iterator it = _shot.begin(); it != _shot.end(); ++it)
      {
	if (_map[(*it)->getY() - 1][(*it)->getX()] == EMPTY)
	  {
	    (*it)->setY((*it)->getY() - 1);
	    tmp.push_back(*it);
	  }
	else
	  {
	    if (_map[(*it)->getY() - 1][(*it)->getX()] > 11)
	      {
		_map[(*it)->getY() - 1][(*it)->getX()] =
		  _map[(*it)->getY() - 1][(*it)->getX()] - 1;
		++_score;
	      }
	    else if (_map[(*it)->getY() - 1][(*it)->getX()] == 11)
	      {
		_map[(*it)->getY() - 1][(*it)->getX()] =
		  _map[(*it)->getY() - 1][(*it)->getX()] = EMPTY;
		++_score;
	      }
	    else if (_map[(*it)->getY() - 1][(*it)->getX()] == 3)
	      {
		findEntity((*it)->getY() - 1, (*it)->getX());
		_score += 25;
	      }
	  }
      }
  _shot = tmp;
}

int			GameCentipede::checkCenti()
{
  if (_centi.size() == 0 && _nbCenti != 0)
    {
      _centi.push_back(createCenti());
      --_nbCenti;
    }
  if (_centi.size() == 0 && _nbCenti == 0)
    return (-1);
  return (0);
}

int			GameCentipede::move()
{
  std::vector<Entity *>	tmp;
  int			x;
  int			y;
  int			x1;
  int			y1;
  int			erase;
  int			deleted;

  if (canMove(_pos.at(0)))
    moveHero(_pos.at(0));
  if (checkCenti() == -1)
    return (-1);
  for (unsigned int i = 0; i < _centi.size(); i++)
    {
      deleted = 0;
      tmp = _centi.at(i);
      x = tmp.at(0)->getX();
      y = tmp.at(0)->getY();
      erase = 0;
      if ((deleted = moveCentipede(tmp.at(0))) == -1)
      	{
	  _map[tmp.at(0)->getY()][tmp.at(0)->getX()] = 15;
	  if (tmp.size() != 0)
	    deleted = moveCentipede(tmp.at(0));
	  else
	    {
	      _centi.erase(_centi.begin() + i);
	      erase = 1;
	    }
	}
      if (deleted == -2)
	_centi.erase(_centi.begin() + i);
      else if (deleted == -3)
	return (-1);
      else
	for (unsigned int j = 1; erase != 1 && j < tmp.size(); j++)
	  {
	    x1 = tmp.at(j)->getX();
	    y1 = tmp.at(j)->getY();
	    tmp.at(j)->setX(x);
	    tmp.at(j)->setY(y);
	    ++j;
	    if (j < tmp.size())
	      {
		x = tmp.at(j)->getX();
		y = tmp.at(j)->getY();
		tmp.at(j)->setX(x1);
		tmp.at(j)->setY(y1);
	      }
	  }
    }
  if (_newShot)
    {
      _lib->playSound(PACMANEATS);
      _shot.push_back(new Shot(_pos.at(0)->getX(), _pos.at(0)->getY(), Powerup::e_type::SHOT));
      _newShot = false;
    }
  updateMap();
  moveShot();
  updateMap();
  return (0);
}

void	GameCentipede::setOldDirection(int dir)
{
  _oldDirection = dir;
}

int	GameCentipede::getOldDirection()const
{
  return (_oldDirection);
}

void	findPos(std::vector<Entity *> ent)
{
  arcade::WhereAmI	*pos;
  int		i;

  i = ent.size();
  pos = static_cast<arcade::WhereAmI *>(static_cast<void *>(new char[sizeof(arcade::WhereAmI) + i * sizeof(arcade::Position)]));
  pos->type = arcade::CommandType::WHERE_AM_I;
  pos->lenght = i;
  i = 0;
  for (std::vector<Entity *>::iterator it = ent.begin(); it != ent.end(); ++it)
    {
      pos->position[i].x = (*it)->getX();
      pos->position[i].y = (*it)->getY();
      ++i;
    }
  if (write(1, pos, (sizeof(arcade::WhereAmI) + i * sizeof(arcade::Position))))
    return ;
  delete[] pos;
}

void	findMap(std::string *mapSnake)
{
  arcade::GetMap	*_map;
  int		i;
  int		c;
  int		j;

  _map = static_cast<arcade::GetMap *>(static_cast<void *>(new char[sizeof(arcade::GetMap) + 30 * 60 * sizeof(arcade::TileType)]));
  _map->type = arcade::CommandType::GET_MAP;
  _map->width = 30;
  _map->height = 60;
  c = 0;
  for (i = 0; i < 30; ++i)
    for (j = 0; j < 60; ++j)
      mapSnake[i][j] >= 7 ?
	_map->tile[c++] = arcade::TileType::OTHER :
	_map->tile[c++] = static_cast<arcade::TileType>(mapSnake[i][j]);
  if (write(1, _map, (sizeof(arcade::GetMap) + 30 * 60 * sizeof(arcade::TileType))))
    return ;
  delete[] _map;
}

void	Play()
{
  char			cmd;
  Game			*game;
  int			Direction;

  game = makeGame();
  std::vector<Entity *>	_pos = game->getPos();
  std::string		*_map = game->getMap();
  _pos.at(0)->setDirection(UP);
  while (std::cin.get(cmd))
    {
      if (static_cast<arcade::CommandType>(cmd) == arcade::CommandType::WHERE_AM_I)
	findPos(_pos);
      if (static_cast<arcade::CommandType>(cmd) == arcade::CommandType::GET_MAP)
	findMap(_map);
      if (static_cast<arcade::CommandType>(cmd) == arcade::CommandType::GO_UP)
	{
	  Direction = UP;
	  _pos.at(0)->setDirection(Direction);
	}
      if (static_cast<arcade::CommandType>(cmd) == arcade::CommandType::GO_DOWN)
	{
      	  Direction = DOWN;
	  _pos.at(0)->setDirection(Direction);
	}
      if (static_cast<arcade::CommandType>(cmd) == arcade::CommandType::GO_RIGHT)
	{
      	  Direction = RIGHT;
	  _pos.at(0)->setDirection(Direction);
	}
      if (static_cast<arcade::CommandType>(cmd) == arcade::CommandType::GO_LEFT)
	{
      	  Direction = LEFT;
	  _pos.at(0)->setDirection(Direction);
	}
      if (static_cast<arcade::CommandType>(cmd) == arcade::CommandType::GO_FORWARD)
	_pos.at(0)->setDirection(Direction);
      if (static_cast<arcade::CommandType>(cmd) == arcade::CommandType::PLAY)
	game->play(0);
      std::cin.get(cmd);
    }
}

Game			*makeGame()
{
  return (new GameCentipede);
}
