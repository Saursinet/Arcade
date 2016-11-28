//
// Shot.hpp for arcade in /home/wilmot_g/Rendu/cpp_arcade/leHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Mar 10 16:06:12 2016 guillaume wilmot
// Last update Fri Apr  1 10:57:08 2016 Florian Saurs
//

#ifndef SHOT_HPP_
# define SHOT_HPP_

# include "Powerup.hpp"

class Shot : public Powerup {
public:
  Shot(int, int, e_type);
  ~Shot();
  Shot(const Shot &);
  Shot &operator=(const Shot &);
};

#endif /* !SHOT_HPP_ */
