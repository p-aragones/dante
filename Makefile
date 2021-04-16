##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile of infinadd
##

NAME	=	dante

all:		$(NAME)

$(NAME):	make_lib $(OBJ)

make_lib:
		$(MAKE) -C	solver/
		$(MAKE)	-C	generator/

clean:
		rm -f $(OBJ)
		$(MAKE) clean -C solver/
		$(MAKE) clean -C generator/

fclean: 	clean
		rm -f $(NAME)
		$(MAKE) fclean -C solver/
		$(MAKE) fclean -C generator/

re:		fclean all
		$(MAKE) re -C solver/
		$(MAKE) re -C generator/
