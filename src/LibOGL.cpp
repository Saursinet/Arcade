//
// libmethods.cpp for LibOGL in /home/noboud_n/rendu/cpp_arcade/nyrii/src
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.net>
//
// Started on  Thu Mar 10 07:45:18 2016 Nyrandone Noboud-Inpeng
// Last update Sun Apr  3 21:51:46 2016 guillaume wilmot
//

#include <iostream>
#include <unistd.h>
#include "gl.h"
#include "freeglut.h"
#include "SDL_image.h"
#include "LibOGL.hpp"
#include "GameSnake.hpp"

LibOGL::LibOGL()
{
  int	argc;

  argc = 1;
  _window = NULL;
  glutInit(&argc, NULL);
  _pacmanMusic = NULL;
  _snakeMusic = NULL;
  _init = false;
}

LibOGL::~LibOGL()
{

}

LibOGL		&LibOGL::operator=(LibOGL const &to_copy)
{
  if (this != &to_copy)
    {
      _window = to_copy.getSurface();
      _sounds = to_copy.getSounds();
      _textures = to_copy.getTextures();
      _pacmanMusic = to_copy.getPMusic();
      _snakeMusic = to_copy.getSMusic();
    }
  return (*this);
}

LibOGL::LibOGL(LibOGL const &to_copy)
{
  _window = to_copy.getSurface();
  _sounds = to_copy.getSounds();
  _textures = to_copy.getTextures();
  _pacmanMusic = to_copy.getPMusic();
  _snakeMusic = to_copy.getSMusic();
}

SDL_Surface		*LibOGL::getSurface() const
{
  return (_window);
}

std::map<e_sound, Mix_Chunk *>	LibOGL::getSounds() const
{
  return (_sounds);
}

Mix_Music		*LibOGL::getPMusic() const
{
  return (_pacmanMusic);
}

Mix_Music		*LibOGL::getSMusic() const
{
  return (_snakeMusic);
}

std::map<e_textures, GLuint>	LibOGL::getTextures() const
{
  return (_textures);
}

ILib		*makeLib()
{
  return (new LibOGL);
}

void		initGL()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70, static_cast<float>(1920.0 / 1080.0), 0.1, 100.0);
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_DEPTH_TEST);
  glClearDepth(1.0f);
  glShadeModel(GL_SMOOTH);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}


int		LibOGL::init()
{
  if (_init)
    return (0);
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
      std::cerr << ERROR_SDL << SDL_GetError() << std::endl;
      return (-1);
    }
  SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, 180);
  _window = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_OPENGL | SDL_NOFRAME);
  if (_window == NULL)
    {
      std::cerr << ERROR_WINDOW << std::endl;
      return (-1);
    }

  initGL();

  if (initTexturesSnake() == -1 || initTexturesPacman() == -1 || initTexturesCentipede() == -1)
    {
      std::cerr << ERROR_TEXTURES << std::endl;
      return (-1);
    }

  SDL_WM_SetCaption("OGL", NULL);

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,
  		    MIX_DEFAULT_CHANNELS, 1024) == -1)
    std::cerr << ERROR_AUDIO << Mix_GetError() << std::endl;
  if ((_sounds[DIE] = Mix_LoadWAV(SOUND_DIE)) == NULL
      || (_sounds[SNAKEEATS] = Mix_LoadWAV(SOUND_SEATS)) == NULL
      || (_sounds[PACMANEATS] = Mix_LoadWAV(SOUND_PEATS)) == NULL
      || (_sounds[WAKAWAKA] = Mix_LoadWAV(SOUND_WAKA)) == NULL)
    {
      std::cerr << ERROR_MUSIC << Mix_GetError() << std::endl;
      return (-1);
    }
  if ((_snakeMusic = Mix_LoadMUS(MUSIC_SNAKE)) == NULL
      || (_pacmanMusic = Mix_LoadMUS(MUSIC_PACMAN)) == NULL)
    {
      std::cerr << ERROR_MUSIC << Mix_GetError() << std::endl;
      return (-1);
    }
  _init = true;
  return (0);
}

