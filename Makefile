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
			Snake

LIBS_GRAPHIC	=	ncurses	\
					sdl2	\
					sfml

LIBS_FLAGS	=	-lncurses	\
				-lSDL2	\
				-lSDL2_ttf	\
				-lsfml-graphics	\
				-lsfml-window	\
				-lsfml-system

FLAGS	=	-std=c++17 -fPIC
DARWIN_SDL2_FLAGS = -I/opt/homebrew/include/SDL2 -L/opt/homebrew/lib
DARWIN_SFML_FLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib

UNAME	:=	$(shell uname -s)

# ifeq ($(UNAME),Darwin)
#     FLAGS += -w
# endif

all: core games graphicals
	@echo "$(YELLOW)$(UNAME)$(RESET)"

core:
	@echo "$(GREEN)core$(RESET)"
	g++ $(FLAGS) -Iinclude -c src/Core/Main.cpp -o Main.o
	g++ $(FLAGS) -Iinclude -c src/Core/Launcher.cpp -o Launcher.o
	g++ $(FLAGS) -Iinclude -c src/Core/DLLoader.cpp -o DLLoader.o
	g++ $(FLAGS) -Iinclude -c src/Core/Menu/Menu.cpp -o Menu.o
	g++ $(FLAGS) -Iinclude -c src/Core/Menu/ncurses/nc_menu.cpp -o nc_menu.o
	g++ $(FLAGS) -Iinclude -c src/Core/Menu/sfml/sfml_menu.cpp -o sfml_menu.o
	g++ $(FLAGS) -Iinclude -c src/Core/Menu/sdl2/sdl2_menu.cpp -o sdl2_menu.o
ifeq ($(UNAME),Darwin)
	g++ Main.o Launcher.o DLLoader.o nc_menu.o sfml_menu.o sdl2_menu.o Menu.o -o arcade -ldl $(DARWIN_SDL2_FLAGS) $(DARWIN_SDL2_FLAGS) $(LIBS_FLAGS)
else
	g++ Main.o Launcher.o DLLoader.o nc_menu.o sfml_menu.o sdl2_menu.o Menu.o -o arcade -ldl $(LIBS_FLAGS)
endif
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
ifeq ($(UNAME),Darwin)
	@for lib in $(LIBS_GRAPHIC); do \
		g++ $(FLAGS) -Iinclude -shared src/Libs/$$lib/$$lib.cpp src/Core/Menu/$$lib/*.cpp -o lib/arcade_$$lib.so $(DARWIN_SDL2_FLAGS) $(LIBS_FLAGS); \
	done
else
	@for lib in $(LIBS_GRAPHIC); do \
		g++ $(FLAGS) -Iinclude -shared src/Libs/$$lib/$$lib.cpp src/Core/Menu/$$lib/*.cpp -o lib/arcade_$$lib.so $(LIBS_FLAGS); \
	done
endif

clean:
	rm -f *.o arcade lib/*.so

fclean: clean
	rm -f lib/*.so
	rm -f *.so

re: fclean all

unitest: re
	./arcade unitest
