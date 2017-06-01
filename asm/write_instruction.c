/*
** write_instruction.c for asm in /home/Vatoth/Epitech/CPE_2016_corewar
**
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Sat Apr  1 20:33:36 2017 Quentin Sonnefraud
** Last update Sun Apr  2 16:12:09 2017 Antoine
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "op.h"
#include "asm.h"

int	lend_to_bend(int nb)
{
  int		tmp;

  tmp = (nb & 255);
  nb &= ~255;
  nb |= ((nb & 4278190080) >> 24);
  nb &= ~4278190080;
  nb |= (tmp << 24);
  tmp = ((nb & 65280) >> 8);
  nb &= ~65280;
  nb |= ((nb & 16711680) >> 8);
  nb &= ~16711680;
  nb |= (tmp << 16);
  return (nb);
}

static int	write_instruction(int fd, t_list *cont, t_parser *instruction)
{
  char		opcode;
  char		coding_byte;
  int		i;

  if (!instruction)
    return (84);
  opcode = get_opcode(instruction->instruction);
  write(fd, &opcode, 1);
  if (opcode != 1 && opcode != 9 && opcode != 12 && opcode != 15)
    {
      coding_byte = get_coding_byte(instruction);
      write(fd, &coding_byte, 1);
    }
  i = -1;
  while (instruction->param[++i])
    get_param_value(fd, cont, instruction->param[i], instruction);
  return (0);
}

void		write_instructions(int fd, t_list *cont)
{
  t_parser	*tmp;

  tmp = cont->first;
  while (tmp)
    {
      write_instruction(fd, cont, tmp);
      tmp = tmp->next;
    }
}
