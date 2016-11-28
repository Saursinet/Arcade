//
// Entity.hpp for arcade in /home/wilmot_g/Rendu/cpp_arcade/leHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Mar 10 16:06:12 2016 guillaume wilmot
// Last update Sun Apr  3 18:01:33 2016 Nyrandone Noboud-Inpeng
//

#ifndef ENTITY_HPP_
# define ENTITY_HPP_

class	Entity{
public:

enum	e_type
  {
    RED = 0,
    PINK,
    YELLOW,
    BLUE,
    PAC,
    SHIP,
    HEAD,
    BODY,
    TAIL
  };

  Entity(int, int, e_type);
  ~Entity();
  Entity(const Entity &);
  Entity &operator=(const Entity &);

  int			getX() const;
  int			getY() const;
  e_type		getType() const;
  int			getFrame() const;
  int			getDirection() const;
  unsigned int		getStatus() const;
  unsigned int		getFlee() const;
  unsigned int		getStandBy() const;
  bool			getDead() const;

  void			setDirection(int);
  void			setX(int);
  void			setY(int);
  void			setFrame(int);
  void			setType(Entity::e_type);
  void			setStatus(unsigned int);
  void			setFlee(unsigned int);
  void			setDead(bool);
  void			setStandBy(unsigned int);
protected:
  int			_x;
  int			_y;
  int			_direction;
  int			_frame;
  Entity::e_type	_type;
  unsigned int		_isInvincible;
  unsigned int		_standBy;
  unsigned int		_flee;
  bool			_isDead;
};

#endif /* !ENTITY_HPP_ */
