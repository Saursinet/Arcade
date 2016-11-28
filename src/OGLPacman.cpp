//
// OGLPacman.cpp for OGLPacman in /home/noboud_n/cpp_arcade/src
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.net>
//
// Started on  Wed Mar 16 14:55:39 2016 Nyrandone Noboud-Inpeng
// Last update Sun Apr  3 22:35:00 2016 Nyrandone Noboud-Inpeng
//

#include <map>
#include "gl.h"
#include "freeglut.h"
#include "Game.hpp"
#include "LibOGL.hpp"

void		LibOGL::drawGround(double x, double y) const
{
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[PGROUND]);
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

void		LibOGL::ghosts(double x, double y, unsigned int k, Game const *game) const
{
  glEnable(GL_TEXTURE_2D);

  if (game->getEntities()[k]->getDead() == true)
    {
      disappearPacman(x, y, k, game);
      return ;
    }
  if (game->getEntities()[k]->getDirection() == Direction::DOWN
      || game->getEntities()[k]->getDirection() == Direction::UP)
    {
      if (game->getPos()[0]->getStatus() > 0)
	glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[SIDEGHAST]);
      else if (game->getEntities()[k]->getType() == Entity::e_type::RED)
	glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[SIDEMONSTER01]);
      else if (game->getEntities()[k]->getType() == Entity::e_type::PINK)
	glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[SIDEMONSTER04]);
      else if (game->getEntities()[k]->getType() == Entity::e_type::YELLOW)
	glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[SIDEMONSTER03]);
      else if (game->getEntities()[k]->getType() == Entity::e_type::BLUE)
	glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[SIDEMONSTER02]);
      glBegin(GL_QUADS);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0), 0, (y + 0.07));
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0) + 0.1, 0, (y + 0.07));
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0, y + 0.03);
      glTexCoord2d(0.0, 1.0);
      glVertex3d((x / 100.0), 0, y + 0.03);
      glEnd();
      glBegin(GL_QUADS);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0) + 0.1, 0, (y + 0.07));
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.07));
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0.1, y + 0.03);
      glTexCoord2d(0.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0, y + 0.03);
      glEnd();
      glBegin(GL_QUADS);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0), 0, (y + 0.07));
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0), 0.1, (y + 0.07));
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0), 0.1, y + 0.03);
      glTexCoord2d(0.0, 1.0);
      glVertex3d((x / 100.0), 0, y + 0.03);
      glEnd();
      glBegin(GL_QUADS);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0), 0.1, (y + 0.07));
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.07));
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0.1, y + 0.03);
      glTexCoord2d(0.0, 1.0);
      glVertex3d((x / 100.0), 0.1, y + 0.03);
      glEnd();
      glBegin(GL_QUADS);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0), 0, y + 0.03);
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0) + 0.1, 0, y + 0.03);
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.1, 0.1, y + 0.03);
      glTexCoord2d(0.0, 1.0);
      glVertex3d((x / 100.0), 0.1, y + 0.03);
      glEnd();
      if (game->getEntities()[k]->getDirection() == Direction::DOWN)
	{
	  if (game->getPos()[0]->getStatus() > 0)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[GHAST]);
	  else if (game->getEntities()[k]->getType() == Entity::e_type::RED)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[MONSTER01]);
	  else if (game->getEntities()[k]->getType() == Entity::e_type::PINK)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[MONSTER04]);
	  else if (game->getEntities()[k]->getType() == Entity::e_type::YELLOW)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[MONSTER03]);
	  else if (game->getEntities()[k]->getType() == Entity::e_type::BLUE)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[MONSTER02]);
	  glBegin(GL_QUADS);
	  glTexCoord2d(0.0, 1.0);
	  glVertex3d((x / 100.0), 0, (y + 0.07));
	  glTexCoord2d(1.0, 1.0);
	  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.07));
	  glTexCoord2d(1.0, 0.0);
	  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.07));
	  glTexCoord2d(0.0, 0.0);
	  glVertex3d((x / 100.0), 0.1, (y + 0.07));
	  glEnd();
	}
      else
	{
	  glBegin(GL_QUADS);
	  glTexCoord2d(0.0, 0.0);
	  glVertex3d((x / 100.0), 0, (y + 0.07));
	  glTexCoord2d(1.0, 0.0);
	  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.07));
	  glTexCoord2d(1.0, 1.0);
	  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.07));
	  glTexCoord2d(0.0, 1.0);
	  glVertex3d((x / 100.0), 0.1, (y + 0.07));
	  glEnd();
	}
    }
  else if (game->getEntities()[k]->getDirection() == Direction::LEFT
	   || game->getEntities()[k]->getDirection() == Direction::RIGHT
	   || game->getEntities()[k]->getDirection() == -1)
    {
      if (game->getPos()[0]->getStatus() > 0)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[SIDEGHAST]);
      else if (game->getEntities()[k]->getType() == Entity::e_type::RED)
	glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[SIDEMONSTER01]);
      else if (game->getEntities()[k]->getType() == Entity::e_type::PINK)
	glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[SIDEMONSTER04]);
      else if (game->getEntities()[k]->getType() == Entity::e_type::YELLOW)
	glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[SIDEMONSTER03]);
      else if (game->getEntities()[k]->getType() == Entity::e_type::BLUE)
	glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[SIDEMONSTER02]);
      glBegin(GL_QUADS);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0) + 0.03, 0, (y + 0.1));
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0) + 0.07, 0, (y + 0.1));
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.07, 0, y);
      glTexCoord2d(0.0, 1.0);
      glVertex3d((x / 100.0) + 0.03, 0, y);
      glEnd();
      glBegin(GL_QUADS);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0) + 0.03, 0.1, (y + 0.1));
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0) + 0.07, 0.1, (y + 0.1));
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.07, 0.1, y);
      glTexCoord2d(0.0, 1.0);
      glVertex3d((x / 100.0) + 0.03, 0.1, y);
      glEnd();
      glBegin(GL_QUADS);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0) + 0.03, 0, (y + 0.1));
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0) + 0.07, 0, (y + 0.1));
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.07, 0.1, (y + 0.1));
      glTexCoord2d(0.0, 1.0);
      glVertex3d((x / 100.0) + 0.03, 0.1, (y + 0.1));
      glEnd();
      glBegin(GL_QUADS);
      glTexCoord2d(0.0, 0.0);
      glVertex3d((x / 100.0) + 0.03, 0, y);
      glTexCoord2d(1.0, 0.0);
      glVertex3d((x / 100.0) + 0.07, 0, y);
      glTexCoord2d(1.0, 1.0);
      glVertex3d((x / 100.0) + 0.07, 0.1, y);
      glTexCoord2d(0.0, 1.0);
      glVertex3d((x / 100.0) + 0.03, 0.1, y);
      glEnd();
      if (game->getEntities()[k]->getDirection() == Direction::RIGHT)
	{
	  if (game->getPos()[0]->getStatus() > 0)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[GHAST]);
	  else if (game->getEntities()[k]->getType() == Entity::e_type::RED)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[MONSTER01]);
	  else if (game->getEntities()[k]->getType() == Entity::e_type::PINK)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[MONSTER04]);
	  else if (game->getEntities()[k]->getType() == Entity::e_type::YELLOW)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[MONSTER03]);
	  else if (game->getEntities()[k]->getType() == Entity::e_type::BLUE)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[MONSTER02]);
	  glBegin(GL_QUADS);
	  glTexCoord2d(0.0, 1.0);
	  glVertex3d((x / 100.0) + 0.07, 0, (y + 0.1));
	  glTexCoord2d(0.0, 0.0);
	  glVertex3d((x / 100.0) + 0.07, 0.1, (y + 0.1));
	  glTexCoord2d(1.0, 0.0);
	  glVertex3d((x / 100.0) + 0.07, 0.1, y);
	  glTexCoord2d(1.0, 1.0);
	  glVertex3d((x / 100.0) + 0.07, 0, y);
	  glEnd();
	}
      else
	{
	  glBegin(GL_QUADS);
	  glTexCoord2d(0.0, 0.0);
	  glVertex3d((x / 100.0) + 0.07, 0, (y + 0.1));
	  glTexCoord2d(1.0, 0.0);
	  glVertex3d((x / 100.0) + 0.07, 0.1, (y + 0.1));
	  glTexCoord2d(1.0, 1.0);
	  glVertex3d((x / 100.0) + 0.07, 0.1, y);
	  glTexCoord2d(0.0, 1.0);
	  glVertex3d((x / 100.0) + 0.07, 0, y);
	  glEnd();
	}
      if (game->getEntities()[k]->getDirection() == Direction::LEFT)
	{
	  if (game->getPos()[0]->getStatus() > 0)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[GHAST]);
	  else if (game->getEntities()[k]->getType() == Entity::e_type::RED)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[MONSTER01]);
	  else if (game->getEntities()[k]->getType() == Entity::e_type::PINK)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[MONSTER04]);
	  else if (game->getEntities()[k]->getType() == Entity::e_type::YELLOW)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[MONSTER03]);
	  else if (game->getEntities()[k]->getType() == Entity::e_type::BLUE)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[MONSTER02]);
	  glBegin(GL_QUADS);
	  glTexCoord2d(0.0, 1.0);
	  glVertex3d((x / 100.0) + 0.03, 0, (y + 0.1));
	  glTexCoord2d(0.0, 0.0);
	  glVertex3d((x / 100.0) + 0.03, 0.1, (y + 0.1));
	  glTexCoord2d(1.0, 0.0);
	  glVertex3d((x / 100.0) + 0.03, 0.1, y);
	  glTexCoord2d(1.0, 1.0);
	  glVertex3d((x / 100.0) + 0.03, 0, y);
	  glEnd();
	}
      else
	{
	  if (game->getPos()[0]->getStatus() > 0)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[SIDEGHAST]);
	  else if (game->getEntities()[k]->getType() == Entity::e_type::RED)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[SIDEMONSTER01]);
	  else if (game->getEntities()[k]->getType() == Entity::e_type::PINK)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[SIDEMONSTER04]);
	  else if (game->getEntities()[k]->getType() == Entity::e_type::YELLOW)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[SIDEMONSTER03]);
	  else if (game->getEntities()[k]->getType() == Entity::e_type::BLUE)
	    glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[SIDEMONSTER02]);
	  glBegin(GL_QUADS);
	  glTexCoord2d(0.0, 0.0);
	  glVertex3d((x / 100.0) + 0.03, 0, (y + 0.1));
	  glTexCoord2d(0.0, 1.0);
	  glVertex3d((x / 100.0) + 0.03, 0.1, (y + 0.1));
	  glTexCoord2d(1.0, 1.0);
	  glVertex3d((x / 100.0) + 0.03, 0.1, y);
	  glTexCoord2d(1.0, 0.0);
	  glVertex3d((x / 100.0) + 0.03, 0, y);
	  glEnd();
	}
    }
  glDisable(GL_TEXTURE_2D);
}

