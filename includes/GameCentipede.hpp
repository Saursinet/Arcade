//
// GameCentipede.hpp for arcade in /home/wilmot_g/Rendu/cpp_arcade/leHaineux/includes
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Mar 10 19:09:29 2016 guillaume wilmot
// Last update Sun Apr  3 18:06:14 2016 Nyrandone Noboud-Inpeng
//

#ifndef GAMECENTIPEDE_HPP_
# define GAMECENTIPEDE_HPP_

# include "Game.hpp"
# include "Centipede.hpp"
# include "HeroCenti.hpp"
# include "Shot.hpp"

# define UNUSED __attribute__((__unused__))

extern "C"
{
  Game	*makeGame();
  void	Play();
};

class GameCentipede : public Game {
public:
  GameCentipede();
  ~GameCentipede();
  GameCentipede(const GameCentipede &);
  GameCentipede	&operator=(const GameCentipede &);

  int		play(int);

  void		generateMap();
  void		timer(int = 0);
  void		changeDirection(int &, int &);
  int		move();
  int		canMove(Entity *);
  int		moveCentipede(Entity *);
  int		moveHero(Entity *);
  void		updateMap();
  void		setOldDirection(int);
  int		getOldDirection()const;
  void		findEntity(int x, int y);
  void		moveShot();
  int		checkCenti();
  std::vector<Entity *>	createCenti();

  int		_oldDirection;
  bool		_newShot;
  int		_nbCenti;
private:
  void		updateEnum();
};

#endif /* !GAMECENTIPEDE_HPP_ */
