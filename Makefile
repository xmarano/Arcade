##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

BINARY_NAME	=	arcade
SRC_FILES	=	src/main.cpp	\
				src/Game/Menu/Menu.cpp	\

SRC_NCURSES	=	src/Ncurses/ncurses_setup.cpp	\
				src/Ncurses/ncurses_display.cpp

SRC_SDL2	=	src/Sdl2/sdl2_setup.cpp	\
				src/Sdl2/sdl2_display.cpp

FLAGS	=	-std=c++17
LDFLAGS		=	-ldl -lncurses -lSDL2 -lSDL2_ttf

all: graphicals core

core:
	g++ $(FLAGS) $(SRC_FILES) -o $(BINARY_NAME) $(LDFLAGS)

graphicals:
	g++ -shared -fPIC $(SRC_NCURSES) -o lib/arcade_ncurses.so -lncurses
	g++ -shared -fPIC $(SRC_SDL2) -o lib/arcade_sdl2.so -lSDL2 -lSDL2_ttf
	export SDL_VIDEODRIVER=x11

clean:
	rm -f lib/*.so

fclean: clean
	rm -f $(BINARY_NAME)

re: fclean all
