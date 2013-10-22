#include <stdlib.h>
#include "../mysh.h"

void free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    free(tab[i++]);
  free(tab[i]);
  free(tab);
}
