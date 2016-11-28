//
// GameSnake.cpp for  in /home/saurs_f/cpp_arcade/cacatest/leHaineux
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Thu Mar 10 21:21:06 2016 Florian Saurs
// Last update Sun Apr  3 17:56:30 2016 Nyrandone Noboud-Inpeng
//

#include <unistd.h>
#include "GameSnake.hpp"

GameSnake::GameSnake() : Game()
{
  srand(time(NULL));
  _food = 0;
  _pos.push_back(new Snake(28, 15, Entity::e_type::HEAD));
  _pos.push_back(new Snake(29, 15, Entity::e_type::BODY));
  _pos.push_back(new Snake(30, 15, Entity::e_type::BODY));
  _pos.push_back(new Snake(31, 15, Entity::e_type::TAIL));
  _name = GameName::SNAKE;
  generateMap();
}

GameSnake::~GameSnake() {}

GameSnake::GameSnake(const GameSnake &src) : Game()
{
  this->_map = src.getMap();
  this->_pos = src.getPos();
  this->_entities = src.getEntities();
  this->_finito = src.getFinish();
  this->_width = src.getWidth();
  this->_height = src.getHeight();
  this->_direction = src.getDirection();
  this->_food = src.getFood();
}

GameSnake	&GameSnake::operator=(const GameSnake &src)
{
  if (this != &src)
    {
      this->_map = src.getMap();
      this->_pos = src.getPos();
      this->_entities = src.getEntities();
      this->_finito = src.getFinish();
      this->_width = src.getWidth();
      this->_height = src.getHeight();
      this->_direction = src.getDirection();
      this->_food = src.getFood();
    }
  return (*this);
}

void					GameSnake::generateMap()
{
  std::vector<Entity *>::iterator	it;
  Snake					*snake;

  _map = new std::string[30];
  for (unsigned int i = 0; i < 30; ++i)
    for (unsigned int j = 0; j < 60; ++j)
      {
	if (i == 0 || j == 0 || i == 29 || j == 59)
	  _map[i] += (char)1;
	else
	  _map[i] += (char)0;
      }
  for (it = _pos.begin(); it != _pos.end(); ++it)
    {
      snake = static_cast<Snake *>(*it);
      if (it == _pos.begin())
	_map[snake->getY()][snake->getX()] = 9;
      else
	_map[snake->getY()][snake->getX()] = 7;
    }
  --it;
  snake = static_cast<Snake *>(*it);
  _map[snake->getY()][snake->getX()] = 8;
}

void				GameSnake::updateMap()
{
  std::vector<Entity *>::iterator it;
  Snake	*snake;

  for (int i = 0; i < 30; i++)
    for (int j = 0; j < 60; j++)
      if (_map[i][j] == 7 || _map[i][j] == 9 || _map[i][j] == 8)
	_map[i][j] = 0;
  for (it = _pos.begin(); it != _pos.end(); ++it)
    {
      snake = static_cast<Snake *>(*it);
      if (it == _pos.begin())
	_map[snake->getY()][snake->getX()] = 9;
      else
	_map[snake->getY()][snake->getX()] = 7;
    }
  --it;
  snake = static_cast<Snake *>(*it);
  _map[snake->getY()][snake->getX()] = 8;
}

void                    GameSnake::timer(UNUSED int i)
{
  clock_t                       time;

  time = clock();
  while (time - _time < 80000 - (_score * 1000))
    time = clock();
  _time = time;
}

void		GameSnake::changeDirection(int &tmpDir, int &tmpDir2)
{
  if (tmpDir != UP && tmpDir != DOWN && tmpDir != RIGHT && tmpDir != LEFT)
    tmpDir = tmpDir2;
  else
    {
      if (_direction == DOWN && tmpDir != UP)
	_direction = tmpDir;
      if (_direction == UP && tmpDir != DOWN)
	_direction = tmpDir;
      if (_direction == LEFT && tmpDir != RIGHT)
	_direction = tmpDir;
      if (_direction == RIGHT && tmpDir != LEFT)
	_direction = tmpDir;
    }
}

