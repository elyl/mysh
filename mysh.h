#ifndef __MYSH__
#define __MYSH__

typedef struct s_env
{
  char		*value;
  struct s_env	*next;
}	t_env;

void	mysh(t_env *env);
void	aff_env(t_env * env);
void	free_env(t_env *env);

t_env	*get_env(char **env);

#endif
