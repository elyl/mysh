#include <string.h>
#include "../mysh.h"

void run_com(t_list *list, t_list *env)
{
  if (strcmp(list->value, "cd") == 0)
    cd(list, env);
  else if (strcmp(list->value, "env") == 0)
    aff_list(env);
  else if (strcmp(list->value, "clear") == 0)
    clear();
}
