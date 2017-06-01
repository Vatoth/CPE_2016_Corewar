/*
** my_str_to_wordtab.h for tetris in /home/vatoth/PSU_2016_tetris/include
** 
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Fri Feb 24 19:57:50 2017 Vatoth
** Last update Sat Apr  1 17:57:25 2017 Quentin Sonnefraud
*/

#ifndef MY_STR_TO_WORDTAB_H_
# define MY_STR_TO_WORDTAB_H_

typedef struct  s_tab
{
  char          **array;
  int           nb;
  int           i;
  int           y;
  int           k;
}               t_tab;

char    **my_str_to_wordtab(const char *str, const char s);

#endif /* !MY_STR_TO_WORDTAB_H_ */
