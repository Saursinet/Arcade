//
// Libraries.cpp for Libraries in /home/noboud_n/rendu/cpp_arcade/src
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.net>
//
// Started on  Fri Apr  1 14:17:29 2016 Nyrandone Noboud-Inpeng
// Last update Sun Apr  3 18:20:00 2016 Nyrandone Noboud-Inpeng
//

#include <sys/types.h>
#include <dirent.h>
#include <dlfcn.h>
#include "Libraries.hpp"
#include "Game.hpp"

Libs::Libs()
{
  _game = NULL;
  _lib = NULL;
  _nbLib = 0;
  _nbGame = 0;
  _typeLib = 0;
  _typeGame = 0;
  _handleLib = NULL;
  _handleGame = NULL;
}

Libs::~Libs()
{
  if (_handleGame)
    dlclose(_handleGame);
  if (_handleLib)
    dlclose(_handleLib);
}

Libs::Libs(const Libs &) {}

Libs				&Libs::operator=(const Libs &)
{
  return (*this);
}

int				Libs::loadLibs()
{
  DIR				*dir;
  struct dirent			*rd;

  _nbLib = 0;
  if ((dir = opendir("lib")) == NULL)
    {
      std::cerr << "Cannot find the lib folder" << std::endl;
      return (-1);
    }
  while ((rd = readdir(dir)) != NULL)
    if (rd->d_name[0] != '.')
      if (openLib("./lib/" + std::string(rd->d_name), 0) == 0)
	{
	  _libs.push_back(std::string(rd->d_name));
	  _nbLib++;
	}
  closedir(dir);
  return (0);
}

int				Libs::openLib(const std::string &libName, int i)
{
  ILib				*(*external_creator)();

  if (_handleLib)
    dlclose(_handleLib);
  _handleLib = dlopen(libName.c_str(), RTLD_NOW);
  if (_handleLib == NULL)
    {
      std::cerr << dlerror() << std::endl;
      std::cerr << "Failed to open library: " << libName << std::endl;
      return (-1);
    }
  external_creator = reinterpret_cast<ILib *(*)()>(dlsym(_handleLib, "makeLib"));
  if (external_creator == NULL)
    {
      std::cerr << "Failed to create obj from: " << libName << std::endl;
      dlclose(_handleLib);
      return (-1);
    }
  if (i)
    _lib = external_creator();
  return (0);
}

int				Libs::loadGames()
{
  DIR				*dir;
  struct dirent			*rd;

  _nbGame = 0;
  if ((dir = opendir("games")) == NULL)
    {
      std::cerr << "Cannot find the games folder" << std::endl;
      return (-1);
    }
  while ((rd = readdir(dir)) != NULL)
    if (rd->d_name[0] != '.')
      if (openGame("./games/" + std::string(rd->d_name), 0) != -1)
        {
	  _games.push_back(std::string(rd->d_name));
          ++_nbGame;
        }
  closedir(dir);
  return (0);
}

int				Libs::openGame(const std::string &libName, int i)
{
  Game				*(*external_creator)();

  if (_handleGame)
    dlclose(_handleGame);
  _handleGame = dlopen(libName.c_str(), RTLD_NOW);
  if (_handleGame == NULL)
    {
      std::cerr << dlerror() << std::endl;
      std::cerr << "Failed to open library: " << libName << std::endl;
      return (-1);
    }
  external_creator = reinterpret_cast<Game *(*)()>(dlsym(_handleGame, "makeGame"));
  if (external_creator == NULL)
    {
      dlclose(_handleGame);
      std::cerr << "Failed to create obj from: " << libName << std::endl;
      return (-1);
    }
  if (i)
    _game = external_creator();
  return (0);
}

std::vector<std::string>	Libs::getLibs() const
{
  return (_libs);
}

ILib				*Libs::getLib() const
{
  return (_lib);
}

unsigned int			Libs::getNbLib() const
{
  return (_nbLib);
}

std::vector<std::string>	Libs::getGames() const
{
  return (_games);
}

Game				*Libs::getGame() const
{
  return (_game);
}

unsigned int			Libs::getNbGame() const
{
  return (_nbGame);
}
