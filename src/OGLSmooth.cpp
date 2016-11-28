//
// OGLSmooth.cpp for OGLSmooth in /home/noboud_n/rendu/cpp_arcade/src
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.net>
//
// Started on  Fri Mar 18 19:15:12 2016 Nyrandone Noboud-Inpeng
// Last update Thu Mar 31 22:32:17 2016 Nyrandone Noboud-Inpeng
//

#include "LibOGL.hpp"

void			LibOGL::smoothPos(double *x, double *y, int k, Game const *game) const
{
  if (game->getPos()[k]->getDirection() == Direction::DOWN
      && game->getTab()[(game->getPos()[k]->getY() + 1) > game->getHeight() - 1 ? 0 : (game->getPos()[k]->getY() + 1)][game->getPos()[k]->getX()] != 1
      && isBlocked(game->getPos()[k]->getY() + 1, game->getPos()[k]->getX(), game) != 1)
    *y += (game->getPos()[k]->getFrame() % 4 * 0.025);
  else if (game->getPos()[k]->getDirection() == Direction::UP && game->getTab()[(game->getPos()[k]->getY() - 1) < 0 ? game->getHeight() - 1: (game->getPos()[k]->getY() - 1)][game->getPos()[k]->getX()] != 1
	   && isBlocked(game->getPos()[k]->getY() - 1, game->getPos()[k]->getX(), game) != 1)
    *y -= (game->getPos()[k]->getFrame() % 4 * 0.025);
  else if (game->getPos()[k]->getDirection() == Direction::LEFT && game->getTab()[game->getPos()[k]->getY()][(game->getPos()[k]->getX() - 1) < 0 ? game->getWidth() - 1 : (game->getPos()[k]->getX() - 1)] != 1
	   && isBlocked(game->getPos()[k]->getY(), game->getPos()[k]->getX() - 1, game) != 1)
    *x -= (game->getPos()[k]->getFrame() % 4 * 2.5);
  else if (game->getPos()[k]->getDirection() == Direction::RIGHT && game->getTab()[game->getPos()[k]->getY()][(game->getPos()[k]->getX() + 1) > game->getWidth() - 1 ? 0 : (game->getPos()[k]->getX() + 1)] != 1
	   && isBlocked(game->getPos()[k]->getY(), game->getPos()[k]->getX() + 1, game) != 1)
    *x += (game->getPos()[k]->getFrame() % 4 * 2.5);

  if (game->getPos()[k]->getFrame() + 1 <= 3)
    game->getPos()[k]->setFrame(game->getPos()[k]->getFrame() + 1);
  else
    game->getPos()[k]->setFrame(0);
}

void			LibOGL::smoothEntities(double *x, double *y, int k, Game const *game) const
{
  if (!game->getEntities()[k]->getStandBy())
    {
      if (game->getEntities()[k]->getDirection() == Direction::DOWN
	  && game->getTab()[(game->getEntities()[k]->getY() + 1) > game->getHeight() - 1 ? 0 : (game->getEntities()[k]->getY() + 1)][game->getEntities()[k]->getX()] != 1
	  && isBlocked(game->getEntities()[k]->getY() + 1, game->getEntities()[k]->getX(), game) != 1)
	*y += (game->getEntities()[k]->getFrame() % 4 * 0.025);
      else if (game->getEntities()[k]->getDirection() == Direction::UP
	       && game->getTab()[(game->getEntities()[k]->getY() - 1) < 0 ? game->getHeight() - 1: (game->getEntities()[k]->getY() - 1)][game->getEntities()[k]->getX()] != 1
	       && isBlocked(game->getEntities()[k]->getY() - 1, game->getEntities()[k]->getX(), game) != 1)
	*y -= (game->getEntities()[k]->getFrame() % 4 * 0.025);
      else if (game->getEntities()[k]->getDirection() == Direction::LEFT
	       && game->getTab()[game->getEntities()[k]->getY()][(game->getEntities()[k]->getX() - 1) < 0 ? game->getWidth() - 1 : (game->getEntities()[k]->getX() - 1)] != 1
	       && isBlocked(game->getEntities()[k]->getY(), game->getEntities()[k]->getX() - 1, game) != 1)
	*x -= (game->getEntities()[k]->getFrame() % 4 * 2.5);
      else if (game->getEntities()[k]->getDirection() == Direction::RIGHT
	       && game->getTab()[game->getEntities()[k]->getY()][(game->getEntities()[k]->getX() + 1) > game->getWidth() - 1 ? 0 : (game->getEntities()[k]->getX() + 1)] != 1
	       && isBlocked(game->getEntities()[k]->getY(), game->getEntities()[k]->getX() + 1, game) != 1)
	*x += (game->getEntities()[k]->getFrame() % 4 * 2.5);
      if (game->getEntities()[k]->getFrame() + 1 <= 3)
	game->getEntities()[k]->setFrame(game->getEntities()[k]->getFrame() + 1);
      else
	game->getEntities()[k]->setFrame(0);
    }
}

void			LibOGL::smoothCam(double *x, double *y, int k, Game const *game) const
{
  if (game->getPos()[k]->getDirection() == Direction::DOWN
      && game->getTab()[(game->getPos()[k]->getY() + 1) > game->getHeight() - 1 ? 0 : (game->getPos()[k]->getY() + 1)][game->getPos()[k]->getX()] != 1
      && isBlocked(game->getPos()[k]->getY() + 1, game->getPos()[k]->getX(), game) != 1)
    *y += (game->getPos()[k]->getFrame() % 4 * 0.004);
  else if (game->getPos()[k]->getDirection() == Direction::UP && game->getTab()[(game->getPos()[k]->getY() - 1) < 0 ? game->getHeight() - 1: (game->getPos()[k]->getY() - 1)][game->getPos()[k]->getX()] != 1
	   && isBlocked(game->getPos()[k]->getY() - 1, game->getPos()[k]->getX(), game) != 1)
    *y -= (game->getPos()[k]->getFrame() % 4 * 0.004);
  else if (game->getPos()[k]->getDirection() == Direction::LEFT && game->getTab()[game->getPos()[k]->getY()][(game->getPos()[k]->getX() - 1) < 0 ? game->getWidth() - 1 : (game->getPos()[k]->getX() - 1)] != 1
	   && isBlocked(game->getPos()[k]->getY(), game->getPos()[k]->getX() - 1, game) != 1)
    *x -= (game->getPos()[k]->getFrame() % 4 * 0.020);
  else if (game->getPos()[k]->getDirection() == Direction::RIGHT && game->getTab()[game->getPos()[k]->getY()][(game->getPos()[k]->getX() + 1) > game->getWidth() - 1 ? 0 : (game->getPos()[k]->getX() + 1)] != 1
	   && isBlocked(game->getPos()[k]->getY(), game->getPos()[k]->getX() + 1, game) != 1)
    *x += (game->getPos()[k]->getFrame() % 4 * 0.020);
}
