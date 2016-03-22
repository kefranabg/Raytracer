/*
** loop_light.c for rt in /home/acca_b/Dropbox/EPITECH/Tek1/Raytracer/raytracer-2017-chanut_g/src
**
** Made by baptiste acca
** Login   <acca_b@epitech.net>
**
** Started on  Fri May 17 17:29:43 2013 baptiste acca
** Last update Sun Jun  9 15:56:48 2013 alan chauchet
*/

#include		"raytracer.h"

static t_object_tab	g_object_tab[6] =
  {
    {CONE_NB, &cone_luminosity},
    {CYLINDER_NB, &cylinder_luminosity},
    {SPHERE_NB, &sphere_luminosity},
    {PLAN_NB, &plan_luminosity},
    {PARABOLE_NB, &parabole_luminosity},
    {HYPERBOLE_NB, &hyperbole_luminosity},
  };

void			change_var(t_rt *rt, double cos_atmp,
				   t_light *light, t_object *object)
{
  rt->light_var.cos_a += cos_atmp;
  rt->light_var.color.red += ((light->color & 0xFF0000) >> 16);
  rt->light_var.color.green += ((light->color & 0x00FF00) >> 8);
  rt->light_var.color.blue += ((light->color & 0x0000FF));
  rt->light_var.brightness = object->effects.brightness;
}

void			calc_light_var(t_rt *rt, t_light *light,
				       t_vision *vision)
{
  rt->light_var.vector.x = light->coord.x
    - (rt->k * vision->vector->x + vision->eye->coord.x);
  rt->light_var.vector.y = light->coord.y
    - (rt->k * vision->vector->y + vision->eye->coord.y);
  rt->light_var.vector.z = light->coord.z
    - (rt->k * vision->vector->z + vision->eye->coord.z);
  rt->light_var.norme_l = sqrt(pow(rt->light_var.vector.x, 2)
			       + pow(rt->light_var.vector.y, 2)
			       + pow(rt->light_var.vector.z, 2));
}

void			check_light(t_rt *rt, t_light *light,
				    t_object *object, t_vision *vision)
{
  double		cos_atmp;
  int			count;

  calc_light_var(rt, light, vision);
  count = 0;
  while (count < 6 &&
  	 object->object_nb != g_object_tab[count].object_nb)
    count++;
  if (count < 6)
    g_object_tab[count].fct_lum(rt, vision,
				       object, &rt->light_var.norm);
  rt->light_var.norme_n = sqrt(pow(rt->light_var.norm.x, 2)
			       + pow(rt->light_var.norm.y, 2)
			       + pow(rt->light_var.norm.z, 2));
  rt->light_var.shadow += check_shadow(rt, light, vision);
  cos_atmp = ((rt->light_var.vector.x * rt->light_var.norm.x)
	      + (rt->light_var.vector.y * rt->light_var.norm.y)
	      + (rt->light_var.vector.z * rt->light_var.norm.z))
    / (rt->light_var.norme_n * rt->light_var.norme_l);
  if (cos_atmp > 0.000001)
    change_var(rt, cos_atmp, light, object);
}

void			loop_light(t_rt *rt, t_object *object, t_vision *vision)
{
  t_light		*light;
  int			count;

  rt->light_var.shadow = 0;
  rt->light_var.cos_a = 0;
  rt->light_var.color.red = 0;
  rt->light_var.color.blue = 0;
  rt->light_var.color.green = 0;
  light = rt->first_light;
  count = 0;
  while (light != NULL)
    {
      count++;
      check_light(rt, light, object, vision);
      light = light->next;
    }
  rt->light_var.shadow /= count;
}
