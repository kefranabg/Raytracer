/*
** cylinder.c for rt in /home/acca_b/Dropbox/EPITECH/Tek1/Raytracer/raytracer-2017-chanut_g/src
**
** Made by baptiste acca
** Login   <acca_b@epitech.net>
**
** Started on  Thu May 16 15:05:43 2013 baptiste acca

*/

#include		"raytracer.h"

void			cylinder_luminosity(t_rt *rt,
					    t_vision *vision,
					    t_object *object,
					    t_coord *norm)
{
  t_coord		coord;

  if (rt->negative == 0)
    {
      coord.x = (rt->k * vision->new_vector->x
                 + vision->new_eye->coord.x);
      coord.y = (rt->k * vision->new_vector->y
                 + vision->new_eye->coord.y);
    }
  else
    {
      coord.x = - (rt->k * vision->new_vector->x
                   + vision->new_eye->coord.x);
      coord.y = - (rt->k * vision->new_vector->y
                   + vision->new_eye->coord.y);
    }
  coord.z = 0;
  norm->x = matrice_rotate_x(rt, &coord, object, 1);
  norm->y = matrice_rotate_y(rt, &coord, object, 1);
  norm->z = matrice_rotate_z(rt, &coord, object, 1);
  if (object->effects.disturb_x > 1 || object->effects.disturb_y > 1)
    normal_perturbation(rt, object, vision, norm);
}

double			inter_cylinder(t_rt *rt,
				       t_negative *negative)
{
  double		a;
  double		b;
  double		c;
  double		delta;
  double		ret;

  a = pow(negative->vector->x, 2) + pow(negative->vector->y, 2);
  b = 2 * (negative->eye->coord.x * negative->vector->x
	   + negative->eye->coord.y * negative->vector->y);
  c = pow(negative->eye->coord.x, 2) + pow(negative->eye->coord.y, 2)
    - pow(negative->object->param, 2);
  if ((delta = pow(b, 2) - (4 * a * c)) >= 0)
    {
      ret = (- b - sqrt(delta)) / (2 * a);
      if (rt->negative == 2)
        ret = (- b + sqrt(delta)) / (2 * a);
      if (rt->negative == 0)
        return (negative_object(rt, ret, (- b + sqrt(delta)) / (2 * a),
                                negative));
      return (ret);
    }
  return (-1);
}
