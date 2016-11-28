//
// LibCaca.cpp for  in /home/saurs_f/cacatest
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Wed Mar  9 17:11:05 2016 Florian Saurs
// Last update Sun Apr  3 22:09:06 2016 Florian Saurs
//

#include <unistd.h>
#include "LibCaca.hpp"
#include "GameSnake.hpp"

LibCaca::LibCaca()
{
  nbr[0] = &LibCaca::Draw0;
  nbr[1] = &LibCaca::Draw1;
  nbr[2] = &LibCaca::Draw2;
  nbr[3] = &LibCaca::Draw3;
  nbr[4] = &LibCaca::Draw4;
  nbr[5] = &LibCaca::Draw5;
  nbr[6] = &LibCaca::Draw6;
  nbr[7] = &LibCaca::Draw7;
  nbr[8] = &LibCaca::Draw8;
  nbr[9] = &LibCaca::Draw9;
  _init = false;
  _shoot = false;
}

LibCaca::~LibCaca() {}

int		LibCaca::init()
{
  if (_init)
    return (0);
  if (caca_init())
    {
      fprintf(stderr, "Failed to load caca library.");
      return (-1);
    }
  caca_set_window_title("SnakeCaca");
  caca_clear();
  _init = true;
  return (0);
}

ILib		*makeLib()
{
  return (new LibCaca);
}

unsigned int	LibCaca::getEvent(unsigned int direction) const
{
  unsigned int	event;
  static int	received = 0;

  if (direction == STOP)
    return (received);
  event = caca_get_event(CACA_EVENT_KEY_PRESS);
  if (event == 0)
    {
      received = 0;
      return (direction);
    }
  received = 1;
  if (event == TOUCH_UP)
    return (UP);
  else if (event == TOUCH_LEFT)
    return (LEFT);
  else if (event == TOUCH_RIGHT)
    return (RIGHT);
  else if (event == TOUCH_DOWN)
    return (DOWN);
  else if (event == ESCAPE)
    return (0);
  else if (event == TOUCH_2)
    return (2);
  else if (event == TOUCH_3)
    return (3);
  else if (event == TOUCH_4)
    return (4);
  else if (event == TOUCH_5)
    return (5);
  else if (event == TOUCH_8)
    return (8);
  else if (event == TOUCH_9)
    return (9);
  else if (event == SPACE)
    return (1);
  return (direction);
}

void		LibCaca::DrawS() const
{
  caca_draw_thin_box(61, 1, 63, 1);
  caca_draw_thin_box(61, 2, 61, 3);
  caca_draw_thin_box(62, 3, 63, 3);
  caca_draw_thin_box(63, 3, 63, 5);
  caca_draw_thin_box(61, 5, 62, 5);
}

void		LibCaca::DrawC() const
{
  caca_draw_thin_box(65, 1, 67, 1);
  caca_draw_thin_box(65, 2, 65, 4);
  caca_draw_thin_box(65, 5, 67, 5);
}

void		LibCaca::DrawO() const
{
  caca_draw_thin_box(69, 1, 71, 1);
  caca_draw_thin_box(69, 2, 69, 4);
  caca_draw_thin_box(71, 2, 71, 4);
  caca_draw_thin_box(69, 5, 71, 5);
}

void		LibCaca::DrawR() const
{
  caca_draw_thin_box(73, 1, 74, 1);
  caca_draw_thin_box(73, 1, 73, 5);
  caca_draw_thin_box(74, 3, 74, 3);
  caca_draw_thin_box(75, 2, 75, 2);
  caca_draw_thin_box(75, 4, 75, 5);
}

void		LibCaca::DrawE() const
{
  caca_draw_thin_box(77, 1, 79, 1);
  caca_draw_thin_box(77, 5, 79, 5);
  caca_draw_thin_box(77, 3, 78, 3);
  caca_draw_thin_box(77, 1, 77, 5);
}

