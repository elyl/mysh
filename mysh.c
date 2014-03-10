#include <unistd.h>
#include "mysh.h"

void mysh(t_list *env)
{
  char		com[READ_SIZE + 1];
  int		s;
  t_com		*st;

  write(1, "$>", 2);
  while ((s = read(0, &com, READ_SIZE)) != -1)
    {
      com[s - 1] = '\0';
      if (s > 1)
	{
	  st = parse_str(clean_string(&com[0]));
	  run_com(st, env);
	}
      write(1, "$>", 2);
    }
}
