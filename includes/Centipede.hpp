//
// Centipede.hpp for  in /home/saurs_f/cpp_arcade/leHaineux
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Mar 15 16:40:09 2016 Florian Saurs
// Last update Tue Mar 29 09:13:26 2016 Florian Saurs
//

#ifndef CENTIPEDE_HPP_
# define CENTIPEDE_HPP_

# include "Entity.hpp"

class	Centipede : public Entity
{
public:
  Centipede(int, int, e_type);
  ~Centipede();
};

#endif /* !CENTIPEDE_HPP_ */