void		LibCaca::Draw0(int dec) const
{
  caca_draw_thin_box(61 + dec, 11, 63 + dec, 11);
  caca_draw_thin_box(61 + dec, 11, 61 + dec, 15);
  caca_draw_thin_box(63 + dec, 12, 63 + dec, 15);
  caca_draw_thin_box(62 + dec, 15, 63 + dec, 15);
}

void		LibCaca::Draw1(int dec) const
{
  caca_draw_thin_box(62 + dec, 11, 62 + dec, 15);
}

void		LibCaca::Draw2(int dec) const
{
  caca_draw_thin_box(61 + dec, 11, 63 + dec, 11);
  caca_draw_thin_box(61 + dec, 13, 63 + dec, 13);
  caca_draw_thin_box(61 + dec, 15, 63 + dec, 15);
  caca_draw_thin_box(63 + dec, 12, 63 + dec, 12);
  caca_draw_thin_box(61 + dec, 14, 61 + dec, 14);
}

void		LibCaca::Draw3(int dec) const
{
  caca_draw_thin_box(61 + dec, 11, 63 + dec, 11);
  caca_draw_thin_box(61 + dec, 13, 63 + dec, 13);
  caca_draw_thin_box(61 + dec, 15, 63 + dec, 15);
  caca_draw_thin_box(63 + dec, 12, 63 + dec, 14);
}

void		LibCaca::Draw4(int dec) const
{
  caca_draw_thin_box(61 + dec, 11, 61 + dec, 13);
  caca_draw_thin_box(63 + dec, 11, 63 + dec, 15);
  caca_draw_thin_box(62 + dec, 13, 62 + dec, 13);
}

void		LibCaca::Draw5(int dec) const
{
  caca_draw_thin_box(61 + dec, 11, 63 + dec, 11);
  caca_draw_thin_box(61 + dec, 12, 61 + dec, 13);
  caca_draw_thin_box(62 + dec, 13, 63 + dec, 13);
  caca_draw_thin_box(63 + dec, 13, 63 + dec, 15);
  caca_draw_thin_box(61 + dec, 15, 62 + dec, 15);
}

void		LibCaca::Draw6(int dec) const
{
  caca_draw_thin_box(61 + dec, 11, 63 + dec, 11);
  caca_draw_thin_box(61 + dec, 12, 61 + dec, 15);
  caca_draw_thin_box(62 + dec, 13, 63 + dec, 13);
  caca_draw_thin_box(63 + dec, 13, 63 + dec, 15);
  caca_draw_thin_box(61 + dec, 15, 62 + dec, 15);
}

void		LibCaca::Draw7(int dec) const
{
  caca_draw_thin_box(61 + dec, 11, 63 + dec, 11);
  caca_draw_thin_box(63 + dec, 12, 63 + dec, 15);
}

void		LibCaca::Draw8(int dec) const
{
  caca_draw_thin_box(61 + dec, 11, 63 + dec, 11);
  caca_draw_thin_box(61 + dec, 12, 61 + dec, 15);
  caca_draw_thin_box(62 + dec, 13, 63 + dec, 13);
  caca_draw_thin_box(63 + dec, 12, 63 + dec, 15);
  caca_draw_thin_box(61 + dec, 15, 62 + dec, 15);
}

void		LibCaca::Draw9(int dec) const
{
  caca_draw_thin_box(61 + dec, 11, 63 + dec, 11);
  caca_draw_thin_box(61 + dec, 11, 61 + dec, 13);
  caca_draw_thin_box(62 + dec, 13, 63 + dec, 13);
  caca_draw_thin_box(63 + dec, 12, 63 + dec, 15);
  caca_draw_thin_box(61 + dec, 15, 62 + dec, 15);
}

int		LibCaca::printMinus(int tmp) const
{
  caca_draw_thin_box(61, 13, 63, 13);
  return (-tmp);
}

