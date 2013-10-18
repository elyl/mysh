#include <stdlib.h>
#include <string.h>
#include "../mysh.h"

t_list	*parse_str(char *str)
{
  int		i;
  int		l;
  char		buffer[255];
  t_list	*list;
  t_list	*first;

  i = 0;
  list = malloc(sizeof(t_list));
  list->value = NULL;
  first = list;
  l = 0;
  while (str[i])
    {
      if (str[i] == ' ')
	{
	  strncpy(&buffer[0], &str[l], i - l);
	  buffer[i - l] = '\0';
	  list = add_to_list(&buffer[0], list);
	  l = ++i;
	}
      i++;
    }
  add_to_list(strcpy(&buffer[0], &str[l]), list);
  return (first);
}
