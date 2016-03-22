/*
** init_param.c for init_param.c in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g/src
**
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
**
** Started on  Wed May 15 16:53:27 2013 franck abgrall
** Last update Sun Jun  9 16:05:04 2013 alan chauchet
*/

#include		"raytracer.h"

int			init_param_aliasing(t_rt *rt)
{
  if ((rt->mlx_init.img_ptr_aliasing =
       mlx_new_image(rt->mlx_init.mlx_ptr, rt->size.size_x
		     / rt->general_param.anti_aliasing
		     / rt->general_param.aliasing,
                     rt->size.size_y / rt->general_param.anti_aliasing
		     / rt->general_param.aliasing)) == NULL)
    return (my_puterror(CONNECT_ERROR));
  rt->mlx_init.data_aliasing = (unsigned char *)mlx_get_data_addr
    (rt->mlx_init.img_ptr,
     &rt->mlx_init.bits_per_pixel_aliasing,
     &rt->mlx_init.size_line_aliasing,
     &rt->mlx_init.endian_aliasing);
  return (EXIT_SUCCESS);
}

int			init_param_cpy_anti_alias(t_rt *rt)
{
  if ((rt->mlx_init.img_ptr_resize =
       mlx_new_image(rt->mlx_init.mlx_ptr, rt->size.size_x
		     / rt->general_param.anti_aliasing, rt->size.size_y
		     / rt->general_param.anti_aliasing)) == NULL)
    return (my_puterror(CONNECT_ERROR));
  if ((rt->mlx_init.win_ptr =
       mlx_new_window(rt->mlx_init.mlx_ptr, rt->size.size_x
		      / rt->general_param.anti_aliasing, rt->size.size_y
		      / rt->general_param.anti_aliasing, WINDOW_NAME))
      == NULL)
    return (my_puterror(CONNECT_ERROR));
  rt->mlx_init.data_resize = (unsigned char *)mlx_get_data_addr
    (rt->mlx_init.img_ptr_resize,
     &rt->mlx_init.bits_per_pixel_resize,
     &rt->mlx_init.size_line_resize,
     &rt->mlx_init.endian_resize);
  return (EXIT_SUCCESS);
}

int			init_param_cpy_alias(t_rt *rt)
{
  if ((rt->mlx_init.img_ptr_resize =
       mlx_new_image(rt->mlx_init.mlx_ptr,
                     rt->size.size_x * rt->general_param.aliasing,
                     rt->size.size_y * rt->general_param.aliasing)) == NULL)
    return (my_puterror(CONNECT_ERROR));
  if ((rt->mlx_init.win_ptr =
       mlx_new_window(rt->mlx_init.mlx_ptr, rt->size.size_x
		      * rt->general_param.aliasing, rt->size.size_y
		      * rt->general_param.aliasing, WINDOW_NAME))
      == NULL)
    return (my_puterror(CONNECT_ERROR));
  rt->mlx_init.data_resize = (unsigned char *)mlx_get_data_addr
    (rt->mlx_init.img_ptr_resize,
     &rt->mlx_init.bits_per_pixel_resize,
     &rt->mlx_init.size_line_resize,
     &rt->mlx_init.endian_resize);
  return (EXIT_SUCCESS);
}

int			init_param(t_rt *rt)
{
  if ((rt->mlx_init.mlx_ptr = mlx_init()) == NULL)
    return (my_puterror(CONNECT_ERROR));
  if ((rt->mlx_init.img_ptr =
       mlx_new_image(rt->mlx_init.mlx_ptr,
		     rt->size.size_x,
		     rt->size.size_y)) == NULL)
    return (my_puterror(CONNECT_ERROR));
  rt->mlx_init.data = (unsigned char *)mlx_get_data_addr
    (rt->mlx_init.img_ptr,
     &rt->mlx_init.bits_per_pixel,
     &rt->mlx_init.size_line,
     &rt->mlx_init.endian);
  if (rt->general_param.anti_aliasing >= 1)
    if (init_param_cpy_anti_alias(rt) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  if (rt->general_param.aliasing > 1)
    if (init_param_cpy_alias(rt) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  if (rt->general_param.aliasing > 1)
    if (init_param_aliasing(rt) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