void		LibOGL::emptyPacman(double x, double y) const
{
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[PGROUND]);
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

void		LibOGL::blockPacman(double x, double y) const
{
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[PWALL]);
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
  glDisable(GL_TEXTURE_2D);
  glColor3ub(0, 0, 0);
  glBegin(GL_QUADS);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glVertex3d((x / 100.0) + 0.1, 0, y);
  glVertex3d((x / 100.0), 0, y);
  glEnd();
  glBegin(GL_QUADS);
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
  glVertex3d((x / 100.0) + 0.1, 0.1, y);
  glVertex3d((x / 100.0) + 0.1, 0, y);
  glEnd();
  glBegin(GL_QUADS);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glVertex3d((x / 100.0), 0.1, (y + 0.1));
  glVertex3d((x / 100.0), 0.1, y);
  glVertex3d((x / 100.0), 0, y);
  glEnd();
  glColor3ub(0, 0, 0);
  glBegin(GL_QUADS);
  glVertex3d((x / 100.0), 0, (y + 0.1));
  glVertex3d((x / 100.0) + 0.1, 0, (y + 0.1));
  glVertex3d((x / 100.0) + 0.1, 0.1, (y + 0.1));
  glVertex3d((x / 100.0), 0.1, (y + 0.1));
  glEnd();
  glBegin(GL_QUADS);
  glVertex3d((x / 100.0), 0, y);
  glVertex3d((x / 100.0) + 0.1, 0, y);
  glVertex3d((x / 100.0) + 0.1, 0.1, y);
  glVertex3d((x / 100.0), 0.1, y);
  glEnd();
}

