/*
** get_for_write.c for get_for_write.c in /home/homegan/projects/CPE_2016_corewar
**
** Made by Antoine
** Login   <antoine.le-du@epitech.eu>
**
** Started on  Sun Apr  2 16:05:30 2017 Antoine
** Last update Mon Apr 03 21:36:10 2017 nikola.tomic@epitech.eu
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "op.h"
#include "asm.h"

static t_op    op_tab[] =
  {
    {"live", 1, {T_DIR}, 1, 10, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
     "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
     "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
     "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
     "load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
     "store index"},
    {"fork", 1, {T_DIR}, 12, 800, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
     "long load index"},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    {"aff", 1, {T_REG}, 16, 2, "aff"},
    {NULL}
  };

char		get_opcode(char *instruction)
{
  int		i;

  i = 0;
  if (!instruction)
    return (0);
  while (i < 16 && my_strcmp(op_tab[i].mnemonique, instruction) != 0)
    i += 1;
  return (op_tab[i].code);
}

char		get_coding_byte(t_parser *instruction)
{
  char		coding_byte;
  int		shift;
  int		i;

  if (!instruction)
    return (0);
  shift = 6;
  coding_byte = 0;
  i = -1;
  while (shift >= 0 && instruction->param[++i])
    {
      coding_byte |= ((instruction->param[i][0] == 'r') ? 1 :
	  (instruction->param[i][0] == DIRECT_CHAR) ? 2 : 3) << shift;
      shift -= 2;
    }
  return (coding_byte);
}

int		get_lbl(t_parser *list, char *label, t_parser *instruction)
{
  t_parser	*tmp;

  tmp = list;
  while (tmp && my_strcmp(label, tmp->label) != 0)
    tmp = tmp->next;
  return ((tmp) ? tmp->addr_label - instruction->addr_label : 0);
}

int		get_param_value(int fd, t_list *cont, char *param,
				t_parser *instruction)
{
  int		value;

  if (!param)
    return (0);
  value = (my_strstr(param, ":")) ? get_lbl(cont->first,
	   my_strstr(param, ":") + 1, instruction) : my_getnbr(param);
  if (param[0] == 'r')
    write(fd, &value, 1);
  else if (param[0] == DIRECT_CHAR &&
	   my_strcmp(instruction->instruction, "ld") != 0 &&
	   my_strcmp(instruction->instruction, "st") != 0 &&
	   my_strcmp(instruction->instruction, "zjmp") != 0 &&
	   my_strcmp(instruction->instruction, "ldi") != 0 &&
	   my_strcmp(instruction->instruction, "sti") != 0 &&
	   my_strcmp(instruction->instruction, "fork") != 0)
    {
      value = lend_to_bend(value);
      write(fd, &value, DIR_SIZE);
    }
  else
    {
      value = (lend_to_bend(value << 8) >> 8);
      write(fd, &value, IND_SIZE);
    }
  return (value);
}
