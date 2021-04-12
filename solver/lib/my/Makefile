##
## EPITECH PROJECT, 2020
## makefile
## File description:
## library makefile
##

NAME	=	libmy.a

RWILDCARD = $(foreach d,$(wildcard $1*),$(call RWILDCARD,$d/,$2) $(filter $(subst *,%,$2),$d))

SRC += $(call RWILDCARD,$(PATH_SRC),*.c)

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
