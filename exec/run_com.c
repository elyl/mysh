#include <string.h>
#include <stdio.h>
#include "../mysh.h"

void run_com(t_list *list, t_list *env)
{
  char	*tmp;

  if (strcmp(list->value, "cd") == 0)
    cd(list, env);
  else if (strcmp(list->value, "env") == 0)
    aff_list(env);
  else if (strcmp(list->value, "clear") == 0)
    clear();
  else if (strcmp(list->value, "exit") == 0)
    quit(list, env);
  else if ((tmp = check_file(list->value, env)) != NULL)
    {
      exec(tmp, list, env);
      printf("%s\n", tmp);
    }
  else
    printf("No such file or directory\n");
}
