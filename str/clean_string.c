#include <string.h>
#include <stdio.h>
#include "../mysh.h"

char *clean_string(char *str)
{
  int	i;
  int	n;
  int	f;

  i = 0;
  f = 0;
  n = 0;
  while (str[i] || n != 0)
    {
      if (str[i] == '"')
	f ^= 1;
      if (str[i] == ' ' && ((i > 0 && str[i - 1] == ' ') || i == 0) && f == 0)
	{
	  ++n;
	}
      else if (str[i] != ' ' && n != 0)
	{
	  strcpy(&str[i - n], &str[i]);
	  i -= n;
	  n = 0;
	}
      ++i;
    }
  return (str);
}
