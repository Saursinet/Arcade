//
// Lib.cpp for cpp_arcade in /home/wilmot_g/Rendu/cpp_arcade/leHaineux/src
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Mar  9 16:55:49 2016 guillaume wilmot
// Last update Sun Apr  3 22:30:06 2016 guillaume wilmot
//

#include <signal.h>
#include <unistd.h>
#include "LibSDL.hpp"

ILib					*makeLib()
{
  return (new LibSDL);
}

LibSDL::LibSDL()
{
  _init = false;
}

LibSDL::~LibSDL() {}

LibSDL::LibSDL(const LibSDL &) {}

LibSDL					&LibSDL::operator=(const LibSDL &)
{
  return (*this);
}

int					LibSDL::init()
{
  if (_init)
    return (0);
  if (SDL_Init(SDL_INIT_VIDEO) == -1 ||
      (_screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_NOFRAME)) == NULL)
    {
      std::cerr << "Could not initiate SDL" << std::endl;
      return (-1);
    }
  SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, 180);
  SDL_WM_SetCaption("Arcade SDL", NULL);
  if (TTF_Init() == -1)
    {
      std::cerr << "Could not initiate TTF" << std::endl;
      return (-1);
    }
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
      std::cerr << "Could not initiate MIX" << std::endl;
      return (-1);
    }
  if ((_police = TTF_OpenFont("assets/Calibri.ttf", 50)) == NULL
      || (_menuPolice = TTF_OpenFont("assets/Calibri.ttf", 30)) == NULL)
    {
      std::cerr << "Could not find assets/Calibri.ttf" << std::endl;
      return (0);
    }
  Mix_AllocateChannels(100);
  SDL_EnableUNICODE(1);
  if (loadAssets() == -1)
    return (-1);
  if (!(_buff = SDL_CreateRGBSurface(SDL_HWSURFACE, WINX, WINY, BPP, 0, 0, 0, 0)))
    return (-1);
  signal(SIGINT, SIG_DFL);
  _init = true;
  return (0);
}

int					LibSDL::printBorder(int i, int j, t_line ref, Game * const game) const
{
  char					touch[4];
  t_line				line;

  touch[0] = (i > 0) ? game->getTab()[i - 1][j] : 1;
  touch[1] = (j < game->getWidth() - 1) ? game->getTab()[i][j + 1] : 1;
  touch[2] = (i < game->getHeight() - 1) ? game->getTab()[i + 1][j] : 1;
  touch[3] = (j > 0) ? game->getTab()[i][j - 1] : 1;
  line = ref;
  if (touch[0] != 1)
    {
      line.x2 += 31;
      drawLine(line, _buff, COLORE);
      line.y1 += SIZEBORDER;
      line.y2 += SIZEBORDER;
      line.x1 = (touch[3] != 1) ? line.x1 + SIZEBORDER : line.x1 - SIZEBORDER;
      line.x2 = (touch[1] != 1) ? line.x2 - SIZEBORDER : line.x2 + SIZEBORDER;
      drawLine(line, _buff, COLORI);
    }
  line = ref;
  if (touch[1] != 1)
    {
      line.x1 += 31;
      line.x2 += 31;
      line.y2 += 31;
      drawLine(line, _buff, COLORE);
      line.x1 -= SIZEBORDER;
      line.x2 -= SIZEBORDER;
      line.y1 = (touch[0] != 1) ? line.y1 + SIZEBORDER : line.y1 - SIZEBORDER;
      line.y2 = (touch[2] != 1) ? line.y2 - SIZEBORDER : line.y2 + SIZEBORDER;
      drawLine(line, _buff, COLORI);
    }
  line = ref;
  if (touch[2] != 1)
    {
      line.y1 += 31;
      line.y2 += 31;
      line.x2 += 31;
      drawLine(line, _buff, COLORE);
      line.y1 -= SIZEBORDER;
      line.y2 -= SIZEBORDER;
      line.x1 = (touch[3] != 1) ? line.x1 + SIZEBORDER : line.x1 - SIZEBORDER;
      line.x2 = (touch[1] != 1) ? line.x2 - SIZEBORDER : line.x2 + SIZEBORDER;
      drawLine(line, _buff, COLORI);
    }
  line = ref;
  if (touch[3] != 1)
    {
      line.y2 += 31;
      drawLine(line, _buff, COLORE);
      line.x1 += SIZEBORDER;
      line.x2 += SIZEBORDER;
      line.y1 = (touch[0] != 1) ? line.y1 + SIZEBORDER : line.y1 - SIZEBORDER;
      line.y2 = (touch[2] != 1) ? line.y2 - SIZEBORDER : line.y2 + SIZEBORDER;
      drawLine(line, _buff, COLORI);
    }
  return (0);
}

