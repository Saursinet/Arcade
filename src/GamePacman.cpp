//
// Game.cpp for arcade in /home/wilmot_g/Rendu/cpp_arcade/leHaineux/src
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Mar 10 20:17:34 2016 guillaume wilmot
// Last update Sun Apr  3 19:02:05 2016 guillaume wilmot
//

#include <cmath>
#include <unistd.h>
#include "GamePacman.hpp"

GamePacman::GamePacman() : Game()
{
  _gums = 0;
  _pos.push_back(new Pacman(0, 0, Entity::e_type::PAC));
  _pos.at(0)->setDirection(UP);
  _direction = UP;
  _name = GameName::PACMAN;
  generateMap();
}

GamePacman::~GamePacman() {}

GamePacman::GamePacman(const GamePacman &src) : Game()
{
  this->_map = src.getMap();
  this->_pos = src.getPos();
  this->_entities = src.getEntities();
  this->_finito = src.getFinish();
  this->_width = src.getWidth();
  this->_height = src.getHeight();
  this->_direction = src.getDirection();
  this->_gums = src.getGums();
}

GamePacman		&GamePacman::operator=(const GamePacman &src)
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
      this->_gums = src.getGums();
    }
  return (*this);
}

void			GamePacman::generateMap()
{
  _map = new std::string[30];
  _map[0]  += "111111111111111111111111111111611111111111116111111111111111";
  _map[1]  += "121116166666166611116666666666666666666666666666611666666621";
  _map[2]  += "166166116616161616666161111111611111111116116111666611111161";
  _map[3]  += "166116666116666616111166666111611111166116666111111111111161";
  _map[4]  += "116666166116111616111161116111611111161111116111111111116661";
  _map[5]  += "111161166616111666666666666666666666666666666666666666666111";
  _map[6]  += "111166111666111611161111116111111111111111166111111111111111";
  _map[7]  += "111116166666616666661666666661666661116666116666666666666661";
  _map[8]  += "166616661161616111161611116661616166666616116611611616111161";
  _map[9]  += "161611111661616666661666666166616161616616666616666616616661";
  _map[10] += "161666666661666111661611611111666161616116116611111611111161";
  _map[11] += "161611116161666166666661666661616661666666116666666661666161";
  _map[12] += "161616666161116661161661111661611611666111116111111661616161";
  _map[13] += "161616116666666111666661666611111666616666116661666661666161";
  _map[14] += "161616166166666666616161666613031116616166666166616666666161";
  _map[15] += "161616661161111116116161161113031666616166166661116666166161";
  _map[16] += "161616111161111116116166666611011111116666116166111116666161";
  _map[17] += "666616666661111116666116611611666666666666616666666666116666";
  _map[18] += "161616116161111111166616111616661111111111667611111111111111";
  _map[19] += "161616616161111111111666111666111111111111116111111111111111";
  _map[20] += "161666666166661116666666666611111111111111116111111111111111";
  _map[21] += "161616166161161116661611111111111111111111116111111111111111";
  _map[22] += "161616166666661111611666161111111111111111116111111111111111";
  _map[23] += "166616161111611116611161161111111111111111116111111111111111";
  _map[24] += "161616661166611666116661161111111111111111116111111111111111";
  _map[25] += "161611166161611116116166666111111111111111116111111111111111";
  _map[26] += "161611116661611116166166116666611111111111116111111111111111";
  _map[27] += "161611166161111116161116111161111111111111116111111111111111";
  _map[28] += "126666661111111112661116666166611111111111116111111111111111";
  _map[29] += "111111111111111111111111111111611111111111116111111111111111";
  for (int i = 0; i < 30; i++)
    for (int j = 0; j < 60; j++)
      {
	_map[i][j] -= '0';
	if (_map[i][j] == 7)
	  {
	    _pos.at(0)->setY(i);
	    _pos.at(0)->setX(j);
	  }
	else if (_map[i][j] == 6)
	  {
	    _gums++;
	    _powerups.push_back(new Powerup(j, i, Powerup::e_type::GUM));
	  }
	else if (_map[i][j] == 2)
	  {
	    _map[i][j] = 0;
	    _powerups.push_back(new Powerup(j, i, Powerup::e_type::BIGGUM));
	  }
	else if (_map[i][j] == 3)
	  _entities.push_back(new Pacman(j, i, _entities.size() == 0 ? Entity::e_type::RED :
					 _entities.size() == 1 ? Entity::e_type::PINK :
					 _entities.size() == 3 ? Entity::e_type::YELLOW :
					 Entity::e_type::BLUE));
      }
}

void			GamePacman::updateMap()
{
  for (int i = 0; i < 30; i++)
    for (int j = 0; j < 60; j++)
      if (_map[i][j] == 7 || _map[i][j] == 3)
	_map[i][j] = 0;
  _map[_pos.at(0)->getY()][_pos.at(0)->getX()] = 7;
  for (unsigned int i = 0; i < _entities.size(); i++)
    _map[_entities[i]->getY()][_entities[i]->getX()] = 3;
}

