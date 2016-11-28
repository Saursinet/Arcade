//
// Powerup.hpp for arcade in /home/wilmot_g/Rendu/cpp_arcade/leHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Mar 10 16:06:12 2016 guillaume wilmot
// Last update Sun Apr  3 18:01:41 2016 Nyrandone Noboud-Inpeng
//

#ifndef POWERUP_HPP_
# define POWERUP_HPP_

class	Powerup{
public:

enum	e_type
  {
    GUM = 0,
    BIGGUM,
    FOOD,
    SHOT
  };

  Powerup(int, int, e_type);
  ~Powerup();
  Powerup(const Powerup &);
  Powerup &operator=(const Powerup &);

  int			getX() const;
  int			getY() const;
  e_type		getType() const;

  void			setX(int);
  void			setY(int);
  void			setType(Powerup::e_type);
protected:
  int			_x;
  int			_y;
  Powerup::e_type	_type;
};

#endif /* !POWERUP_HPP_ */
