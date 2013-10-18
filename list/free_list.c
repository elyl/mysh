#include <stdlib.h>
#include "../mysh.h"

void free_list(t_list *list)
{
  t_list	*last;

  while (list != NULL)
    {
      free(list->value);
      last = list;
      list = list->next;
      free(last);
    }
}
