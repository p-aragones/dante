##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## (name of the project)'s Makefile
##

NAME	=	generator

SRC	=	src/main.c	\
		src/check_args.c	\
		src/generator.c		\
		src/exp_map.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include/

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all