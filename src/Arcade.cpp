//
// main.cpp for Arcade in /home/wilmot_g/Rendu/cpp_arcade/leHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Mar 10 11:41:16 2016 guillaume wilmot
// Last update Sun Apr  3 19:07:28 2016 Florian Saurs
//

#include <dirent.h>
#include <fstream>
#include "Libraries.hpp"
#include "Score.hpp"
#include "Arcade.hpp"
#include "Menu.hpp"

Arcade::Arcade() {}

Arcade::~Arcade() {}

Arcade::Arcade(const Arcade &) {}

Arcade		&Arcade::operator=(const Arcade &)
{
  return (*this);
}

int		Arcade::launchGame(Game *game, ILib **lib, Libs &libs, Menu &menu)
{
  unsigned int	indexGame;
  unsigned int	indexLib;
  int		tmp;
  std::string	login = "";

  tmp = 1;
  login = menu.getLogin();
  menu.findIndexes();
  indexGame = menu.getIndexGame();
  indexLib = menu.getIndexLib();
  while (tmp == 1 || tmp == 2 || tmp == 3)
    {
      if ((tmp = game->game(lib, libs, indexLib)) == -1)
	return (-1);
      if (_score.getScoreTab()[0] == "")
	_score.createFile(login, game->getScore(), libs.getGames()[indexGame]);
      else
	_score.addScore(login, game->getScore(), libs.getGames()[indexGame]);
      delete game;
      if (tmp == 0)
	return (0);
      if (tmp == 4)
	return (1);
      if (tmp == 2)
	indexGame = indexGame + 1 >= libs.getNbGame() ? 0 : indexGame + 1;
      else if (tmp == 1)
	indexGame = indexGame == 0 ? libs.getNbGame() - 1 : indexGame - 1;
      if (libs.openGame("./games/" + libs.getGames()[indexGame], 1) == -1 || !(game = libs.getGame()))
	return (-1);
    }
  delete *lib;
  delete game;
  return (0);
}

int		Arcade::start(char **av)
{
  Libs		libs;
  Menu		menu;
  std::string	gameName;
  std::string	libName;
  Game		*game;
  ILib		*lib;
  int		ret;

  _score.checkHighscore();
  if (libs.loadGames() == -1 || libs.loadLibs() == -1)
    return (-1);
  libName = av[1];
  if (libs.openLib(libName, 1) == -1 || !(lib = libs.getLib()))
    return (-1);
  ret = 1;
  while (ret == 1)
    {
      if (ret == 1)
	if (menu.choose(&libs, lib, _score.getScoreTab()) == -1)
	  return (-1);
      lib->end();
      delete lib;
      libName = menu.getLibName();
      if (libs.openLib("./lib/" + libName, 1) == -1 || !(lib = libs.getLib()))
	return (-1);
      gameName = menu.getGameName();
      if (libs.openGame("./games/" + gameName, 1) == -1 || !(game = libs.getGame()))
	return (-1);
      if ((ret = launchGame(game, &lib, libs, menu)) == -1)
	return (-1);
    }
  return (0);
}
