/*
** raytracing.c for rt in /home/chauch_a//Dropbox/Raytracer/raytracer-2017-chanut_g
**
** Made by alan chauchet
** Login   <chauch_a@epitech.net>
**
** Started on  Wed May 15 14:50:24 2013 alan chauchet
** Last update Sun Jun  9 18:26:13 2013 adrien domoison
*/

#include	"raytracer.h"

void		*raytracing(void *rt)
{
  int		max;
  int		pos;

  load_cos_and_sin((t_rt *)rt);
  max = ((t_rt *)rt)->pix_calc.nb_pixel - ((t_rt *)rt)->pix_calc.pixel_pos;
  while (((t_rt *)rt)->pix_calc.pixel_pos <= ((t_rt *)rt)->pix_calc.nb_pixel)
    {
      if (((t_rt *)rt)->thread_nb == ((t_rt *)rt)->general_param.threads)
	{
	  pos = max - (((t_rt *)rt)->pix_calc.nb_pixel -
		       ((t_rt *)rt)->pix_calc.pixel_pos);
	  aff_loading((t_rt *)rt, pos, max, 0x00D111);
	}
      search_inter((t_rt *)rt, ((t_rt *)rt)->pix_calc.pixel_pos
		   % ((t_rt *)rt)->size.size_x,
		   ((t_rt *)rt)->pix_calc.pixel_pos
		   / ((t_rt *)rt)->size.size_x);
      ((t_rt *)rt)->pix_calc.pixel_pos++;
    }
  return (NULL);
}
