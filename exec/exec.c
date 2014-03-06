#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "../mysh.h"

void exec(char *tmp, t_com *com, t_list *env)
{
  int	pid;
  int	fd[2];
  char	**argv;
  char	**environ;

  if (com->op == OP_PIPE)
    {
      pipe(fd);
      com->next->fd[0] = fd[0];
      com->next->fd[1] = fd[1];
      com->fd[1] = fd[1];
    }
  if ((pid = fork()) == 0)
    {
      if (com->op == OP_PIPE)
	close(fd[0]);
      if (com->op == OP_NULL)
	close(com->fd[1]);
      dup2(1, fd[1]);
      dup2(0, fd[0]);
      argv = list_to_tab(com->com);
      environ = list_to_tab(env);
      execve(tmp, argv, environ);
    }
  else if (pid != -1)
    {
      run_com(com->next, env);
      /*close(fd[0]);
      close(fd[1]);*/
      wait(NULL);
    }
  else
    printf("An error occured while running the program\n");
}
