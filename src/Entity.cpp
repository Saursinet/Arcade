//
// Entity.cpp for arcade in /home/wilmot_g/Rendu/cpp_arcade/leHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Mar 10 16:14:04 2016 guillaume wilmot
// Last update Thu Mar 31 22:15:50 2016 guillaume wilmot
//

#include "Entity.hpp"

Entity::Entity(int x, int y, e_type type)
{
  _x = x;
  _y = y;
  _type = type;
  _direction = 9999;
  _frame = 0;
  _isInvincible = 0;
  _isDead = 0;
  _flee = 0;
  _standBy = type == PAC ? 0 : 20;
}

Entity::~Entity()
{}

Entity::Entity(const Entity &src)
{
  this->_x = src._x;
  this->_y = src._y;
  this->_type = src._type;
}

Entity		&Entity::operator=(const Entity &src)
{
  if (&src != this)
    {
      this->_x = src._x;
      this->_y = src._y;
      this->_type = src._type;
    }
  return (*this);
}

int		Entity::getX() const
{
  return (_x);
}

int		Entity::getY() const
{
  return (_y);
}

Entity::e_type	Entity::getType() const
{
  return (_type);
}

int		Entity::getFrame() const
{
  return (_frame);
}

int		Entity::getDirection() const
{
  return (_direction);
}

unsigned int	Entity::getStatus() const
{
  return (_isInvincible);
}

unsigned int	Entity::getFlee() const
{
  return (_flee);
}

bool		Entity::getDead() const
{
  return (_isDead);
}

unsigned int	Entity::getStandBy() const
{
  return (_standBy);
}

void		Entity::setDirection(int dir)
{
  _direction = dir;
}

void		Entity::setX(int x)
{
  _x = x;
}

void		Entity::setY(int y)
{
  _y = y;
}

void		Entity::setFrame(int frame)
{
  _frame = frame;
}

void		Entity::setType(Entity::e_type type)
{
  _type = type;
}

void		Entity::setStatus(unsigned int status)
{
  _isInvincible = status;
}

void		Entity::setFlee(unsigned int flee)
{
  _flee = flee;
}

void		Entity::setDead(bool dead)
{
  _isDead = dead;
}

void		Entity::setStandBy(unsigned int stand)
{
  _standBy = stand;
}