void			GamePacman::timer(int i)
{
  clock_t		time;

  time = clock();
  while (time - _time < 80000)
    time = clock();
  _time = time;
  _lib->print(static_cast<Game * const>(this));
  if (i < 2)
    timer(i + 1);
}

void			GamePacman::changeDirection(int &tmpDir, int &tmpDir2)
{
  if (tmpDir != UP && tmpDir != DOWN && tmpDir != RIGHT && tmpDir != LEFT)
    tmpDir = tmpDir2;
  else
    {
      if (_direction != tmpDir)
	{
	  _direction = tmpDir;
	  _pos[0]->setDirection(_direction);
	  _pos[0]->setFrame(0);
	}
    }
}

void			GamePacman::changeEnnemiesDirection()
{
  processPaths();
  for (unsigned int i = 0; i < _entities.size(); i++)
    {
      if (!_pos[0]->getStatus() && !_entities[i]->getDead())
	_entities[i]->setDirection(findBestWay(_entities[i]->getY(), _entities[i]->getX(),
					       _pos[0]->getY(), _pos[0]->getX()));
      else if (!_entities[i]->getDead())
      	{
      	  int		tile[4][2];
      	  float		best = -1;
      	  int		bestDir = -1;

      	  tile[0][0] = _entities[i]->getY() - 1;
      	  tile[0][1] = _entities[i]->getX();
      	  tile[1][0] = _entities[i]->getY();
      	  tile[1][1] = _entities[i]->getX() + 1;
      	  tile[2][0] = _entities[i]->getY() + 1;
      	  tile[2][1] = _entities[i]->getX();
      	  tile[3][0] = _entities[i]->getY();
      	  tile[3][1] = _entities[i]->getX() - 1;
      	  for (unsigned int i = 0; i < 4; i++)
      	    if (_map[limitY(tile[i][0])][limitX(tile[i][1])] != BLOCK && _map[limitY(tile[i][0])][limitX(tile[i][1])] != BODY)
      	      if (best == -1 || std::sqrt(std::pow(limitX(_pos[0]->getX()) - limitX(tile[i][1]), 2) +
      					  std::pow(limitX(_pos[0]->getY()) - limitY(tile[i][0]), 2)) > best)
      		{
      		  best = std::sqrt(pow(limitX(_pos[0]->getX()) - limitX(tile[i][1]), 2) +
      				   pow(limitX(_pos[0]->getY()) - limitY(tile[i][0]), 2));
      		  bestDir = i;
      		}
      	  _entities[i]->setFlee(_entities[i]->getFlee() ? _entities[i]->getFlee() - 1 : 0);
      	  if (bestDir != -1 && !_entities[i]->getFlee())
      	    {
      	      _entities[i]->setDirection(findBestWay(_entities[i]->getY(), _entities[i]->getX(),
						     limitY(tile[bestDir][0]), limitX(tile[bestDir][1])));
      	      _entities[i]->setFlee(2);
      	    }
	  else
	    _entities[i]->setDirection(-1);
      	}
      else
	{
	  _entities[i]->setDirection(findBestWay(_entities[i]->getY(), _entities[i]->getX(),
						 _map[_height / 2 - 1][_width / 2] != EMPTY ?
						 _height / 2 : _height / 2 - 1, _width / 2));
	  if (_entities[i]->getY() == _height / 2 - 1 && _entities[i]->getX() == _width / 2)
	    {
	      _entities[i]->setDead(0);
	      _entities[i]->setStandBy(20);
	    }
	}
      _entities[i]->setFrame(0);
    }
  freePaths();
}

int			GamePacman::play(int opt)
{
  static int		music = 0;

  _pos[0]->setStatus(_pos[0]->getStatus() ? _pos[0]->getStatus() - 1 : _pos[0]->getStatus());
  move();
  changeEnnemiesDirection();
  if (!music++ && opt == 1)
    _lib->playSound(WAKAWAKA);
  return (!_gums || _finito ? 1 : 0);
}

void			GamePacman::removePowerup()
{
  unsigned int	i = 0;

  while (i < _powerups.size() && (_powerups[i]->getY() != _pos[0]->getY() ||
				  _powerups[i]->getX() != _pos[0]->getX()))
    i++;
  if (i < _powerups.size())
    {
      if (_powerups[i]->getType() == Powerup::e_type::BIGGUM)
	{
	  _pos.at(0)->setStatus(_pos.at(0)->getStatus() + 50);
	  _lib->playSound(PACMANEATS);
	}
      _powerups.erase(_powerups.begin() + i);
      _gums--;
      ++_score;
    }
}

int			GamePacman::movePacman(Entity *e, int player)
{
  int			i = e->getY();
  int			j = e->getX();

  if (e->getDirection() == LEFT)
    e->setX(limitX(j - 1));
  else if (e->getDirection() == UP)
    e->setY(limitY(i - 1));
  else if (e->getDirection() == DOWN)
    e->setY(limitY(i + 1));
  else if (e->getDirection() == RIGHT)
    e->setX(limitX(j + 1));
  if (player)
    removePowerup();
  updateMap();
  return (0);
}

