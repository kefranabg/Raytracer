/*
** aff_loading.c<2> for rt in /home/acca_b/Dropbox/EPITECH/Tek1/rtv1/src/raytracing
**
** Made by baptiste acca
** Login   <acca_b@epitech.net>
**
** Started on  Thu May 16 11:06:50 2013 baptiste acca
** Last update Sun Jun  9 18:15:22 2013 adrien domoison
*/

#include		"raytracer.h"

void			aff_text(t_rt *rt)
{
  mlx_string_put(rt->mlx_init.mlx_ptr, rt->mlx_init.win_ptr,
		 rt->size.win_x / 2 - 50,
		 rt->size.win_y / 2 - 50,
		 0xFFFFFF, "Loading, please wait");
  mlx_string_put(rt->mlx_init.mlx_ptr, rt->mlx_init.win_ptr,
		 rt->size.win_x - 400,
		 rt->size.win_y - 50,
		 0xFFFFFF,
		 "abgral_f - acca_b - chanut_g - chauch_a - domois_a - loeb_t");
}

void			aff_vertical_bar(t_rt *rt)
{
  int			x;
  int			y;

  y = -6;
  while (y <= 6)
    {
      x = (rt->size.win_x / 4) - 1;
      while (x <= (rt->size.win_x / 4) + 1)
	{
	  mlx_pixel_put(rt->mlx_init.mlx_ptr, rt->mlx_init.win_ptr,
	  		x, rt->size.win_y / 2 - y,
			0x00820F);
	  mlx_pixel_put(rt->mlx_init.mlx_ptr, rt->mlx_init.win_ptr,
	  		x + (rt->size.win_x / 4 * 2), rt->size.win_y / 2 - y,
			0x00820F);
	  x++;
	}
      y++;
    }
}

void			aff_horizontal_bar(t_rt *rt)
{
  int			x;
  int			y;

  x = (rt->size.win_x / 4);
  while (x <= rt->size.win_x / 4 * 3)
    {
      y = -1;
      while (y <= 1)
	{
	  mlx_pixel_put(rt->mlx_init.mlx_ptr, rt->mlx_init.win_ptr,
	  		x, rt->size.win_y / 2 - 6 - y, 0x00820F);
	  mlx_pixel_put(rt->mlx_init.mlx_ptr, rt->mlx_init.win_ptr,
	  		x, rt->size.win_y / 2 + 6 - y, 0x00820F);
	  y++;
	}
      x++;
    }
}

void			aff_load_bar(t_rt *rt)
{
  clear_img(rt);
  aff_text(rt);
  aff_vertical_bar(rt);
  aff_horizontal_bar(rt);
}

void			aff_loading(t_rt *rt, int pos, int max, int color)
{
  int			coef;

  coef = ((rt->size.win_x / 4 * 3) - 3) - ((rt->size.win_x / 4) + 3);
  if ((coef * pos / max) + ((rt->size.win_x / 4) + 3) >
      (coef * (pos - 1) / max) + ((rt->size.win_x / 4) + 3))
    mlx_pixel_put(rt->mlx_init.mlx_ptr,
		  rt->mlx_init.win_ptr,
		  (coef * pos / max) + ((rt->size.win_x / 4) + 3),
		  rt->size.win_y / 2, color);
}
