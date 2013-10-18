#include <stdlib.h>
#include <string.h>
#include "../mysh.h"

t_list	*get_env(char **environ)
{
  int		i;
  t_list	*first;
  t_list	*env;

  i = 0;
  first = malloc(sizeof(t_list));
  env = first;
  while (environ[i])
    {
      if (i != 0)
	{
	  env->next = malloc(sizeof(t_list));
	  env = env->next;
	  env->next = NULL;
	}
      env->value = malloc((strlen(environ[i]) + 1) * sizeof(char));
      strcpy(env->value, environ[i]);
      i++;
    }
  return (first);
}
