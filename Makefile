## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##
YELLOW  = $(shell tput setaf 3; tput bold)
GREEN   = $(shell tput setaf 2; tput bold)
RESET   = $(shell tput sgr0)

NAME	=	arcade

GAMES	=	Pacman	\
			Menu

LIBS_GRAPHIC	=	ncurses	\
					sdl2	\
					sfml

LIBS_FLAGS	=	-lncurses	\
				-lSDL2	\
				-lsfml-graphics	\
				-lsfml-window	\
				-lsfml-system

FLAGS	=	-std=c++17 -fPIC
DARWIN_SDL2_FLAGS = -I/opt/homebrew/include/SDL2 -L/opt/homebrew/lib
DARWIN_SFML_FLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib

UNAME	:=	$(shell uname -s)

ifeq ($(UNAME),Darwin)
    FLAGS += -w
endif

all: core games graphicals
	@echo "$(YELLOW)$(UNAME)$(RESET)"

core:
	@echo "$(GREEN)core$(RESET)"
	g++ $(FLAGS) -Iinclude -c src/Core/Main.cpp -o Main.o
	g++ $(FLAGS) -Iinclude -c src/Core/DLLoader.cpp -o DLLoader.o
	g++ Main.o DLLoader.o -o arcade -ldl
	rm -f *.o

games:
	@echo "$(GREEN)games$(RESET)"
ifeq ($(UNAME),Darwin)
	@for game in $(GAMES); do \
		g++ $(FLAGS) -Iinclude -shared src/Games/$$game/$$game.cpp -o lib/arcade_$$game.so $(DARWIN_SDL2_FLAGS); \
	done
else
	@for game in $(GAMES); do \
		g++ $(FLAGS) -Iinclude -shared src/Games/$$game/$$game.cpp -o lib/arcade_$$game.so; \
	done
endif

graphicals:
	@echo "$(GREEN)graphicals$(RESET)"
	@for lib in $(LIBS_GRAPHIC); do \
		g++ $(FLAGS) -Iinclude -shared src/Libs/$$lib/$$lib.cpp -o lib/arcade_$$lib.so $(LIBS) $(LIBS_FLAGS); \
	done

clean:
	rm -f *.o arcade lib/*.so

fclean: clean
	rm -f lib/*.so
	rm -f *.so

re: fclean all
