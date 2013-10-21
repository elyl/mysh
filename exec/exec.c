#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "../mysh.h"

void exec(char *tmp, t_list *list, t_list *env)
{
  int	pid;
  char	**argv;
  char	**environ;

  if ((pid = fork()) == 0)
    {
      argv = list_to_tab(list);
      environ = list_to_tab(env);
      execve(tmp, argv, environ);
    }
  else if (pid != -1)
    wait(NULL);
  else
    printf("An error occured while running the program\n");
}
