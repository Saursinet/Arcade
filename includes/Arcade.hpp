//
// Arcade.hpp for  in /home/wilmot_g/Rendu/cpp_arcade2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Apr  1 13:28:04 2016 guillaume wilmot
// Last update Sun Apr  3 03:47:08 2016 guillaume wilmot
//

#ifndef ARCADE_HPP_
# define ARCADE_HPP_

# include "Game.hpp"
# include "Score.hpp"

class				Arcade {
public:
  Arcade();
  ~Arcade();
  Arcade(const Arcade &);
  Arcade			&operator=(const Arcade &);

  int				launchGame(Game *, ILib **, Libs &, Menu &);
  int				start(char **);
private:
  Score				_score;
};

#endif /* !ARCADE_HPP_ */