int					LibSDL::getAngle(const std::vector<Entity *> &e, unsigned int i) const
{
  int					x1;
  int					x2;
  int					x3;
  int					y1;
  int					y2;
  int					y3;

  x1 = e[i]->getY();
  y1 = e[i]->getX();
  x2 = (i < e.size() - 1) ? e[i + 1]->getY() : -1;
  y2 = (i < e.size() - 1) ? e[i + 1]->getX() : -1;
  x3 = (i > 0) ? e[i - 1]->getY() : -1;
  y3 = (i > 0) ? e[i - 1]->getX() : -1;
  if (i == 0)
    {
      if (x2 < x1 || x2 > x1)
	return (x2 < x1 ? 3 : 1);
      if (y2 < y1 || y2 > y1)
	return (y2 < y1 ? 2 : 0);
      return (0);
    }
  else if (i >= e.size() - 1)
    {
      if (x3 < x1 || x3 > x1)
	return (x3 > x1 ? 3 : 1);
      if (y3 < y1 || y3 > y1)
	return (y3 > y1 ? 2 : 0);
      return (0);
    }
  if ((x1 != x2 || x1 != x3) && (y1 != y2 || y1 != y3))
    {
      if ((y2 > y1 && x3 > x1) || (y3 > y1 && x2 > x1))
	return (-3);
      if ((x2 < x1 && y3 > y1) || (y2 > y1 && x3 < x1))
	return (-2);
      if ((y2 < y1 && x3 < x1) || (y3 < y1 && x2 < x1))
	return (-1);
      if ((x2 > x1 && y3 < y1) || (y2 < y1 && x3 > x1))
	return (-42);
    }
  if (x3 < x1 || x3 > x1)
    return (x3 > x1 ? 3 : 1);
  if (x2 < x1 || x2 > x1)
    return (x2 < x1 ? 3 : 1);
  return (0);
}

int					LibSDL::printSnakePart(SDL_Rect pos, int angle, SDL_Surface * const *tile) const
{
 if (angle < 0)
   {
     angle = (angle == -42) ? 0 : -angle;
     tile = _assets.snake.corner;
   }
 SDL_BlitSurface(tile[angle], NULL, _buff, &pos);
 return (0);
}

int					LibSDL::pacmanBlocked(int i, int j, Game * const game) const
{
  i = game->limitY(i);
  j = game->limitX(j);
  if (i < 0 || j < 0)
    return (1);
  if (game->getTab()[i][j] == 1 || game->getTab()[i][j] == 3)
    return (1);
  return (0);
}

int					LibSDL::isBlocked(int i, int j, Game * const game) const
{
  i = game->limitY(i);
  j = game->limitX(j);
  if (i < 0 || j < 0)
    return (1);
  if (game->getTab()[i][j] == 1 || game->getTab()[i][j] == 3)
    return (1);
  if (game->getTab()[i][j] == 7)
    if ((game->getPos()[0]->getDirection() == DOWN && pacmanBlocked(game->getPos()[0]->getY() + 1, game->getPos()[0]->getX(), game)) ||
	(game->getPos()[0]->getDirection() == UP && pacmanBlocked(game->getPos()[0]->getY() - 1, game->getPos()[0]->getX(), game)) ||
	(game->getPos()[0]->getDirection() == LEFT && pacmanBlocked(game->getPos()[0]->getY(), game->getPos()[0]->getX() - 1, game)) ||
	(game->getPos()[0]->getDirection() == RIGHT && pacmanBlocked(game->getPos()[0]->getY(), game->getPos()[0]->getX() + 1, game)))
      return (1);
  return (0);
}

