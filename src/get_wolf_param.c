/*
** get_wolf_param.c<2> for rt in /home/domois_a//MERGE/src
** 
** Made by adrien domoison
** Login   <domois_a@epitech.net>
** 
** Started on  Sun Jun  9 18:16:59 2013 adrien domoison
** Last update Sun Jun  9 18:17:06 2013 adrien domoison
*/

#include		"raytracer.h"

int			get_wolf_param(t_rt *rt, char *nb_img, char *speed)
{
  if (my_str_isnum(nb_img, 0) == 1)
    return (my_puterror(BAD_ARG_S));
  if (my_str_isnum(speed, 0) == 1)
    return (my_puterror(BAD_ARG_S));
  rt->general_param.speed = atoi(speed);
  rt->general_param.nb_img = atoi(nb_img);
  if (rt->general_param.nb_img <= 1 || rt->general_param.speed <= 1)
    return (my_puterror(SIZE_ZERO));
  if (rt->general_param.speed > 1080)
    return (EXIT_FAILURE);
  if (rt->general_param.nb_img > 1920)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
