##
## EPITECH PROJECT, 2023
## hangman
## File description:
## Makefile
##

SRC := $(wildcard src/*.c)

NAME = hangman

all: $(NAME)

$(LIBNAME):
	$(MAKE) -C src/lib

$(NAME):
	gcc $(SRC) -o $(NAME) -g3

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
