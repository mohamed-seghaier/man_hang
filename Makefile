SRC	=	./src/main.c				\
		./src/errors_handler.c		\
		./src/game.c				\
		./utils/string.c			\
		./utils/inputs_f.c			\
		./utils/files_handler.c		\

OBJ	=	$(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -g

NAME	=	man_hang

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