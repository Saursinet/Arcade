//
// Powerup.cpp for arcade in /home/wilmot_g/Rendu/cpp_arcade/leHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Mar 10 16:14:04 2016 guillaume wilmot
// Last update Fri Apr  1 11:00:53 2016 Florian Saurs
//

#include "Powerup.hpp"

Powerup::Powerup(int x, int y, e_type type)
{
  _x = x;
  _y = y;
  _type = type;
}

Powerup::~Powerup()
{}

Powerup::Powerup(const Powerup &src)
{
  this->_x = src._x;
  this->_y = src._y;
  this->_type = src._type;
}

Powerup		&Powerup::operator=(const Powerup &src)
{
  if (&src != this)
    {
      this->_x = src._x;
      this->_y = src._y;
      this->_type = src._type;
    }
  return (*this);
}

int		Powerup::getX() const
{
  return (_x);
}

int		Powerup::getY() const
{
  return (_y);
}

Powerup::e_type	Powerup::getType() const
{
  return (_type);
}

void		Powerup::setX(int x)
{
  _x = x;
}

void		Powerup::setY(int y)
{
  _y = y;
}
