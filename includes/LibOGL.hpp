//
// LibOGL.hpp for LibOGL in /home/noboud_n/rendu/cpp_arcade/nyrii/inc
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.net>
//
// Started on  Sat Mar 12 03:34:24 2016 Nyrandone Noboud-Inpeng
// Last update Sun Apr  3 01:13:24 2016 Nyrandone Noboud-Inpeng
//

#ifndef LIBOGL_H_
# define LIBOGL_H_

# include <map>
# include "SDL.h"
# include "SDL_mixer.h"
# include "gl.h"
# include "Game.hpp"
# include "ILib.hpp"

# define TITLE		"OpenGL game's interface"
# define ERROR_WINDOW	"Error: initialization of the window failed."
# define ERROR_TEXTURES	"Error: initialization of the textures failed."
# define ERROR_AUDIO	"Error: initialization of the audio failed -- "
# define ERROR_SDL	"Error: initialization of the SDL failed -- "
# define ERROR_MUSIC	"Error: unable to load WAV file -- "
# define ERROR_PLAYWAV	"Error: unable to play WAV file -- "
# define MUSIC_SNAKE	"./assets/snake/sounds/OGLMusicSnake.wav"
# define MUSIC_PACMAN	"./assets/snake/sounds/OGLMusicSnake.wav"
# define SOUND_SEATS	"./assets/snake/sounds/snakeEats.wav"
# define SOUND_PEATS	"./assets/pacman/sounds/pacmanEats.wav"
# define SOUND_WAKA	"./assets/pacman/sounds/wakaWaka.wav"
# define SOUND_DIE	"./assets/pacman/sounds/die.wav"

extern		"C"
{
  ILib		*makeLib();
}

enum		e_textures
  {
    TEX_UNDEFINED = -1,
    WALL = 0,
    FRONTWALL,
    GROUND,
    APPLE,
    SNAKEBODY,
    FRONTHEAD,
    PWALL,
    PGROUND,
    PCOIN,
    MONSTER01,
    MONSTER02,
    MONSTER03,
    MONSTER04,
    GHAST,
    SIDEMONSTER01,
    SIDEMONSTER02,
    SIDEMONSTER03,
    SIDEMONSTER04,
    SIDEGHAST,
    CBODY,
    CFRONTHEAD,
    FIVEHP,
    FOURHP,
    THREEHP,
    TWOHP,
    ONEHP,
    FRAMEONE,
    FRAMETWO,
    FRAMETHREE,
    CSHIP
  };

enum		e_form
  {
    TRIANGLE = 0,
    CUBE,
    SPHERE
  };

enum		e_direction
  {
    NORTH = 0,
    EAST,
    SOUTH,
    WEST
  };

class		LibOGL : public ILib
{
 public:
  LibOGL();
  ~LibOGL();
  LibOGL	&operator=(LibOGL const &);
  LibOGL(LibOGL const &);

  int					init();
  int					print(Game *const game) const;
  unsigned int				getEvent(unsigned int) const;
  int					playSound(e_sound);
  int					end();
  void					printMenu(Menu * const) const;
  void					display_intro(int *, int *, Menu * const) const;
  char					getChar() const;
  int					chooseGame(Menu * const) const;
  int					chooseLib(Menu * const) const;

  SDL_Surface				*getSurface() const;
  std::map<e_sound, Mix_Chunk *>	getSounds() const;
  Mix_Music				*getPMusic() const;
  Mix_Music				*getSMusic() const;
  std::map<e_textures, GLuint>		getTextures() const;

  int					initTexturesSnake();
  int					initTexturesPacman();
  int					initTexturesCentipede();
  void					globalSceneSnake(Game const *) const;
  void					globalScenePacman(Game const *) const;
  void					globalSceneCentipede(Game const *) const;

  void					emptySnake(double, double) const;
  void					blockSnake(double, double) const;
  void					foodSnake(double, double) const;
  void					headSnake(double, double, Game const *) const;
  void					bodySnake(double, double, Game const *) const;
  void					tailSnake(double, double, Game const *) const;

  void					smoothPos(double *, double *, int, Game const *) const;
  void					disappearPacman(double, double, unsigned int, Game const *) const;
  void					smoothEntities(double *, double *, int, Game const *) const;
  void					smoothCam(double *, double *, int, Game const *) const;
  void					drawGround(double, double) const;
  void					emptyPacman(double, double) const;
  void					blockPacman(double, double) const;
  void					foodPacman(double, double) const;
  void					powPacman(double, double) const;
  void					headPacman(double, double, unsigned int, Game const *) const;
  void					redPacman(double, double, unsigned int, Game const *) const;
  void					pinkPacman(double, double, unsigned int, Game const *) const;
  void					yellowPacman(double, double, unsigned int, Game const *) const;
  void					bluePacman(double, double, unsigned int, Game const *) const;
  void				        ghosts(double, double, unsigned int, Game const *) const;
  int					pacmanBlocked(int, int, Game const *) const;
  int					isBlocked(int, int, Game const *) const;

  void					spaceShip(double, double, int) const;
  void					emptyCentipede(double, double) const;
  void					blockCentipede(double, double) const;
  void					shotCentipede(double, double) const;
  void					headCentipede(double, double, std::vector<Entity *>) const;
  void					bodyCentipede(double, double, std::vector<Entity *>) const;
  void					tailCentipede(double, double, std::vector<Entity *>) const;
  void					obstacleCentipede(int, double, double) const;
 private:
  SDL_Surface				*_window;
  std::map<e_sound, Mix_Chunk *>	_sounds;
  Mix_Music				*_pacmanMusic;
  Mix_Music				*_snakeMusic;
  std::map<e_textures, GLuint>		_textures;
  bool					_init;
};

/* -- staticGetters.cpp -- */
int	getDirection(int);
int	musicOn(int);

#endif /* LIBOGL_H_ */
