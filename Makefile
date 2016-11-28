##
## Makefile for Makefile in /home/wilmot_g/Rendu/cpp_arcade2/leHaineux
##
## Made by guillaume wilmot
## Login   <wilmot_g@epitech.net>
##
## Started on  Sat Mar 12 16:42:46 2016 guillaume wilmot
## Last update Sun Apr  3 21:22:48 2016 Nyrandone Noboud-Inpeng
##

LIBSDL	= LibSDL.cpp			\
	  LibSDLDrawLine.cpp		\
	  LibSDLAssetsManager.cpp	\
	  Entity.cpp			\
	  Powerup.cpp

LIBCACA	= LibCaca.cpp			\
	  Powerup.cpp			\
	  Entity.cpp

LIBOGL	= LibOGL.cpp			\
	  staticGetters.cpp		\
	  OGLSmooth.cpp			\
	  OGLTextures.cpp		\
	  OGLSnake.cpp			\
	  OGLPacman.cpp			\
	  OGLCentipede.cpp		\
	  Entity.cpp			\
	  Powerup.cpp			\
	  Shot.cpp

LIBSNAKE = GameSnake.cpp		\
           Entity.cpp			\
	   Game.cpp			\
	   Snake.cpp			\
	   Powerup.cpp			\
	   Libraries.cpp

LIBPACMAN = GamePacman.cpp		\
	    GamePacmanPaths.cpp		\
	    Entity.cpp			\
	    Game.cpp			\
	    Powerup.cpp			\
	    Pacman.cpp			\
	    Libraries.cpp


LIBCENTIPEDE =	GameCentipede.cpp	\
	    	HeroCenti.cpp		\
	    	Entity.cpp		\
	    	Game.cpp		\
	    	Centipede.cpp		\
		Powerup.cpp		\
		Shot.cpp		\
		Libraries.cpp

SRC	= Main.cpp			\
	  Game.cpp			\
	  Entity.cpp			\
	  Arcade.cpp			\
	  Score.cpp			\
	  Menu.cpp			\
	  Libraries.cpp

OBJ	= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

OBJSDL	= $(addprefix $(OBJDIR), $(LIBSDL:.cpp=.o))

OBJCACA	= $(addprefix $(OBJDIR), $(LIBCACA:.cpp=.o))

OBJOGL	= $(addprefix $(OBJDIR), $(LIBOGL:.cpp=.o))

OBJSNAKE = $(addprefix $(OBJDIR), $(LIBSNAKE:.cpp=.o))

OBJPACMAN = $(addprefix $(OBJDIR), $(LIBPACMAN:.cpp=.o))

OBJCENTIPEDE = $(addprefix $(OBJDIR), $(LIBCENTIPEDE:.cpp=.o))

RM	= rm -f

CCX	= g++

NAME	= arcade

SDL	= $(addprefix $(LIBDIR), lib_arcade_sdl.so)

CACA	= $(addprefix $(LIBDIR), lib_arcade_caca.so)

OGL	= $(addprefix $(LIBDIR), lib_arcade_opengl.so)

SNAKE	= $(addprefix $(GAMEDIR), lib_arcade_snake.so)

PACMAN	= $(addprefix $(GAMEDIR), lib_arcade_pacman.so)

CENTIPEDE	= $(addprefix $(GAMEDIR), lib_arcade_centipede.so)

OBJDIR	= obj/

LIBDIR	= lib/

GAMEDIR	= games/

SRCDIR	= src/

INCDIR	= -I includes/ -I includes/SDL -I includes/CACA -I includes/OPENGL

MAKEOBJ	= obj

MAKELIB = lib

MAKEGAME = games

CXXFLAGS = -W -Wall -Wextra -Werror -fPIC -std=c++11 -rdynamic

all:
	@make --no-print-directory $(SNAKE)
	@make --no-print-directory $(PACMAN)
	@make --no-print-directory $(CENTIPEDE)
	@make --no-print-directory $(CACA)
	@make --no-print-directory $(SDL)
	@make --no-print-directory $(OGL)
	@make --no-print-directory $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(MAKEOBJ)
	@mkdir -p $(MAKELIB)
	@mkdir -p $(MAKEGAME)
	$(CCX) $(CXXFLAGS) -o $@ -c $< $(INCDIR)

$(NAME): $(OBJ)
	$(CCX) $(CXXFLAGS) -o $(NAME) $(OBJ) -ldl

$(SDL): $(OBJSDL)
	$(CCX) $(CXXFLAGS) -shared -o $(SDL) $(OBJSDL) -L./LIBS/SDL -lSDL -lSDL_image -lSDL_mixer -lSDL_gfx -lSDL_ttf -Wl,-rpath,./LIBS/SDL

$(CACA): $(OBJCACA)
	$(CCX) $(CXXFLAGS) -shared -o $(CACA) $(OBJCACA) LIBS/CACA/libcaca_pic.a -rdynamic -L/usr/lib64 -lX11 -lncurses

$(OGL): $(OBJOGL)
	$(CCX) $(CXXFLAGS) -shared -o $(OGL) $(OBJOGL) -L./LIBS/OPENGL/lib -lGLU -lGL -L./LIBS/OPENGL -lglut -L./LIBS/SDL -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -Wl,-rpath,./LIBS/SDL

$(SNAKE): $(OBJSNAKE)
	$(CCX) $(CXXFLAGS) -shared -o $(SNAKE) $(OBJSNAKE)

$(PACMAN): $(OBJPACMAN)
	$(CCX) $(CXXFLAGS) -shared -o $(PACMAN) $(OBJPACMAN)

$(CENTIPEDE): $(OBJCENTIPEDE)
	$(CCX) $(CXXFLAGS) -shared -o $(CENTIPEDE) $(OBJCENTIPEDE)

lib:
	@make --no-print-directory $(SNAKE)
	@make --no-print-directory $(PACMAN)
	@make --no-print-directory $(CENTIPEDE)
	@make --no-print-directory $(SDL)
	@make --no-print-directory $(CACA)
	@make --no-print-directory $(OGL)

pacman:
	@make --no-print-directory $(PACMAN)

centipede:
	@make --no-print-directory $(CENTIPEDE)

snake:
	@make --no-print-directory $(SNAKE)

sdl:
	@make --no-print-directory $(SDL)

opengl:
	@make --no-print-directory $(OPENGL)

caca:
	@make --no-print-directory $(CACA)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJSDL)
	$(RM) $(OBJCACA)
	$(RM) $(OBJOGL)
	$(RM) $(OBJSNAKE)
	$(RM) $(OBJPACMAN)
	$(RM) $(OBJCENTIPEDE)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(SDL)
	$(RM) $(CACA)
	$(RM) $(OGL)
	$(RM) $(SNAKE)
	$(RM) $(PACMAN)
	$(RM) $(CENTIPEDE)

re: fclean all
