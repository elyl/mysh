#include "../mysh.h"

int search_char(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] && str[i] != c)
    i++;
  return ((str[i]) ? i : -1);
}
