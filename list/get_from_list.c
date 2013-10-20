#include <stdlib.h>
#include <string.h>
#include "../mysh.h"

t_list	*get_from_list(const char *name, t_list *list)
{
  char	*tmp;

  tmp = malloc((strlen(name) + 2) * sizeof(char));
  strcpy(tmp, name);
  strcat(tmp, "=");
  while (list != NULL)
    {
      if (strncmp(list->value, tmp, strlen(name) + 1) == 0)
	{
	  free(tmp);
	  return (list);
	}
      list = list->next;
    }
  free(tmp);
  return (NULL);
}
