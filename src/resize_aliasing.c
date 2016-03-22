/*
** resize_aliasing.c for resize_aliasing.c in /home/abgral_f//Dropbox/Raytracer/transparence/src
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Sat Jun  8 06:04:58 2013 franck abgrall
** Last update Sun Jun  9 15:59:26 2013 alan chauchet
*/

#include		"raytracer.h"

int			resize_aliasing(t_rt *rt)
{
  if (rt->general_param.aliasing > 1 &&
      (rt->size.size_x < 1000 || rt->size.size_y < 1000))
    return (my_puterror(ALIASING_ERROR));
  if (rt->general_param.anti_aliasing > 1 &&
      rt->general_param.aliasing > 1)
    return (my_puterror(ERROR_ALIASING));
  if (rt->general_param.anti_aliasing >= 1)
    resize_window_anti_aliasing(rt);
  if (rt->general_param.aliasing > 1)
    resize_window_aliasing(rt);
  return (EXIT_SUCCESS);
}
