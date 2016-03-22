/*
** transparency.c for transparency.c in /home/acca_b/Dropbox/EPITECH/Tek1/Raytracer/transparence/src
**
** Made by baptiste acca
** Login   <acca_b@epitech.net>
**
** Started on  Mon May 27 16:51:41 2013 baptiste acca
** Last update Sat Jun  8 17:15:39 2013 baptiste acca
*/

#include		"raytracer.h"

int			sign(double nb)
{
  if (nb < 0)
    return (-1);
  return (1);
}

void			reflexion_color(int *color, t_object *inter,
					int new_obj)
{
  int			first_color[3];
  int			new_color[3];

  first_color[0] = (int)((*color & 0xFF0000) >> 16);
  first_color[1] = (int)((*color & 0x00FF00) >> 8);
  first_color[2] = (int)(*color & 0x0000FF);
  new_color[0] = (int)((new_obj & 0xFF0000) >> 16);
  new_color[1] = (int)((new_obj & 0x00FF00) >> 8);
  new_color[2] = (int)(new_obj & 0x0000FF);
  first_color[0] = new_color[0] * inter->effects.reflexion
    + first_color[0] * (1 - inter->effects.reflexion);
  if (first_color[0] > 255)
    first_color[0] = 255;
  first_color[1] = new_color[1] * inter->effects.reflexion
    + first_color[1] * (1 - inter->effects.reflexion);
  if (first_color[1] > 255)
    first_color[1] = 255;
  first_color[2] = new_color[2] * inter->effects.reflexion
    + first_color[2] * (1 - inter->effects.reflexion);
  if (first_color[2] > 255)
    first_color[2] = 255;
  *color = ((first_color[0] << 16) + (first_color[1] << 8) + first_color[2]);
}

void			reflexion_plan(t_coord *vector_r, t_coord *vector,
				       t_coord norm, t_eye *next_eye)
{
  vector_r->x = vector->x;
  vector_r->y = vector->y;
  vector_r->z = vector->z;
  if (norm.x > 0.000001 || norm.x < -0.999999)
    vector_r->x = ((-100) / norm.x) * vector->x;
  if (norm.y > 0.000001 || norm.y < -0.999999)
    vector_r->y = ((-100) / norm.y) * vector->y;
  if (norm.z > 0.000001 || norm.z < -0.999999)
    vector_r->z = ((-100) / norm.z) * vector->z;
  next_eye->coord.x += sign(norm.x);
  next_eye->coord.y += sign(norm.y);
  next_eye->coord.z += sign(norm.z);
}

void			reflexion(t_rt *rt, int *color,
				  t_coord *vector, t_eye *eye)
{
  int			new_obj;
  t_object		*inter;
  t_vision		vision;
  t_coord		new_vector;
  t_eye			new_eye;
  t_coord		vector_r;
  t_eye			next_eye;
  t_coord		norm;

  rt->stop_reflexion++;
  inter = rt->final_obj;
  calc_matrice_eye(rt, rt->final_obj, eye, &new_eye);
  calc_matrice_vector(rt, rt->final_obj, vector, &new_vector);
  vision = assign_vision(&new_vector, &new_eye, vector, eye);
  calc_norm_reflexion(rt, &vision, &norm, inter);
  calc_next_eye_reflexion(rt, &vision, &next_eye);
  if (inter->object_nb == PLAN_NB)
    reflexion_plan(&vector_r, vision.vector, norm, &next_eye);
  else
    calc_reflected_vector(&vector_r, &norm, &vision);
  new_obj = object_loop(rt, &vector_r, &next_eye, NULL);
  if (rt->inter == TRUE && rt->final_obj->effects.reflexion > 0.000001 &&
      rt->stop_reflexion < 200)
    reflexion(rt, &new_obj, &vector_r, &next_eye);
  reflexion_color(color, inter, new_obj);
}