int		GameSnake::play(int opt)
{
  int		x;
  int		y;
  int		limit;


  move();
  if (opt == 1)
    _lib->playSound(MUSICSNAKE);
  while (_food < 10)
    {
      y = (rand() % 27) + 1;
      x = (rand() % 58) + 1;
      limit = 0;
      while (_map[y][x] != EMPTY && limit < 100)
	{
	  y = (rand() % 27) + 1;
	  x = (rand() % 58) + 1;
	  ++limit;
	}
      _map[y][x] = FOOD;
      _powerups.push_back(new Powerup(x, y, Powerup::e_type::FOOD));
      ++_food;
    }
  if (_finito)
    return (1);
  return (0);
}

void	GameSnake::moveIt(std::vector<Entity *>::iterator it, int x, int y)
{
  (*it)->setY(y);
  (*it)->setX(x);
}

int	GameSnake::checkFood(int i, int j)
{
  int		plus;

  plus = 0;
  if (_direction == LEFT)
    {
      if (_map[i][j - 1] == FOOD)
	++plus;
      _pos.at(0)->setY(i);
      _pos.at(0)->setX(j - 1);
    }
  else if (_direction == UP)
    {
      if (_map[i - 1][j] == FOOD)
	++plus;
      _pos.at(0)->setY(i - 1);
      _pos.at(0)->setX(j);
    }
  else if (_direction == DOWN)
    {
      if (_map[i + 1][j] == FOOD)
	++plus;
      _pos.at(0)->setY(i + 1);
      _pos.at(0)->setX(j);
    }
  else if (_direction == RIGHT)
    {
      if (_map[i][j + 1] == FOOD)
	++plus;
      _pos.at(0)->setY(i);
      _pos.at(0)->setX(j + 1);
    }
  return (plus);
}

void	GameSnake::removeFood(int i, int j)
{
  std::vector<Powerup *>::iterator	it;

  _score++;
  for (it = _powerups.begin(); it != _powerups.end(); it++)
    if ((*it)->getY() == i && (*it)->getX() == j)
      {
	_powerups.erase(it);
	return ;
      }
}

int	GameSnake::moveSnake(unsigned int i, unsigned int j)
{
  int		plus;
  std::vector<Entity *>::iterator	it;
  int		x;
  int		y;
  int		t;

  if ((plus = checkFood(i, j)) != 0)
    removeFood(_pos.at(0)->getY(), _pos.at(0)->getX());
  it = _pos.begin();
  ++it;
  y = (*it)->getY();
  x = (*it)->getX();
  (*it)->setY(i);
  (*it)->setX(j);
  t = 0;
  while (++it != _pos.end())
    {
      if (t == 0)
	{
	  i = (*it)->getY();
	  j = (*it)->getX();
	  moveIt(it, x, y);
	  ++t;
	}
      else
	{
	  y = (*it)->getY();
	  x = (*it)->getX();
	  moveIt(it, j, i);
	  t = 0;
	}
    }
  if (plus != 0)
    {
      --it;
      --_food;
      _pos.push_back(new Snake((*it)->getX(), (*it)->getY(), Entity::e_type::TAIL));
      _pos[_pos.size() - 2]->setType(Entity::e_type::BODY);
      _lib->playSound(SNAKEEATS);
    }
  updateMap();
  return (0);
}

