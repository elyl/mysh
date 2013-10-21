#ifndef __MYSH__
#define __MYSH__

#define READ_SIZE	255

typedef struct s_list
{
  char		*value;
  struct s_list	*next;
}	t_list;

void	mysh(t_list *env);
void	aff_list(t_list *list);
void	free_list(t_list *list);
void	run_com(t_list *list, t_list *env);
void	clear();
void	cd(t_list *com, t_list *env);
void	change_in_list(t_list *dest, char *new);
void	change_str_in_list(t_list *list, char *new);
void	exec(char *tmp, t_list *list, t_list *env);
void	quit(t_list *list, t_list *env);
void	free_tab(char **tab);

char	*epur_str(char *str);
char	*check_file(char *name, t_list *env);

char	**get_path(t_list *env);
char	**list_to_tab(t_list *list);

int	count_char(char *str, char c);

t_list	*parse_str(char *str);
t_list	*get_env(char **list);
t_list	*add_to_list(char *value, t_list *list);
t_list	*get_from_list(const char *name, t_list *list);

void	print_tab(char **tab);

#endif
