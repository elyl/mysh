#include <stdlib.h>
#include <string.h>
#include "../mysh.h"

t_env	*get_env(char **environ)
{
  int	i;
  t_env	*first;
  t_env	*env;

  i = 0;
  first = malloc(sizeof(t_env));
  env = first;
  while (environ[i])
    {
      if (i != 0)
	{
	  env->next = malloc(sizeof(t_env));
	  env = env->next;
	  env->next = NULL;
	}
      env->value = malloc((strlen(environ[i]) + 1) * sizeof(char));
      strcpy(env->value, environ[i]);
      i++;
    }
  return (first);
}
