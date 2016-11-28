//
// OGLCentipede.cpp for Centipede in /home/noboud_n/rendu/cpp_arcade/src
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.net>
//
// Started on  Wed Mar 30 14:41:56 2016 Nyrandone Noboud-Inpeng
// Last update Sun Apr  3 22:39:06 2016 Nyrandone Noboud-Inpeng
//

#include <map>
#include <vector>
#include "gl.h"
#include "freeglut.h"
#include "LibOGL.hpp"

void		LibOGL::emptyCentipede(double x, double y) const
{
  glColor3ub(0, 0, 0);
  glBegin(GL_QUADS);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glVertex3d((x / 100.0) + 0.1, 0, y);
  glVertex3d((x / 100.0), 0, y);
  glEnd();
}

void		LibOGL::blockCentipede(double x, double y) const
{
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[PWALL]);
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

void		LibOGL::obstacleCentipede(UNUSED int diff, double x, double y) const
{
  glEnable(GL_TEXTURE_2D);
  if (diff == 0)
    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[FIVEHP]);
  else if (diff == 1)
    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[FOURHP]);
  else if (diff == 2)
    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[THREEHP]);
  else if (diff == 3)
    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[TWOHP]);
  else if (diff == 4)
    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[ONEHP]);
  glBegin(GL_QUADS);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.015 * diff));
  glVertex3d((x / 100.0), 0, (y + 0.015 * diff));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.015 * diff));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.015 * diff));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0), 0.1, (y + 0.1));
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0.1, (y + 0.015 * diff));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0, (y + 0.015 * diff));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0.1, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.015 * diff));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0.1, (y + 0.015 * diff));
  glEnd();
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
  glVertex3d((x / 100.0), 0, (y + 0.01 * diff));
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.01 * diff));
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.015 * diff));
  glVertex3d((x / 100.0), 0.1, (y + 0.015 * diff));
  glEnd();
  glDisable(GL_TEXTURE_2D);
}

