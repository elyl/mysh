#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysh.h"

int	main(int argc, char **argv, char **env)
{
  t_list	*environ;

  environ = get_env(env);
  mysh(environ);
  free_list(environ);
}
