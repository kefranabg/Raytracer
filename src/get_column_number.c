/*
** get_column_number.c for get_column_number in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Mon May 13 17:40:43 2013 franck abgrall
** Last update Sun Jun  9 16:08:04 2013 alan chauchet
*/

#include	"raytracer.h"

int		get_column_number(int specs_nb, t_rt *rt)
{
  int		count;

  count = 0;
  while (count < SIZE_TAB)
    {
      if (specs_nb == rt->ref_tab[count])
	return (count + 1);
      count++;
    }
  return (EXIT_FAILURE);
}
