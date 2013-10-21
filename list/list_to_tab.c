#include <stdlib.h>
#include <string.h>
#include "../mysh.h"

char **list_to_tab(t_list *list)
{
  char		**tab;
  int		n;
  t_list	*tmp;

  n = 0;
  tmp = list;
  while (tmp != NULL)
    {
      n++;
      tmp = tmp->next;
    }
  tab = malloc((n + 1) * sizeof(char*));
  tab[n] = NULL;
  n = 0;
  while (list != NULL)
    {
      tab[n] = malloc((strlen(list->value) + 1) * sizeof(char));
      strcpy(tab[n], list->value);
      n++;
      list = list->next;
    }
  return (tab);
}
