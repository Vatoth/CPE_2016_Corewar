/*
** init_header.c for asm in /home/Vatoth/Epitech/CPE_2016_corewar
**
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Fri Mar 31 11:44:55 2017 Quentin Sonnefraud
** Last update Mon Apr  3 16:34:37 2017 Quentin Sonnefraud
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "op.h"
#include "asm.h"

int	take_name(const char *arg,
		  char header_name[PROG_NAME_LENGTH + 1])
{
  int		i;
  int		j;

  i = 0;
  while (arg[i] && arg[i] != '"')
    i++;
  header_name = my_memset(header_name, 0, PROG_NAME_LENGTH + 1);
  j = 0;
  while (arg[++i] && arg[i] != '"')
    {
      if ((PROG_NAME_LENGTH + 1) == j)
	return (1);
      header_name[j++] = arg[i];
    }
  if (arg[i] != '"')
    return (1);
  header_name[j] = '\0';
  return (0);
}

int	take_comment(const char *arg,
		     char header_comment[COMMENT_LENGTH + 1])
{
  int		i;
  int		j;

  i = 0;
  while (arg[i] && arg[i] != '"')
    i++;
  header_comment = my_memset(header_comment, 0, COMMENT_LENGTH + 1);
  j = 0;
  while (arg[++i] && arg[i] != '"')
    {
      if ((COMMENT_LENGTH + 1) == j)
	return (1);
      header_comment[j++] = arg[i];
    }
  if (arg[i] != '"')
    return (1);
  header_comment[j] = '\0';
  return (0);
}

int		init_header(t_header header_cor, int fd_output, int prog_size)
{
  header_cor.magic = COREWAR_EXEC_MAGIC;
  header_cor.prog_size = prog_size;
  header_cor.magic = lend_to_bend(header_cor.magic);
  header_cor.prog_size = lend_to_bend(header_cor.prog_size);
  write(fd_output, &header_cor, sizeof(header_cor));
  return (0);
}
