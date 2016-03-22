/*
** resize_window_aliasing.c for resize_window_aliasing.c in /home/abgral_f//Dropbox/Raytracer/transparence/src
**
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Jun  1 18:23:27 2013 franck abgrall
** Last update Sun Jun  9 15:59:05 2013 alan chauchet
*/

#include		"raytracer.h"

void			resize_light_anti_aliasing(t_light *tmp, t_rt *rt)
{
  tmp->coord.x *= rt->general_param.anti_aliasing;
  tmp->coord.y *= rt->general_param.anti_aliasing;
  tmp->coord.z *= rt->general_param.anti_aliasing;
}

void			resize_obj_anti_aliasing(t_object *tmp, t_rt *rt)
{
  tmp->coord.x *= rt->general_param.anti_aliasing;
  tmp->coord.y *= rt->general_param.anti_aliasing;
  tmp->coord.z *= rt->general_param.anti_aliasing;
  if (tmp->object_nb != CONE_NB && tmp->object_nb != PARABOLE_NB &&
      tmp->object_nb != HYPERBOLE_NB)
    tmp->param *= rt->general_param.anti_aliasing;
}

void			resize_window_anti_aliasing(t_rt *rt)
{
  t_object		*tmp_obj;
  t_light		*tmp_light;

  rt->eye.coord.x *= rt->general_param.anti_aliasing;
  rt->eye.coord.y *= rt->general_param.anti_aliasing;
  rt->eye.coord.z *= rt->general_param.anti_aliasing;
  rt->size.size_x *= rt->general_param.anti_aliasing;
  rt->size.size_y *= rt->general_param.anti_aliasing;
  tmp_obj = rt->first_object;
  while (tmp_obj != NULL)
    {
      resize_obj_anti_aliasing(tmp_obj, rt);
      tmp_obj = tmp_obj->next;
    }
  tmp_light = rt->first_light;
  while (tmp_light != NULL)
    {
      resize_light_anti_aliasing(tmp_light, rt);
      tmp_light = tmp_light->next;
    }
}
