//
// Pacman.hpp for  in /home/saurs_f/cpp_arcade/leHaineux
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Mar 15 16:40:09 2016 Florian Saurs
// Last update Tue Mar 15 16:40:28 2016 Florian Saurs
//

#ifndef PACMAN_HPP_
# define PACMAN_HPP_

# include "Entity.hpp"

class	Pacman : public Entity
{
public:
  Pacman(int, int, e_type);
  ~Pacman();
};

#endif /* !PACMAN_HPP_ */
