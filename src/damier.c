/*
** damier.c for rt in /home/chauch_a//damier
** 
** Made by alan chauchet
** Login   <chauch_a@epitech.net>
** 
** Started on  Tue Jun  4 21:18:23 2013 alan chauchet
** Last update Tue Jun  4 21:18:36 2013 alan chauchet
*/

#include	"raytracer.h"

void		damier(t_rt *rt, t_object *object,
		       t_coord *vector, t_eye *eye)
{
  int		freq;

  freq = (rt->general_param.anti_aliasing
	  * object->effects.check_frequency) / 2;
  if (freq == 0)
    freq = 1;
  if ((sin(M_PI / freq)
       * sin((M_PI / freq) * (eye->coord.y + rt->k * vector->y)) >= 0
       && sin(M_PI / freq) * sin((M_PI / freq)
				 * (eye->coord.x + rt->k * vector->x)) >= 0)
      || (sin(M_PI / freq)
	  * sin((M_PI / freq) * (eye->coord.y + rt->k * vector->y)) < 0
	  && sin(M_PI / freq) * sin((M_PI / freq)
				    * (eye->coord.x + rt->k * vector->x)) < 0))
    rt->color = 0xFFFFFF - object->color;
  else
    rt->color = object->color;
}