int		LibOGL::print(Game *const game) const
{
  std::map<GameName, void (LibOGL::*)(Game const *) const>	fptr;

  fptr[SNAKE] = &LibOGL::globalSceneSnake;
  fptr[PACMAN] = &LibOGL::globalScenePacman;
  fptr[CENTIPEDE] = &LibOGL::globalSceneCentipede;

  if (musicOn(-1) == 0)
    {
      if (game->getGameName() == GameName::SNAKE)
	{
	  if (Mix_PlayMusic(_snakeMusic, -1) == -1)
	    {
	      std::cerr << ERROR_PLAYWAV << Mix_GetError() << std::endl;
	      return (-1);
	    }
	}
      else if (game->getGameName() == GameName::PACMAN)
	{
	  if (Mix_PlayMusic(_snakeMusic, -1) == -1)
	    {
	      std::cerr << ERROR_PLAYWAV << Mix_GetError() << std::endl;
	      return (-1);
	    }
	}
      musicOn(1);
    }
  if (fptr[game->getGameName()])
    {
      (this->*fptr[game->getGameName()])(game);
      return (0);
    }
  return (-1);
}

unsigned int	LibOGL::getEvent(unsigned int direction) const
{
  SDL_Event	ev;
  int		e;
  static int	received = 0;

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

int		LibOGL::playSound(e_sound sound)
{
  if (_sounds[sound] != NULL && sound != MUSICPACMAN && sound != MUSICSNAKE)
    Mix_PlayChannel(-1, _sounds[sound], 0);
  if (sound == DIE)
    sleep(2);
  return (0);
}

int		LibOGL::end()
{
  int		i;

  i = 0;
  Mix_FreeChunk(_sounds[DIE]);
  Mix_FreeChunk(_sounds[WAKAWAKA]);
  Mix_FreeChunk(_sounds[PACMANEATS]);
  Mix_FreeMusic(_snakeMusic);
  Mix_FreeMusic(_pacmanMusic);
  Mix_CloseAudio();
  for (std::map<e_textures, GLuint>::iterator it = _textures.begin(); it != _textures.end(); it++)
    {
      glDeleteTextures(1, &it->second);
      ++i;
    }
  musicOn(0);
  SDL_Quit();
  return (0);
}

char		LibOGL::getChar() const
{
  SDL_Event	event;

  SDL_EnableUNICODE(SDL_ENABLE);
  if (SDL_PollEvent(&event) && event.type == SDL_KEYDOWN)
    {
      if ((event.key.keysym.sym == SDLK_ESCAPE) || event.type == SDL_QUIT)
        return (-1);
      if (event.key.keysym.sym == SDLK_RETURN)
        return (0);
      if (event.key.keysym.unicode)
	return (event.key.keysym.unicode);
    }
  SDL_EnableUNICODE(SDL_DISABLE);
  return (-2);

}

void		LibOGL::display_intro(int *x, int *y, Menu * const menu) const
{
  std::string	intro = "Hello and welcome ! We hope you'll enjoy playing one of the available games of the following libraries !";
  std::string	toPrint = "";
  unsigned int	i;

  glRasterPos2d(*x, *y);
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
		   reinterpret_cast<const unsigned char *>(intro.c_str()));
  *y += 50;
  toPrint = !menu->getLibs()->getGames().size() ? "No games available" : "Games :";
  glRasterPos2d(*x, *y);
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
		   reinterpret_cast<const unsigned char *>(toPrint.c_str()));
  *y += 32;
  for (i = 0; i < menu->getLibs()->getGames().size(); i++)
    {
      if (menu->getLibs()->getGames()[i] == menu->getGameName())
	glColor3ub(0, 255, 0);
      else
	glColor3ub(255, 255, 255);
      glRasterPos2d(*x, *y);
      glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
		       reinterpret_cast<const unsigned char *>(menu->getLibs()->getGames()[i].c_str()));
      *y += 32;
    }
  *y += 18;
  glColor3ub(255, 255, 255);
  toPrint = !menu->getLibs()->getGames().size() ? "No libraries available" : "Libraries :";
  glRasterPos2d(*x, *y);
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
		   reinterpret_cast<const unsigned char *>(toPrint.c_str()));
  *y += 32;
  for (i = 0; i < menu->getLibs()->getLibs().size(); i++)
    {
      if (menu->getLibs()->getLibs()[i] == menu->getLibName())
	glColor3ub(0, 255, 0);
      else
	glColor3ub(255, 255, 255);
      glRasterPos2d(*x, *y);
      glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
		       reinterpret_cast<const unsigned char *>(menu->getLibs()->getLibs()[i].c_str()));
      *y += 32;
    }
  *y += 18;
  glColor3ub(255, 255, 255);
  if (menu->getScore())
    {
      toPrint = "Score:";
      glRasterPos2d(*x, *y);
      glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
		       reinterpret_cast<const unsigned char *>(toPrint.c_str()));
      *y += 32;
      i = 0;
      while (menu->getScore()[i] != "" && i < 10)
	{
	  toPrint = menu->getScore()[i];
	  glRasterPos2d(*x, *y);
	  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
			   reinterpret_cast<const unsigned char *>(toPrint.c_str()));
	  ++i;
	  *y += 32;
	}
    }
  *y += 18;
  toPrint = "Please enter your login (1-10 characters) :";
  glRasterPos2d(*x, *y);
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
		   reinterpret_cast<const unsigned char *>(toPrint.c_str()));
  *y += 50;
}

