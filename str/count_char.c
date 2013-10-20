#include "../mysh.h"

int count_char(char *str, char c)
{
  int	i;
  int	t;

  i = 0;
  t = 0;
  while (str[i])
    if (str[i++] == c)
      t++;
  return (t);
}
