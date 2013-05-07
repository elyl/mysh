NAME=	mysh
CC=	gcc
CFLAGS=	-W -Wall -g
SRC=	main.c
OBJ=	$(SRC:.c=.o)
RM=	rm -fv

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean:
	@$(RM) $(OBJ)

re: fclean clean $(NAME)