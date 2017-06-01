/*
** get_addr.c for CPE_2016_corewar in /home/nikola/delivery/CPE_2016_corewar
**
** Made by nikola.tomic@epitech.eu
** Login   <nikola@epitech.net>
**
** Started on  Fri Mar 31 19:33:22 2017 nikola.tomic@epitech.eu
** Last update Mon Apr 03 21:36:47 2017 nikola.tomic@epitech.eu
*/

#include "asm.h"
#include "op.h"

static int	my_verif(char *instruction)
{
  if (!instruction)
    return (1);
  if (my_strcmp(instruction, "ld") != 0 &&
      my_strcmp(instruction, "st") != 0 &&
      my_strcmp(instruction, "zjmp") != 0 &&
      my_strcmp(instruction, "ldi") != 0 &&
      my_strcmp(instruction, "sti") != 0 &&
      my_strcmp(instruction, "fork") != 0)
    return (0);
  return (1);
}

void		get_addr(t_list *list)
{
  t_parser	*ctrl;
  int		i;
  int		y;

  i = 0;
  ctrl = list->first;
  while (ctrl)
    {
      ctrl->addr_label = i;
      i++;
      if (my_strcmp(ctrl->instruction, "zjmp") != 0 &&
	  my_strcmp(ctrl->instruction, "lfork") != 0 &&
	  my_strcmp(ctrl->instruction, "fork") != 0 &&
	  my_strcmp(ctrl->instruction, "live") != 0)
	i++;
      y = -1;
      while (ctrl->param[++y])
	i += (ctrl->param[y][0] == 'r') ? 1 :
	  (ctrl->param[y][0] == DIRECT_CHAR &&
	   my_verif(ctrl->instruction) == 0) ?
	    DIR_SIZE : IND_SIZE;
      ctrl = ctrl->next;
    }
  list->prog_size += i;
}
