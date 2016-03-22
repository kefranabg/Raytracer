/*
** transparency.c for transparency.c in /home/acca_b/Dropbox/EPITECH/Tek1/Raytracer/transparence/src
**
** Made by baptiste acca
** Login   <acca_b@epitech.net>
**
** Started on  Mon May 27 16:51:41 2013 baptiste acca
** Last update Sun Jun  9 18:25:48 2013 franck abgrall
*/

#include		"raytracer.h"

void			add_transp_tab(t_rt *rt, t_object *object)
{
  int			count;
  t_object		**new_tab;

  if ((new_tab = malloc(sizeof(t_object*) *
			(rt->transp.size_tab + 1))) == NULL)
    exit(my_puterror(MALLOC_ERROR));
  count = 0;
  while (count < rt->transp.size_tab - 1)
    {
      new_tab[count] = rt->transp.inter[count];
      count++;
    }
  new_tab[count] = object;
  new_tab[count + 1] = NULL;
  free(rt->transp.inter);
  rt->transp.inter = new_tab;
}

void			transparency_color(int first_color[3], int new_color[3],
					   int new_obj, t_object *inter)
{
  new_color[0] = (int)((new_obj & 0xFF0000) >> 16);
  new_color[1] = (int)((new_obj & 0x00FF00) >> 8);
  new_color[2] = (int)(new_obj & 0x0000FF);
  first_color[0] = new_color[0] * inter->effects.opacity
    + first_color[0] * (1 - inter->effects.opacity);
  if (first_color[0] > 255)
    first_color[0] = 255;
  first_color[1] = new_color[1] * inter->effects.opacity
    + first_color[1] * (1 - inter->effects.opacity);
  if (first_color[1] > 255)
    first_color[1] = 255;
  first_color[2] = new_color[2] * inter->effects.opacity
    + first_color[2] * (1 - inter->effects.opacity);
  if (first_color[2] > 255)
    first_color[2] = 255;
}

void			transparency(t_rt *rt, int *color,
				     t_coord *vector, t_eye *eye)
{
  int			first_color[3];
  int			new_color[3];
  int			new_obj;
  t_object		*inter;

  inter = rt->final_obj;
  first_color[0] = (int)((*color & 0xFF0000) >> 16);
  first_color[1] = (int)((*color & 0x00FF00) >> 8);
  first_color[2] = (int)(*color & 0x0000FF);
  new_obj = object_loop(rt, vector, eye, rt->transp.inter);
  if (rt->inter == TRUE && rt->final_obj != NULL
      && rt->final_obj->effects.opacity >= 0.1)
    {
      rt->transp.size_tab++;
      add_transp_tab(rt, rt->final_obj);
      transparency(rt, &new_obj, vector, eye);
    }
  transparency_color(first_color, new_color, new_obj, inter);
  *color = ((first_color[0] << 16) + (first_color[1] << 8) + first_color[2]);
}