int					LibSDL::printMushroom(int diff, int i, int j) const
{
  SDL_Rect				pos;
  SDL_Surface				*mush;
  unsigned int				color;

  pos.y = i * 32;
  pos.x = j * 32;
  pos.y += diff * (32 / static_cast<float>(5));
  if (!(mush = SDL_CreateRGBSurface(SDL_HWSURFACE, 32, (5 - diff) * 32 / static_cast<float>(5), BPP, 0, 0, 0, 0)))
    return (-1);
  diff = 5 - diff;
  color = 0;
  color |= ((255 * diff * 20) / 100) << 8;
  color |= ((255 * (100 - (diff * 20))) / 100) << 16;
  SDL_FillRect(mush, NULL, color);
  SDL_BlitSurface(mush, NULL, _buff, &pos);
  return (0);
}

int					LibSDL::printOneEntity(const std::vector<Entity *> &e, int i, Game * const game) const
{
  SDL_Rect				pos;
  SDL_Surface				*tile2;
  SDL_Surface				*tile3;
  int					angle;

  pos.y = e[i]->getY() * 32;
  pos.x = e[i]->getX() * 32;

  if (!e[i]->getStandBy())
    {
      if (e[i]->getDirection() == DOWN && isBlocked(e[i]->getY() + 1, e[i]->getX(), game) != 1)
	pos.y += (e[i]->getFrame() % 4) * 32 / 4;
      else if (e[i]->getDirection() == UP && isBlocked(e[i]->getY() - 1, e[i]->getX(), game) != 1)
	pos.y -= (e[i]->getFrame() % 4) * 32 / 4;
      else if (e[i]->getDirection() == LEFT && isBlocked(e[i]->getY(), e[i]->getX() - 1, game) != 1)
	pos.x -= (e[i]->getFrame() % 4) * 32 / 4;
      else if (e[i]->getDirection() == RIGHT && isBlocked(e[i]->getY(), e[i]->getX() + 1, game) != 1)
	pos.x += (e[i]->getFrame() % 4) * 32 / 4;
    }

  if ((e[i]->getType() == Entity::e_type::PINK ||
      e[i]->getType() == Entity::e_type::RED ||
      e[i]->getType() == Entity::e_type::BLUE ||
       e[i]->getType() == Entity::e_type::YELLOW) && e[i]->getDead())
    SDL_BlitSurface(_assets.pacman.eyes[e[i]->getFrame()], NULL, _buff, &pos);
  else if ((e[i]->getType() == Entity::e_type::PINK ||
      e[i]->getType() == Entity::e_type::RED ||
      e[i]->getType() == Entity::e_type::BLUE ||
       e[i]->getType() == Entity::e_type::YELLOW) && game->getPos()[0]->getStatus())
    SDL_BlitSurface(e[i]->getFrame() ? _assets.pacman.dead2 : _assets.pacman.dead, NULL, _buff, &pos);
  else if (e[i]->getType() == Entity::e_type::RED)
    SDL_BlitSurface(_assets.pacman.red[e[i]->getFrame()], NULL, _buff, &pos);
  else if (e[i]->getType() == Entity::e_type::PINK)
    SDL_BlitSurface(_assets.pacman.pink[e[i]->getFrame()], NULL, _buff, &pos);
  else if (e[i]->getType() == Entity::e_type::YELLOW)
    SDL_BlitSurface(_assets.pacman.yellow[e[i]->getFrame()], NULL, _buff, &pos);
  else if (e[i]->getType() == Entity::e_type::BLUE)
    SDL_BlitSurface(_assets.pacman.blue[e[i]->getFrame()], NULL, _buff, &pos);
  else if (e[i]->getType() == Entity::e_type::PAC)
    {
      angle = 0;
      angle = (e[i]->getDirection() == UP) ? 90 : angle;
      angle = (e[i]->getDirection() == LEFT) ? 180 : angle;
      angle = (e[i]->getDirection() == DOWN) ? 270 : angle;
      tile2 = SDL_CreateRGBSurface(SDL_HWSURFACE, 32, 32, BPP, 0, 0, 0, 0);
      SDL_BlitSurface(_assets.pacman.pac[e[i]->getFrame() % 4], NULL, tile2, NULL);
      tile3 = rotozoomSurface(tile2, angle, 1, 0);
      SDL_SetColorKey(tile3, SDL_SRCCOLORKEY, SDL_MapRGB(tile2->format, 0, 0, 0));
      SDL_FreeSurface(tile2);
      SDL_BlitSurface(tile3, NULL, _buff, &pos);
      SDL_FreeSurface(tile3);
    }
  else if (e[i]->getType() == Entity::e_type::HEAD)
    printSnakePart(pos, getAngle(e, i), _assets.snake.head);
  else if (e[i]->getType() == Entity::e_type::BODY)
    printSnakePart(pos, getAngle(e, i), _assets.snake.body);
  else if (e[i]->getType() == Entity::e_type::TAIL)
    printSnakePart(pos, getAngle(e, i), _assets.snake.tail);
  else if (e[i]->getType() == Entity::e_type::SHIP)
    SDL_BlitSurface(_assets.ship[e[i]->getFrame() % 3], NULL, _buff, &pos);

  if (!e[i]->getStandBy() || (e[i]->getType() == Entity::e_type::SHIP))
    if ((e[i]->getType() == Entity::e_type::SHIP) ||
	((e[i]->getDirection() == DOWN && isBlocked(e[i]->getY() + 1, e[i]->getX(), game) != 1) ||
	 (e[i]->getDirection() == UP && isBlocked(e[i]->getY() - 1, e[i]->getX(), game) != 1) ||
	 (e[i]->getDirection() == LEFT && isBlocked(e[i]->getY(), e[i]->getX() - 1, game) != 1) ||
	 (e[i]->getDirection() == RIGHT && isBlocked(e[i]->getY(), e[i]->getX() + 1, game) != 1)))
      e[i]->setFrame(e[i]->getFrame() == 7 ? 0 : e[i]->getFrame() + 1);
  return (0);
}

