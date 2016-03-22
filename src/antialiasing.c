/*
** antialiasing.c for antialiasing.c in /home/loeb_t/Dropbox/Raytracer/raytracer-2017-chanut_g/src
**
** Made by thomas loeb
** Login   <loeb_t@epitech.net>
**
** Started on  Mon May 27 14:06:08 2013 thomas loeb
** Last update Sat Jun  8 05:57:43 2013 franck abgrall
*/

#include	"raytracer.h"

char		calc_average(t_rt *rt, int x, int y, int nb)
{
  double	average;
  int		count_x;
  int		count_y;

  average = 0;
  count_y = 0;
  while (count_y != rt->general_param.anti_aliasing)
    {
      count_x = 0;
      while (count_x != rt->general_param.anti_aliasing)
        {
          if (x * 4 * rt->general_param.anti_aliasing + count_x * 4 + y
	      * rt->size.size_x * 4 * rt->general_param.anti_aliasing
	      + count_y * rt->size.size_x * 4
	      + nb < rt->size.size_x * rt->size.size_y * 4)
	    average += rt->mlx_init.data[x * 4 * rt->general_param.anti_aliasing
					 + count_x * 4 + y * rt->size.size_x *
					 4 * rt->general_param.anti_aliasing
					 + count_y * rt->size.size_x * 4 + nb];
          count_x++;
        }
      count_y++;
    }
  average /= rt->general_param.anti_aliasing * rt->general_param.anti_aliasing;
  return ((unsigned char)average);
}

int			antialiasing(t_rt *rt)
{
  int			real_size_x;
  int			real_size_y;
  int			x;
  int			y;

  real_size_x = rt->size.size_x / rt->general_param.anti_aliasing;
  real_size_y = rt->size.size_y / rt->general_param.anti_aliasing;
  y = 0;
  while (y < real_size_y)
    {
      x = 0;
      while (x < real_size_x)
        {
          rt->mlx_init.data_resize[x * 4 + y * real_size_x
				   * 4] = calc_average(rt, x, y, 0);
          rt->mlx_init.data_resize[x * 4 + y * real_size_x
				   * 4 + 1] = calc_average(rt, x, y, 1);
          rt->mlx_init.data_resize[x * 4 + y * real_size_x
				   * 4 + 2] = calc_average(rt, x, y, 2);
          x++;
        }
      y++;
    }
  return (EXIT_SUCCESS);
}
