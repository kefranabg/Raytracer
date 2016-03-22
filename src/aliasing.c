/*
** aliasing.c for aliasing.c in /home/abgral_f//Dropbox/Raytracer/transparence/src
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Fri Jun  7 15:42:34 2013 franck abgrall
** Last update Sun Jun  9 16:13:16 2013 alan chauchet
*/

#include		"raytracer.h"

int			fill_resize_window(t_rt *rt, int x,
					   int y, t_color *color)
{
  int			count_x;
  int			count_y;
  int			pos;

  count_y = 0;
  while (count_y != rt->general_param.aliasing)
    {
      count_x = 0;
      while (count_x != rt->general_param.aliasing)
        {
	  pos = x * 4 * rt->general_param.aliasing + count_x * 4 + y
	    * rt->size.size_x
	    * rt->general_param.aliasing * rt->general_param.aliasing
	    * 4 + count_y * rt->size.size_x * rt->general_param.aliasing * 4;
          rt->mlx_init.data_resize[pos] = color->red;
          rt->mlx_init.data_resize[pos + 1] = color->green;
          rt->mlx_init.data_resize[pos + 2] = color->blue;
          count_x++;
        }
      count_y++;
    }
  return (EXIT_SUCCESS);
}

int			aliasing(t_rt *rt)
{
  int			x;
  int			y;
  t_color		color;

  y = 0;
  while (y < rt->size.size_y)
    {
      x = 0;
      while (x < rt->size.size_x)
        {
          color.red = rt->mlx_init.data_aliasing
	    [x * 4 + y * rt->size.size_x * 4];
          color.green = rt->mlx_init.data_aliasing
	    [x * 4 + y * rt->size.size_x * 4 + 1];
          color.blue = rt->mlx_init.data_aliasing
	    [x * 4 + y * rt->size.size_x * 4 + 2];
          fill_resize_window(rt, x, y, &color);
          x++;
        }
      y++;
    }
  return (EXIT_SUCCESS);
}
