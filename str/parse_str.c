#include <stdlib.h>
#include <string.h>
#include "../mysh.h"

t_com	*parse_str(char *str)
{
  int		i;
  int		l;
  char		buffer[255];
  t_com		*com;
  t_com		*current;

  i = 0;
  com = new_com_elem();
  current = com;
  l = 0;
  while (str[i])
    {
      if (str[i] == '|')
	{
	  current->next = new_com_elem();
	  current->op |= OP_PIPE;
	  current = current->next;
	}
      else if (str[i] == ' ' && l != 0)
	{
	  strncpy(&buffer[0], &str[i - l], l);
	  buffer[l] = '\0';
	  add_to_list(&buffer[0], current->com);
	  l = 0;
	}
      else if (str[i] != ' ')
	++l;
      ++i;
    }
  if (l != 0)
    {
      strncpy(&buffer[0], &str[i - l], l);
      buffer[l] = '\0';
      add_to_list(&buffer[0], current->com);
    }
  return (com);
}
