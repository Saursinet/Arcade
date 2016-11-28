//
// Menu.cpp for Arcade in /home/wilmot_g/Rendu/cpp_arcade2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Apr  1 23:15:56 2016 guillaume wilmot
// Last update Sun Apr  3 18:11:33 2016 Nyrandone Noboud-Inpeng
//

#include <algorithm>
#include "Menu.hpp"

Menu::Menu()
{
  _libName = "";
  _gameName = "";
  _login = "";
}

void			Menu::parseLibName(std::string &libName)
{
  std::string           tmp;
  std::size_t           place;

  tmp = libName;
  std::reverse(libName.begin(), libName.end());
  place = libName.find("/");
  if (place != std::string::npos)
    libName = libName.substr(0, place);
  std::reverse(libName.begin(), libName.end());
  std::cout << tmp << std::endl;
}

void			Menu::findIndexes()
{
  unsigned int		i;

  _indexLib = 0;
  _indexGame = 0;
  for (i = 0; i < _libs->getNbLib(); i++)
    if (_libName == _libs->getLibs()[i])
      _indexLib = i;
  for (i = 0; i < _libs->getNbGame(); i++)
    if (_gameName == _libs->getGames()[i])
      _indexGame = i;
}

int			Menu::choose(Libs *libs, ILib *lib, std::string *score)
{
  char			c;

  if (lib->init() == -1)
    return (-1);
  _libs = libs;
  _score = score;
  if (lib->chooseGame(this) == -1)
    return (-1);
  if (lib->chooseLib(this) == -1)
    return (-1);
  findIndexes();
  if (_login == "")
    while (42)
      {
	c = lib->getChar();
	if (c != -2)
	  {
	    if (c == -1)
	      return (-1);
	    if (c == 0 && _login.length() > 0)
	      return (0);
	    if (_login.length() < 10 && (c == ' ' || (c >= '0' && c <= '9') ||
					 (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
	      _login += c;
	    else if (_login.length() > 0 && c == '\b')
	      _login.erase(_login.length() - 1);
	  }
	lib->printMenu(this);
      }
  return (0);
}

std::string		Menu::getLibName() const
{
  return (_libName);
}

std::string		Menu::getGameName() const
{
  return (_gameName);
}

std::string		Menu::getLogin() const
{
  return (_login);
}

Libs			*Menu::getLibs() const
{
  return (_libs);
}

std::string		*Menu::getScore() const
{
  return (_score);
}

unsigned int		Menu::getIndexGame() const
{
  return (_indexGame);
}

unsigned int		Menu::getIndexLib() const
{
  return (_indexLib);
}

void			Menu::setLibName(const std::string &lib)
{
  _libName = lib;
}

void			Menu::setGameName(const std::string &game)
{
  _gameName = game;
}
