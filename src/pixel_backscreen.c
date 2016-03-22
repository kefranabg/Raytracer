/*
** pixel_backscreen.c for rt in /home/chauch_a//texture
** 
** Made by alan chauchet
** Login   <chauch_a@epitech.net>
** 
** Started on  Fri Jun  7 15:52:40 2013 alan chauchet
** Last update Sun Jun  9 20:48:14 2013 alan chauchet
*/

#include	"raytracer.h"

int		pixel_backscreen(t_rt *rt, int x, int y)
{
  int		color;
  double	mult_x;
  double	mult_y;
  int		pos_x;
  int		pos_y;
  int		pos;

  color = 0;
  x = x / rt->general_param.anti_aliasing * rt->general_param.aliasing;
  y = y / rt->general_param.anti_aliasing * rt->general_param.aliasing;
  mult_x = ((double)rt->general_param.backscreen.a)
    / ((double)rt->size.size_x / ((double)rt->general_param.anti_aliasing)
       * ((double)rt->general_param.aliasing));
  mult_y = ((double)rt->general_param.backscreen.b)
    / ((double)rt->size.size_y / ((double)rt->general_param.anti_aliasing)
       * ((double)rt->general_param.aliasing));
  pos_x = ((int)(((double)x) * mult_x));
  pos_y = ((int)(((double)y) * mult_y));
  pos = (pos_x + pos_y * rt->general_param.backscreen.a) * 4;
  if (pos < rt->general_param.backscreen.a
      * rt->general_param.backscreen.b * 4)
    color = (rt->general_param.backscreen.data[pos + 2] << 16)
      + (rt->general_param.backscreen.data[pos + 1] << 8)
      + (rt->general_param.backscreen.data[pos]);
  return (color);
}