void		LibOGL::spaceShip(double x, double y, int frame) const
{
  emptyCentipede(x, y);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[CSHIP]);
  glColor3ub(255, 255, 255);
  glBegin(GL_TRIANGLES);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.05, 0.05, y);
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.02, 0.1, (y + 0.03));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.08, 0.1, (y + 0.03));
  glEnd();
  glBegin(GL_TRIANGLES);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.05, 0.05, y);
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.02, 0, (y + 0.03));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.08, 0, (y + 0.03));
  glEnd();
  glBegin(GL_TRIANGLES);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.05, 0.05, y);
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.08, 0.1, (y + 0.03));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.08, 0, (y + 0.03));
  glEnd();
  glBegin(GL_TRIANGLES);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.05, 0.05, y);
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.02, 0.1, (y + 0.03));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.02, 0, (y + 0.03));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.02, 0.0, y + 0.03);
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.08, 0.0, y + 0.03);
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.08, 0.1, y + 0.03);
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.02, 0.1, y + 0.03);
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.02, 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.08, 0, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.08, 0, (y + 0.03));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.02, 0, (y + 0.03));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.08, 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.08, 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.08, 0.1, (y + 0.03));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.08, 0, (y + 0.03));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.02, 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.02, 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.02, 0.1, (y + 0.03));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.02, 0, (y + 0.03));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.02, 0.1, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.08, 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.08, 0.1, (y + 0.03));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.02, 0.1, (y + 0.03));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.02, 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.08, 0, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.08, 0.1, (y + 0.1));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.02, 0.1, (y + 0.1));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.02, 0, (y + 0.03));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.08, 0, (y + 0.03));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.08, 0.1, (y + 0.03));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.02, 0.1, (y + 0.03));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.02, 0, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.02, 0, (y + 0.05));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0, (y + 0.05));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.02, 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.02, 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.02, 0.1, (y + 0.05));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.02, 0, (y + 0.05));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0), 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0), 0.1, (y + 0.05));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0, (y + 0.05));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0.1, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.02, 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.02, 0.1, (y + 0.05));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0.1, (y + 0.05));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.02, 0, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.02, 0.1, (y + 0.1));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0.1, (y + 0.1));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0), 0, (y + 0.05));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.02, 0, (y + 0.05));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.02, 0.1, (y + 0.05));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0.1, (y + 0.05));
  glEnd();
  glColor3ub(255, 255, 255);
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.08, 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.05));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.08, 0, (y + 0.05));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.05));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.05));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.08, 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.08, 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.08, 0.1, (y + 0.05));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.08, 0, (y + 0.05));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.08, 0.1, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.05));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.08, 0.1, (y + 0.05));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.08, 0, (y + 0.1));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.08, 0.1, (y + 0.1));
  glEnd();
  glBegin(GL_QUADS);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.08, 0, (y + 0.05));
  glTexCoord2d(1.0, 0.0);
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.05));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.05));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.08, 0.1, (y + 0.05));
  glEnd();
  if (frame == 0)
    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[FRAMEONE]);
  else if (frame == 1)
    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[FRAMETWO]);
  else if (frame == 2)
    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[FRAMETHREE]);
  else
    glDisable(GL_TEXTURE_2D);
  glColor3ub(0, 0, 0);
  glBegin(GL_TRIANGLES);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.02, 0.0, (y + 0.15));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.04, 0.1, (y + 0.1));
  glEnd();
  glBegin(GL_TRIANGLES);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.02, 0.0, (y + 0.15));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0.01, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.04, 0.05, (y + 0.1));
  glEnd();
  glBegin(GL_TRIANGLES);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.02, 0.0, (y + 0.15));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.04, 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.04, 0.0, (y + 0.1));
  glEnd();
  glBegin(GL_TRIANGLES);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.02, 0.0, (y + 0.15));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0), 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0), 0.0, (y + 0.1));
  glEnd();
  glColor3ub(0, 0, 0);
  glBegin(GL_TRIANGLES);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.085, 0.0, (y + 0.15));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.065, 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
  glEnd();
  glBegin(GL_TRIANGLES);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.085, 0.0, (y + 0.15));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.065, 0.01, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0.05, (y + 0.1));
  glEnd();
  glBegin(GL_TRIANGLES);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.085, 0.0, (y + 0.15));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.1, 0.0, (y + 0.1));
  glEnd();
  glBegin(GL_TRIANGLES);
  glTexCoord2d(0.0, 0.0);
  glVertex3d((x / 100.0) + 0.085, 0.0, (y + 0.15));
  glTexCoord2d(0.0, 1.0);
  glVertex3d((x / 100.0) + 0.065, 0.1, (y + 0.1));
  glTexCoord2d(1.0, 1.0);
  glVertex3d((x / 100.0) + 0.065, 0.0, (y + 0.1));
  glEnd();
  glDisable(GL_TEXTURE_2D);
}

void		LibOGL::shotCentipede(double x, double y) const
{
  GLUquadric	*quad;

  emptyCentipede(x, y);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[PCOIN]);
  quad = gluNewQuadric();
  gluQuadricTexture(quad, GL_TRUE);
  glTranslated(x / 100.0 + 0.05, 0.05, y + 0.05);
  gluSphere(quad, 0.04, 10, 5);
  glEnd();
  glTranslated(-x / 100.0 - 0.05, -0.05, -y - 0.05);
  gluDeleteQuadric(quad);
  glDisable(GL_TEXTURE_2D);
}

void		LibOGL::headCentipede(double x, double y, std::vector<Entity *> tmp) const
{
  int		x1;
  int		x2;
  int		y1;
  int		y2;

  x1 = tmp[0]->getX();
  y1 = tmp[0]->getY();
  if (tmp.size() > 1)
    {
      x2 = tmp[1]->getX();
      y2 = tmp[1]->getY();
    }
  else
    {
      x2 = x1;
      y2 = y1 - 1;
    }
  glColor3ub(255, 255, 255);
  glBegin(GL_QUADS);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glVertex3d((x / 100.0) + 0.1, 0, y);
  glVertex3d((x / 100.0), 0, y);
  glEnd();
  glEnable(GL_TEXTURE_2D);
  if (x2 < x1 || x2 > x1)
    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[CFRONTHEAD]);
  else
    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[CBODY]);
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
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[CBODY]);
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
      glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[CFRONTHEAD]);
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
      glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[CBODY]);
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

