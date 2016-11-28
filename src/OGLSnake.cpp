//
// snake.cpp for snake in /home/noboud_n/rendu/cpp_arcade/nyrii/src
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.net>
//
// Started on  Thu Mar 10 19:33:46 2016 Nyrandone Noboud-Inpeng
// Last update Sun Apr  3 22:33:01 2016 Nyrandone Noboud-Inpeng
//

#include <map>
#include "gl.h"
#include "freeglut.h"
#include "LibOGL.hpp"

void		LibOGL::emptySnake(double x, double y) const
{
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[GROUND]);
  glColor3ub(255, 255, 255);
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0, y);
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0), 0, y);
  glEnd();
  glDisable(GL_TEXTURE_2D);
}

void		LibOGL::blockSnake(double x, double y) const
{
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[WALL]);
  glBegin(GL_QUADS);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glVertex3d((x / 100.0) + 0.1, 0, y);
  glVertex3d((x / 100.0), 0, y);
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, y);
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0, y);
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0), 0.1, (y + 0.1));
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0.1, y);
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0, y);
  glEnd();
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[FRONTWALL]);
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0.1, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, y);
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0.1, y);
  glEnd();
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[WALL]);
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0.1, (y + 0.1));
  glEnd();
  glBegin(GL_QUADS);
  glVertex3d((x / 100.0), 0, y);
  glVertex3d((x / 100.0) + 0.1, 0, y);
  glVertex3d((x / 100.0) + 0.1, 0.1, y);
  glVertex3d((x / 100.0), 0.1, y);
  glEnd();
  glDisable(GL_TEXTURE_2D);
}

void		LibOGL::headSnake(double x, double y, Game const *game) const
{
  int		x1;
  int		x2;
  int		y1;
  int		y2;

  x1 = game->getPos()[0]->getX();
  y1 = game->getPos()[0]->getY();
  x2 = game->getPos()[1]->getX();
  y2 = game->getPos()[1]->getY();
  glColor3ub(255, 255, 255);
  glBegin(GL_QUADS);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glVertex3d((x / 100.0) + 0.1, 0, y);
  glVertex3d((x / 100.0), 0, y);
  glEnd();
  glEnable(GL_TEXTURE_2D);
  if (x2 < x1 || x2 > x1)
    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[FRONTHEAD]);
  else
    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[SNAKEBODY]);
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, y);
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0, y);
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0), 0.1, y);
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0), 0, y);
  glEnd();
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[SNAKEBODY]);
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0.1, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, y);
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0.1, y);
  glEnd();
  glColor3ub(255, 255, 255);
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0, y);
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0, y);
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, y);
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0.1, y);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  if (y2 < y1)
    {
      glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[FRONTHEAD]);
      glBegin(GL_QUADS);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0), 0, (y + 0.1));
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
      glTexCoord2d(0.0, 1.0);
      glVertex3d((x / 100.0), 0.1, (y + 0.1));
      glEnd();
      glDisable(GL_TEXTURE_2D);
    }
  else
    {
      glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[SNAKEBODY]);
      glBegin(GL_QUADS);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0), 0, (y + 0.1));
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
      glTexCoord2d(0.0, 1.0);
      glVertex3d((x / 100.0), 0.1, (y + 0.1));
      glEnd();
      glDisable(GL_TEXTURE_2D);
    }
}

void		LibOGL::bodySnake(double x, double y, UNUSED Game const *game) const
{
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[SNAKEBODY]);
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0, y);
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0, y);
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, y);
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0, y);
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0), 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0), 0.1, y);
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0, y);
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0.1, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, y);
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0.1, y);
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0.1, (y + 0.1));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0, y);
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0, y);
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, y);
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0.1, y);
  glEnd();
  glDisable(GL_TEXTURE_2D);
}

void		LibOGL::tailSnake(double x, double y, Game const *game) const
{
  int		x1;
  int		x2;
  int		y1;
  int		y2;

  x1 = game->getPos()[game->getPos().size() - 1]->getX();
  y1 = game->getPos()[game->getPos().size() - 1]->getY();
  x2 = game->getPos()[game->getPos().size() - 2]->getX();
  y2 = game->getPos()[game->getPos().size() - 2]->getY();

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[GROUND]);
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0, y);
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0), 0, y);
  glEnd();
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[SNAKEBODY]);
  if (x1 < x2)
    {
      glBegin(GL_TRIANGLES);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0), 0.05, (y + 0.05));
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0.1, y);
      glEnd();
      glBegin(GL_TRIANGLES);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0), 0.05, (y + 0.05));
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0) + 0.1, 0.0, y);
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0.0, y + 0.1);
      glEnd();
      glBegin(GL_TRIANGLES);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0), 0.05, (y + 0.05));
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0, y + 0.1);
      glEnd();
      glBegin(GL_TRIANGLES);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0), 0.05, y + 0.05);
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0) + 0.1, 0.1, y);
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0.0, y);
      glEnd();
    }
  else if (x1 > x2)
    {
      glBegin(GL_TRIANGLES);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0), 0.1, y);
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0), 0.1, (y + 0.1));
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0.05, (y + 0.05));
      glEnd();
      glBegin(GL_TRIANGLES);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0), 0.0, y);
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0), 0.0, y + 0.1);
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0.05, y + 0.05);
      glEnd();
      glBegin(GL_TRIANGLES);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0), 0.1, y + 0.1);
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0), 0.0, y + 0.1);
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0.05, y + 0.05);
      glEnd();
      glBegin(GL_TRIANGLES);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0), 0.1, y + 0.1);
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0), 0.0, y);
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0.05, y + 0.05);
      glEnd();
    }
  else if (y1 < y2)
    {
      glBegin(GL_TRIANGLES);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0) + 0.05, 0.05, y);
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0), 0.1, (y + 0.1));
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
      glEnd();
      glBegin(GL_TRIANGLES);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0) + 0.05, 0.05, y);
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0), 0, (y + 0.1));
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
      glEnd();
      glBegin(GL_TRIANGLES);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0) + 0.05, 0.05, y);
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
      glEnd();
      glBegin(GL_TRIANGLES);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0) + 0.05, 0.05, y);
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0), 0.1, (y + 0.1));
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0), 0, (y + 0.1));
      glEnd();
    }
  else
    {
      glBegin(GL_TRIANGLES);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0) + 0.05, 0.0, (y + 0.1));
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0), 0.1, y);
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0.1, y);
      glEnd();
      glBegin(GL_TRIANGLES);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0) + 0.05, 0.0, (y + 0.1));
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0), 0.05, y);
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0.05, y);
      glEnd();
      glBegin(GL_TRIANGLES);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0) + 0.05, 0.0, (y + 0.1));
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0) + 0.1, 0.1, y);
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0.0, y);
      glEnd();
      glBegin(GL_TRIANGLES);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0) + 0.05, 0.0, (y + 0.1));
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0), 0.1, y);
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0), 0.0, y);
      glEnd();
    }
  glDisable(GL_TEXTURE_2D);
}

