##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##
YELLOW  = $(shell tput setaf 3; tput bold)
GREEN   = $(shell tput setaf 2; tput bold)
RESET   = $(shell tput sgr0)

NAME	=	ncurses

SRC		=	main.cpp

FLAGS	=	-std=c++17 

all:
	g++ $(SRC) -o $(NAME) $(FLAGS) -lncurses

clean:
	rm -f lib/*.so

fclean: clean
	rm -f $(NAME)

re: fclean all
