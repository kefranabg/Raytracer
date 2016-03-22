/*
** check_separator_number.c for check_separator_number.c in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g/src
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Tue Apr 30 22:59:19 2013 franck abgrall
** Last update Sun Jun  9 16:28:20 2013 alan chauchet
*/

#include	"raytracer.h"

int		check_if_empty_box(t_list *list)
{
  int		count;

  count = 0;
  while (list->line[count] != '\0')
    {
      if (list->line[count] == SEPARATOR
          && list->line[count + 1] == SEPARATOR)
	{
	  my_puterror(EMPTY_BOX);
	  my_putnbr(list->line_nb);
	  return (EXIT_FAILURE);
	}
      count++;
    }
  return (EXIT_SUCCESS);
}

int		check_separator_number(t_list *list)
{
  int		count;
  int		count_separator;

  count = 0;
  count_separator = 0;
  while (list->line[count] != '\0')
    {
      if (list->line[count] == SEPARATOR)
        count_separator++;
      count++;
    }
  if (count_separator != NB_SEPARATOR)
    return (my_puterror(BAD_SEPARATOR_NB));
  return (EXIT_SUCCESS);
}
