##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile of infinadd
##

NAME	=	solver

RWILDCARD = $(foreach d,$(wildcard $1*),$(call RWILDCARD,$d/,$2) $(filter $(subst *,%,$2),$d))

SRC += $(call RWILDCARD,$(PATH_SRC),*.c)

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include/

LDLIBS	=	-L./lib/ -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) -C lib/my
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDLIBS)

clean:
		rm -f $(OBJ)
		$(MAKE) clean -C lib/my/

fclean: 	clean
		rm -f $(NAME)
		$(MAKE) fclean -C lib/my

run_tests:

re:		fclean all
