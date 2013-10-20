#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include "../mysh.h"

char	**get_path(t_list *env)
{
  char	*base;
  char	**path;
  char	*tmp;
  int	nb;
  int	i;

  i = 0;
  base = strchr(get_from_list("PATH", env)->value, '=');
  base++;
  nb = count_char(base, ':');
  path = malloc((nb + 1) * sizeof(char*));
  path[nb] = NULL;
  while (i < nb)
    {
      tmp = strchrnul(base, ':');
      path[i] = malloc((strlen(base) - strlen(tmp) + 2) * sizeof(char));
      *tmp = '\0';
      strcpy(path[i], base);
      base = tmp++;
      i++;
    }
  return (path);
}
