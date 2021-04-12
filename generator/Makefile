##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## (name of the project)'s Makefile
##

CC	=	gcc
LD	=	$(CC)
RM	=	rm -f

INC_PATH	=	include/

NAME	=	generator

SRC	=	src/main.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I $(INC_PATH)
CFLAGS	+=	-pedantic
CFLAGS	+=	-g3
CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-Wno-long-long
CFLAGS	+=	-Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	$(LD) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
