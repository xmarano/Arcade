##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

BINARY_NAME	=	arcade
SRC_MAIN	=	src/main.cpp
SRC_MENU	=	src/Menu.cpp

SRC_NCURSES	=	src/Ncurses/ncurses_setup.cpp
SRC_SDL2	=	src/Sdl2/sdl2_setup.cpp

CXXFLAGS	=	-std=c++17 -Wall -Wextra -Werror
LDFLAGS		=	-ldl -lncurses -lSDL2 -lSDL2_ttf

all: graphicals core

core:
	g++ $(CXXFLAGS) $(SRC_MAIN) $(SRC_MENU) -o $(BINARY_NAME) $(LDFLAGS)

graphicals:
	g++ -shared -fPIC $(SRC_NCURSES) -o lib/arcade_ncurses.so -lncurses
	g++ -shared -fPIC $(SRC_SDL2) -o lib/arcade_sdl2.so -lSDL2 -lSDL2_ttf
	export SDL_VIDEODRIVER=x11

clean:
	rm -f lib/*.so

fclean: clean
	rm -f $(BINARY_NAME)

re: fclean all
