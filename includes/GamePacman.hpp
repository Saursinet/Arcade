//
// GamePacman.hpp for arcade in /home/wilmot_g/Rendu/cpp_arcade/leHaineux/includes
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Mar 10 19:09:29 2016 guillaume wilmot
// Last update Sun Apr  3 19:04:30 2016 guillaume wilmot
//

#ifndef GAMEPACMAN_HPP_
# define GAMEPACMAN_HPP_

# include "Game.hpp"
# include "Pacman.hpp"

extern "C"
{
  Game	*makeGame();
  void	Play();
};

typedef struct  s_paths t_paths;
struct          s_paths
{
  int           id;
  int           visited;
  int           visited_by;
  int           pos[2];
  int           best_way[2];
  t_paths       *neighboors[4];
  t_paths       *next;
};

class GamePacman : public Game {
public:
  GamePacman();
  ~GamePacman();
  GamePacman(const GamePacman &);
  GamePacman	&operator=(const GamePacman &);

  int		play(int);

  void		generateMap();
  void		timer(int = 0);
  void		changeDirection(int &, int &);
  void		changeEnnemiesDirection();
  int		move();
  int		movePacman(Entity *, int);
  void		updateMap();

  int		getGums() const;
private:
  void		processPaths();
  void		freePaths();
  void		addInPaths(t_paths **, int, int, int) const;
  void		addNeighboors(t_paths **) const;
  void		addNeighboor(t_paths **, int, int, int) const;
  void		reinitPaths(t_paths *) const;
  void		addOrRemoveFromKe(int, int, int *) const;
  void		setListOnKe(t_paths **, int) const;
  void		removePowerup();
  int		canMove(Entity *, Entity *);
  int		isBlocked(int, int) const;
  int		*initKe(t_paths *) const;
  int		getBestWay(t_paths *, int, int) const;
  int		findBestWay(int, int, int, int) const;
  float		pathfinding(t_paths *, int, int) const;
  float		extractPath(int, std::vector<int> *, t_paths *, t_paths *) const;
  float		distance(int[2], int[2]) const;

  int		_gums;
  t_paths	*_paths;
  int		_nbPaths;
};

#endif /* !GAMEPACMAN_HPP_ */
