//
// LibSDL.hpp for LibSDL in /home/wilmot_g/Rendu/cpp_arcade/leHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Mar  9 16:50:44 2016 guillaume wilmot
// Last update Sun Apr  3 21:53:44 2016 guillaume wilmot
//

#ifndef LIBSDL_HPP_
# define LIBSDL_HPP_

# include <map>
# include "SDL.h"
# include "SDL_image.h"
# include "SDL_mixer.h"
# include "SDL_rotozoom.h"
# include "SDL_ttf.h"
# include "Protocol.hpp"
# include "ILib.hpp"
# include "Game.hpp"

# define SIZEBORDER 10
# define COLORE 0x0000FF
# define COLORI 0x0000AA
# define BPP 32
# define WINX 1920
# define WINY 1080

typedef struct	s_line
{
  int		x1;
  int		x2;
  int		y1;
  int		y2;
}		t_line;

typedef struct  s_sounds
{
  Mix_Chunk     *wakaWaka;
  Mix_Chunk     *pacmanEats;
  Mix_Chunk     *snakeEats;
  Mix_Chunk     *die;
  Mix_Music     *pacmanMusic;
  Mix_Music     *snakeMusic;
}               t_sounds;

typedef struct	s_snake
{
  SDL_Surface	*corner[4];
  SDL_Surface	*body[4];
  SDL_Surface	*head[4];
  SDL_Surface	*tail[4];
  SDL_Surface	*food;
}		t_snake;

typedef struct	s_pacman
{
  SDL_Surface	*blue[8];
  SDL_Surface	*red[8];
  SDL_Surface	*pink[8];
  SDL_Surface	*yellow[8];
  SDL_Surface	*eyes[8];
  SDL_Surface	*pac[4];
  SDL_Surface	*gum;
  SDL_Surface	*bigGum;
  SDL_Surface	*dead;
  SDL_Surface	*dead2;
}		t_pacman;

typedef struct	s_assets
{
  t_pacman	pacman;
  t_snake	snake;
  SDL_Surface	*ship[3];
  t_sounds	sounds;
}		t_assets;

extern "C" {
  ILib		*makeLib();
}

class LibSDL : public ILib {
public:
  LibSDL();
  ~LibSDL();
  LibSDL(const LibSDL &);
  LibSDL &operator=(const LibSDL &);

  int		init();
  int		print(Game * const) const;
  int		end();
  int		playSound(e_sound);
  unsigned int	getEvent(unsigned int) const;
  void		printMenu(Menu * const) const;
  char		getChar() const;

private:
  int		chooseGame(Menu * const) const;
  int		chooseLib(Menu * const) const;
  int		isBlocked(int, int, Game * const) const;
  int		pacmanBlocked(int, int, Game * const) const;
  int		loadSound(const std::string &, Mix_Chunk **) const;
  int		loadSounds();
  int		loadAssets();
  int		loadTexture(const std::string &, SDL_Surface **) const;
  int		getGif(std::string, SDL_Surface **, int) const;
  int		getAngle(const std::vector<Entity *> &, unsigned int) const;
  int		printScore(Game * const) const;
  int		printEntity(Game * const) const;
  int		printBorder(int, int, t_line, Game * const) const;
  int		printMushroom(int, int, int) const;
  int		printSnakePart(SDL_Rect, int, SDL_Surface * const *) const;
  int		printOneEntity(const std::vector<Entity *> &, int, Game * const) const;
  int		printPowerup(Powerup *) const;
  int		displayBase(SDL_Rect *, Menu * const) const;
  int		printText(const std::string &, SDL_Rect *, int, unsigned int) const;
  void		putPixel(SDL_Surface *, int, int, Uint32) const;
  void		drawCaseOne(t_line, SDL_Surface *, Uint32) const;
  void		drawCaseTwo(t_line, SDL_Surface *, Uint32) const;
  void		swap(t_line *) const;
  void		drawLine(t_line, SDL_Surface *, Uint32) const;

  t_assets				_assets;
  TTF_Font                              *_police;
  TTF_Font                              *_menuPolice;
  SDL_Surface				*_screen;
  SDL_Surface				*_buff;
  std::map<e_sound, Mix_Chunk *>        _sounds;
  bool					_init;
};

#endif /* !LIBSDL_HPP_ */
