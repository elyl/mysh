#include <stdio.h>
#include "../mysh.h"

void aff_list(t_list *list)
{
  while (list != NULL)
    {
      printf("%s\n", list->value);
      list = list->next;
    }
}
