/*
** sphere.c for rt in /home/acca_b/Dropbox/EPITECH/Tek1/Raytracer/raytracer-2017-chanut_g/src
**
** Made by baptiste acca
** Login   <acca_b@epitech.net>
**
** Started on  Thu May 16 14:50:22 2013 baptiste acca
** Last update Sun Jun  9 14:28:47 2013 thomas loeb
*/

#include		"raytracer.h"

void			sphere_luminosity(t_rt *rt, t_vision *vision,
					  t_object *object, t_coord *norm)
{
  if (rt->negative == 0)
    {
      norm->x = ((rt->k * vision->vector->x + vision->eye->coord.x)
		 - object->coord.x);
      norm->y = ((rt->k * vision->vector->y + vision->eye->coord.y)
		 - object->coord.y);
      norm->z = ((rt->k * vision->vector->z + vision->eye->coord.z)
		 - object->coord.z);
    }
  else
    {
      norm->x = - ((rt->k * vision->vector->x + vision->eye->coord.x)
		   - object->coord.x);
      norm->y = - ((rt->k * vision->vector->y + vision->eye->coord.y)
		   - object->coord.y);
      norm->z = - ((rt->k * vision->vector->z + vision->eye->coord.z)
		   - object->coord.z);
    }
  if (object->effects.disturb_x > 1 || object->effects.disturb_y > 1)
    normal_perturbation(rt, object, vision, norm);
}

double			inter_sphere(t_rt *rt, t_negative *negative)
{
  double		a;
  double		b;
  double		c;
  double		delta;
  double		ret;

  a = pow(negative->vector->x, 2)
    + pow(negative->vector->y, 2) + pow(negative->vector->z, 2);
  b = 2 * (negative->eye->coord.x * negative->vector->x
	   + negative->eye->coord.y * negative->vector->y
	   + negative->eye->coord.z * negative->vector->z);
  c = (pow(negative->eye->coord.x, 2) + pow(negative->eye->coord.y, 2)
       + pow(negative->eye->coord.z, 2) - pow(negative->object->param, 2));
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
