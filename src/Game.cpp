//
// Game.cpp for arcade in /home/wilmot_g/Rendu/cpp_arcade/leHaineux/src
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Mar 10 20:17:34 2016 guillaume wilmot
// Last update Sun Apr  3 22:39:10 2016 Florian Saurs
//

#include "Game.hpp"
#include "Libraries.hpp"
#include "Menu.hpp"

Game::Game()
{
  _finito = false;
  _direction = UP;
  _width = 60;
  _height = 30;
  _time = clock();
  _score = 0;
  _login = "";
  _name = GameName::UNDEFINED;
}

Game::Game(const Game &src)
{
  this->_map = src.getMap();
  this->_pos = src.getPos();
  this->_entities = src.getEntities();
  this->_finito = src.getFinish();
  this->_width = src.getWidth();
  this->_height = src.getHeight();
  this->_time = src.getClock();
  this->_direction = src.getDirection();
  this->_name = src.getGameName();
}

Game				&Game::operator=(const Game &src)
{
  if (&src != this)
    {
      this->_map = src.getMap();
      this->_pos = src.getPos();
      this->_entities = src.getEntities();
      this->_finito = src.getFinish();
      this->_width = src.getWidth();
      this->_height = src.getHeight();
      this->_time = src.getClock();
      this->_direction = src.getDirection();
      this->_name = src.getGameName();
    }
  return (*this);
}

int				Game::limitY(int y) const
{
  return (y >= _height ? 0 : y < 0 ? _height - 1 : y);
}

int				Game::limitX(int x) const
{
  return (x >= _width ? 0 : x < 0 ? _width - 1 : x);
}

int			Game::game(ILib **lib, Libs &libs, unsigned int &i)
{
  int			event;
  int			backup;
  int			replay;

  backup = 0;
  event = 0;
  replay = false;
  _lib = (*lib);
  if (_lib->init() == -1)
    return (-1);
  while (_finito != true)
    {
      backup = event;
      if ((event = _lib->getEvent(_direction)) == 0)
        _finito = true;
      else if (event == 2 || event == 3)
      	{
      	  _lib->end();
	  delete _lib;
	  if (event == 2)
	    i = i == 0 ? libs.getNbLib() - 1 : i - 1;
	  else
	    i = i == libs.getNbLib() - 1 ? 0 : i + 1;
	  if (libs.openLib("./lib/" + libs.getLibs()[i], 1) == -1 ||
	      !(_lib = libs.getLib()) || _lib->init() == -1)
	    return (-1);
	  *lib = _lib;
	  _pos[0]->setFrame(0);
	  event = backup;
      	}
      else if (replay || event == 8)
	return (3);
      else if (event == 9)
	return (4);
      else if (event == 4 || event == 5)
	return (event == 4 ? 1 : 2);
      else if (event == 1)
	{
	  if (play(2))
	    replay = true;
          _lib->print(this);
          timer();
	}
      else
	{
	  if (play(1))
	    replay = true;
	  changeDirection(event, backup);
	  if (!_finito)
	    {
	      _lib->print(this);
	      timer();
	    }
        }
    }
  return (replay ? 3 : 0);
}

std::vector<struct Entity *>	Game::getPos() const
{
  return (_pos);
}

std::vector<Entity *>		Game::getEntities() const
{
  return (_entities);
}

std::vector<Powerup *>		Game::getPowerups() const
{
  return (_powerups);
}

std::vector<std::vector<Entity *>>	Game::getCenti() const
{
  return (_centi);
}


std::vector<Shot *>		Game::getShots() const
{
  return (_shot);
}

std::string			*Game::getMap() const
{
  return (_map);
}

std::string			*Game::getTab() const
{
  return (_map);
}

int				Game::getHeight() const
{
  return (_height);
}

int				Game::getWidth() const
{
  return (_width);
}

int				Game::getScore() const
{
  return (_score);
}

std::string			Game::getLogin() const
{
  return (_login);
}

int				Game::getDirection() const
{
  return (_direction);
}

bool				Game::getFinish() const
{
  return (_finito);
}

clock_t				Game::getClock() const
{
  return (_time);
}

GameName			Game::getGameName() const
{
  return (_name);
}
