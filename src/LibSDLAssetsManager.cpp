//
// Lib.cpp for cpp_arcade in /home/wilmot_g/Rendu/cpp_arcade/leHaineux/src
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Mar  9 16:55:49 2016 guillaume wilmot
// Last update Sun Apr  3 19:00:18 2016 guillaume wilmot
//

#include "LibSDL.hpp"

int		LibSDL::end()
{
  int		i;

  SDL_FreeSurface(_assets.pacman.gum);
  SDL_FreeSurface(_assets.pacman.bigGum);
  SDL_FreeSurface(_assets.pacman.dead);
  SDL_FreeSurface(_assets.pacman.dead2);
  SDL_FreeSurface(_assets.snake.food);
  for (i = 0; i < 8; i++)
    {
      SDL_FreeSurface(_assets.pacman.blue[i]);
      SDL_FreeSurface(_assets.pacman.red[i]);
      SDL_FreeSurface(_assets.pacman.pink[i]);
      SDL_FreeSurface(_assets.pacman.yellow[i]);
      SDL_FreeSurface(_assets.pacman.eyes[i]);
      if (i < 4)
	{
	  SDL_FreeSurface(_assets.pacman.pac[i]);
	  SDL_FreeSurface(_assets.snake.head[i]);
	  SDL_FreeSurface(_assets.snake.body[i]);
	  SDL_FreeSurface(_assets.snake.tail[i]);
	  SDL_FreeSurface(_assets.snake.corner[i]);
	}
      if (i < 3)
	SDL_FreeSurface(_assets.ship[i]);
    }
  Mix_FreeChunk(_assets.sounds.die);
  Mix_FreeChunk(_assets.sounds.wakaWaka);
  Mix_FreeChunk(_assets.sounds.snakeEats);
  Mix_FreeChunk(_assets.sounds.pacmanEats);
  Mix_FreeMusic(_assets.sounds.snakeMusic);
  Mix_FreeMusic(_assets.sounds.pacmanMusic);
  Mix_CloseAudio();
  TTF_CloseFont(_police);
  TTF_Quit();
  SDL_Quit();
  return (0);
}

int			LibSDL::loadSound(const std::string &path, Mix_Chunk **sound) const
{
  if ((*sound = Mix_LoadWAV(path.c_str())) == NULL)
    {
      std::cerr << "Could not load " << path << std::endl;
      return (-1);
    }
  return (0);
}

int			LibSDL::loadSounds()
{
  if ((loadSound("assets/pacman/sounds/die.wav", &_assets.sounds.die)) == -1 ||
      (loadSound("assets/pacman/sounds/pacmanEats.wav", &_assets.sounds.pacmanEats)) == -1 ||
      (loadSound("assets/pacman/sounds/pacmanMusic.wav", &_assets.sounds.wakaWaka)) == -1 ||
      (loadSound("assets/snake/sounds/snakeEats.wav", &_assets.sounds.snakeEats)) == -1)
    return (-1);
  if ((_assets.sounds.pacmanMusic = Mix_LoadMUS("assets/pacman/sounds/wakaWaka.wav")) == NULL)
    {
      std::cerr << "could not load assets/pacman/sounds/wakaWaka.wav" << std::endl;
      return (-1);
    }
  if ((_assets.sounds.snakeMusic = Mix_LoadMUS("assets/snake/sounds/SDLMusicSnake.wav")) == NULL)
    {
      std::cerr << "could not load assets/snake/sounds/snakeMusic.wav" << std::endl;
      return (-1);
    }
  return (1);
}

