//
// OGLTextures.cpp for OGLTextures in /home/noboud_n/rendu/cpp_arcade/src
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.net>
//
// Started on  Thu Mar 17 13:52:37 2016 Nyrandone Noboud-Inpeng
// Last update Sun Apr  3 01:13:19 2016 Nyrandone Noboud-Inpeng
//

#include "gl.h"
#include "freeglut.h"
#include "SDL_image.h"
#include "LibOGL.hpp"

int		LibOGL::initTexturesSnake()
{
  SDL_Surface	*surface;

  if ((surface = IMG_Load("assets/OGLAssets/snake/wall.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[WALL]);
  glBindTexture(GL_TEXTURE_2D, _textures[WALL]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/snake/frontwall.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[FRONTWALL]);
  glBindTexture(GL_TEXTURE_2D, _textures[FRONTWALL]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/snake/ground.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[GROUND]);
  glBindTexture(GL_TEXTURE_2D, _textures[GROUND]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGBA,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/snake/apple.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[APPLE]);
  glBindTexture(GL_TEXTURE_2D, _textures[APPLE]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
  glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/snake/snake.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[SNAKEBODY]);
  glBindTexture(GL_TEXTURE_2D, _textures[SNAKEBODY]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGBA,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/snake/fronthead.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[FRONTHEAD]);
  glBindTexture(GL_TEXTURE_2D, _textures[FRONTHEAD]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGBA,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);
  return (0);
}

int		LibOGL::initTexturesPacman()
{
  SDL_Surface	*surface;

  if ((surface = IMG_Load("assets/OGLAssets/pacman/topwall.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[PWALL]);
  glBindTexture(GL_TEXTURE_2D, _textures[PWALL]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/pacman/ground.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[PGROUND]);
  glBindTexture(GL_TEXTURE_2D, _textures[PGROUND]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/pacman/pcoin.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[PCOIN]);
  glBindTexture(GL_TEXTURE_2D, _textures[PCOIN]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/pacman/01Monster.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[MONSTER01]);
  glBindTexture(GL_TEXTURE_2D, _textures[MONSTER01]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/pacman/02Monster.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[MONSTER02]);
  glBindTexture(GL_TEXTURE_2D, _textures[MONSTER02]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/pacman/03Monster.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[MONSTER03]);
  glBindTexture(GL_TEXTURE_2D, _textures[MONSTER03]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/pacman/04Monster.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[MONSTER04]);
  glBindTexture(GL_TEXTURE_2D, _textures[MONSTER04]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/pacman/ghast.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[GHAST]);
  glBindTexture(GL_TEXTURE_2D, _textures[GHAST]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/pacman/side01Monster.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[SIDEMONSTER01]);
  glBindTexture(GL_TEXTURE_2D, _textures[SIDEMONSTER01]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/pacman/side02Monster.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[SIDEMONSTER02]);
  glBindTexture(GL_TEXTURE_2D, _textures[SIDEMONSTER02]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/pacman/side03Monster.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[SIDEMONSTER03]);
  glBindTexture(GL_TEXTURE_2D, _textures[SIDEMONSTER03]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/pacman/side04Monster.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[SIDEMONSTER04]);
  glBindTexture(GL_TEXTURE_2D, _textures[SIDEMONSTER04]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/pacman/sideGhast.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[SIDEGHAST]);
  glBindTexture(GL_TEXTURE_2D, _textures[SIDEGHAST]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);
  return (0);
}

int		LibOGL::initTexturesCentipede()
{
  SDL_Surface	*surface;

 if ((surface = IMG_Load("assets/OGLAssets/centipede/centipede.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[CBODY]);
  glBindTexture(GL_TEXTURE_2D, _textures[CBODY]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGBA,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/centipede/cfronthead.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[CFRONTHEAD]);
  glBindTexture(GL_TEXTURE_2D, _textures[CFRONTHEAD]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGBA,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/centipede/fivehp.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[FIVEHP]);
  glBindTexture(GL_TEXTURE_2D, _textures[FIVEHP]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/centipede/fourhp.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[FOURHP]);
  glBindTexture(GL_TEXTURE_2D, _textures[FOURHP]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/centipede/threehp.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[THREEHP]);
  glBindTexture(GL_TEXTURE_2D, _textures[THREEHP]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/centipede/twohp.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[TWOHP]);
  glBindTexture(GL_TEXTURE_2D, _textures[TWOHP]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/centipede/onehp.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[ONEHP]);
  glBindTexture(GL_TEXTURE_2D, _textures[ONEHP]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/centipede/fireframe01.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[FRAMEONE]);
  glBindTexture(GL_TEXTURE_2D, _textures[FRAMEONE]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGBA,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/centipede/fireframe02.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[FRAMETWO]);
  glBindTexture(GL_TEXTURE_2D, _textures[FRAMETWO]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGBA,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/centipede/fireframe03.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[FRAMETHREE]);
  glBindTexture(GL_TEXTURE_2D, _textures[FRAMETHREE]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGBA,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);

  if ((surface = IMG_Load("assets/OGLAssets/centipede/cship.png")) == NULL)
    return (-1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(1, &_textures[CSHIP]);
  glBindTexture(GL_TEXTURE_2D, _textures[CSHIP]);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB,
  	       GL_UNSIGNED_BYTE, surface->pixels);
  SDL_FreeSurface(surface);
  return (0);
}
