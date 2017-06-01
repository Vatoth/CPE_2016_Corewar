/*
** clear_file.c for asm in /home/Vatoth/Epitech/CPE_2016_corewar
** 
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Sat Apr  1 17:11:20 2017 Quentin Sonnefraud
** Last update Mon Apr  3 17:55:36 2017 Quentin Sonnefraud
*/

#include "op.h"

static void    delete_comment(char *str)
{
  int   i;

  i = 0;
  while (str[i] && str[i] != COMMENT_CHAR)
    {
      i++;
    }
  while (str[i])
    str[i++] = '\0';
}

void    epur_str(char *str)
{
  int   i;
  int   j;

  delete_comment(str);
  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
        {
          str[j++] = str[i];
          if (str[i + 1] != '\0' && (str[i + 1] == ' ' || str[i + 1] == '\t'))
            str[j++] = ' ';
        }
      i++;
    }
  if (j != 0 && (str[j - 1] == ' ' || str[j - 1] == '\t'))
    str[j - 1] = '\0';
  str[j] = '\0';
}

void    clear_space(char *str)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
        {
          str[j++] = str[i];
          if (str[i + 1] != '\0' && (str[i + 1] == ' ' || str[i + 1] == '\t'))
            str[j++] = ' ';
        }
      i++;
    }
  if (j != 0 && (str[j - 1] == ' ' || str[j - 1] == '\t'))
    str[j - 1] = '\0';
  str[j] = '\0';
}
