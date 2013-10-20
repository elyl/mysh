#include <stdlib.h>
#include <string.h>
#include "../mysh.h"

void change_in_list(t_list *dest, char *new)
{
  char	*tmp;

  tmp = dest->value;
  new = strchr(new, '=');
  *strchr(tmp, '=') = '\0';
  dest->value = malloc((strlen(tmp) + strlen(new) + 1) * sizeof(char));
  strcpy(dest->value, tmp);
  strcat(dest->value, new);
  free(tmp);
}
