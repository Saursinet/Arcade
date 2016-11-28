//
// Shot.cpp for arcade in /home/wilmot_g/Rendu/cpp_arcade/leHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Mar 10 16:14:04 2016 guillaume wilmot
// Last update Fri Apr  1 10:57:25 2016 Florian Saurs
//

#include "Shot.hpp"

Shot::Shot(int x, int y, e_type type) : Powerup(x, y, type) {}

Shot::~Shot() {}

Shot::Shot(const Shot &) : Powerup(_x, _y, _type) {}

Shot		&Shot::operator=(const Shot &src)
{
  if (&src != this)
    {
      this->_x = src._x;
      this->_y = src._y;
      this->_type = src._type;
    }
  return (*this);
}
