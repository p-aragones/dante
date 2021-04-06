##
## EPITECH PROJECT, 2020
## makefile
## File description:
## library makefile
##

NAME	=	libmy.a

SRC	=	src/my_getnbr.c					\
		src/my_putchar.c				\
		src/my_put_nbr.c				\
		src/my_putstr.c					\
		src/my_strcat.c					\
		src/my_strcmp.c					\
		src/my_str_isalpha.c			\
		src/my_str_isnum.c				\
		src/my_strlen.c					\
		src/my_strdup.c					\
		src/my_malloc.c					\
		src/split_func.c 				\
		src/my_split.c 					\

CFLAGS	+=	-I./include/ -pedantic

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../$(NAME)
		cp include/utils.h ../../include/.

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)
		rm -rf ../$(NAME)

re:		fclean all
