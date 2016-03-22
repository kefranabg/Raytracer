/*
** redirect_appropriate_function.c for redirect_appropriate_function.c in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g/src
**
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
**
** Started on  Sat May 11 15:37:06 2013 franck abgrall
** Last update Sun Jun  9 16:14:03 2013 alan chauchet
*/

#include	"raytracer.h"

static int	(*pointer_tab[])(t_list *, int, t_rt *) =
{
  &get_sphere_specs,
  &get_cylinder_specs,
  &get_plan_specs,
  &get_cone_specs,
  &get_light_specs,
  &get_eyes_specs,
  &get_parabole_specs,
  &get_hyperbole_specs
};

int		redirect_appropriate_function(int object_nb, t_list *list, t_rt *rt)
{
  int		count;

  count = 0;
  while (count != NB_OBJECT)
    {
      if (pointer_tab[count](list, object_nb, rt) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      count++;
    }
  return (EXIT_SUCCESS);
}
