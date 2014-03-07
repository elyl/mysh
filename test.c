#include <unistd.h>

int main(int agrc, char **argv)
{
  int	fd[2];
  int	pid;

  pipe(fd);
  if ((pid = fork()) == 0)
    {
      close(fd[0]);
      close(1);
      dup(fd[1]);
      execvp("ls", argv);
    }
  if ((pid = fork()) == 0)
    {
      close(fd[1]);
      close(0);
      dup(fd[0]);
      execvp("wc", argv);
    }
  close(fd[0]);
  close(fd[1]);
}
