//
// Game.hpp for arcade in /home/wilmot_g/Rendu/cpp_arcade/leHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Mar 10 17:56:58 2016 guillaume wilmot
// Last update Sun Apr  3 18:00:46 2016 Nyrandone Noboud-Inpeng
//

#ifndef GAME_HPP_
# define GAME_HPP_

# include <vector>
# include "ILib.hpp"
# include "Protocol.hpp"
# include "IGame.hpp"
# include "Entity.hpp"
# include "Powerup.hpp"
# include "Shot.hpp"
# include "Libraries.hpp"

enum	MainAction {
  TOUCH_2 = 16777266,
  TOUCH_3 = 16777267,
  TOUCH_4 = 16777268,
  TOUCH_5 = 16777269,
  TOUCH_8 = 16777272,
  TOUCH_9 = 16777273
};

enum	Direction {
  TOUCH_UP = 16777489,
  TOUCH_DOWN = 16777490,
  TOUCH_LEFT = 16777491,
  TOUCH_RIGHT = 16777492,
  ESCAPE = 16777243,
  UP = 11,
  DOWN = 12,
  RIGHT = 13,
  LEFT = 10,
  SPACE = 16777248,
  STOP = 9999,
  RETURN = 16777229
};

enum	Type {
  BLOCK = 1,
  EMPTY = 0,
  ENNEMY = 3,
  BODY = 7,
  HEAD = 9,
  TAIL = 8,
  FOOD = 6
};

enum	GameName {
  UNDEFINED = -1,
  SNAKE = 0,
  PACMAN,
  CENTIPEDE
};

class	Libs;
class	ILib;

class	Game : public IGame {
public:
  Game();
  virtual ~Game() {}
  Game(const Game &);
  Game				&operator=(const Game &);

  //Actual Game
  virtual int			game(ILib **, Libs &, unsigned int &);
  virtual void			changeDirection(int &, int &) {}
  virtual void			timer(int = 0) {}

  //Getters
  std::vector<Entity *>		getPos() const;
  std::vector<Entity *>		getEntities() const;
  std::vector<Powerup *>	getPowerups() const;
  std::vector<Shot *>		getShots() const;
  int				getHeight() const;
  int				getWidth() const;
  int				getScore() const;
  int				limitX(int) const;
  int				limitY(int) const;
  std::string			*getMap() const;
  std::string			*getTab() const;
  std::string			getLogin()const;
  int				getDirection() const;
  bool				getFinish() const;
  clock_t			getClock() const;
  GameName			getGameName() const;
  virtual int			play(int) {return (0);}

  std::vector<std::vector<Entity *> >	getCenti()const;

private:
  virtual void			generateMap() {}

protected:
  clock_t			_time;
  bool				_finito;
  int				_direction;
  int				_width;
  int				_height;
  int				_score;
  GameName			_name;
  std::vector<Entity *>		_pos;
  std::vector<Entity *>		_entities;
  std::vector<Powerup *>	_powerups;
  std::vector<Shot *>		_shot;
  std::string			*_map;
  ILib				*_lib;
  std::string			_login;

  std::vector<std::vector<Entity *> >	_centi;
};

#endif /* !GAME_HPP_ */
