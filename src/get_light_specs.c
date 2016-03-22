/*
** get_light_specs.c for get_light_specs.c in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g/src
**
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
**
** Started on  Thu May 16 15:03:57 2013 franck abgrall
** Last update Tue Jun  4 19:32:26 2013 franck abgrall
*/

#include	"raytracer.h"

int             get_coord_light(t_list *list, t_rt *rt)
{
  if ((rt->last_light->coord.x =
       get_specs(list, rt, POSX_NB)) == -1)
    return (EXIT_FAILURE);
  if ((rt->last_light->coord.y =
       get_specs(list, rt, POSY_NB)) == -1)
    return (EXIT_FAILURE);
  if ((rt->last_light->coord.z =
       get_specs(list, rt, POSZ_NB)) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		get_light_specs(t_list *list, int object_nb, t_rt *rt)
{
  if (object_nb == LIGHT_NB)
    {
      (void)object_nb;
      if (add_light(rt) == EXIT_FAILURE)
        return (EXIT_FAILURE);
      if (get_coord_light(list, rt) == EXIT_FAILURE)
        return (EXIT_FAILURE);
      if ((rt->last_light->color =
           get_color(list, rt, COLOR_NB)) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
