/*
** object_list_two.c for object_list_two.c in /home/abgral_f//Dropbox/Raytracer/transparence/src
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Sat Jun  8 06:40:15 2013 franck abgrall
** Last update Sun Jun  9 16:03:53 2013 alan chauchet
*/

#include	"raytracer.h"

int		get_cone_specs(t_list *list, int object_nb, t_rt *rt)
{
  if (object_nb == CONE_NB)
    {
      if (add_object(rt, object_nb) == EXIT_FAILURE)
        return (EXIT_FAILURE);
      if (get_coord(list, rt) == EXIT_FAILURE)
        return (EXIT_FAILURE);
      if (get_rotate(list, rt) == EXIT_FAILURE)
        return (EXIT_FAILURE);
      if ((rt->last_object->color =
           get_color(list, rt, COLOR_NB)) == EXIT_FAILURE)
        return (EXIT_FAILURE);
      if (get_effects(list, rt) == -1)
        return (EXIT_FAILURE);
      if ((rt->last_object->param = get_specs(list, rt, ANGLE_NB))
          == -1)
        return (EXIT_FAILURE);
      if ((rt->last_object->limit = get_specs(list, rt, LIMIT_NB))
          == -1)
        return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