void		LibCaca::printScore(int score)
{
  int		tmp;
  int		pow;
  int		dec;
  int		maxValue;

  caca_set_color(CACA_COLOR_MAGENTA, CACA_COLOR_MAGENTA);
  DrawS();
  DrawC();
  DrawO();
  DrawR();
  DrawE();
  tmp = score;
  dec = 99999;
  maxValue = 0;
  if (tmp < 99999)
    {
      if (tmp < 0)
	tmp = printMinus(tmp);
      while (dec > tmp)
	{
	  ++maxValue;
	  dec /= 10;
	}
      --maxValue;
      pow = 1;
      while (pow <= tmp)
	pow *= 10;
      if (tmp != 0)
	pow /= 10;
      while (pow != 0)
	{
	  (this->*(nbr[tmp / pow]))(maxValue * 4);
	  tmp %= pow;
	  pow /= 10;
	  ++maxValue;
	}
    }
}

void		LibCaca::printEntitie(Game *const game) const
{
  std::vector<Entity *>	hero;
  std::vector<Entity *>	ghost;
  std::vector<Powerup *>	pow;

  hero = game->getPos();
  ghost = game->getEntities();
  pow = game->getPowerups();
  caca_set_color(CACA_COLOR_RED, CACA_COLOR_RED);
  for (unsigned int i = 0; i < pow.size(); ++i)
    caca_draw_thin_box(pow.at(i)->getX(), pow.at(i)->getY(), pow.at(i)->getX(), pow.at(i)->getY());
  caca_set_color(CACA_COLOR_LIGHTRED, CACA_COLOR_LIGHTRED);
  for (unsigned int i = 0; i < ghost.size(); ++i)
    caca_draw_thin_box(ghost.at(i)->getX(), ghost.at(i)->getY(), ghost.at(i)->getX(), ghost.at(i)->getY());
  for (unsigned int i = 0; i < hero.size(); ++i)
    {
      if (i == 0 || i == hero.size() - 1)
	caca_set_color(CACA_COLOR_LIGHTGREEN, CACA_COLOR_LIGHTGREEN);
      else
	caca_set_color(CACA_COLOR_GREEN, CACA_COLOR_GREEN);
      caca_draw_thin_box(hero.at(i)->getX(), hero.at(i)->getY(), hero.at(i)->getX(), hero.at(i)->getY());
    }
}

int		LibCaca::print(Game * const game) const
{
  unsigned int	i;
  unsigned int	j;
  std::string	*_map;

  _map = game->getTab();
  i = 0;
  while (i < 30)
    {
      j = 0;
      while (j < 60)
  	{
  	  if (_map[i][j] == EMPTY)
	    {
	      caca_set_color(CACA_COLOR_DARKGRAY, CACA_COLOR_DARKGRAY);
	      caca_draw_thin_box(j, i, j, i);
	    }
  	  else if (_map[i][j] == 3)
	    {
	      caca_set_color(CACA_COLOR_BROWN, CACA_COLOR_BROWN);
	      caca_draw_thin_box(j, i, j, i);
	    }
  	  else if (_map[i][j] > 9)
	    {
	      caca_set_color(CACA_COLOR_BLUE, CACA_COLOR_BLUE);
	      caca_draw_thin_box(j, i, j, i);
	    }
	  else
	    caca_set_color(CACA_COLOR_BLACK, CACA_COLOR_BLACK);
  	  caca_draw_thin_box(j, i, j, i);
  	  ++j;
  	}
      ++i;
    }
  printEntitie(game);
  caca_set_color(CACA_COLOR_BLACK, CACA_COLOR_BLACK);
  i = 0;
  while (i < 30)
    {
      j = 60;
      while (j < 80)
	{
	  caca_draw_thin_box(j, i, j, i);
	  ++j;
	}
      ++i;
    }
  const_cast<LibCaca *>(this)->printScore(game->getScore());
  caca_refresh();
  return (0);
}

int		LibCaca::end()
{
  caca_end();
  return (0);
}

int		LibCaca::playSound(e_sound sound)
{
  std::ofstream	tty;

  tty.open("/dev/tty");
  if (tty.fail())
    return (0);
  if (sound == SNAKEEATS || sound == PACMANEATS)
    tty << '\a';
  if (sound == DIE)
    for (int i = 0; i < 4; i++)
      {
	usleep(i % 2 == 0 ? 500000 : 300000);
	tty << '\a' << std::flush;
      }
  tty.close();
  return (0);
}

