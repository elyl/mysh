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
	list/list_to_tab.c		\
	list/free_tab.c			\
	list/new_list_elem.c		\
	list/new_com_elem.c		\
	str/parse_str.c			\
	str/count_char.c		\
	str/clean_string.c		\
	env/get_env.c			\
	env/get_path.c			\
	exec/exec.c			\
	exec/check_file.c		\
	exec/run_com.c			\
	built_in/cd.c			\
	built_in/quit.c			\
	built_in/clear.c		\
	debug/print_tab.c
OBJ=	$(SRC:.c=.o)
RM=	rm -fv

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean:
	@$(RM) $(NAME)

re: fclean clean $(NAME)