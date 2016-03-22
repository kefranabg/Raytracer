/*
** my_pixel_put.c for rt in /home/chauch_a//Dropbox/Raytracer/raytracer-2017-chanut_g/src
** 
** Made by alan chauchet
** Login   <chauch_a@epitech.net>
** 
** Started on  Fri May 17 14:31:52 2013 alan chauchet
** Last update Sat Jun  1 18:28:08 2013 franck abgrall
*/

#include		"raytracer.h"

void			my_pixel_put(t_rt *rt, int x, int y, int color)
{
  int			pos;
  unsigned char		data[3];

  if (x >= 0 && x <= rt->size.size_x && y >= 0 && y <= rt->size.size_y)
    {
      data[0] = (color & 0xFF0000) >> 16;
      data[1] = (color & 0x00FF00) >> 8;
      data[2] = (color & 0x0000FF);
      pos = x * 4 + y * rt->mlx_init.size_line;
      rt->mlx_init.data[pos] = data[2];
      rt->mlx_init.data[pos + 1] = data[1];
      rt->mlx_init.data[pos + 2] = data[0];
    }
}
