/*
** load_cos_and_sin.c for rt in /home/chauch_a//Dropbox/Raytracer/raytracer-2017-chanut_g
** 
** Made by alan chauchet
** Login   <chauch_a@epitech.net>
** 
** Started on  Thu May 16 10:57:52 2013 alan chauchet
** Last update Sun Jun  9 16:04:46 2013 alan chauchet
*/

#include	"raytracer.h"

void		load_cos_and_sin(t_rt *rt)
{
  int		count;

  count = 0;
  while (count < 360)
    {
      rt->cosinus[count] = cos(RAD(count));
      rt->sinus[count] = sin(RAD(count));
      count++;
    }
}
