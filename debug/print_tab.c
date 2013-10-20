#include <stdio.h>
#include "../mysh.h"

void print_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    printf("%s\n", tab[i++]);
}