void		LibOGL::bodyCentipede(double x, double y, UNUSED std::vector<Entity *> tmp) const
{
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[CBODY]);
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

void		LibOGL::tailCentipede(double x, double y, std::vector<Entity *> tmp) const
{
  int		x1;
  int		x2;
  int		y1;
  int		y2;

  x1 = tmp[tmp.size() - 1]->getX();
  y1 = tmp[tmp.size() - 1]->getY();
  x2 = tmp[tmp.size() - 2]->getX();
  y2 = tmp[tmp.size() - 2]->getY();
  emptyCentipede(x, y);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[CBODY]);
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

void			LibOGL::globalSceneCentipede(Game const *game) const
{
  int			i;
  std::map<Type, void (LibOGL::*)(double, double) const>					ptrfunc;
  std::map<Shot::e_type, void (LibOGL::*)(double, double) const>				ptrfuncShots;
  std::map<Entity::e_type, void (LibOGL::*)(double, double, std::vector<Entity *>) const>	ptrfuncEnt;
  double		x;
  double		y;
  int			realy;
  int			realx;
  unsigned int		k;
  std::vector<Entity *>	tmp;

  i = 1;
  ptrfunc[EMPTY] = &LibOGL::emptyCentipede;
  ptrfunc[BLOCK] = &LibOGL::blockCentipede;
  ptrfuncShots[Shot::e_type::SHOT] = &LibOGL::shotCentipede;
  ptrfuncEnt[Entity::e_type::HEAD] = &LibOGL::headCentipede;
  ptrfuncEnt[Entity::e_type::BODY] = &LibOGL::bodyCentipede;
  ptrfuncEnt[Entity::e_type::TAIL] = &LibOGL::tailCentipede;
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(3.0, 3.0, 1.0, 3.0, -1.0, 0.0, 0.0, 1.0, 0.0);
  realy = 0;
  realx = 0;
  x = 0.0;
  y = -2.0;
  while (i < game->getWidth() * game->getHeight())
    {
      if (ptrfunc[static_cast<Type>(static_cast<int>(game->getTab()[realy][realx]))])
  	(this->*ptrfunc[static_cast<Type>(static_cast<int>(game->getTab()[realy][realx]))])(x, y);
      else if (game->getTab()[realy][realx] > 10 && game->getTab()[realy][realx] <= 15)
	obstacleCentipede(15 - game->getTab()[realy][realx], x, y);
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
  x = 10.0 * game->getPos()[0]->getX();
  y = -2.0 + 0.1 * game->getPos()[0]->getY();
  static int test = 0;
  spaceShip(x, y, test);
  test++;
  if (test >= 4)
    test = 0;
  for (k = 0; k < game->getShots().size(); k++)
    {
      y = -2.0;
      if (ptrfuncShots[game->getShots()[k]->getType()])
  	{
  	  x = 10.0 * game->getShots()[k]->getX();
  	  y += 0.1 * game->getShots()[k]->getY();
  	  (this->*ptrfuncShots[game->getShots()[k]->getType()])(x, y);
  	}
    }
  for (k = 0; k < game->getCenti().size(); k++)
    {
      tmp = game->getCenti().at(k);
      for (unsigned int n = 0; n < tmp.size(); n++)
  	{
	  y = -2.0;
      	  if (ptrfuncEnt[tmp[n]->getType()])
      	    {
      	      x = 10.0 * tmp[n]->getX();
      	      y += 0.1 * tmp[n]->getY();
      	      (this->*ptrfuncEnt[tmp[n]->getType()])(x, y, tmp);
      	    }
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