char		LibCaca::getChar() const
{
  unsigned int	event = 0;

  event = caca_get_event(CACA_EVENT_KEY_PRESS);
  if (event != 0)
    {
      if (event == ESCAPE)
	return (-1);
      if (event == RETURN)
	return (0);
      if (event)
	return (event);
    }
  return (-2);
}

int			LibCaca::displayBase(Menu *const menu) const
{
  std::string		intro = "The Arcade !";
  std::string		toPrint = "";
  unsigned int		i = 0;
  int			x = 1;
  int			y = 1;

  caca_set_color(CACA_COLOR_BLACK, CACA_COLOR_WHITE);
  caca_putstr(x, y, intro.c_str());
  toPrint = !menu->getLibs()->getGames().size() ? "No games available" : "Games :";
  caca_putstr(x, ++y, toPrint.c_str());
  for (i = 0; i < menu->getLibs()->getGames().size(); i++)
    {
      menu->getLibs()->getGames()[i] == menu->getGameName() ? caca_set_color(CACA_COLOR_GREEN, CACA_COLOR_WHITE): caca_set_color(CACA_COLOR_BLACK, CACA_COLOR_WHITE);
      caca_putstr(x, ++y, menu->getLibs()->getGames()[i].c_str());
    }
  caca_set_color(CACA_COLOR_BLACK, CACA_COLOR_WHITE);
  toPrint = !menu->getLibs()->getGames().size() ? "No libraries available" : "Libraries :";
  caca_putstr(x, ++y, toPrint.c_str());
  for (i = 0; i < menu->getLibs()->getLibs().size(); i++)
    {
      menu->getLibs()->getLibs()[i] == menu->getLibName() ? caca_set_color(CACA_COLOR_GREEN, CACA_COLOR_WHITE): caca_set_color(CACA_COLOR_BLACK, CACA_COLOR_WHITE);
      caca_putstr(x, ++y, menu->getLibs()->getLibs()[i].c_str());
    }
  caca_set_color(CACA_COLOR_BLACK, CACA_COLOR_WHITE);
  if (menu->getScore())
    {
      caca_putstr(x, ++y, "Score :");
      i = 0;
      while (menu->getScore()[i] != "" && i < 10)
	{
	  toPrint = menu->getScore()[i++].c_str();
	  caca_putstr(x, ++y, toPrint.c_str());
	}
    }
  toPrint = "Please enter your login (1-10 characters) :\n";
  caca_putstr(x, ++y, toPrint.c_str());
  return (++y);
}

void			LibCaca::printMenu(Menu * const menu) const
{
  static int		cursor = 0;
  std::string		login;
  int			y;
  int			x;

  x = 1;
  caca_set_color(CACA_COLOR_BLACK, CACA_COLOR_BLACK);
  for (int i = 0; i < 200; ++i)
    for (int j = 0; j < 200; ++j)
      caca_draw_thin_box(i, j, i + 1, j + 1);
  login = menu->getLogin();
  if ((y = displayBase(menu)) == -1)
    return ;
  if (cursor < 10)
    login += "|";
  if (login != "")
    caca_putstr(x, y, login.c_str());
  if (cursor < 10)
    login.pop_back();
  caca_refresh();
  cursor = cursor == 20 ? 0 : cursor + 1;
}

