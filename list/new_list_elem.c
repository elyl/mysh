#include <stdlib.h>
#include "../mysh.h"

t_list	*new_list_elem()
{
  t_list	*st;

  if ((st = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  st->next = NULL;
  st->value = NULL;
  return (st);
}
