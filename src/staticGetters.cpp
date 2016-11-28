//
// staticGetters.cpp for staticGetters in /home/noboud_n/cpp_arcade/nyrii/src
// 
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.net>
// 
// Started on  Sun Mar 13 16:04:25 2016 Nyrandone Noboud-Inpeng
// Last update Tue Mar 15 11:42:14 2016 Nyrandone Noboud-Inpeng
//

#include "LibOGL.hpp"

Game		*getGame(Game const *game)
{
  static Game		*_game = NULL;

  if (game != NULL)
    _game = const_cast<Game *>(game);
  return (_game);
}

int		musicOn(int putMusicOn)
{
  static int	music = 0;

  if (putMusicOn != -1)
    music = putMusicOn;
  return (music);
}
