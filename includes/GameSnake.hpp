//
// GameSnake.hpp for arcade in /home/wilmot_g/Rendu/cpp_arcade/leHaineux/includes
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Mar 10 19:09:29 2016 guillaume wilmot
// Last update Sun Apr  3 18:06:58 2016 Nyrandone Noboud-Inpeng
//

#ifndef GAMESNAKE_HPP_
# define GAMESNAKE_HPP_

# include "Game.hpp"
# include "Snake.hpp"

extern "C"
{
  Game	*makeGame();
  void	Play();
};

class GameSnake : public Game {
public:
  GameSnake();
  virtual ~GameSnake();
  GameSnake(const GameSnake &);
  GameSnake	&operator=(const GameSnake &);

  void		generateMap();
  void		changeDirection(int &, int &);
  void		timer(int = 0);

  int		play(int);
  int		getFood() const;
private:
  void		removeFood(int, int);
  int		checkFood(int, int);
  int		move();
  int		moveSnake(unsigned int, unsigned int);
  void		moveIt(std::vector<Entity *>::iterator, int, int);
  void		updateMap();

  int		_food;
};

#endif /* !GAMESNAKE_HPP_ */