void		LibOGL::printMenu(Menu * const menu) const
{
  static int	cursor = 0;
  std::string	login;
  int		x;
  int		y;

  x = 32;
  y = 30;
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0, 1920, 1080, 0, 0, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.f, 0.f, 0.f, 1.f);
  glColor3ub(255, 255, 255);
  login = menu->getLogin();
  display_intro(&x, &y, menu);
  if (cursor < 10)
    login += "|";
  if (login != "")
    {
      glRasterPos2d(x, y);
      glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
		       reinterpret_cast<const unsigned char *>(login.c_str()));
    }
  if (cursor < 10)
    login.pop_back();
  cursor = cursor == 20 ? 0 : cursor + 1;
  SDL_GL_SwapBuffers();
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

int		LibOGL::chooseGame(Menu * const menu) const
{
  std::string	intro = "The Arcade !";
  std::string	toPrint = "";
  unsigned int	i = 0;
  unsigned int	idx = 0;
  int		x;
  int		y;
  SDL_Event	event;

  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0, 1920, 1080, 0, 0, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  while (42)
    {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glClearColor(0.f, 0.f, 0.f, 1.f);
      glColor3ub(255, 255, 255);
      x = 32;
      y = 30;
      glRasterPos2d(x, y);
      glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
		       reinterpret_cast<const unsigned char *>(intro.c_str()));
      y += 50;
      toPrint = !menu->getLibs()->getNbGame() ? "No games available" : "Games :";
      glRasterPos2d(x, y);
      glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
		       reinterpret_cast<const unsigned char *>(toPrint.c_str()));
      y += 32;
      for (i = 0; i < menu->getLibs()->getNbGame(); i++)
	{
	  if (i == idx)
	    glColor3ub(0, 255, 0);
	  else
	    glColor3ub(255, 255, 255);
	  glRasterPos2d(x, y);
	  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
			   reinterpret_cast<const unsigned char *>(menu->getLibs()->getGames()[i].c_str()));
	  y += 32;
	}
      if (SDL_PollEvent(&event) && event.type == SDL_KEYDOWN)
	{
	  if (event.key.keysym.sym == SDLK_DOWN)
	    idx = idx >= menu->getLibs()->getNbGame() - 1 ? 0 : idx + 1;
	  if (event.key.keysym.sym == SDLK_UP)
	    idx = idx == 0 ? menu->getLibs()->getNbGame() - 1 : idx - 1;
	  if (event.key.keysym.sym == SDLK_RETURN)
	    {
  	      SDL_EnableUNICODE(SDL_DISABLE);
  	      glMatrixMode(GL_PROJECTION);
  	      glPopMatrix();
  	      glMatrixMode(GL_MODELVIEW);
  	      glLoadIdentity();
	      if (idx < menu->getLibs()->getNbGame())
		menu->setGameName(menu->getLibs()->getGames()[idx]);
	      else
		return (-1);
	      return (0);
	    }
	  if (event.key.keysym.sym == SDLK_ESCAPE)
	    return (-1);
	}
      SDL_GL_SwapBuffers();
    }
  return (0);
}

