#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../mysh.h"

void cd(t_com *com, t_list *env)
{
  /*  char		tmp[255];
  char		*tmp2;
  struct stat	buf;

  list = list->next;
  if (list == NULL)
    {
      change_in_list(get_from_list("OLDPWD", env), get_from_list("PWD", env)->value);
      change_in_list(get_from_list("PWD", env), get_from_list("HOME", env)->value);
    }
  else if (strcmp(list->value, "-") == 0)
    {
      strcpy(&tmp[0], get_from_list("PWD", env)->value);
      change_in_list(get_from_list("PWD", env), get_from_list("OLDPWD", env)->value);
      change_in_list(get_from_list("OLDPWD", env), &tmp[0]);
    }
  else if (strcmp(list->value, "..") == 0)
    {
      *strrchr(get_from_list("PWD", env)->value, '/') = '\0';
    }
  else if (strcmp(list->value, ".") == 0)
    list = list;
  else
    {
      if (stat(list->value, &buf) != -1 && buf.st_mode & S_IFDIR)
	{
	  change_in_list(get_from_list("OLDPWD", env), get_from_list("PWD", env)->value);
	  change_str_in_list(get_from_list("PWD", env), list->value);
	}
    }
  tmp2 = strchr(get_from_list("PWD", env)->value, '=');
  tmp2++;
  printf("Directory changed to %s.\n", tmp2);*/
}
