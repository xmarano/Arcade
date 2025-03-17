##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

NAME_LIB	=	libfoo.so \
				libarc.so

NAME_MAIN	=	jeu

SRC	=	libfoo.cpp	\
		libarc.cpp

all:
	g++ -shared -o libarc.so -fPIC libarc.cpp -L. -larc
	g++ -shared -o libfoo.so -fPIC libfoo.cpp -L. -lfoo
	g++ main.cpp -o $(NAME_MAIN) -ldl

clean:
	rm -f $(NAME_LIB)

fclean: clean
	rm -f $(NAME_MAIN)

re: fclean all