int					LibSDL::printPowerup(Powerup *p) const
{
  SDL_Rect				pos;

  pos.y = p->getY() * 32;
  pos.x = p->getX() * 32;
  if (p->getType() == Powerup::e_type::GUM)
    SDL_BlitSurface(_assets.pacman.gum, NULL, _buff, &pos);
  else if (p->getType() == Powerup::e_type::BIGGUM)
    SDL_BlitSurface(_assets.pacman.bigGum, NULL, _buff, &pos);
  else if (p->getType() == Powerup::e_type::FOOD)
    SDL_BlitSurface(_assets.snake.food, NULL, _buff, &pos);
  else if (p->getType() == Powerup::e_type::SHOT)
    SDL_BlitSurface(_assets.snake.food, NULL, _buff, &pos);
  return (0);
}

int					LibSDL::printEntity(Game * const game) const
{
  unsigned int				i;
  unsigned int				n;

  for (i = 0; i < game->getPowerups().size(); i++)
    printPowerup(game->getPowerups()[i]);
  for (i = 0; i < game->getShots().size(); i++)
    printPowerup(static_cast<Powerup *>(game->getShots()[i]));
  for (i = 0; i < game->getPos().size(); i++)
    printOneEntity(game->getPos(), i, game);
  for (i = 0; i < game->getEntities().size(); i++)
    printOneEntity(game->getEntities(), i, game);
  for (i = 0; i < game->getCenti().size(); i++)
    for (n = 0; n < game->getCenti().at(i).size(); n++)
      printOneEntity(game->getCenti().at(i), n, game);
  return (0);
}


