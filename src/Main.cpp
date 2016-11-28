//
// main.cpp for Arcade in /home/wilmot_g/Rendu/cpp_arcade/leHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Mar 10 11:41:16 2016 guillaume wilmot
// Last update Sun Apr  3 18:20:37 2016 Nyrandone Noboud-Inpeng
//

#include <unistd.h>
#include "Arcade.hpp"

int		usage(int ac, char **av)
{
  if (ac != 2)
    {
      std::cerr << "Usage: " << av[0] << " ./lib/lib_arcade_sdl.so" << std::endl;
      return (-1);
    }
  if (access(av[1], X_OK) == -1)
    {
      std::cerr << "Wrong Library. Check the .lib file to see what library is available."
		<< std::endl;
      return (-1);
    }
  return (0);
}

int		main(int ac, char **av)
{
  Arcade	arcade;

  if (usage(ac, av) == -1)
    return (-1);
  return (arcade.start(av));
}
