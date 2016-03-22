/*
** expose_hook.c for rt in /home/chauch_a//Dropbox/Raytracer/raytracer-2017-chanut_g
** 
** Made by alan chauchet
** Login   <chauch_a@epitech.net>
** 
** Started on  Fri May 17 17:39:49 2013 alan chauchet
** Last update Sun Jun  9 18:33:19 2013 adrien domoison
*/

#include	"raytracer.h"

int		expose_hook(t_rt *rt)
{
  mlx_put_image_to_window(rt->mlx_init.mlx_ptr, rt->mlx_init.win_ptr,
			  rt->img_tab[rt->pos].img_ptr, 0, 0);
  return (EXIT_SUCCESS);
}
