/*
** init_rt.c for init_rt.c in /home/abgral_f//Dropbox/Raytracer/transparence/src
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Sat Jun  8 06:00:50 2013 franck abgrall
** Last update Sun Jun  9 18:19:54 2013 adrien domoison
*/

#include		"raytracer.h"

void			init_rt(t_rt *rt)
{
  rt->general_param.nb_img = 1;
  rt->general_param.speed = 0;
  rt->general_param.anti_aliasing = 1;
  rt->general_param.aliasing = 1;
  rt->general_param.threads = 1;
  rt->general_param.filter = 0;
  rt->general_param.ambiance_light = 0;
  rt->general_param.backscreen.name = NULL;
  rt->pos = 0;
  rt->eye.check = FALSE;
  rt->first_line = NULL;
  rt->first_light = NULL;
  rt->last_light = NULL;
  rt->first_object = NULL;
  rt->last_object = NULL;
}
