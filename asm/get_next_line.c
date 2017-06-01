/*
** getnextline.c for getnextline.c in /home/Vatoth/CPE_2016_getnextline
**
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
**
** Started on  Wed Jan 11 08:40:02 2017 Quentin Sonnefraud
** Last update Wed Mar 22 15:07:02 2017 Quentin Sonnefraud
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "asm.h"

static char	*my_realloc(char *str, const size_t size)
{
  char		*my_str;
  int		i;

  i = 0;
  if ((my_str = malloc((size + my_strlen(str)) * sizeof(char))) == NULL)
    return (NULL);
  while (str[i])
    {
      my_str[i] = str[i];
      i++;
    }
  free(str);
  return (my_str);
}

static int	read_char(const int fd, char *read_c)
{
  static char	buffer[READ_SIZE];
  static int	bytes_reads = 0;
  static int	y = 0;

  if (bytes_reads == 0)
    {
      if ((bytes_reads = read(fd, buffer, READ_SIZE)) <= 0)
	return (-1);
      y = 0;
    }
  *read_c = buffer[y];
  y = y + 1;
  bytes_reads = bytes_reads - 1;
  return (0);
}

char		*get_next_line(const int fd)
{
  int		i;
  char		read_c;
  char		*str;
  int		check;

  i = 0;
  read_c = 0;
  if ((check = read_char(fd, &read_c)) == -1)
    return (NULL);
  if ((str = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  my_memset(str, 0, READ_SIZE + 1 * sizeof(char));
  while (read_c != '\n')
    {
      str[i++] = read_c;
      if (read_char(fd, &read_c) < 0)
	break;
      if (i > (READ_SIZE + 1))
	if ((str = my_realloc(str, (i + (READ_SIZE + 1) * sizeof(*str)))) == NULL)
	  return (NULL);
    }
  if (str[i])
    str[i] = '\0';
  return (str);
}
