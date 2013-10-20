NAME=	mysh
CC=	gcc
CFLAGS=	-W -Wall -g
SRC=	main.c				\
	mysh.c				\
	list/aff_list.c			\
	list/add_to_list.c		\
	list/get_from_list.c		\
	list/change_in_list.c		\
	list/change_str_in_list.c	\
	list/free_list.c 		\
	str/parse_str.c			\
	str/search_char.c		\
	env/get_env.c			\
	exec/run_com.c			\
	built_in/cd.c			\
	built_in/clear.c
OBJ=	$(SRC:.c=.o)
RM=	rm -fv

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean:
	@$(RM) $(OBJ)

re: fclean clean $(NAME)