int	GameSnake::move()
{
  unsigned int	i = _pos.at(0)->getY();
  unsigned int	j = _pos.at(0)->getX();

  if ((_direction == LEFT && _map[i][j - 1] != EMPTY && _map[i][j - 1] != FOOD) ||
      (_direction == RIGHT && _map[i][j + 1] != EMPTY && _map[i][j + 1] != FOOD) ||
      (_direction == UP && _map[i - 1][j] != EMPTY && _map[i - 1][j] != FOOD) ||
      (_direction == DOWN && _map[i + 1][j] != EMPTY && _map[i + 1][j] != FOOD))
    {
      _lib->playSound(DIE);
      _finito = true;
      return (0);
    }
  else
    return (moveSnake(i, j));
  return (-1);
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

void	findMap(std::string *&mapSnake)
{
  arcade::GetMap	*_map;
  int		i;
  int		c;
  int		j;

  _map = static_cast<arcade::GetMap *>(static_cast<void *>(new char[sizeof(arcade::GetMap) + 30 * 60 * sizeof(arcade::TileType)]));
  _map->type = arcade::CommandType::GET_MAP;
  _map->width = 60;
  _map->height = 30;
  c = 0;
  for (i = 0; i < 30; ++i)
    for (j = 0; j < 60; ++j)
      {
	mapSnake[i][j] >= 7 ?
	  _map->tile[c++] = arcade::TileType::EMPTY :
	  _map->tile[c++] = static_cast<arcade::TileType>(mapSnake[i][j]);
	if (mapSnake[i][j] >= 7)
	  mapSnake[i][j] = EMPTY;
      }
  if (write(1, _map, (sizeof(arcade::GetMap) + 30 * 60 * sizeof(arcade::TileType))))
    return ;
  delete[] _map;
}

int	checkFood(std::vector<Entity *> &_pos, int i, int j, std::string *_map)
{
  int		plus;
  int		_direction = _pos.at(0)->getDirection();

  plus = 0;
  if (_direction == LEFT)
    {
      if (_map[i][j - 1] == FOOD)
	++plus;
      _pos.at(0)->setY(i);
      _pos.at(0)->setX(j - 1);
    }
  else if (_direction == UP)
    {
      if (_map[i - 1][j] == FOOD)
	++plus;
      _pos.at(0)->setY(i - 1);
      _pos.at(0)->setX(j);
    }
  else if (_direction == DOWN)
    {
      if (_map[i + 1][j] == FOOD)
	++plus;
      _pos.at(0)->setY(i + 1);
      _pos.at(0)->setX(j);
    }
  else if (_direction == RIGHT)
    {
      if (_map[i][j + 1] == FOOD)
	++plus;
      _pos.at(0)->setY(i);
      _pos.at(0)->setX(j + 1);
    }
  return (plus);
}

void	moveIt(std::vector<Entity *>::iterator &it, int x, int y)
{
  (*it)->setY(y);
  (*it)->setX(x);
}

int		moveSnake(unsigned int i, unsigned int j, std::vector<Entity *> &_pos, std::string *_map)
{
  int		plus;
  std::vector<Entity *>::iterator	it;
  int		x;
  int		y;
  int		t;

  plus = checkFood(_pos, i, j, _map);
  it = _pos.begin();
  ++it;
  y = (*it)->getY();
  x = (*it)->getX();
  (*it)->setY(i);
  (*it)->setX(j);
  t = 0;
  while (++it != _pos.end())
    {
      if (t == 0)
	{
	  i = (*it)->getY();
	  j = (*it)->getX();
	  moveIt(it, x, y);
	  ++t;
	}
      else
	{
	  y = (*it)->getY();
	  x = (*it)->getX();
	  moveIt(it, j, i);
	  t = 0;
	}
    }
  if (plus != 0)
    {
      --it;
      _pos.push_back(new Snake((*it)->getX(), (*it)->getY(), Entity::e_type::TAIL));
      _pos[_pos.size() - 2]->setType(Entity::e_type::BODY);
    }
  return (0);
}

int			move(Game *game, std::string *_map)
{
  std::vector<Entity *>	_pos = game->getPos();
  unsigned int	i = _pos.at(0)->getY();
  unsigned int	j = _pos.at(0)->getX();
  int		_direction = _pos.at(0)->getDirection();

  if ((_direction == LEFT && _map[i][j - 1] != EMPTY && _map[i][j - 1] != FOOD) ||
      (_direction == RIGHT && _map[i][j + 1] != EMPTY && _map[i][j + 1] != FOOD) ||
      (_direction == UP && _map[i - 1][j] != EMPTY && _map[i - 1][j] != FOOD) ||
      (_direction == DOWN && _map[i + 1][j] != EMPTY && _map[i + 1][j] != FOOD))
    return (0);
  else
    return (moveSnake(i, j, _pos, _map));
  return (-1);
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
	move(game, _map);
      std::cin.get(cmd);
    }
}

Game	*makeGame()
{
  return (new GameSnake);
}

int		GameSnake::getFood() const
{
  return (_food);
}
