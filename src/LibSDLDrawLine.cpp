//
// Lib.cpp for cpp_arcade in /home/wilmot_g/Rendu/cpp_arcade/leHaineux/src
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Mar  9 16:55:49 2016 guillaume wilmot
// Last update Sun Apr  3 21:59:10 2016 guillaume wilmot
//

#include "LibSDL.hpp"

void			LibSDL::putPixel(SDL_Surface *surface, int x, int y, Uint32 pixel) const
{
  int			bpp;
  Uint8			*p;

  bpp = surface->format->BytesPerPixel;
  p = reinterpret_cast<Uint8 *>(surface->pixels) + y * surface->pitch + x * bpp;
  if (bpp == 1)
    *p = pixel;
  else if (bpp == 2)
    *reinterpret_cast<Uint16 *>(p) = pixel;
  else if (bpp == 3)
    if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
      {
        p[0] = (pixel >> 16) & 0xff;
        p[1] = (pixel >> 8) & 0xff;
        p[2] = pixel & 0xff;
      }
    else
      {
        p[0] = pixel & 0xff;
        p[1] = (pixel >> 8) & 0xff;
        p[2] = (pixel >> 16) & 0xff;
      }
  else if (bpp == 4)
    *reinterpret_cast<Uint32 *>(p) = pixel;
}

void			LibSDL::drawCaseOne(t_line coords, SDL_Surface *screen, Uint32 color) const
{
  int			x;

  x = coords.x1;
  while (x <= coords.x2)
    {
      if (coords.x2 - coords.x1 != 0)
        putPixel(screen, x, coords.y1 + ((coords.y2 - coords.y1) *
                                         (x - coords.x1)) /
                 (coords.x2 - coords.x1), color);
      x++;
    }
}

void			LibSDL::drawCaseTwo(t_line coords, SDL_Surface *screen, Uint32 color) const
{
  int			y;

  y = coords.y1;
  while (y <= coords.y2)
    {
      if (coords.y2 - coords.y1 != 0)
        putPixel(screen, coords.x1 + ((coords.x2 - coords.x1) *
                                      (y - coords.y1)) /
                 (coords.y2 - coords.y1), y, color);
      y++;
    }
}

void			LibSDL::swap(t_line *coords) const
{
  int			tmp;

  tmp = coords->x1;
  coords->x1 = coords->x2;
  coords->x2 = tmp;
  tmp = coords->y1;
  coords->y1 = coords->y2;
  coords->y2 = tmp;
}

void			LibSDL::drawLine(t_line coords, SDL_Surface *screen, Uint32 color) const
{
  coords.x1 = coords.x1 < 0 ? 0 : coords.x1;
  coords.x2 = coords.x2 < 0 ? 0 : coords.x2;
  coords.y1 = coords.y1 < 0 ? 0 : coords.y1;
  coords.y2 = coords.y2 < 0 ? 0 : coords.y2;
  if (coords.x1 <= coords.x2 && (coords.x2 - coords.x1) >=
      abs(coords.y2 - coords.y1))
    drawCaseOne(coords, screen, color);
  else if (coords.x1 > coords.x2 && abs(coords.x2 - coords.x1) >=
           abs(coords.y2 - coords.y1))
    {
      swap(&coords);
      drawCaseOne(coords, screen, color);
    }
  else if ((coords.y2 - coords.y1) >= 0 && abs(coords.x2 - coords.x1) <=
           abs(coords.y2 - coords.y1))
    drawCaseTwo(coords, screen, color);
  else
    {
      swap(&coords);
      drawCaseTwo(coords, screen, color);
    }
}
