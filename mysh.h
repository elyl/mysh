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

char	*epur_str(char *str);

t_list	*parse_str(char *str);
t_list	*get_env(char **env);
t_list	*add_to_list(char *value, t_list *list);

#endif