int					LibSDL::printScore(Game * const game) const
{
  std::string				score;
  SDL_Surface				*text;
  SDL_Color				color;
  SDL_Rect				pos;

  memset(&color, 255, sizeof(color));
  pos.x = 32;
  pos.y = (30 * 32);
  score = "Score : ";
  if (!(text = TTF_RenderText_Blended(_police, score.c_str(), color)))
    return (0);
  SDL_BlitSurface(text, NULL, _buff, &pos);
  SDL_FreeSurface(text);
  pos.x += 150;
  score = std::to_string(game->getScore());
  if (!(text = TTF_RenderText_Blended(_police, score.c_str(), color)))
    return (0);
  SDL_BlitSurface(text, NULL, _buff, &pos);
  SDL_FreeSurface(text);
  return (0);
}

int					LibSDL::print(Game * const game) const
{
  t_line				line = {0, 0, 0, 0};
  int					i;
  int					j;

  SDL_FillRect(_buff, NULL, 0x000000);
  for (i = 0; i < game->getHeight(); i++)
    {
      line.x1 = 0;
      line.x2 = 0;
      for (j = 0; j < game->getWidth(); j++)
	{
	  if (game->getTab()[i][j] == 1)
	    printBorder(i, j, line, game);
	  if (game->getTab()[i][j] > 10 && game->getTab()[i][j] <= 15)
	    printMushroom(15 - game->getTab()[i][j], i, j);
	  line.x1 += 32;
	  line.x2 += 32;
	}
      line.y1 += 32;
      line.y2 += 32;
    }
  printEntity(game);
  printScore(game);
  SDL_BlitSurface(_buff, NULL, _screen, NULL);
  SDL_Flip(_screen);
  return (0);
}

int					LibSDL::playSound(e_sound sound)
{
  if (_sounds[sound] != NULL)
    Mix_PlayChannel(-1, _sounds[sound], 0);
  else if (sound == MUSICPACMAN && Mix_PlayingMusic() != 1)
    Mix_PlayMusic(_assets.sounds.pacmanMusic, -1);
  else if (sound == MUSICSNAKE && Mix_PlayingMusic() != 1)
    Mix_PlayMusic(_assets.sounds.snakeMusic, -1);
  if (sound == DIE)
    sleep(2);
  return (0);
}

unsigned int				LibSDL::getEvent(unsigned int direction) const
{
  SDL_Event				ev;
  int					e;
  static int				received = 0;

  if (direction == STOP)
    return (received);
  while ((e = SDL_PollEvent(&ev)) && ev.type != SDL_KEYDOWN && ev.type != SDL_QUIT);
  if (!e || (e && ev.type != SDL_KEYDOWN && ev.type != SDL_QUIT))
    {
      received = 0;
      return (direction);
    }
  received = 1;
  if ((ev.key.keysym.sym == SDLK_ESCAPE) || ev.type == SDL_QUIT)
    return (0);
  if (ev.key.keysym.sym == SDLK_UP)
    return (UP);
  if (ev.key.keysym.sym == SDLK_DOWN)
    return (DOWN);
  if (ev.key.keysym.sym == SDLK_LEFT)
    return (LEFT);
  if (ev.key.keysym.sym == SDLK_RIGHT)
    return (RIGHT);
  if (ev.key.keysym.sym == SDLK_SPACE)
    return (1);
  if (ev.key.keysym.mod & KMOD_SHIFT)
    {
      if (ev.key.keysym.sym == 233)
	return (2);
      if (ev.key.keysym.sym == 34)
	return (3);
      if (ev.key.keysym.sym == 39)
	return (4);
      if (ev.key.keysym.sym == 40)
	return (5);
      if (ev.key.keysym.sym == 95)
	return (8);
      if (ev.key.keysym.sym == 231)
	return (9);
    }
  else
    {
      if (ev.key.keysym.sym == SDLK_2)
	return (2);
      if (ev.key.keysym.sym == SDLK_3)
	return (3);
      if (ev.key.keysym.sym == SDLK_4)
	return (4);
      if (ev.key.keysym.sym == SDLK_5)
	return (5);
      if (ev.key.keysym.sym == SDLK_8)
	return (8);
      if (ev.key.keysym.sym == SDLK_9)
	return (9);
    }
  return (direction);
}

