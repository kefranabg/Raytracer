/*
** key_hook.c for rt in /home/chauch_a//Dropbox/Raytracer/raytracer-2017-chanut_g
**
** Made by alan chauchet
** Login   <chauch_a@epitech.net>
**
** Started on  Thu May 16 11:50:54 2013 alan chauchet
** Last update Sun Jun  9 18:30:18 2013 adrien domoison
*/

#include	<X11/X.h>
#include	"raytracer.h"

int			key_wolf(int keycode, t_rt *rt)
{
  if (keycode == UP_KEY)
    {
      if (rt->pos < rt->general_param.nb_img - 1)
	rt->pos++;
      mlx_put_image_to_window(rt->mlx_init.mlx_ptr,
			      rt->mlx_init.win_ptr,
			      rt->img_tab[rt->pos].img_ptr, 0, 0);
    }
  else
    if (keycode == DOWN_KEY)
      {
	if (rt->pos > 0)
	  rt->pos--;
	mlx_put_image_to_window(rt->mlx_init.mlx_ptr,
				rt->mlx_init.win_ptr,
				rt->img_tab[rt->pos].img_ptr, 0, 0);
      }
  return (EXIT_SUCCESS);
}

int			key_hook(int keycode, t_rt *rt)
{
  if (keycode == ESC_KEY)
    {
      mlx_destroy_window(rt->mlx_init.mlx_ptr, rt->mlx_init.win_ptr);
      exit(EXIT_SUCCESS);
    }
  else
    if (keycode == S_KEY)
      {
	if (bmp(rt) == EXIT_FAILURE)
	  return (EXIT_FAILURE);
	my_putstr(IMG_SAVED);
	if (rt->scene_name != NULL)
	  my_putstr(rt->scene_name);
	my_putchar('\n');
      }
  key_wolf(keycode, rt);
  return (EXIT_SUCCESS);
}
