##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

BINARY_NAME	=	arcade
SRC_MAIN	=	main.cpp

SRC_NCURSES	=	src/libarc.cpp
SRC_SDL2	=	src/libfoo.cpp

all: graphicals core

core:
	g++ main.cpp -o $(BINARY_NAME) -ldl

# games:

graphicals:
	g++ -shared -o arcade_ncurses.so -fPIC $(SRC_NCURSES)
	g++ -shared -o arcade_sdl2.so -fPIC $(SRC_SDL2)
	mv *.so lib/

clean:
	rm -f ./lib/*.so

fclean: clean
	rm -f $(BINARY_NAME)

re: fclean all
