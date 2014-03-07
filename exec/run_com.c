#include <string.h>
#include <stdio.h>
#include "../mysh.h"

void run_com(t_com *com, t_list *env)
{
  char	*tmp;

  if (com == NULL || com->com->value == NULL)
    return;
  if (strcmp(com->com->value, "cd") == 0)
    cd(com, env);
  else if (strcmp(com->com->value, "env") == 0)
    aff_list(env);
  else if (strcmp(com->com->value, "clear") == 0)
    clear();
  else if (strcmp(com->com->value, "exit") == 0)
    quit(com, env);
  else if ((tmp = check_file(com->com->value, env)) != NULL)
    exec(tmp, com, env);
  else
    printf("No such file or directory\n");
}
