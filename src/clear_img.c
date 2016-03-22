/*
** clear_img.c for rt in /home/domois_a//MERGE
** 
** Made by adrien domoison
** Login   <domois_a@epitech.net>
** 
** Started on  Sun Jun  9 17:45:41 2013 adrien domoison
** Last update Sun Jun  9 18:05:27 2013 adrien domoison
*/

#include		"raytracer.h"

void			clear_img(t_rt *rt)
{
  int			pos;
  int			max;

  pos = 0;
  max = rt->size.win_y * rt->size.win_y;
  while (pos <= max)
    {
      aff_loading(rt, pos, max, 0x000000);
      pos++;
    }
}