void		LibOGL::headPacman(double x, double y, UNUSED unsigned int k, UNUSED Game const *game) const
{
  GLUquadric	*quad;

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[PGROUND]);
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
  glColor3ub(255, 240, 0);
  quad = gluNewQuadric();
  gluQuadricNormals(quad, GLU_SMOOTH);
  glTranslated(x / 100.0 + 0.05, 0.05, y + 0.05);
  gluSphere(quad, 0.06, 10, 5);
  glEnd();
  glTranslated(-x / 100.0 - 0.05, -0.05, -y - 0.05);
  gluDeleteQuadric(quad);
}

void		LibOGL::foodPacman(double x, double y) const
{
  GLUquadric	*quad;

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[PGROUND]);
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
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[PCOIN]);
  quad = gluNewQuadric();
  gluQuadricTexture(quad, GL_TRUE);
  glTranslated(x / 100.0 + 0.05, 0.05, y + 0.05);
  gluSphere(quad, 0.02, 10, 5);
  glEnd();
  glTranslated(-x / 100.0 - 0.05, -0.05, -y - 0.05);
  gluDeleteQuadric(quad);
  glDisable(GL_TEXTURE_2D);
}

void		LibOGL::powPacman(double x, double y) const
{
  GLUquadric	*quad;

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[PGROUND]);
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

