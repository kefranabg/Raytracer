/*
** reflexion_calc.c for reflexion_calc.c in /home/acca_b/Dropbox/EPITECH/Tek1/Raytracer/transparence
**
** Made by baptiste acca
** Login   <acca_b@epitech.net>
**
** Started on  Sat Jun  8 17:12:00 2013 baptiste acca
** Last update Sun Jun  9 15:57:09 2013 alan chauchet
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

void			calc_norm_reflexion(t_rt *rt, t_vision *vision,
					    t_coord *norm, t_object *inter)
{
  int			count;

  count = 0;
  while (count < 6 &&
  	 inter->object_nb != g_object_tab[count].object_nb)
    count++;
  if (count < 6)
    g_object_tab[count].fct_lum(rt, vision, inter, norm);
}

void			calc_next_eye_reflexion(t_rt *rt, t_vision *vision,
						t_eye *next_eye)
{
  next_eye->coord.x = rt->k * vision->vector->x + vision->eye->coord.x;
  next_eye->coord.y = rt->k * vision->vector->y + vision->eye->coord.y;
  next_eye->coord.z = rt->k * vision->vector->z + vision->eye->coord.z;
}

void			calc_reflected_vector(t_coord *vector_r, t_coord *norm,
					      t_vision *vision)
{
  double		scal;

  scal = vision->vector->x * norm->x
    + vision->vector->y * norm->y + vision->vector->z * norm->z;
  vector_r->x = (-2 * norm->x * scal) + vision->vector->x;
  vector_r->y = (-2 * norm->y * scal) + vision->vector->y;
  vector_r->z = (-2 * norm->z * scal) + vision->vector->z;
}

t_vision		assign_vision(t_coord *new_vector, t_eye *new_eye,
				      t_coord *vector, t_eye *eye)
{
  t_vision		vision;

  vision.new_eye = new_eye;
  vision.new_vector = new_vector;
  vision.vector = vector;
  vision.eye = eye;
  return (vision);
}
