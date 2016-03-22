/*
** check_shadow.c for rt in /home/acca_b/Dropbox/EPITECH/Tek1/Raytracer/raytracer-2017-chanut_g/src
**
** Made by baptiste acca
** Login   <acca_b@epitech.net>
**
** Started on  Fri May 17 17:57:44 2013 baptiste acca
** Last update Sun Jun  9 16:10:11 2013 alan chauchet
*/

#include		"raytracer.h"

static t_inter_obj	g_inter_obj[6] =
  {
    {CONE_NB, &inter_cone},
    {CYLINDER_NB, &inter_cylinder},
    {SPHERE_NB, &inter_sphere},
    {PLAN_NB, &inter_plan},
    {PARABOLE_NB, &inter_parabole},
    {HYPERBOLE_NB, &inter_hyperbole}
  };

void			calc_prov_eye(t_rt *rt, t_object *object,
				      t_vision *vision)
{
  t_coord		coord;

  coord.x = (rt->k * vision->vector->x
	     + vision->eye->coord.x) - object->coord.x;
  coord.y = (rt->k * vision->vector->y
	     + vision->eye->coord.y) - object->coord.y;
  coord.z = (rt->k * vision->vector->z
	     + vision->eye->coord.z) - object->coord.z;
  vision->new_eye->coord.x = matrice_rotate_x(rt, &coord, object, -1);
  vision->new_eye->coord.y = matrice_rotate_y(rt, &coord, object, -1);
  vision->new_eye->coord.z = matrice_rotate_z(rt, &coord, object, -1);
}

void			calc_prov_vector(t_rt *rt, t_light *light,
					t_object *object, t_vision *vision)
{
  t_coord		coord;

  coord.x = light->coord.x - (rt->k * vision->vector->x
			      + vision->eye->coord.x);
  coord.y = light->coord.y - (rt->k * vision->vector->y
			      + vision->eye->coord.y);
  coord.z = light->coord.z - (rt->k * vision->vector->z
			      + vision->eye->coord.z);
  vision->new_vector->x = matrice_rotate_x(rt, &coord, object, -1);
  vision->new_vector->y = matrice_rotate_y(rt, &coord, object, -1);
  vision->new_vector->z = matrice_rotate_z(rt, &coord, object, -1);
}

double			shadow_object(t_rt *rt, t_object *object,
				      t_vision *vision, t_light *light)
{
  t_negative		negative;
  double		ktmp;
  int			count;

  rt->shadow = TRUE;
  negative.object = object;
  negative.eye = vision->new_eye;
  negative.vector = vision->new_vector;
  negative.light = light;
  negative.vision = vision;
  ktmp = rt->k;
  count = 0;
  while (count < 6 && object->object_nb != g_inter_obj[count].nb)
    count++;
  if (count != 6)
    ktmp = g_inter_obj[count].inter_obj(rt, &negative);
  return (ktmp);
}

void			shadow_save_restore_eye(double (*tmp)[6],
						t_vision *vision,
						char status)
{
  if (status == 0)
    {
      (*tmp)[0] = vision->new_vector->x;
      (*tmp)[1] = vision->new_vector->y;
      (*tmp)[2] = vision->new_vector->z;
      (*tmp)[3] = vision->new_eye->coord.x;
      (*tmp)[4] = vision->new_eye->coord.y;
      (*tmp)[5] = vision->new_eye->coord.z;
    }
  else
    {
      vision->new_vector->x = (*tmp)[0];
      vision->new_vector->y = (*tmp)[1];
      vision->new_vector->z = (*tmp)[2];
      vision->new_eye->coord.x = (*tmp)[3];
      vision->new_eye->coord.y = (*tmp)[4];
      vision->new_eye->coord.z = (*tmp)[5];
    }
}

char			check_shadow(t_rt *rt, t_light *light,
				     t_vision *vision)
{
  t_object		*object_tmp;
  double		ktmp;
  char			ret;
  double		tmp[6];

  ret = 1;
  object_tmp = rt->first_object;
  shadow_save_restore_eye(&tmp, vision, 0);
  while (object_tmp != NULL)
    {
      if (object_tmp->limit == 0)
	{
	  calc_prov_eye(rt, object_tmp, vision);
	  calc_prov_vector(rt, light, object_tmp, vision);
	  ktmp = shadow_object(rt, object_tmp, vision, light);
	  if (ktmp > 0.00001 && ktmp < 1)
	    ret = 0;
	}
      object_tmp = object_tmp->next;
    }
  shadow_save_restore_eye(&tmp, vision, 1);
  return (ret);
}