void		LibOGL::disappearPacman(double x, double y, unsigned int k, Game const *game) const
{
  GLUquadric	*quad;

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, static_cast<std::map<e_textures, GLuint>>(_textures)[PGROUND]);
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
  if (game->getEntities()[k]->getDirection() == Direction::RIGHT)
    {
      glColor3ub(0, 0, 0);
      quad = gluNewQuadric();
      glTranslated(x / 100.0 + 0.06, 0.1, y + 0.03);
      gluSphere(quad, 0.015, 10, 5);
      glEnd();
      glTranslated(-x / 100.0 - 0.06, -0.1, -y - 0.03);
      gluDeleteQuadric(quad);
      glColor3ub(255, 255, 255);
      quad = gluNewQuadric();
      glTranslated(x / 100.0 + 0.05, 0.1, y + 0.03);
      gluSphere(quad, 0.02, 10, 5);
      glEnd();
      glTranslated(-x / 100.0 - 0.05, -0.1, -y - 0.03);
      gluDeleteQuadric(quad);
      glColor3ub(0, 0, 0);
      quad = gluNewQuadric();
      glTranslated(x / 100.0 + 0.06, 0.1, y + 0.07);
      gluSphere(quad, 0.015, 10, 5);
      glEnd();
      glTranslated(-x / 100.0 - 0.06, -0.1, -y - 0.07);
      gluDeleteQuadric(quad);
      glColor3ub(255, 255, 255);
      quad = gluNewQuadric();
      glTranslated(x / 100.0 + 0.05, 0.1, y + 0.07);
      gluSphere(quad, 0.02, 10, 5);
      glEnd();
      glTranslated(-x / 100.0 - 0.05, -0.1, -y - 0.07);
      gluDeleteQuadric(quad);
    }
  else if (game->getEntities()[k]->getDirection() == Direction::LEFT
	   || game->getEntities()[k]->getDirection() == -1)
    {
      glColor3ub(0, 0, 0);
      quad = gluNewQuadric();
      glTranslated(x / 100.0 + 0.04, 0.1, y + 0.03);
      gluSphere(quad, 0.015, 10, 5);
      glEnd();
      glTranslated(-x / 100.0 - 0.04, -0.1, -y - 0.03);
      gluDeleteQuadric(quad);
      glColor3ub(255, 255, 255);
      quad = gluNewQuadric();
      glTranslated(x / 100.0 + 0.05, 0.1, y + 0.03);
      gluSphere(quad, 0.02, 10, 5);
      glEnd();
      glTranslated(-x / 100.0 - 0.05, -0.1, -y - 0.03);
      gluDeleteQuadric(quad);
      glColor3ub(0, 0, 0);
      quad = gluNewQuadric();
      glTranslated(x / 100.0 + 0.04, 0.1, y + 0.07);
      gluSphere(quad, 0.015, 10, 5);
      glEnd();
      glTranslated(-x / 100.0 - 0.04, -0.1, -y - 0.07);
      gluDeleteQuadric(quad);
      glColor3ub(255, 255, 255);
      quad = gluNewQuadric();
      glTranslated(x / 100.0 + 0.05, 0.1, y + 0.07);
      gluSphere(quad, 0.02, 10, 5);
      glEnd();
      glTranslated(-x / 100.0 - 0.05, -0.1, -y - 0.07);
      gluDeleteQuadric(quad);
    }
  else if (game->getEntities()[k]->getDirection() == Direction::UP)
    {
      glColor3ub(255, 255, 255);
      quad = gluNewQuadric();
      glTranslated(x / 100.0 + 0.03, 0.1, y + 0.05);
      gluSphere(quad, 0.02, 10, 5);
      glEnd();
      glTranslated(-x / 100.0 - 0.03, -0.1, -y - 0.05);
      gluDeleteQuadric(quad);
      quad = gluNewQuadric();
      glTranslated(x / 100.0 + 0.07, 0.1, y + 0.05);
      gluSphere(quad, 0.02, 10, 5);
      glEnd();
      glTranslated(-x / 100.0 - 0.07, -0.1, -y - 0.05);
      gluDeleteQuadric(quad);
    }
  else if (game->getEntities()[k]->getDirection() == Direction::DOWN)
    {
      glColor3ub(0, 0, 0);
      quad = gluNewQuadric();
      glTranslated(x / 100.0 + 0.03, 0.1, y + 0.06);
      gluSphere(quad, 0.015, 10, 5);
      glEnd();
      glTranslated(-x / 100.0 - 0.03, -0.1, -y - 0.06);
      gluDeleteQuadric(quad);
      glColor3ub(255, 255, 255);
      quad = gluNewQuadric();
      glTranslated(x / 100.0 + 0.03, 0.1, y + 0.05);
      gluSphere(quad, 0.02, 10, 5);
      glEnd();
      glTranslated(-x / 100.0 - 0.03, -0.1, -y - 0.05);
      gluDeleteQuadric(quad);
      glColor3ub(0, 0, 0);
      quad = gluNewQuadric();
      glTranslated(x / 100.0 + 0.07, 0.1, y + 0.06);
      gluSphere(quad, 0.015, 10, 5);
      glEnd();
      glTranslated(-x / 100.0 - 0.07, -0.1, -y - 0.06);
      gluDeleteQuadric(quad);
      glColor3ub(255, 255, 255);
      quad = gluNewQuadric();
      glTranslated(x / 100.0 + 0.07, 0.1, y + 0.05);
      gluSphere(quad, 0.02, 10, 5);
      glEnd();
      glTranslated(-x / 100.0 - 0.07, -0.1, -y - 0.05);
      gluDeleteQuadric(quad);
    }
}

