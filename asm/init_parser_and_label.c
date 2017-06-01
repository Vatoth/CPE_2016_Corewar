/*
** init_parser_and_label.c for asm in /home/Vatoth/Epitech/CPE_2016_corewar
** 
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Sat Apr  1 17:35:39 2017 Quentin Sonnefraud
** Last update Mon Apr  3 09:13:45 2017 Quentin Sonnefraud
*/

#include "asm.h"

static int	init_element(t_list *list, const char *s,
			     const int num_line)
{
  t_parser      *new_element;

  if ((new_element = malloc(sizeof(*new_element))) == NULL)
    return (1);
  if ((new_element->line = my_strdup(s)) == NULL)
    return (1);
  new_element->num_line = num_line;
  new_element->label = NULL;
  new_element->addr_label = 0;
  new_element->instruction = NULL;
  new_element->param = NULL;
  new_element->prev = list->last;
  new_element->next = NULL;
  if (list->last)
    list->last->next = new_element;
  else
    list->first = new_element;
  list->last = new_element;
  return (0);
}

static char	*parse_label(const char *s)
{
  int		i;
  char		*label;

  i = 0;
  while (s[i] && s[i] != ':')
    i++;
  if (s[i])
    {
      if ((label = malloc(sizeof(char) * (i + 1))) == NULL)
        return (NULL);
      label = my_memset(label, 0, i + 1);
      i = -1;
      while (s[++i] != ':')
        {
          if ((s[i] < 'a' && s[i] > 'z') || (s[i] < 'A' && s[i] > 'Z') ||
              (s[i] < '0' && s[i] > '9') || s[i] == ' ')
            {
              free(label);
              return (NULL);
            }
          label[i] = s[i];
        }
      return (label);
    }
  return (NULL);
}

static void	delete_label(char *s)
{
  int		i;

  i = 0;
  while (s[i] != ':')
    s[i++] = ' ';
  s[i] = ' ';
  epur_str(s);
}

static int              init_parser(char **tab, t_list *list)
{
  int			i;
  int			num_line;
  t_parser		*element;

  num_line = 2;
  i = -1;
  while (tab[++i] != NULL)
    if (init_element(list, tab[i], num_line++) == 1)
      return (1);
  i = -1;
  element = list->first;
  while (tab[++i])
    {
      if ((element->label = parse_label(element->line)))
	delete_label(element->line);
      element = element->next;
    }
  if (label_call(list) == 1)
    return (1);
  return (0);
}

int             parser(char **tab, t_list *list)
{
  int           i;
  t_parser	*element;
  char		**instruct;

  list->first = NULL;
  list->last = NULL;
  if (init_parser(tab, list) == 1)
    return (1);
  i = -1;
  element = list->first;
  while (tab[++i])
    {
      if (!(instruct = parse_instruction(element->line)) ||
	  !(element->instruction = my_strdup(instruct[0])) ||
	  (instruct[1] == NULL) ||
	  !(instruct = parse_param(instruct[1], instruct[0], list)))
	{
	  my_puterror(" (Line : ");
	  my_puterror_nbr(element->num_line + 1);
	  my_puterror(")\n");
	  return (1);
	}
      element->param = instruct;
      element = element->next;
    }
  return (0);
}
