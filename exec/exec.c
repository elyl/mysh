#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "../mysh.h"

void exec(char *tmp, t_com *com, t_list *env)
{
  int	pid;
  int	fd[2] = {0, 0};
  char	**argv;
  char	**environ;

  if (com->op & OP_PIPE)
    {
      pipe(fd);
      com->next->fd[0] = fd[0];
      com->next->fd[1] = fd[1];
    }
  if ((pid = fork()) == 0)
    {
      printf("fd: %d %d\n", com->fd[0], com->fd[1]);
      if (com->op & OP_PIPE)
	{
	  printf("Closing : 1, %d; switching to: %d\n", fd[0], com->fd[1]);
	  close(1);
	  close(fd[0]);
	  dup(fd[1]);
	}
      if (com->fd[0] != 0)
	{
	  printf("Closing : 0, %d; switching to: %d\n", com->fd[1], com->fd[0]);
	  close(0);
	  close(com->fd[1]);
	  dup(com->fd[0]);
	}
      argv = list_to_tab(com->com);
      environ = list_to_tab(env);
      execve(tmp, argv, environ);
    }
  else if (pid != -1)
    {
      run_com(com->next, env);
      if (fd[0] != 0)
	{
	  close(fd[0]);
	  close(fd[1]);
	}
      if (!(com->op & OP_BG) && com->fd[0] == 0)
	wait(NULL);
    }
  else
    printf("An error occured while running the program\n");
}
