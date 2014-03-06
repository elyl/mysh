#include <stdlib.h>
#include "../mysh.h"

void quit(t_com *com, t_list *env)
{
  //free_list(list);
  free_list(env);
  exit(EXIT_SUCCESS);
}
