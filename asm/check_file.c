/*
** main.c for asm in /home/Vatoth/Epitech/CPE_2016_corewar/ASM
** 
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Mon Mar 20 11:59:27 2017 Quentin Sonnefraud
** Last update Mon Apr  3 19:33:51 2017 Quentin Sonnefraud
*/

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include "asm.h"
#include "op.h"

static int	check_point_s(const char *file, const char *to_check)
{
  int		i;
  int		c;

  c = 0;
  i = 0;
  while (file[c])
    c++;
  c--;
  while (to_check[i])
    i++;
  i--;
  while (file[c] == to_check[i] && file[c] && i > 0)
    {
      i--;
      c--;
    }
  if (file[c] == to_check[i])
    return (0);
  else if (file[c] > to_check[i])
    return (1);
  else if (file[c] < to_check[i])
    return (-1);
  return (0);
}

static int	new_file(const char *file, const char *extention)
{
  int		len;
  int		fd;
  char		*tmp;
  int		i;
  int		j;

  i = 0;
  j = 0;
  len  = my_strlen(file) - 2;
  if ((tmp = malloc(sizeof(char) * (len + 5))) == NULL)
    return (-1);
  tmp = my_memset(tmp, 0, len + 5);
  while (i < len)
    {
      tmp[i] = file[i];
      i++;
    }
  while (extention[j])
    tmp[i++] = extention[j++];
  fd = open(tmp, O_CREAT | O_WRONLY | O_TRUNC, 0666);
  free(tmp);
  return (fd);
}

static int	count_line(const int fd_input)
{
  char		*s;
  int		len;

  len = 0;
  while ((s = get_next_line(fd_input)))
    {
      free(s);
      len++;
    }
  if (lseek(fd_input, 0, SEEK_SET) == -1)
    return (0);
  return (len);
}

static char	**create_tab(const int len, const int fd_input)
{
  char		**tab;
  int		i;
  int		j;
  char		*s;

  if ((tab = malloc(sizeof(char *) * (len + 1))) == NULL)
    return (NULL);
  j = 0;
  i = 0;
  while (i < len)
    {
      if ((s = get_next_line(fd_input)) == NULL)
	return (NULL);
      if (i > 1)
	epur_str(s);
      if (my_strlen(s) > 0)
	tab[j++] = s;
      else
	free(s);
      i++;
    }
  tab[j] = NULL;
  close(fd_input);
  return (tab);
}

int	redirect(const char *file)
{
  int		fd_input;
  int		fd_output;
  char		**tab;
  t_list	list;
  t_header	header;

  if ((check_point_s(file, ".s") != 0)
      || ((fd_input = open(file, O_RDONLY)) == -1)
      || (((tab = create_tab(count_line(fd_input), fd_input)) == NULL))
      || ((tab[0] == NULL) || (tab[1] == NULL))
      || (my_compare(tab[0], NAME_CMD_STRING,
		     my_strlen(NAME_CMD_STRING) - 1) != 0)
      || (my_compare(tab[1], COMMENT_CMD_STRING,
		     my_strlen(COMMENT_CMD_STRING) - 1) != 0)
      || take_name(tab[0], header.prog_name) == 1
      || take_comment(tab[1], header.comment) == 1
      || (parser(&tab[2], &list) == 1)
      || ((fd_output = new_file(get_name(file), ".cor")) == -1))
    return (1);
  list.prog_size = 0;
  get_addr(&list);
  init_header(header, fd_output, list.prog_size);
  write_instructions(fd_output, &list);
  my_printf("SUCESSFULLY COMPILED\n");
  return (0);
}
