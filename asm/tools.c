/*
** tools.c for asm in /home/Vatoth/Epitech/CPE_2016_corewar/ASM
**
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Wed Mar 22 13:55:03 2017 Quentin Sonnefraud
** Last update Mon Apr  3 18:55:00 2017 Quentin Sonnefraud
*/

#include <stdlib.h>
#include "asm.h"
#include <stdio.h>

int     my_strcmp(const char *s1, const char *s2)
{
  int   character;

  if (!s1 || !s2)
    return ((s1) ? 1 : (s2) ? -1 : 0);
  character = 0;
  while (s1[character] == s2[character] && s1[character] && s2[character])
    character = character + 1;
  if (s1[character] > s2[character])
    return (1);
  else if (s1[character] < s2[character])
    return (-1);
  else
    return (0);
}

char    *my_strdup(const char *src)
{
  char  *dest;
  int   i;
  int   n;

  i = 0;
  n = my_strlen(src);
  if ((dest = malloc(sizeof(char) * (n + 1))) == NULL)
    return (NULL);
  while (i < n)
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}

int     my_compare(const char *s1, const char *s2, int i)
{
  while (i > 0 && *s1)
    {
      s1++;
      s2++;
      i--;
    }
  if (*s1 != *s2)
    return (1);
  return (0);
}

char	count_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      epur_str(tab[i]);
      i++;
    }
  return ((char) i);
}

void    *my_memset(void *str, const int c, size_t n)
{
  char  *d;

  d = str;
  while (n > 0)
    {
      *d++ = c;
      n--;
    }
  return (str);
}
