/*
** pars_first_line.c for pars_first_line.c in /home/abgral_f//Depots/raytracer-2017-chanut_g/src
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Tue Apr 30 15:42:42 2013 franck abgrall
** Last update Sun Jun  9 16:14:17 2013 alan chauchet
*/

#include	"raytracer.h"

void		mem_set_ref_tab(int ref_tab[SIZE_TAB])
{
  int		count;

  count = 0;
  while (count < SIZE_TAB)
    {
      ref_tab[count] = 0;
      count++;
    }
}

int		init_rt_pars(t_rt *rt, int ref_tab[SIZE_TAB])
{
  rt->first_object = NULL;
  rt->ref_tab = &(ref_tab[0]);
  return (EXIT_SUCCESS);
}

int		pars_first_line(t_list *list, t_rt *rt)
{
  int		ref_tab[SIZE_TAB];

  init_rt_pars(rt, ref_tab);
  mem_set_ref_tab(ref_tab);
  if (check_separator_number(list) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (check_if_empty_box(list) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (check_right_name(list->line, ref_tab) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (fill_struct_tab(list, rt) == EXIT_FAILURE)
    {
      free_object_list(rt);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
