/*
** apply_filter2.c for apply_filter2.c in /home/acca_b/Dropbox/EPITECH/Tek1/Raytracer/transparence
**
** Made by baptiste acca
** Login   <acca_b@epitech.net>
**
** Started on  Sat Jun  8 14:31:26 2013 baptiste acca
** Last update Sat Jun  8 14:35:45 2013 baptiste acca
*/

#include		"raytracer.h"

int			green_filter(int color)
{
  int			color_tmp[3];

  color_tmp[0] = (int)((color & 0xFF0000) >> 16) * 0.2;
  color_tmp[1] = (int)((color & 0x00FF00) >> 8);
  color_tmp[2] = (int)(color & 0x0000FF) * 0.2;
  return (((color_tmp[0] << 16)
	   + (color_tmp[1] << 8) + color_tmp[2]));
}

int			blue_filter(int color)
{
  int			color_tmp[3];

  color_tmp[0] = (int)((color & 0xFF0000) >> 16) * 0.2;
  color_tmp[1] = (int)((color & 0x00FF00) >> 8) * 0.2;
  color_tmp[2] = (int)(color & 0x0000FF);
  return (((color_tmp[0] << 16)
	   + (color_tmp[1] << 8) + color_tmp[2]));
}

int			purple_filter(int color)
{
  int			color_tmp[3];

  color_tmp[0] = (int)((color & 0xFF0000) >> 16);
  color_tmp[1] = (int)((color & 0x00FF00) >> 8) * 0.2;
  color_tmp[2] = (int)(color & 0x0000FF);
  return (((color_tmp[0] << 16)
	   + (color_tmp[1] << 8) + color_tmp[2]));
}

int			cyan_filter(int color)
{
  int			color_tmp[3];

  color_tmp[0] = (int)((color & 0xFF0000) >> 16) * 0.2;
  color_tmp[1] = (int)((color & 0x00FF00) >> 8);
  color_tmp[2] = (int)(color & 0x0000FF);
  return (((color_tmp[0] << 16)
	   + (color_tmp[1] << 8) + color_tmp[2]));
}

int			grey_filter(int color)
{
  int			color_tmp[3];

  color_tmp[0] = (int)((color & 0xFF0000) >> 16) * 0.2;
  color_tmp[1] = (int)((color & 0x00FF00) >> 8) * 0.2;
  color_tmp[2] = (int)(color & 0x0000FF) * 0.2;
  return (((color_tmp[0] << 16)
	   + (color_tmp[1] << 8) + color_tmp[2]));
}