int					LibSDL::printText(const std::string &str, SDL_Rect *pos, int i, unsigned int c) const
{
  SDL_Surface				*text;
  SDL_Color				color;

  color.r = c >> 16;
  color.g = (c >> 8) ^ 0x00FF00;
  color.b = c ^ 0xFFFF00;
  if (!(text = TTF_RenderText_Blended(_menuPolice, str.c_str(), color)))
    return (-1);
  SDL_BlitSurface(text, NULL, _buff, pos);
  SDL_FreeSurface(text);
  pos->y += i;
  return (0);
}

int					LibSDL::displayBase(SDL_Rect *pos, Menu * const menu) const
{
  std::string				intro = "The Arcade !";
  std::string				toPrint = "";
  unsigned int				i = 0;

  pos->x = 32;
  pos->y = 0;
  if (printText(intro.c_str(), pos, 32, 0xffffff) == -1)
    return (-1);
  toPrint = !menu->getLibs()->getGames().size() ? "No games available" : "Games :";
  if (printText(toPrint.c_str(), pos, 32, 0xffffff) == -1)
    return (-1);
  for (i = 0; i < menu->getLibs()->getGames().size(); i++)
    if (printText(menu->getLibs()->getGames()[i], pos, 32, menu->getLibs()->getGames()[i] == menu->getGameName() ? 0x50ff50 : 0xffffff) == -1)
      return (-1);
  pos->y += 32;
  toPrint = !menu->getLibs()->getGames().size() ? "No libraries available" : "Libraries :";
  if (printText(toPrint.c_str(), pos, 32, 0xffffff) == -1)
    return (-1);
  for (i = 0; i < menu->getLibs()->getLibs().size(); i++)
    if (printText(menu->getLibs()->getLibs()[i], pos, 32, menu->getLibs()->getLibs()[i] == menu->getLibName() ? 0x50ff50 : 0xffffff) == -1)
      return (-1);
  pos->y += 32;
  if (menu->getScore())
    {
      if (printText("Score :", pos, 32, 0xffffff) == -1)
	return (-1);
      i = 0;
      while (menu->getScore()[i] != "" && i < 10)
	{
	  toPrint = menu->getScore()[i++].c_str();
	  if (printText(toPrint.c_str(), pos, 32, 0xffffff) == -1)
	    return (-1);
	}
      pos->y += 32;
    }
  toPrint = "Please enter your login (1-10 characters) :";
  if (printText(toPrint.c_str(), pos, 32, 0xffffff) == -1)
    return (-1);
  pos->y += 32 * 2;
  return (0);
}

void					LibSDL::printMenu(Menu * const menu) const
{
  static int				cursor = 0;
  SDL_Surface				*text;
  SDL_Color				color;
  SDL_Rect				pos;
  std::string				login;

  login = menu->getLogin();
  memset(&color, 255, sizeof(color));
  SDL_BlitSurface(_buff, NULL, _screen, NULL);
  SDL_Flip(_screen);
  SDL_FillRect(_buff, NULL, 0x000000);
  SDL_Flip(_screen);
  if (displayBase(&pos, menu) == -1)
    return ;
  if (cursor < 10)
    login += "|";
  if (login != "")
    {
      if (!(text = TTF_RenderText_Blended(_menuPolice, login.c_str(), color)))
	return ;
      SDL_BlitSurface(text, NULL, _buff, &pos);
      SDL_FreeSurface(text);
    }
  if (cursor < 10)
    login.pop_back();
  SDL_BlitSurface(_buff, NULL, _screen, NULL);
  SDL_Flip(_screen);
  cursor = cursor == 20 ? 0 : cursor + 1;
}

char					LibSDL::getChar() const
{
  SDL_Event				event;

  if (SDL_PollEvent(&event) && event.type == SDL_KEYDOWN)
    {
      if ((event.key.keysym.sym == SDLK_ESCAPE) || event.type == SDL_QUIT)
	return (-1);
      if (event.key.keysym.sym == SDLK_RETURN)
	return (0);
      if (event.key.keysym.unicode)
	return (event.key.keysym.unicode);
    }
  return (-2);
}

