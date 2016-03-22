/*
** search_inter.c for rt in /home/chauch_a//Dropbox/Raytracer/raytracer-2017-chanut_g
**
** Made by alan chauchet
** Login   <chauch_a@epitech.net>
**
** Started on  Wed May 15 18:16:32 2013 alan chauchet
** Last update Sun Jun  9 17:05:34 2013 alan chauchet
*/

#include	"raytracer.h"

void		apply_transparency(t_rt *rt, int *color)
{
  if (rt->inter == TRUE && rt->final_obj != NULL
      && rt->final_obj->effects.opacity > 0.00001)
    {
      rt->transp.size_tab = 1;
      if ((rt->transp.inter = malloc(sizeof(t_object*) * 2)) == NULL)
	exit(my_puterror(MALLOC_ERROR));
      rt->transp.inter[0] = rt->final_obj;
      rt->transp.inter[1] = NULL;
      transparency(rt, color, &(rt->vector), &(rt->eye));
    }
}

void		search_inter(t_rt *rt, int pos_x, int pos_y)
{
  t_object	*obj;
  double	dist;
  int		color;
  bool		inter;

  rt->pos_x = pos_x;
  rt->pos_y = pos_y;
  calc_rot_eye(rt, pos_x, pos_y);
  color = object_loop(rt, &(rt->vector), &(rt->eye), NULL);
  obj = rt->final_obj;
  dist = rt->k;
  inter = rt->inter;
  apply_transparency(rt, &color);
  rt->final_obj = obj;
  rt->k = dist;
  rt->inter = inter;
  if (rt->inter == TRUE && rt->final_obj != NULL
      && rt->final_obj->effects.reflexion >= 0.00001)
    {
      rt->stop_reflexion = 0;
      reflexion(rt, &color, &(rt->vector), &(rt->eye));
    }
  filter_color(rt, &color);
  my_pixel_put(rt, pos_x, pos_y, color);
}
