/*
** hyperbole.c for hyperbole.c in /home/loeb_t/Dropbox/Raytracer/transparence/src
**
** Made by thomas loeb
** Login   <loeb_t@epitech.net>
**
** Started on  Fri Jun  7 16:33:05 2013 thomas loeb
** Last update Sun Jun  9 14:27:34 2013 thomas loeb
*/

#include		"raytracer.h"

void			hyperbole_luminosity(t_rt *rt, t_vision *vision,
					     t_object *object, t_coord *norm)
{
  t_coord		coord;

  if (rt->negative == 0)
    {
      coord.x = (rt->k * vision->new_vector->x + vision->new_eye->coord.x);
      coord.y = (rt->k * vision->new_vector->y + vision->new_eye->coord.y);
      coord.z = ((- RAD(object->param)) *
                 (rt->k * vision->new_vector->z + vision->new_eye->coord.z));
    }
  else
    {
      coord.x = - (rt->k * vision->new_vector->x + vision->new_eye->coord.x);
      coord.y = - (rt->k * vision->new_vector->y + vision->new_eye->coord.y);
      coord.z = - ((- RAD(object->param)) *
                   (rt->k * vision->new_vector->z + vision->new_eye->coord.z));
    }
  norm->x = matrice_rotate_x(rt, &coord, object, 1);
  norm->y = matrice_rotate_y(rt, &coord, object, 1);
  norm->z = matrice_rotate_z(rt, &coord, object, 1);
  if (object->effects.disturb_x > 1 || object->effects.disturb_y > 1)
    normal_perturbation(rt, object, vision, norm);
}

double			inter_hyperbole(t_rt *rt,
					t_negative *neg)
{
  double		a;
  double		b;
  double		c;
  double		delta;
  double		ret;

  a = pow(neg->vector->x, 2) + pow(neg->vector->y, 2)
    - pow(tan(RAD(neg->object->param)), 2) * pow(neg->vector->z, 2);
  b = 2 * (neg->eye->coord.x * neg->vector->x
	   + neg->eye->coord.y * neg->vector->y
           - pow(tan(RAD(neg->object->param)), 2)
	   * (neg->eye->coord.z * neg->vector->z));
  c = pow(neg->eye->coord.x, 2) + pow(neg->eye->coord.y, 2)
    - pow(tan(RAD(neg->object->param)), 2)
    * pow(neg->eye->coord.z, 2) - neg->object->radius;
  if ((delta = pow(b, 2) - (4 * a * c)) >= 0)
    {
      ret = (- b - sqrt(delta)) / (2 * a);
      if (rt->negative == 2)
        ret = (- b + sqrt(delta)) / (2 * a);
      if (rt->negative == 0)
        return (negative_object(rt, ret, (- b + sqrt(delta)) / (2 * a), neg));
      return (ret);
    }
  return (-1);
}
