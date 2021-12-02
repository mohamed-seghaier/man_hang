SRC	=	./src/main.c		\
		./utils/utils.c		\

OBJ	=	$(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

NAME	=	read

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc	$(FLAGS) -o	$(NAME)	$(OBJ)

superclean: fclean clean
		rm	-f	*~
		rm	-f	*#
		rm	-f	vgcore*

fclean:	clean
		rm	-f	$(NAME)

clean:	
		rm	-f	$(OBJ)

re:	superclean	all