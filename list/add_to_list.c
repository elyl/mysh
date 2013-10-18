#include <stdlib.h>
#include <string.h>
#include "../mysh.h"

t_list *add_to_list(char *value, t_list *list)
{
  if (list == NULL)
    list = malloc(sizeof(t_list));
  else if (list->value != NULL)
    {
      while (list->next != NULL)
	list = list->next;
      list->next = malloc(sizeof(t_list));
      list = list->next;
    }
  list->next = NULL;
  list->value = malloc((strlen(value) + 1) * sizeof(char));
  strcpy(list->value, value);
  return (list);
}
