/*
** get_name.c for get_name in /home/homegan/projects/CPE_2016_corewar
** 
** Made by Antoine
** Login   <antoine.le-du@epitech.eu>
** 
** Started on  Sun Apr  2 15:36:20 2017 Antoine
** Last update Sun Apr  2 15:48:53 2017 Antoine
*/

#include <stdlib.h>
#include <unistd.h>

static int    len(const char *path)
{
  int	i;

  i = 0;
  while (path[i] != '\0')
    i++;
  return (i);
}

static int	count_name(const char *path)
{
  int	i;
  int	nb;

  nb = 0;
  i = len(path) - 1;
  while (i >= 0 && path[i] != '/')
    {
      nb ++;
      i--;
    }
  return (nb);
}

char	*get_name(const char *path)
{
  char	*name;
  int	i;
  int	j;

  i = count_name(path);
  j = len(path) - 1;
  if ((name = malloc(sizeof(char) * (count_name(path) + 1))) == NULL)
    return (NULL);
  name[i] = '\0';
  i--;
  while (i >= 0)
    {
      name[i] = path[j];
      i--;
      j--;
    }
  return (name);
}
