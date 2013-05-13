#include <stdio.h>
#include "../mysh.h"

void aff_env(t_env *env)
{
  while (env != NULL)
    {
      printf("%s\n", env->value);
      env = env->next;
    }
}
