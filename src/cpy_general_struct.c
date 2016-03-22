/*
** cpy_general_struct.c for cpy_general_struct.c in /home/abgral_f//Projetsave/rt3/src
**
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
**
** Started on  Sat May 25 14:51:12 2013 franck abgrall
** Last update Sun Jun  9 16:09:52 2013 alan chauchet
*/

#include		"raytracer.h"

static void		cpy_light_var(t_rt *cpy, t_rt *rt)
{
  cpy->light_var.color.red = rt->light_var.color.red;
  cpy->light_var.color.green = rt->light_var.color.green;
  cpy->light_var.color.blue = rt->light_var.color.blue;
  cpy->light_var.norm.x = rt->light_var.norm.x;
  cpy->light_var.norm.y = rt->light_var.norm.y;
  cpy->light_var.norm.z = rt->light_var.norm.z;
  cpy->light_var.vector.x = rt->light_var.vector.x;
  cpy->light_var.vector.y = rt->light_var.vector.y;
  cpy->light_var.vector.z = rt->light_var.vector.z;
  cpy->light_var.norme_n = rt->light_var.norme_n;
  cpy->light_var.norme_l = rt->light_var.norme_l;
  cpy->light_var.brightness = rt->light_var.brightness;
  cpy->light_var.shadow = rt->light_var.shadow;
  cpy->light_var.cos_a = rt->light_var.cos_a;
}

static void	cpy_calc_param(t_rt *cpy, t_rt *rt)
{
  cpy->eye.coord.x = rt->eye.coord.x;
  cpy->eye.coord.y = rt->eye.coord.y;
  cpy->eye.coord.z = rt->eye.coord.z;
  cpy->eye.rotate.rx = rt->eye.rotate.rx;
  cpy->eye.rotate.ry = rt->eye.rotate.ry;
  cpy->eye.rotate.rz = rt->eye.rotate.rz;
  cpy->eye.check = rt->eye.check;
  cpy->vector.x = rt->vector.x;
  cpy->vector.y = rt->vector.y;
  cpy->vector.z = rt->vector.z;
  cpy->color = rt->color;
  cpy->k = rt->k;
  cpy->inter = rt->inter;
  cpy->count_pixel = rt->count_pixel;
}

static void	cpy_general_param(t_rt *cpy, t_rt *rt)
{
  cpy->mlx_init.mlx_ptr = rt->mlx_init.mlx_ptr;
  cpy->mlx_init.win_ptr = rt->mlx_init.win_ptr;
  cpy->mlx_init.img_ptr = rt->mlx_init.img_ptr;
  cpy->mlx_init.data = rt->mlx_init.data;
  cpy->mlx_init.bits_per_pixel = rt->mlx_init.bits_per_pixel;
  cpy->mlx_init.size_line = rt->mlx_init.size_line;
  cpy->mlx_init.endian = rt->mlx_init.endian;
  cpy->size.size_x = rt->size.size_x;
  cpy->size.size_y = rt->size.size_y;
  cpy->size.win_x = rt->size.win_x;
  cpy->size.win_y = rt->size.win_y;
  cpy->general_param.anti_aliasing = rt->general_param.anti_aliasing;
  cpy->general_param.aliasing = rt->general_param.aliasing;
  cpy->general_param.threads = rt->general_param.threads;
  cpy->general_param.filter = rt->general_param.filter;
  cpy->general_param.ambiance_light = rt->general_param.ambiance_light;
  cpy->general_param.backscreen = rt->general_param.backscreen;
  cpy->pix_calc.nb_pixel = rt->pix_calc.nb_pixel;
  cpy->pix_calc.pixel_pos = rt->pix_calc.pixel_pos;
  cpy->thread_nb = rt->thread_nb;
}

t_rt		*cpy_general_struct(t_rt *rt)
{
  t_rt		*cpy;

  if ((cpy = malloc(sizeof(*cpy))) == NULL)
    return (NULL);
  init_rt(cpy);
  if (cpy_object_list(cpy, rt) == EXIT_FAILURE)
    return (NULL);
  if (cpy_light_list(cpy, rt) == EXIT_FAILURE)
    return (NULL);
  cpy_general_param(cpy, rt);
  cpy_calc_param(cpy, rt);
  cpy_light_var(cpy, rt);
  return (cpy);
}