int			LibSDL::loadAssets()
{
  if ((loadTexture("assets/pacman/other/gum.png", &_assets.pacman.gum)) == -1 ||
      (loadTexture("assets/pacman/other/bigGum.png", &_assets.pacman.bigGum)) == -1 ||
      (loadTexture("assets/pacman/other/dead.png", &_assets.pacman.dead)) == -1 ||
      (loadTexture("assets/pacman/other/dead2.png", &_assets.pacman.dead2)) == -1 ||
      (loadTexture("assets/snake/food.png", &_assets.snake.food)) == -1)
    return (-1);
  if (getGif("assets/pacman/ghost/blue/000", _assets.pacman.blue, 8) == -1 ||
      getGif("assets/pacman/ghost/red/000", _assets.pacman.red, 8) == -1 ||
      getGif("assets/pacman/ghost/pink/000", _assets.pacman.pink, 8) == -1 ||
      getGif("assets/pacman/ghost/yellow/000", _assets.pacman.yellow, 8) == -1 ||
      getGif("assets/pacman/eyes/000", _assets.pacman.eyes, 8) == -1 ||
      getGif("assets/pacman/pac/000", _assets.pacman.pac, 4) == -1 ||
      getGif("assets/snake/body1/000", _assets.snake.body, 4) == -1 ||
      getGif("assets/snake/corner/000", _assets.snake.corner, 4) == -1 ||
      getGif("assets/snake/head/000", _assets.snake.head, 4) == -1 ||
      getGif("assets/snake/tail/000", _assets.snake.tail, 4) == -1 ||
      getGif("assets/centipede/ship/000", _assets.ship, 3) == -1)
    return (-1);
  if (loadSounds() == -1)
    return (-1);
  _sounds[DIE] = _assets.sounds.die;
  _sounds[SNAKEEATS] = _assets.sounds.snakeEats;
  _sounds[PACMANEATS] = _assets.sounds.pacmanEats;
  _sounds[WAKAWAKA] = _assets.sounds.wakaWaka;
  return (0);
}

int			LibSDL::loadTexture(const std::string &path, SDL_Surface **texture) const
{
  SDL_Surface		*tmp;
  SDL_Surface		*tmp2;

  if ((tmp = IMG_Load(path.c_str())) == NULL)
    {
      std::cerr << path.c_str() << " is missing" << std::endl;
      return (-1);
    }
  if ((*texture = SDL_DisplayFormatAlpha(tmp)) == NULL)
    return (-1);
  SDL_FreeSurface(tmp);
  if ((tmp2 = SDL_CreateRGBSurface(SDL_SWSURFACE, (*texture)->w, (*texture)->h, 32,
                                   (*texture)->format->Rmask,
                                   (*texture)->format->Gmask,
                                   (*texture)->format->Bmask,
                                   (*texture)->format->Amask)) == NULL)
    return (-1);
  if ((tmp = SDL_DisplayFormatAlpha(tmp2)) == NULL)
    return (-1);
  SDL_FreeSurface(tmp2);
  if ((SDL_SetAlpha(*texture, 0, (*texture)->format->alpha)) == -1)
    return (-1);
  if (SDL_BlitSurface(*texture, NULL, tmp, NULL) == -1)
    return (-1);
  SDL_FreeSurface(*texture);
  *texture = tmp;
  return (1);
}

int			LibSDL::getGif(std::string name, SDL_Surface **gif, int j) const
{
  int			i;
  SDL_Surface		*tmp_s;
  SDL_Surface		*tmp_s2;

  i = 0;
  name += ".png";
  while (i < j)
    {
      name[name.length() - 5] = (i % 10) + 48;
      name[name.length() - 6] = (i / 10) + 48;
      if ((tmp_s = IMG_Load(name.c_str())) == NULL)
        {
	  std::cerr << name.c_str() << " is missing" << std::endl;
          return (-1);
        }
      if ((gif[i] = SDL_DisplayFormatAlpha(tmp_s)) == NULL)
        return (-1);
      SDL_FreeSurface(tmp_s);
      if ((tmp_s2 = SDL_CreateRGBSurface(SDL_SWSURFACE, gif[i]->w, gif[i]->h, 32,
                                         gif[i]->format->Rmask,
                                         gif[i]->format->Gmask,
                                         gif[i]->format->Bmask,
                                         gif[i]->format->Amask)) == NULL)
        return (-1);
      if ((tmp_s = SDL_DisplayFormatAlpha(tmp_s2)) == NULL)
        return (-1);
      SDL_FreeSurface(tmp_s2);
      if (SDL_SetAlpha(gif[i], 0, gif[i]->format->alpha) == -1)
        return (-1);
      if (SDL_BlitSurface(gif[i], NULL, tmp_s, NULL) == -1)
        return (-1);
      SDL_FreeSurface(gif[i]);
      gif[i] = tmp_s;
      i++;
    }
  return (0);
}