int			LibOGL::pacmanBlocked(int i, int j, Game const *game) const
{
  i = i > game->getHeight() - 1 ? 0 : i;
  i = i < 0 ? game->getHeight() - 1 : i;
  j = j > game->getWidth() - 1 ? 0 : j;
  j = j < 0 ? game->getWidth() - 1 : j;
  if (i < 0 || j < 0)
    return (1);
  if (game->getTab()[i][j] == 1 || game->getTab()[i][j] == 3)
    return (1);
  return (0);
}

int			LibOGL::isBlocked(int i, int j, Game const *game) const
{
  i = i > game->getHeight() - 1 ? 0 : i;
  i = i < 0 ? game->getHeight() - 1 : i;
  j = j > game->getWidth() - 1 ? 0 : j;
  j = j < 0 ? game->getWidth() - 1 : j;
  if (i < 0 || j < 0)
    return (1);
  if (game->getTab()[i][j] == 1 || game->getTab()[i][j] == 3)
    return (1);
  if (game->getTab()[i][j] == 7)
    if ((game->getPos()[0]->getDirection() == DOWN
	 && pacmanBlocked(game->getPos()[0]->getY() + 1, game->getPos()[0]->getX(), game))
	|| (game->getPos()[0]->getDirection() == UP
	    && pacmanBlocked(game->getPos()[0]->getY() - 1, game->getPos()[0]->getX(), game))
	|| (game->getPos()[0]->getDirection() == LEFT
	    && pacmanBlocked(game->getPos()[0]->getY(), game->getPos()[0]->getX() - 1, game))
	|| (game->getPos()[0]->getDirection() == RIGHT
	    && pacmanBlocked(game->getPos()[0]->getY(), game->getPos()[0]->getX() + 1, game)))
      return (1);
  return (0);
}

