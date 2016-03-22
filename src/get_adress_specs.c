/*
** get_adress_specs.c for get_adress_specs.c in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g/src
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Mon May 13 18:38:34 2013 franck abgrall
** Last update Sun Jun  9 16:08:23 2013 alan chauchet
*/

#include	"raytracer.h"

int		get_adress_specs(t_list *list, int column_nb)
{
  int		count;
  int		count_separators;

  count = 0;
  count_separators = 0;
  while (list->line[count] != '\0')
    {
      if (list->line[count] == SEPARATOR)
	count_separators++;
      if (count_separators == column_nb)
	return (count + 1);
      count++;
    }
  return (EXIT_FAILURE);
}
