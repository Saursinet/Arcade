//
// Snake.hpp for  in /home/saurs_f/cpp_arcade/leHaineux
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Sun Mar 13 21:34:35 2016 Florian Saurs
// Last update Sun Mar 13 21:43:06 2016 Florian Saurs
//

#ifndef SNAKE_HPP_
# define SNAKE_HPP_

# include "Entity.hpp"

class	Snake : public Entity
{
public:
  Snake(int, int, e_type);
  ~Snake();
};

#endif /* !SNAKE_HPP_ */
