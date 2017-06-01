/*
** main.c for asm in /home/Vatoth/Epitech/CPE_2016_corewar
** 
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Sat Apr  1 17:13:20 2017 Quentin Sonnefraud
** Last update Sat Apr  1 17:13:43 2017 Quentin Sonnefraud
*/

#include "asm.h"

int     main(int ac, char **av)
{
  int   output;

  if (ac != 2)
    {
      help();
      return (0);
    }
  else if ((my_strcmp(av[1], "-h")) == 0 ||
           (my_strcmp(av[1], "--help")) == 0)
    {
      help();
      return (0);
    }
  else
    output = redirect(av[1]);
  return (output);
}
