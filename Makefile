##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

YELLOW  = $(shell tput setaf 3; tput bold)
GREEN   = $(shell tput setaf 2; tput bold)
RESET   = $(shell tput sgr0)

NAME	=	arcade

SRC_FILES	=	src/main.cpp	\
				src/Menu/Menu.cpp	\
				src/DLLoader.cpp	\
				src/Launcher.cpp	\

SRC_NCURSES	=	src/Ncurses/ncurses_setup.cpp	\
				src/Ncurses/ncurses_general.cpp	\
				src/Menu/Ncurses/nc_menu.cpp	\
				src/Game/Pacman/Ncurses/nc_pacman.cpp	\
				src/Game/Snake/Ncurses/nc_snake.cpp	\

SRC_SDL2	=	src/Sdl2/sdl2_setup.cpp	\
				src/Sdl2/sdl2_general.cpp	\
				src/Menu/Sdl2/sdl2_menu.cpp	\
				src/Game/Pacman/Sdl2/sdl2_pacman.cpp	\
				src/Game/Snake/Sdl2/sdl2_snake.cpp	\

SRC_SFML	=	src/Sfml/sfml_setup.cpp	\
				src/Sfml/sfml_general.cpp	\
				src/Menu/Sfml/sfml_menu.cpp	\
				src/Game/Pacman/Sfml/sfml_pacman.cpp	\
				src/Game/Snake/Sfml/sfml_snake.cpp	\

SRC_PACMAN	=	src/Game/Pacman/Pacman.cpp
SRC_SNAKE	+=	src/Game/Snake/Snake.cpp

FLAGS	=	-std=c++17
LDFLAGS		=	-ldl -lncurses -lSDL2 -lSDL2_ttf
DARWIN_SDL2_FLAGS = -I/opt/homebrew/include/SDL2 -L/opt/homebrew/lib
DARWIN_SFML_FLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib

UNAME	:=	$(shell uname -s)

ifeq ($(UNAME),Darwin)
    FLAGS += -w
endif

all: graphicals core
	@echo "$(YELLOW)$(UNAME)$(RESET)"

core:
	@echo "$(GREEN)core$(RESET)"
ifeq ($(UNAME),Linux)
	g++ $(SRC_FILES) -o $(NAME) $(LDFLAGS) $(FLAGS) -I/usr/include/SDL2
else ifeq ($(UNAME),Darwin)
	g++ $(SRC_FILES) -o $(NAME) -ldl -lncurses -lSDL2 -lSDL2_ttf $(DARWIN_SDL2_FLAGS) $(FLAGS)
endif

graphicals: ncurses sdl2 sfml pacman snake

ncurses:
	@echo "$(GREEN)ncurses$(RESET)"
ifeq ($(UNAME),Linux)
	g++ -shared -fPIC $(SRC_NCURSES) -o lib/arcade_ncurses.so -lncurses $(FLAGS) -I/usr/include/SDL2
else ifeq ($(UNAME),Darwin)
	g++ -shared -fPIC $(SRC_NCURSES) -o lib/arcade_ncurses.so -lncurses -lSDL2 $(DARWIN_SDL2_FLAGS) $(FLAGS)
endif

sdl2:
	@echo "$(GREEN)sdl2$(RESET)"
ifeq ($(UNAME),Linux)
	g++ -shared -fPIC $(SRC_SDL2) -o lib/arcade_sdl2.so -lSDL2 -lSDL2_ttf $(FLAGS) -I/usr/include/SDL2
else ifeq ($(UNAME),Darwin)
	g++ -shared -fPIC $(SRC_SDL2) -o lib/arcade_sdl2.so -lSDL2 -lSDL2_ttf $(DARWIN_SDL2_FLAGS) $(FLAGS)
endif

sfml:
	@echo "$(GREEN)sfml$(RESET)"
ifeq ($(UNAME),Linux)
	g++ -shared -fPIC $(SRC_SFML) -o lib/arcade_sfml.so -lsfml-graphics -lsfml-window -lsfml-system $(FLAGS) -I/usr/include/SDL2
else ifeq ($(UNAME),Darwin)
	g++ -shared -fPIC $(SRC_SFML) -o lib/arcade_sfml.so -lsfml-graphics -lsfml-window -lsfml-system $(FLAGS) $(DARWIN_SDL2_FLAGS) $(DARWIN_SFML_FLAGS)
endif

pacman:
	@echo "$(GREEN)pacman$(RESET)"
ifeq ($(UNAME),Linux)
	g++ -shared -fPIC $(SRC_PACMAN) -o lib/arcade_pacman.so -lncurses -lSDL2 -lSDL2_ttf $(FLAGS) -I/usr/include/SDL2
else ifeq ($(UNAME),Darwin)
	g++ -shared -fPIC $(SRC_PACMAN) -o lib/arcade_pacman.so -lncurses -lSDL2 -lSDL2_ttf $(DARWIN_SDL2_FLAGS) $(FLAGS)
endif

snake:
	@echo "$(GREEN)snake$(RESET)"
ifeq ($(UNAME),Linux)
	g++ -shared -fPIC $(SRC_SNAKE) -o lib/arcade_snake.so -lncurses -lSDL2 -lSDL2_ttf $(FLAGS) -I/usr/include/SDL2
else ifeq ($(UNAME),Darwin)
	g++ -shared -fPIC $(SRC_SNAKE) -o lib/arcade_snake.so -lncurses -lSDL2 -lSDL2_ttf $(DARWIN_SDL2_FLAGS) $(FLAGS)
endif

clean:
	rm -f lib/*.so

fclean: clean
	rm -f $(NAME)

re: fclean all

unitest: re
	./arcade unitest
