#include <string.h>
#include "../mysh.h"

t_com	*check_op(t_com	*com)
{
  t_com	*n;
  int	len;

  n = com;
  while (n != NULL)
    {
      len = strlen(n->com->value);
      if (n->com->value[len - 1] == '&')
	{
	  n->com->value[len - 1] = '\0';
	  n->op |= OP_BG;
	}
      n = n->next;
    }
  return (com);
}