int					LibSDL::chooseGame(Menu * const menu) const
{
  std::string				intro = "The Arcade !";
  std::string				toPrint = "";
  unsigned int				i = 0;
  unsigned int				idx = 0;
  SDL_Rect				pos;
  SDL_Event				event;

  while (42)
    {
      pos.x = 32;
      pos.y = 0;
      SDL_FillRect(_buff, NULL, 0x000000);
      toPrint = !menu->getLibs()->getNbGame() ? "No games available" : "Games :";
      if (printText(intro.c_str(), &pos, 32, 0xffffff) == -1)
	return (-1);
      if (printText(toPrint.c_str(), &pos, 32, 0xffffff) == -1)
	return (-1);
      for (i = 0; i < menu->getLibs()->getNbGame(); i++)
	if (printText(menu->getLibs()->getGames()[i], &pos, 32, i == idx ? 0x50ff50 : 0xffffff) == -1)
	  return (-1);
      SDL_BlitSurface(_buff, NULL, _screen, NULL);
      SDL_Flip(_screen);
      if (SDL_PollEvent(&event) && event.type == SDL_KEYDOWN)
	{
	  if (event.key.keysym.sym == SDLK_DOWN)
	    idx = idx >= menu->getLibs()->getNbGame() - 1 ? 0 : idx + 1;
	  if (event.key.keysym.sym == SDLK_UP)
	    idx = idx == 0 ? menu->getLibs()->getNbGame() - 1 : idx - 1;
	  if (event.key.keysym.sym == SDLK_RETURN)
	    {
	      if (idx < menu->getLibs()->getNbGame())
		menu->setGameName(menu->getLibs()->getGames()[idx]);
	      else
		return (-1);
	      return (0);
	    }
	  if (event.key.keysym.sym == SDLK_ESCAPE)
	    return (-1);
	}
    }
}

int					LibSDL::chooseLib(Menu * const menu) const
{
  std::string				intro = "The Arcade !";
  std::string				toPrint = "";
  unsigned int				i = 0;
  unsigned int				idx = 0;
  SDL_Rect				pos;
  SDL_Event				event;

  while (42)
    {
      pos.x = 32;
      pos.y = 0;
      SDL_FillRect(_buff, NULL, 0x000000);
      toPrint = !menu->getLibs()->getNbGame() ? "No games available" : "Games :";
      if (printText(intro.c_str(), &pos, 32, 0xffffff) == -1)
	return (-1);
      if (printText(toPrint.c_str(), &pos, 32, 0xffffff) == -1)
	return (-1);
      for (i = 0; i < menu->getLibs()->getNbGame(); i++)
	if (printText(menu->getLibs()->getGames()[i], &pos, 32, menu->getLibs()->getGames()[i] == menu->getGameName() ? 0x50ff50 : 0xffffff) == -1)
	  return (-1);
      pos.y += 32;
      toPrint = !menu->getLibs()->getLibs().size() ? "No libs available" : "Libraries :";
      if (printText(toPrint.c_str(), &pos, 32, 0xffffff) == -1)
	return (-1);
      for (i = 0; i < menu->getLibs()->getLibs().size(); i++)
	if (printText(menu->getLibs()->getLibs()[i], &pos, 32, i == idx ? 0x50ff50 : 0xffffff) == -1)
	  return (-1);
      SDL_BlitSurface(_buff, NULL, _screen, NULL);
      SDL_Flip(_screen);
      if (SDL_PollEvent(&event) && event.type == SDL_KEYDOWN)
	{
	  if (event.key.keysym.sym == SDLK_DOWN)
	    idx = idx >= menu->getLibs()->getNbLib() - 1 ? 0 : idx + 1;
	  if (event.key.keysym.sym == SDLK_UP)
	    idx = idx == 0 ? menu->getLibs()->getNbLib() - 1 : idx - 1;
	  if (event.key.keysym.sym == SDLK_RETURN)
	    {
	      if (idx < menu->getLibs()->getNbLib())
		menu->setLibName(menu->getLibs()->getLibs()[idx]);
	      else
		return (-1);
	      return (0);
	    }
	  if (event.key.keysym.sym == SDLK_ESCAPE)
	    return (-1);
	}
    }
}
