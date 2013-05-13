NAME=	mysh
CC=	gcc
CFLAGS=	-W -Wall -g
SRC=	main.c		\
	mysh.c		\
	env/aff_env.c	\
	env/get_env.c	\
	env/free_env.c
OBJ=	$(SRC:.c=.o)
RM=	rm -fv

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean:
	@$(RM) $(OBJ)

re: fclean clean $(NAME)