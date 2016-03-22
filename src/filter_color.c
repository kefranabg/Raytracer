/*
** filter_color.c for rt in /home/chauch_a//Dropbox/Raytracer/transparence
**
** Made by alan chauchet
** Login   <chauch_a@epitech.net>
**
** Started on  Tue Jun  4 20:16:35 2013 alan chauchet
** Last update Sat Jun  8 15:13:19 2013 alan chauchet
*/

#include	"raytracer.h"

static t_filter		g_filter[10] =
  {
    {&negativ_filter},
    {&mix_filter},
    {&sepia_filter},
    {&black_white_filter},
    {&red_filter},
    {&green_filter},
    {&blue_filter},
    {&purple_filter},
    {&cyan_filter},
    {&grey_filter},
  };

void		filter_color(t_rt *rt, int *color)
{
  if (rt->general_param.filter > 0)
    *color = g_filter[rt->general_param.filter - 1].filter_fctn(*color);
}
