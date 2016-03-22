/*
** normal_perturbation.c for rt in /home/chauch_a//Dropbox/Raytracer/transparence
**
** Made by alan chauchet
** Login   <chauch_a@epitech.net>
**
** Started on  Mon Jun  3 18:00:24 2013 alan chauchet
** Last update Sun Jun  9 16:14:40 2013 alan chauchet
*/

#include		"raytracer.h"

void			normal_perturbation(t_rt *rt, t_object *object,
					    t_vision *vision, t_coord *norm)
{
  t_coord		prov;
  int			frequency;

  prov.x = norm->x;
  prov.y = norm->y;
  prov.z = norm->z;
  frequency = object->effects.disturb_x * rt->general_param.anti_aliasing;
  if (object->effects.disturb_x > 1)
    norm->y = prov.y + cos((int)((vision->eye->coord.y
				  + rt->k * vision->vector->y) / frequency))
      * (sqrt(pow(prov.x, 2) + pow(prov.y, 2) + pow(prov.z, 2)) / frequency);
  frequency = object->effects.disturb_y * rt->general_param.anti_aliasing;
  if (object->effects.disturb_y > 1)
    norm->x = prov.x + cos((int)((vision->eye->coord.x
				  + rt->k * vision->vector->x) / frequency))
      * (sqrt(pow(prov.x, 2) + pow(prov.y, 2) + pow(prov.z, 2)) / frequency);
}
