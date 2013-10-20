#include <stdlib.h>
#include <string.h>
#include "../mysh.h"

void change_str_in_list(t_list *dest, char *str)
{
  char	*tmp;
  int	len;

  tmp = dest->value;
  if (str[0] == '/')
    *strchr(tmp, '=') = '\0';
  dest->value = malloc((strlen(tmp) + strlen(str) + 2) * sizeof(char));
  strcpy(dest->value, tmp);
  if (str[0] == '/')
    strcat(dest->value, "=");
  else
    strcat(dest->value, "/");
  strcat(dest->value, str);
  free(tmp);
}
