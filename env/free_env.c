#include <stdlib.h>
#include "../mysh.h"

void free_env(t_env *env)
{
  t_env	*last;

  while (env != NULL)
    {
      free(env->value);
      last = env;
      env = env->next;
      free(last);
    }
}
