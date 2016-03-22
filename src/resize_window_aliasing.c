/*
** resize_window_aliasin.c for resize_window_aliasing in /home/abgral_f//Dropbox/Raytracer/transparence/src
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Fri Jun  7 15:38:12 2013 franck abgrall
** Last update Fri Jun  7 15:40:41 2013 franck abgrall
*/

#include		"raytracer.h"

void			resize_light_aliasing(t_light *tmp, t_rt *rt)
{
  tmp->coord.x /= rt->general_param.aliasing;
  tmp->coord.y /= rt->general_param.aliasing;
  tmp->coord.z /= rt->general_param.aliasing;
}

void			resize_obj_aliasing(t_object *tmp, t_rt *rt)
{
  tmp->coord.x /= rt->general_param.aliasing;
  tmp->coord.y /= rt->general_param.aliasing;
  tmp->coord.z /= rt->general_param.aliasing;
  if (tmp->object_nb != 3)
    tmp->param /= rt->general_param.aliasing;
}

void			resize_window_aliasing(t_rt *rt)
{
  t_object		*tmp_obj;
  t_light		*tmp_light;

  rt->eye.coord.x /= rt->general_param.aliasing;
  rt->eye.coord.y /= rt->general_param.aliasing;
  rt->eye.coord.z /= rt->general_param.aliasing;
  rt->size.size_x /= rt->general_param.aliasing;
  rt->size.size_y /= rt->general_param.aliasing;
  tmp_obj = rt->first_object;
  while (tmp_obj != NULL)
    {
      resize_obj_aliasing(tmp_obj, rt);
      tmp_obj = tmp_obj->next;
    }
  tmp_light = rt->first_light;
  while (tmp_light != NULL)
    {
      resize_light_aliasing(tmp_light, rt);
      tmp_light = tmp_light->next;
    }
}
