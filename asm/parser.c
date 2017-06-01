/*
** parser.c for asm in /home/Vatoth/Epitech/CPE_2016_corewar/ASM
** 
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Wed Mar 29 16:43:51 2017 Quentin Sonnefraud
** Last update Mon Apr  3 18:54:36 2017 Quentin Sonnefraud
*/

#include <stdlib.h>
#include "asm.h"
#include "op.h"
#include "my_str_to_wordtab.h"

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

static int	check_reg(const char *param, const int index,
			  const int number)
{
  int	i;

  i = 1;
  if ((op_tab[index].type[number] & T_REG) == 0)
    {
      my_puterror("ERROR : REGISTER IS NOT WAIT HERE");
      return (1);
    }
  while (param[i])
    {
      if ((param[i] < '0' && param[i] > '9'))
	{
	  my_puterror("ERROR : UNKNOW CHAR FOR REGISTER");
	  return (1);
	}
      i++;
    }
  if (i != 1)
    return (0);
  return (1);
}

static int	check_direct(const char *param, const int index,
			     const int number, t_list *list)
{
  int	i;

  i = 1;
  if ((op_tab[index].type[number] & T_DIR) == 0)
    {
      my_puterror("ERROR : DIRECT IS NOT WAIT HERE");
      return (1);
    }
  while (param[i])
    {
      if (param[1] == ':')
	return ((label_exist(list, &param[2]) == 1) ? 1 : 0);
      if ((param[i] < '0' && param[i] > '9') && param[i] != '-')
	{
	  my_puterror("ERROR : UNKNOW CHAR FOR DIRECT");
	  return (1);
	}
      i++;
    }
  if (i != 1)
    return (0);
  return (1);
}

static int	check_indirect(const char *param,
			       const int index, const int number)
{
  int	i;

  i = 0;
  if ((op_tab[index].type[number] & T_IND) == 0)
    {
      my_puterror("ERROR : INDIRECT IS NOT WAIT HERE");
      return (1);
    }
  while (param[i])
    {
      if (param[i] < '0' && param[i] > '9')
	{
	  my_puterror("ERROR : UNKNOW CHAR FOR INDIRECT");
	  return (1);
	}
      i++;
    }
  return (0);
}

static int	check_all(char **param, const int index,
			  t_list *list)
{
  int	i;

  i = -1;
  while (param[++i])
    {
      if (param[i][0] == REGISTER_CHAR)
        {
          if (check_reg(param[i], index, i) == 1)
            return (1);
	}
      else if (param[i][0] == DIRECT_CHAR)
        {
          if (check_direct(param[i], index, i, list) == 1)
            return (1);
        }
      else
        if (check_indirect(param[i], index, i) == 1)
          return (1);
    }
  return (0);
}

char	**parse_param(const char *to_parse,
		      const char *instruct, t_list *list)
{
  char	**param;
  int	index;

  index = 0;
  while (index < 16)
    {
      if (my_strcmp(instruct, op_tab[index].mnemonique) == 0)
	break;
      index++;
    }
  if ((param = my_str_to_wordtab(to_parse, SEPARATOR_CHAR)) == NULL
      || (count_tab(param) != op_tab[index].nbr_args)
      || (check_all(param, index, list) == 1))
    return (NULL);
  return (param);
}
