//
// ILib.hpp for ILib in /home/wilmot_g/Rendu/cpp_arcade/leHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Mar  9 16:50:44 2016 guillaume wilmot
// Last update Sun Apr  3 18:01:09 2016 Nyrandone Noboud-Inpeng
//

#ifndef ILIB_HPP_
# define ILIB_HPP_

# include "Game.hpp"
# include "Menu.hpp"

# define UNUSED __attribute__((__unused__))

class Menu;

enum	e_sound
  {
    MUSICPACMAN = 0,
    MUSICSNAKE,
    DIE,
    SNAKEEATS,
    PACMANEATS,
    WAKAWAKA
  };

class Game;

class ILib {
public:
  virtual ~ILib() {};
  virtual int		init() = 0;
  virtual int		print(Game * const) const = 0;
  virtual int		end() = 0;
  virtual unsigned int	getEvent(unsigned int) const = 0;
  virtual int		playSound(e_sound) = 0;
  virtual void		printMenu(Menu * const) const = 0;
  virtual char		getChar() const = 0;
  virtual int		chooseGame(Menu * const) const = 0;
  virtual int		chooseLib(Menu * const) const = 0;
};

#endif /* !ILIB_HPP_ */
