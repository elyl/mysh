#include <stdlib.h>
#include "../mysh.h"

t_com	*new_com_elem()
{
  t_com	*st;

  if ((st = malloc(sizeof(t_com))) == NULL)
    return (NULL);
  if ((st->com = new_list_elem()) == NULL)
    {
      free(st);
      return (NULL);
    }
  st->next = NULL;
  st->op = OP_NULL;
  st->fd[0] = 0;
  st->fd[1] = 1;
  return (st);
}
