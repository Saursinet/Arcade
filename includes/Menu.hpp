//
// Menu.hpp for Arcade in /home/wilmot_g/Rendu/cpp_arcade2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Apr  1 23:13:53 2016 guillaume wilmot
// Last update Sun Apr  3 18:19:41 2016 Nyrandone Noboud-Inpeng
//

#ifndef MENU_HPP_
# define MENU_HPP_

# include <iostream>
# include "Libraries.hpp"
# include "ILib.hpp"
# include "Score.hpp"

class Libs;
class ILib;

class			Menu {
public:
  Menu();
  ~Menu() {}

  int			choose(Libs *, ILib *, std::string *);
  std::string		getLibName() const;
  std::string		getGameName() const;
  std::string		getLogin() const;
  Libs			*getLibs() const;
  std::string		*getScore() const;
  unsigned int		getIndexGame() const;
  unsigned int		getIndexLib() const;
  void			setLibName(const std::string &);
  void			setGameName(const std::string &);
  void			findIndexes();
private:
  void			parseLibName(std::string &);

  Libs			*_libs;
  std::string		*_score;
  std::string		_libName;
  std::string		_gameName;
  std::string		_login;
  unsigned int		_indexGame;
  unsigned int		_indexLib;
};

#endif /* !MENU_HPP_ */