int			GamePacman::canMove(Entity *e, Entity *pac)
{
  int			i = e->getY();
  int			j = e->getX();

  e->setStandBy(!e->getStandBy() ? 0 : e->getStandBy() - 1);
  if (_finito || e->getStandBy())
    return (0);
  if (e != pac && !pac->getStatus())
    if ((e->getDirection() == LEFT && _map[i][limitX(j - 1)] == BODY) ||
	(e->getDirection() == RIGHT && _map[i][limitX(j + 1)] == BODY) ||
	(e->getDirection() == UP && _map[limitY(i - 1)][j] == BODY) ||
	(e->getDirection() == DOWN && _map[limitY(i + 1)][j] == BODY))
      {
	_finito = true;
	_lib->playSound(DIE);
	return (0);
      }
  if (e == pac && pac->getStatus())
    if ((e->getDirection() == LEFT && _map[i][limitX(j - 1)] == ENNEMY) ||
	(e->getDirection() == RIGHT && _map[i][limitX(j + 1)] == ENNEMY) ||
	(e->getDirection() == UP && _map[limitY(i - 1)][j] == ENNEMY) ||
	(e->getDirection() == DOWN && _map[limitY(i + 1)][j] == ENNEMY))
      for (unsigned int k = 0; k < _entities.size(); k++)
	if (_entities[k]->getX() == (pac->getDirection() == LEFT ? limitX(pac->getX() - 1) :
				     pac->getDirection() == RIGHT ? limitX(pac->getX() + 1) :
				     limitX(pac->getX())) &&
	    _entities[k]->getY() == (pac->getDirection() == UP ? limitY(pac->getY() - 1) :
				     pac->getDirection() == DOWN ? limitY(pac->getY() + 1) :
				     limitX(pac->getY())))
	  {
	    _entities[k]->setDead(1);
	    _lib->playSound(SNAKEEATS);
	    _score += 100;
	  }
  if ((e->getDirection() == LEFT && _map[i][limitX(j - 1)] != EMPTY && _map[i][limitX(j - 1)] != FOOD) ||
      (e->getDirection() == RIGHT && _map[i][limitX(j + 1)] != EMPTY && _map[i][limitX(j + 1)] != FOOD) ||
      (e->getDirection() == UP && _map[limitY(i - 1)][j] != EMPTY && _map[limitY(i - 1)][j] != FOOD) ||
      (e->getDirection() == DOWN && _map[limitY(i + 1)][j] != EMPTY && _map[limitY(i + 1)][j] != FOOD))
    return (0);
  return (1);
}

int			GamePacman::move()
{
  if (canMove(_pos.at(0), _pos.at(0)))
    movePacman(_pos.at(0), 1);
  for (unsigned int i = 0; i < _entities.size(); i++)
    if (canMove(_entities[i], _pos.at(0)))
      movePacman(_entities[i], 0);
  return (-1);
}

int			GamePacman::getGums() const
{
  return (_gums);
}

void			findPos(arcade::CommandType old, std::vector<Entity *> ent)
{
  arcade::WhereAmI	*pos;
  int			i;

  i = ent.size();
  pos = static_cast<arcade::WhereAmI *>(static_cast<void *>(new char[sizeof(arcade::WhereAmI) + i * sizeof(arcade::Position)]));
  pos->type = old;
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

void			findMap(arcade::CommandType old, std::string *mapSnake)
{
  arcade::GetMap	*_map;
  int			i;
  int			c;
  int			j;

  _map = static_cast<arcade::GetMap *>(static_cast<void *>(new char[sizeof(arcade::GetMap) + 30 * 60 * sizeof(arcade::TileType)]));
  _map->type = old;
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

void			Play()
{
  char			cmd;
  Game			*game;
  int			Direction;
  int			tmp2;
  arcade::CommandType	cmd1;

  game = makeGame();
  while (std::cin.read(&cmd, 1))
    {
      tmp2 = 0;
      cmd1 = static_cast<arcade::CommandType>(cmd);
      switch (static_cast<arcade::CommandType>(cmd))
      	{
      	case arcade::CommandType::WHERE_AM_I :
	  findPos(cmd1, game->getEntities());
      	case arcade::CommandType::GET_MAP :
	  findMap(cmd1, game->getMap());
      	case arcade::CommandType::GO_UP :
      	  Direction = UP;
      	  game->changeDirection(Direction, tmp2);
      	case arcade::CommandType::GO_DOWN :
      	  Direction = DOWN;
      	  game->changeDirection(Direction, tmp2);
      	case arcade::CommandType::GO_LEFT :
      	  Direction = RIGHT;
      	  game->changeDirection(Direction, tmp2);
      	case arcade::CommandType::GO_RIGHT :
      	  Direction = LEFT;
      	  game->changeDirection(Direction, tmp2);
      	case arcade::CommandType::GO_FORWARD :
      	  Direction = 0;
      	  game->changeDirection(Direction, tmp2);
      	case arcade::CommandType::PLAY :
	  game->play(0);
      	default :
	  cmd1 = arcade::CommandType::ILLEGAL;
      	}
    }
}

Game			*makeGame()
{
  return (new GamePacman);
}
