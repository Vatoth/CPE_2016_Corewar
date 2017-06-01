/*
** label_exist.c for asm in /home/Vatoth/Epitech/CPE_2016_corewar
** 
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Sat Apr  1 19:41:16 2017 Quentin Sonnefraud
** Last update Sun Apr  2 14:40:54 2017 Quentin Sonnefraud
*/

#include "asm.h"

int		label_call(t_list *list)
{
  t_parser	*element;
  t_parser	*pointer;
  char		*label_to_check;

  element = list->first;
  while (element)
    {
      if (element->label)
	{
	  pointer = element;
	  label_to_check = element->label;
	  element = list->first;
	  while (element)
	    {
	      if (pointer != element)
		if (my_strcmp(element->label, label_to_check) == 0)
		  return (1);
	      element = element->next;
	    }
	  element = pointer;
	}
      element = element->next;
    }
  return (0);
}

int	label_exist(t_list *list, const char *name)
{
  t_parser	*element;
  int		i;

  element = list->first;
  i = 0;
  while (element)
    {
      if (element->label)
	{
	  if (my_strcmp(element->label, name) == 0)
	    i++;
	}
      element = element->next;
    }
  if (i != 0)
    return (0);
  my_puterror("ERROR : INDIRECT TO LABEL DON'T EXIST");
  return (1);
}
