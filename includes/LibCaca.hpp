//
// CacaLib.hpp for  in /home/saurs_f/cacatest
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Wed Mar  9 17:08:29 2016 Florian Saurs
// Last update Sun Apr  3 22:08:10 2016 Florian Saurs
//

#ifndef CACALIB_HPP_
# define CACALIB_HPP_

# include <map>
# include "caca.h"
# include "Game.hpp"
# include "ILib.hpp"
# include "Menu.hpp"

extern "C"
{
  ILib	*makeLib();
};

class LibCaca  : public ILib {
public:
  LibCaca();
  virtual ~LibCaca();

private:
  int			init();
  void			printScore(int);
  int			print(Game * const) const;
  int			end();
  unsigned int		getEvent(unsigned int) const;
  int			playSound(e_sound);
  void			DrawS() const;
  void			DrawC() const;
  void			DrawO() const;
  void			DrawR() const;
  void			DrawE() const;
  void			Draw0(int) const;
  void			Draw1(int) const;
  void			Draw2(int) const;
  void			Draw3(int) const;
  void			Draw4(int) const;
  void			Draw5(int) const;
  void			Draw6(int) const;
  void			Draw7(int) const;
  void			Draw8(int) const;
  void			Draw9(int) const;
  int			printMinus(int) const;
  void			printMenu(Menu * const) const;
  char			getChar() const;
  int			chooseGame(Menu * const) const;
  int			chooseLib(Menu * const) const;
  void			updateShoot(bool);
  bool			getShoot()const;
  void			printEntitie(Game *const) const;
  int			displayBase(Menu *const) const;
  int			choosLib(Menu const *) const;
  int			choosGame(Menu const *) const;

  std::map<int, void (LibCaca::*)(int) const>	nbr;
  std::map<unsigned int, char>			_alpha;
  bool						_shoot;
  bool						_init;
};

#endif /* !CACALIB_HPP_ */
