/*
** plan.c for rt in /home/acca_b/Dropbox/EPITECH/Tek1/Raytracer/raytracer-2017-chanut_g/src
**
** Made by baptiste acca
** Login   <acca_b@epitech.net>
**
** Started on  Thu May 16 15:23:59 2013 baptiste acca
** Last update Sun Jun  9 16:02:08 2013 alan chauchet
*/

#include		"raytracer.h"

void			plan_luminosity(t_rt *rt, t_vision *vision,
					t_object *object, t_coord *norm)
{
  t_coord		coord;

  if (rt->negative == 0)
    {
      coord.x = 0;
      coord.y = 0;
      coord.z = 100;
    }
  norm->x = matrice_rotate_x(rt, &coord, object, 1);
  norm->y = matrice_rotate_y(rt, &coord, object, 1);
  norm->z = matrice_rotate_z(rt, &coord, object, 1);
  if (object->effects.disturb_x > 1 || object->effects.disturb_y > 1)
    normal_perturbation(rt, object, vision, norm);
}

double			inter_plan(t_rt *rt,
				   t_negative *negative)
{
  double		ret;

  if (negative->vector->z != 0)
    {
      ret = - (negative->eye->coord.z / negative->vector->z);
      return (negative_object(rt, ret, -2, negative));
    }
  return (-1);
}
