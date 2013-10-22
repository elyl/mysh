#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../mysh.h"

char	*check_file(char *name, t_list *env)
{
  char		*tmp;
  char		**path;
  struct stat	buf;
  int		i;

  i = 0;
  path = get_path(env);
  while (path[i] != NULL)
    {
      tmp = malloc((strlen(name) + strlen(path[i]) + 2) * sizeof(char));
      strcpy(tmp, path[i]);
      strcat(tmp, "/");
      strcat(tmp, name);
      if (stat(tmp, &buf) != -1 && buf.st_mode & S_IFREG)
	{
	  free_tab(path);
	  return (tmp);
	}
      free(tmp);
      i++;
    }
  free_tab(path);
  return ((stat(name, &buf) != -1 && buf.st_mode & S_IFREG) ? name : NULL);
}
