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
				src/Game/Menu/Menu.cpp	\

SRC_NCURSES	=	src/Ncurses/ncurses_setup.cpp	\
				src/Ncurses/ncurses_general.cpp	\
				src/Game/Menu/Ncurses/nc_display.cpp

SRC_SDL2	=	src/Sdl2/sdl2_setup.cpp	\
				src/Sdl2/sdl2_general.cpp	\
				src/Game/Menu/Sdl2/sdl2_display.cpp	\

FLAGS	=	-std=c++17
LDFLAGS		=	-ldl -lncurses -lSDL2 -lSDL2_ttf
DARWIN_SDL2_FLAGS = -I/opt/homebrew/include/SDL2 -L/opt/homebrew/lib
DARWIN_SFML_FLAGS = -I/opt/homebrew/Cellar/csfml/2.6.1_1/include/ -L/opt/homebrew/Cellar/csfml/2.6.1_1/lib

UNAME	:=	$(shell uname -s)

all: graphicals core
	@echo "$(YELLOW)$(UNAME)$(RESET)"

core:
	@echo "$(GREEN)core$(RESET)"
ifeq ($(UNAME),Linux)
	g++ $(SRC_FILES) -o $(NAME) $(LDFLAGS) $(FLAGS) -I/usr/include/SDL2
else ifeq ($(UNAME),Darwin)
	g++ $(SRC_FILES) -o $(NAME) -ldl -lncurses -lSDL2 -lSDL2_ttf $(DARWIN_SDL2_FLAGS) $(FLAGS)
endif

graphicals: ncurses sdl2

ncurses:
	@echo "$(GREEN)ncurses$(RESET)"
ifeq ($(UNAME),Linux)
	g++ -shared -fPIC $(SRC_NCURSES) -o lib/arcade_ncurses.so -lncurses $(FLAGS)
else ifeq ($(UNAME),Darwin)
	g++ -shared -fPIC $(SRC_NCURSES) -o lib/arcade_ncurses.so -lncurses -lSDL2 $(DARWIN_SDL2_FLAGS) $(FLAGS)
endif

sdl2:
	@echo "$(GREEN)sdl2$(RESET)"
ifeq ($(UNAME),Linux)
	export SDL_VIDEODRIVER=x11
	g++ -shared -fPIC $(SRC_SDL2) -o lib/arcade_sdl2.so -lSDL2 -lSDL2_ttf $(FLAGS) -I/usr/include/SDL2
else ifeq ($(UNAME),Darwin)
	export SDL_VIDEODRIVER=x11
	g++ -shared -fPIC $(SRC_SDL2) -o lib/arcade_sdl2.so -lSDL2 -lSDL2_ttf $(DARWIN_SDL2_FLAGS) $(FLAGS)
endif

clean:
	rm -f lib/*.so

fclean: clean
	rm -f $(NAME)

re: fclean all
