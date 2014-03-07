#ifndef __MYSH__
#define __MYSH__

#define READ_SIZE	255

#define OP_NULL		0x00
#define OP_PIPE		0x01
#define OP_AND		0x02
#define OP_BG		0x04

typedef struct s_list
{
  char		*value;
  struct s_list	*next;
}	t_list;

typedef struct s_com
{
  t_list	*com;
  char		op;
  int		fd[2];
  struct s_com	*next;
}	t_com;

void	mysh(t_list *env);
void	aff_list(t_list *list);
void	free_list(t_list *list);
void	run_com(t_com *com, t_list *env);
void	clear();
void	cd(t_com *com, t_list *env);
void	change_in_list(t_list *dest, char *new);
void	change_str_in_list(t_list *list, char *new);
void	exec(char *tmp, t_com *com, t_list *env);
void	quit(t_com *com, t_list *env);
void	free_tab(char **tab);

char	*clean_string(char *str);
char	*check_file(char *name, t_list *env);

char	**get_path(t_list *env);
char	**list_to_tab(t_list *list);

int	count_char(char *str, char c);

t_list	*get_env(char **list);
t_list	*add_to_list(char *value, t_list *list);
t_list	*get_from_list(const char *name, t_list *list);
t_list	*new_list_elem();

t_com	*parse_str(char *str);
t_com	*new_com_elem();

void	print_tab(char **tab);

#endif
