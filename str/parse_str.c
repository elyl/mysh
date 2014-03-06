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
  com = malloc(sizeof(t_com));
  com->com = malloc(sizeof(t_list));
  com->op = OP_NULL;
  com->next = NULL;
  current = com;
  current->fd[0] = 0;
  current->fd[1] = 1;
  l = 0;
  while (str[i])
    {
      if (str[i] == '|')
	{
	  current->next = malloc(sizeof(t_com));
	  current->next->com = malloc(sizeof(t_list));
	  current->next->com->next = NULL;
	  current->op = OP_PIPE;
	  current= current->next;
	  current->fd[0] = 0;
	  current->fd[1] = 1;
	  current->next = NULL;
	}
      else if (str[i] == ' ' && l != 0)
	{
	  strncpy(&buffer[0], &str[i - l], l);
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
      add_to_list(&buffer[0], current->com);
    }
  return (com);
}