void			LibOGL::globalScenePacman(Game const *game) const
{
  int			i;
  std::map<Type, void (LibOGL::*)(double, double) const>				ptrfunc;
  std::map<Powerup::e_type, void (LibOGL::*)(double, double) const>			ptrfuncPow;
  std::map<Entity::e_type, void (LibOGL::*)(double, double, unsigned int, Game const *) const>	ptrfuncEnt;
  double		x;
  double		y;
  double		yy;
  int			realy;
  int			realx;
  unsigned int		k;

  i = 1;
  ptrfunc[EMPTY] = &LibOGL::emptyPacman;
  ptrfunc[BLOCK] = &LibOGL::blockPacman;
  ptrfuncPow[Powerup::e_type::GUM] = &LibOGL::foodPacman;
  ptrfuncPow[Powerup::e_type::BIGGUM] = &LibOGL::powPacman;
  ptrfuncEnt[Entity::e_type::PAC] = &LibOGL::headPacman;
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  x = 10.0 * game->getPos()[0]->getX() / 100.0;
  y = -2.0 - 0.02 * game->getPos()[0]->getY();
  yy = 2.0 + 0.02 * game->getPos()[0]->getY();
  smoothCam(&x, &yy, 0, game);
  gluLookAt(x, yy, 0.5, x, y, -1.0, 0.0, 1.0, 0.0);
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
	  drawGround(x, y);
	  smoothPos(&x, &y, k, game);
	  (this->*ptrfuncEnt[game->getPos()[k]->getType()])(x, y, k, game);
	}
    }
  for (k = 0; k < game->getEntities().size(); k++)
    {
      y = -2.0;
      if (game->getEntities()[k]->getType() == Entity::e_type::RED
  	  || game->getEntities()[k]->getType() == Entity::e_type::PINK
  	  || game->getEntities()[k]->getType() == Entity::e_type::YELLOW
  	  || game->getEntities()[k]->getType() == Entity::e_type::BLUE)
  	{
  	  x = 10.0 * game->getEntities()[k]->getX();
  	  y += 0.1 * game->getEntities()[k]->getY();
  	  drawGround(x, y);
  	  smoothEntities(&x, &y, k, game);
  	  ghosts(x, y, k, game);
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
  glRasterPos2d(10, 30);
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
