/*
** help.c for help in /home/homegan/projects/CPE_2016_corewar/ASM
** 
** Made by Antoine
** Login   <antoine.le-du@epitech.eu>
** 
** Started on  Fri Mar 24 11:38:45 2017 Antoine
** Last update Sat Apr  1 16:54:57 2017 Quentin Sonnefraud
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"

void	help(void)
{
  my_printf("USAGE\n");
  my_printf("\t./asm file_name[.s]\n");
  my_printf("\nDESCRIPTION\n");
  my_printf("\tfile_name");
  my_printf("\tfile in assembly language to ");
  my_printf("be converted into file_name.cor, an\n");
  my_printf("\t\t\texecutable in the Virtual Machine).\n");
}