int		LibCaca::chooseGame(Menu * const menu) const
{
  std::string	intro = "The Arcade !";
  std::string	toPrint = "";
  unsigned int	i = 0;
  unsigned int	idx = 0;
  int		x;
  int		y;
  unsigned int	event = 0;

  while (42)
    {
      caca_set_color(CACA_COLOR_BLACK, CACA_COLOR_BLACK);
      for (int i = 0; i < 200; ++i)
	for (int j = 0; j < 200; ++j)
	  caca_draw_thin_box(i, j, i + 1, j + 1);
      x = 1;
      y = 1;
      caca_set_color(CACA_COLOR_BLACK, CACA_COLOR_WHITE);
      toPrint = !menu->getLibs()->getNbGame() ? "No games available" : "Games :";
      caca_putstr(x, y, intro.c_str());
      caca_putstr(x, ++y, toPrint.c_str());
      for (i = 0; i < menu->getLibs()->getNbGame(); i++)
	{
	  i == idx ? caca_set_color(CACA_COLOR_GREEN, CACA_COLOR_WHITE): caca_set_color(CACA_COLOR_BLACK, CACA_COLOR_WHITE);
	  caca_putstr(x, ++y, menu->getLibs()->getGames()[i].c_str());
	}
      caca_refresh();
      event = caca_wait_event(CACA_EVENT_KEY_PRESS);
      if (event != 0)
	{
	  if (event == TOUCH_DOWN)
	    idx = idx >= menu->getLibs()->getNbGame() - 1 ? 0 : idx + 1;
	  if (event == TOUCH_UP)
	    idx = idx == 0 ? menu->getLibs()->getNbGame() - 1 : idx - 1;
	  if (event == RETURN)
	    {
	      if (idx < menu->getLibs()->getNbGame())
                menu->setGameName(menu->getLibs()->getGames()[idx]);
              else
                return (-1);
	      return (0);
	    }
	  if (event == ESCAPE)
	    return (-1);
	}
    }
}

int		LibCaca::chooseLib(Menu * const menu) const
{
  std::string	intro = "The Arcade !";
  std::string	toPrint = "";
  unsigned int	i = 0;
  unsigned int	idx = 0;
  int		x;
  int		y;
  unsigned int	event = 0;

  while (42)
    {
      caca_set_color(CACA_COLOR_BLACK, CACA_COLOR_BLACK);
      for (int i = 0; i < 200; ++i)
	for (int j = 0; j < 200; ++j)
	  caca_draw_thin_box(i, j, i + 1, j + 1);
      x = 1;
      y = 1;
      caca_set_color(CACA_COLOR_BLACK, CACA_COLOR_WHITE);
      toPrint = !menu->getLibs()->getNbGame() ? "No games available" : "Games :";
      caca_putstr(x, y, intro.c_str());
      caca_putstr(x, ++y, toPrint.c_str());
      for (i = 0; i < menu->getLibs()->getNbGame(); i++)
	{
	  menu->getLibs()->getGames()[i] == menu->getGameName() ? caca_set_color(CACA_COLOR_GREEN, CACA_COLOR_WHITE): caca_set_color(CACA_COLOR_BLACK, CACA_COLOR_WHITE);
	  caca_putstr(x, ++y, menu->getLibs()->getGames()[i].c_str());
	}
      toPrint = !menu->getLibs()->getLibs().size() ? "No libs available" : "Libraries :";
      caca_putstr(x, ++y, toPrint.c_str());
      for (i = 0; i < menu->getLibs()->getLibs().size(); i++)
	{
	  i == idx ? caca_set_color(CACA_COLOR_GREEN, CACA_COLOR_WHITE): caca_set_color(CACA_COLOR_BLACK, CACA_COLOR_WHITE);
	  caca_putstr(x, ++y, menu->getLibs()->getLibs()[i].c_str());
	}
      caca_refresh();
      event = caca_wait_event(CACA_EVENT_KEY_PRESS);
      if (event != 0)
	{
	  if (event == TOUCH_DOWN)
	    idx = idx >= menu->getLibs()->getNbLib() - 1 ? 0 : idx + 1;
	  if (event == TOUCH_UP)
	    idx = idx == 0 ? menu->getLibs()->getNbLib() - 1 : idx - 1;
	  if (event == RETURN)
	    {
	      if (idx < menu->getLibs()->getNbLib())
		menu->setLibName(menu->getLibs()->getLibs()[idx]);
              else
                return (-1);

	      return (0);
	    }
	  if (event == ESCAPE)
	    return (-1);
	}
    }
}
