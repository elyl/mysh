#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "../mysh.h"

void exec(char *tmp, t_com *com, t_list *env)
{
  int	pid;
  int	fd[2] = {0, 0};

  if (com->op & OP_PIPE)
    {
      pipe(fd);
      com->next->fd[0] = fd[0];
      com->next->fd[1] = fd[1];
    }
  if ((pid = fork()) == 0)
    {
      if (com->op & OP_PIPE)
	{
	  close(1);
	  close(fd[0]);
	  dup(fd[1]);
	}
      if (com->fd[0] != 0)
	{
	  close(0);
	  dup(com->fd[0]);
	}
      execve(tmp, list_to_tab(com->com), list_to_tab(env));
    }
  else if (pid != -1)
    {
      if (fd[1] != 0)
	close(fd[1]);
      if (com->fd[0] != 0)
	close(com->fd[0]);
      run_com(com->next, env);
      if (!(com->op & OP_BG) && com->next == NULL)
	waitpid(pid, NULL, 0);
    }
  else
    printf("An error occured while running the program\n");
}
