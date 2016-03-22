/*
** get_window_size.c for get_window_size.c in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g/src
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Wed May 15 15:50:50 2013 franck abgrall
** Last update Sun Jun  9 16:42:18 2013 alan chauchet
*/

#include		"raytracer.h"

int			get_window_size(t_rt *rt, char *size_x, char *size_y)
{
  if (my_str_isnum(size_x, 0) == 1)
    return (my_puterror(BAD_ARG_S));
  if (my_str_isnum(size_y, 0) == 1)
    return (my_puterror(BAD_ARG_S));
  rt->size.size_y = atoi(size_y);
  rt->size.size_x = atoi(size_x);
  if (rt->size.size_x <= 1 || rt->size.size_y <= 1)
    return (my_puterror(SIZE_ZERO));
  if (rt->size.size_y > 1080)
    return (EXIT_FAILURE);
  if (rt->size.size_x > 1920)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