int		LibOGL::chooseLib(Menu * const menu) const
{
  std::string	intro = "The Arcade !";
  std::string	toPrint = "";
  unsigned int	i = 0;
  unsigned int	idx = 0;
  SDL_Event	event;
  int		x;
  int		y;

  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0, 1920, 1080, 0, 0, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  while (42)
    {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glClearColor(0.f, 0.f, 0.f, 1.f);
      glColor3ub(255, 255, 255);
      x = 32;
      y = 30;
      glRasterPos2d(x, y);
      glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
		       reinterpret_cast<const unsigned char *>(intro.c_str()));
      y += 50;
      toPrint = !menu->getLibs()->getNbGame() ? "No games available" : "Games :";
      glRasterPos2d(x, y);
      glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
		       reinterpret_cast<const unsigned char *>(toPrint.c_str()));
      y += 32;
      for (i = 0; i < menu->getLibs()->getNbGame(); i++)
	{
	  if (menu->getLibs()->getGames()[i] == menu->getGameName())
	    glColor3ub(0, 255, 0);
	  else
	    glColor3ub(255, 255, 255);
	  glRasterPos2d(x, y);
	  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
			   reinterpret_cast<const unsigned char *>(menu->getLibs()->getGames()[i].c_str()));
	  y += 32;
	}
      y += 18;
      glColor3ub(255, 255, 255);
      toPrint = !menu->getLibs()->getLibs().size() ? "No libs available" : "Libraries :";
      glRasterPos2d(x, y);
      glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
		       reinterpret_cast<const unsigned char *>(toPrint.c_str()));
      y += 32;
      for (i = 0; i < menu->getLibs()->getLibs().size(); i++)
	{
	  if (i == idx)
	    glColor3ub(0, 255, 0);
	  else
	    glColor3ub(255, 255, 255);
	  glRasterPos2d(x, y);
	  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
			   reinterpret_cast<const unsigned char *>(menu->getLibs()->getLibs()[i].c_str()));
	  y += 32;
	}
      glColor3ub(255, 255, 255);
      if (SDL_PollEvent(&event) && event.type == SDL_KEYDOWN)
	{
	  if (event.key.keysym.sym == SDLK_DOWN)
	    idx = idx >= menu->getLibs()->getNbLib() - 1 ? 0 : idx + 1;
	  if (event.key.keysym.sym == SDLK_UP)
	    idx = idx == 0 ? menu->getLibs()->getNbLib() - 1 : idx - 1;
	  if (event.key.keysym.sym == SDLK_RETURN)
	    {
  	      SDL_EnableUNICODE(SDL_DISABLE);
  	      glMatrixMode(GL_PROJECTION);
  	      glPopMatrix();
  	      glMatrixMode(GL_MODELVIEW);
  	      glLoadIdentity();
	      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	      glClearColor(0.f, 0.f, 0.f, 1.f);
	      if (idx < menu->getLibs()->getNbLib())
                menu->setLibName(menu->getLibs()->getLibs()[idx]);
	      else
		return (-1);
	      return (0);
	    }
	  if (event.key.keysym.sym == SDLK_ESCAPE)
	    return (-1);
	}
      SDL_GL_SwapBuffers();
    }
  return (0);
}
