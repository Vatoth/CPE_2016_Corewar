/*
** parse_instruction.c for asm in /home/Vatoth/Epitech/CPE_2016_corewar
** 
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Sat Apr  1 17:54:29 2017 Quentin Sonnefraud
** Last update Mon Apr  3 18:57:12 2017 Quentin Sonnefraud
*/

#include "op.h"
#include "my_str_to_wordtab.h"
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

static int	my_strspace(const char *s)
{
  int		i;

  i = 0;
  while (s[i] && s[i] != ' ')
    i++;
  return (i);
}

static char	**tab_space(const char *s)
{
  int	i;
  int	j;
  int	save;
  char	**tab;

  if (!(tab = malloc(sizeof(char *) * 3)))
    return (NULL);
  i = my_strspace(s);
  if (!s[i])
    return (NULL);
  j = ++i;
  if (!(tab[0] = malloc(sizeof(char) * i + 1)) ||
      !(tab[1] = malloc(sizeof(char) * my_strlen(&s[j]) + 1)))
    return (NULL);
  j = my_strlen(s);
  save = i--;
  tab[0] = my_memset(tab[0], 0, i + 1);
  tab[1] = my_memset(tab[1], 0,  my_strlen(&s[i + 1]) + 1);
  while (i-- > 0)
    tab[0][i] = s[i];
  while (j-- > save)
    tab[1][j - save] = s[j];
  tab[2] = NULL;
  return (tab);
}

char    **parse_instruction(const char *s)
{
  int   i;
  char  **instruct;

  if ((instruct = tab_space(s)) == NULL)
    return (NULL);
  i = 0;
  if (instruct[0] != NULL)
    {
      while (i < 16)
        {
          if (my_strcmp(instruct[0], op_tab[i].mnemonique) == 0)
            return (instruct);
          i++;
        }
    }
  my_puterror("ERROR : UNKNOW INSTRUCTION");
  return (NULL);
}
