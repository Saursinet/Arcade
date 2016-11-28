//
// Libraries.hpp for Libraries in /home/noboud_n/rendu/cpp_arcade/src
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.net>
//
// Started on  Fri Apr  1 14:14:28 2016 Nyrandone Noboud-Inpeng
// Last update Sat Apr  2 03:40:22 2016 guillaume wilmot
//

#ifndef LIBRARIES_HPP_
# define LIBRARIES_HPP_

# include <vector>
# include "Game.hpp"
# include "ILib.hpp"

class Game;
class ILib;

class	Libs {
public:
  Libs();
  ~Libs();
  Libs(const Libs &);
  Libs			&operator=(const Libs &);

  std::vector<std::string>	getLibs() const;
  std::vector<std::string>	getGames() const;
  unsigned int			getNbLib() const;
  unsigned int			getNbGame() const;
  Game				*getGame() const;
  ILib				*getLib() const;

  int				openLib(const std::string &, int);
  int				openGame(const std::string &, int);
  int				loadLibs();
  int				loadGames();

private:
  std::vector<std::string>	_libs;
  ILib				*_lib;
  unsigned int			_nbLib;
  unsigned int			_typeLib;
  void				*_handleLib;
  std::vector<std::string>	_games;
  Game				*_game;
  unsigned int			_nbGame;
  unsigned int			_typeGame;
  void				*_handleGame;

};

#endif /* LIBRARIES_HPP_ */
