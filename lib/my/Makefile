##
## EPITECH PROJECT, 2020
## Day10Task01
## File description:
## makefile
##

CC		= gcc

SRC		= $(wildcard *.c)

OBJ		= $(SRC:.c=.o)

NAME		= libmy.a

FLAGS		= -W -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp -f $(NAME) ../
		cp my.h ../../include/my.h
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all