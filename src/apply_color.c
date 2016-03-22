/*
** apply_color.c for rt in /home/acca_b/Dropbox/EPITECH/Tek1/Raytracer/raytracer-2017-chanut_g/src
**
** Made by baptiste acca
** Login   <acca_b@epitech.net>
**
** Started on  Thu May 16 16:45:53 2013 baptiste acca
** Last update Sat Jun  8 06:00:17 2013 franck abgrall
*/

#include		"raytracer.h"

void			color_no_spot(t_rt *rt)
{
  if (rt->first_light == NULL)
    {
      rt->light_var.cos_a = rt->general_param.ambiance_light;
      rt->light_var.brightness = 0;
      rt->light_var.color.red = 255 * rt->general_param.ambiance_light;
      rt->light_var.color.green = 255 * rt->general_param.ambiance_light;
      rt->light_var.color.blue = 255 * rt->general_param.ambiance_light;
    }
}

int			apply_color(t_rt *rt)
{
  int			color[3];

  color_no_spot(rt);
  if (rt->light_var.cos_a < rt->general_param.ambiance_light)
    rt->light_var.cos_a = rt->general_param.ambiance_light;
  if (rt->light_var.shadow < 0.1)
    rt->light_var.shadow = rt->general_param.ambiance_light;
  color[0] = (int)((rt->color & 0xFF0000) >> 16) * rt->light_var.cos_a
    * rt->light_var.shadow + rt->light_var.color.red
    * rt->light_var.brightness * rt->light_var.cos_a * rt->light_var.shadow;
  if (color[0] > 255)
    color[0] = 255;
  color[1] = (int)((rt->color & 0x00FF00) >> 8)
    * rt->light_var.cos_a * rt->light_var.shadow
    + rt->light_var.color.green * rt->light_var.brightness
    * rt->light_var.cos_a * rt->light_var.shadow;
  if (color[1] > 255)
    color[1] = 255;
  color[2] = (int)(rt->color & 0x0000FF)
    * rt->light_var.cos_a * rt->light_var.shadow
    + rt->light_var.color.blue * rt->light_var.brightness
    * rt->light_var.cos_a * rt->light_var.shadow;
  if (color[2] > 255)
    color[2] = 255;
  return ((color[0] << 16) + (color[1] << 8) + color[2]);
}
