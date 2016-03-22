/*
** apply_filter1.c for apply_filter1.c in /home/acca_b/Dropbox/EPITECH/Tek1/Raytracer/transparence
**
** Made by baptiste acca
** Login   <acca_b@epitech.net>
**
** Started on  Sat Jun  8 14:22:57 2013 baptiste acca
** Last update Sat Jun  8 14:33:11 2013 baptiste acca
*/

#include		"raytracer.h"

int			negativ_filter(int color)
{
  return (0xFFFFFF - color);
}

int			mix_filter(int color)
{
  if (0xFFFFFF - color > 0x000000 - color)
    return (color * 0.2);
  else
    return (color * 0.8);
}

int			sepia_filter(int color)
{
  int			color_tmp[3];
  int			final_color[3];

  color_tmp[0] = (int)((color & 0xFF0000) >> 16);
  color_tmp[1] = (int)((color & 0x00FF00) >> 8);
  color_tmp[2] = (int)(color & 0x0000FF);
  final_color[0] = (int)(((double)color_tmp[0] * 0.393)
			 + ((double)color_tmp[1] * 0.769)
			 + ((double)color_tmp[2] * 0.189));
  final_color[1] = (int)(((double)color_tmp[0] * 0.349)
			 + ((double)color_tmp[1] * 0.686)
			 + ((double)color_tmp[2] * 0.168));
  final_color[2] = (int)(((double)color_tmp[0] * 0.272)
			 + ((double)color_tmp[1] * 0.534)
			 + ((double)color_tmp[2] * 0.131));
  if (final_color[0] > 255)
    final_color[0] = 255;
  if (final_color[1] > 255)
    final_color[1] = 255;
  if (final_color[2] > 255)
    final_color[2] = 255;
  return (((final_color[0] << 16)
	   + (final_color[1] << 8) + final_color[2]));
}

int			black_white_filter(int color)
{
  int			grey_color;
  int			color_tmp[3];

  color_tmp[0] = (int)((color & 0xFF0000) >> 16);
  color_tmp[1] = (int)((color & 0x00FF00) >> 8);
  color_tmp[2] = (int)(color & 0x0000FF);
  grey_color = (int)(((double)color_tmp[0])
		     + ((double)color_tmp[1])
		     + ((double)color_tmp[2]));
  if (grey_color > 255)
    grey_color = 255;
  return (((grey_color << 16)
	   + (grey_color << 8) + grey_color));
}

int			red_filter(int color)
{
  int			color_tmp[3];

  color_tmp[0] = (int)((color & 0xFF0000) >> 16);
  color_tmp[1] = (int)((color & 0x00FF00) >> 8) * 0.2;
  color_tmp[2] = (int)(color & 0x0000FF) * 0.2;
  return (((color_tmp[0] << 16)
	   + (color_tmp[1] << 8) + color_tmp[2]));
}
