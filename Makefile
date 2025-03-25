##
## EPITECH PROJECT, 2024
## My_arc
## File description:
## Makefile
##

CXX	=	g++
CXXFLAGS	=	-std=c++17 -fPIC
LDFLAGS	=	-ldl
LIBS	=	-lSDL2

SRC_DIR	=	src
INC_DIR	=	include
LIB_DIR	=	lib

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

all: core games graphicals

core:
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/Core/Main.cpp -o Main.o
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/Core/DLLoader.cpp -o DLLoader.o
	$(CXX) Main.o DLLoader.o -o arcade $(LDFLAGS)

games:
	@for game in $(GAMES); do \
		$(CXX) $(CXXFLAGS) -I$(INC_DIR) -shared $(SRC_DIR)/Games/$$game/$$game.cpp -o $(LIB_DIR)/arcade_$$game.so; \
	done

graphicals:
	@for lib in $(LIBS_GRAPHIC); do \
		$(CXX) $(CXXFLAGS) -I$(INC_DIR) -shared $(SRC_DIR)/Libs/$$lib/$$lib.cpp -o $(LIB_DIR)/arcade_$$lib.so $(LIBS) $(LIBS_FLAGS); \
	done

clean:
	rm -f *.o arcade $(LIB_DIR)/*.so

fclean: clean
	rm -f $(LIB_DIR)/*.so
	rm -f *.so

re: fclean all