void		LibOGL::foodSnake(double x, double y) const
{
  GLUquadric	*quad;

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[GROUND]);
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0, y);
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0), 0, y);
  glEnd();
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[APPLE]);
  quad = gluNewQuadric();
  glMatrixMode(GL_TEXTURE);
  glPushMatrix();
  glLoadIdentity();
  glTranslatef(0.5, 0.5, 0.0);
  glRotatef(30.0, 0.0, 0.0, 1.0);
  glTranslatef(-0.5, -0.5, 0.0);
  glMatrixMode(GL_MODELVIEW);
  gluQuadricNormals(quad, GLU_SMOOTH);
  gluQuadricTexture(quad, GL_TRUE);
  glTranslated(x / 100.0 + 0.05, 0.05, y + 0.05);
  gluSphere(quad, 0.05, 10, 5);
  glEnd();
  glTranslated(-x / 100.0 - 0.05, -0.05, -y - 0.05);
  gluDeleteQuadric(quad);
  glDisable(GL_TEXTURE_2D);
  glMatrixMode(GL_TEXTURE);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
}

void			LibOGL::globalSceneSnake(Game const *game) const
{
  int			i;
  std::map<Type, void (LibOGL::*)(double, double) const>				ptrfunc;
  std::map<Powerup::e_type, void (LibOGL::*)(double, double) const>			ptrfuncPow;
  std::map<Entity::e_type, void (LibOGL::*)(double, double, Game const *) const>	ptrfuncEnt;
  double		x;
  double		y;
  int			realy;
  int			realx;
  unsigned int		k;

  i = 1;
  ptrfunc[EMPTY] = &LibOGL::emptySnake;
  ptrfunc[BLOCK] = &LibOGL::blockSnake;
  ptrfuncPow[Powerup::e_type::FOOD] = &LibOGL::foodSnake;
  ptrfuncEnt[Entity::e_type::HEAD] = &LibOGL::headSnake;
  ptrfuncEnt[Entity::e_type::BODY] = &LibOGL::bodySnake;
  ptrfuncEnt[Entity::e_type::TAIL] = &LibOGL::tailSnake;
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(3.0, 3.0, 0.5, 3.0, -1.0, 0.0, 0.0, 1.0, 0.0);
  realy = 0;
  realx = 0;
  x = 0.0;
  y = -2.0;
  while (i < game->getWidth() * game->getHeight())
    {
      if (ptrfunc[static_cast<Type>(static_cast<int>(game->getTab()[realy][realx]))])
	(this->*ptrfunc[static_cast<Type>(static_cast<int>(game->getTab()[realy][realx]))])(x, y);
      x += 10.0;
      ++i;
      realx++;
      if (i % game->getWidth() == 0)
	{
	  if (realy == 0 && ptrfunc[static_cast<Type>(static_cast<int>(game->getTab()[realy][realx]))])
	    (this->*ptrfunc[BLOCK])(x, y);
	  x = 0;
	  realx = 0;
	  realy += 1;
	  y += 0.1;
	}
    }
  for (k = 0; k < game->getPos().size(); k++)
    {
      y = -2.0;
      if (ptrfuncEnt[game->getPos()[k]->getType()])
	{
	  x = 10.0 * game->getPos()[k]->getX();
	  y += 0.1 * game->getPos()[k]->getY();

	  (this->*ptrfuncEnt[game->getPos()[k]->getType()])(x, y, game);
	}
    }
  for (k = 0; k < game->getPowerups().size(); k++)
    {
      y = -2.0;
      if (ptrfuncPow[game->getPowerups()[k]->getType()])
	{
	  x = 10.0 * game->getPowerups()[k]->getX();
	  y += 0.1 * game->getPowerups()[k]->getY();
	  (this->*ptrfuncPow[game->getPowerups()[k]->getType()])(x, y);
	}
    }
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0, 1920, 1080, 0, 0, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glColor3ub(255, 255, 255);
  glRasterPos2d(150, 850);
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
  		   reinterpret_cast<const unsigned char *>("SCORE: "));
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
  		   reinterpret_cast<const unsigned char *>(std::to_string(game->getScore()).c_str()));
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  SDL_GL_SwapBuffers();
}
