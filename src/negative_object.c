/*
** negative_object.c for negative_object.c in /home/loeb_t/Dropbox/Raytracer/transparence/src
**
** Made by thomas loeb
** Login   <loeb_t@epitech.net>
**
** Started on  Sun Jun  2 15:19:22 2013 thomas loeb
** Last update Sun Jun  9 14:43:17 2013 thomas loeb
*/

#include		"raytracer.h"

static t_inter_obj	g_inter_obj[5] =
  {
    {CONE_NB, &inter_cone},
    {CYLINDER_NB, &inter_cylinder},
    {SPHERE_NB, &inter_sphere},
    {PARABOLE_NB, &inter_parabole},
    {HYPERBOLE_NB, &inter_hyperbole}
  };

double			negative_inter(t_rt *rt, t_negative *neg,
				       char negative, t_object *object)
{
  double		ktmp;
  int			count;

  rt->negative = negative;
  count = 0;
  ktmp = -1;
  while (count < 5 && object->object_nb != g_inter_obj[count].nb)
    count++;
  if (count < 5)
    ktmp = g_inter_obj[count].inter_obj(rt, neg);
  return (ktmp);
}

void			negative_modify(t_rt *rt, t_negative *tmp,
					t_object *object, t_negative *neg)
{
  tmp->object = object;
  tmp->light = neg->light;
  tmp->vision = neg->vision;
  rt->inter_neg.neg_forward = negative_inter(rt, tmp, 1, object);
  rt->inter_neg.neg_backward = negative_inter(rt, tmp, 2, object);
  if (rt->inter_neg.neg_forward < rt->inter_neg.obj_forward &&
      rt->inter_neg.neg_backward > rt->inter_neg.obj_forward)
    {
      if (rt->inter_neg.obj_backward == -2)
	rt->inter_neg.obj_forward = -1;
      else
	{
	  if (rt->inter_neg.obj_backward > rt->inter_neg.neg_backward)
	    {
	      rt->inter_neg.obj_forward = rt->inter_neg.obj_backward;
	      rt->inside = TRUE;
	    }
	  else
	    rt->inter_neg.obj_forward = -1;
	}
    }
}

void			negative_shadow(t_rt *rt, t_negative *neg,
					t_object *prov, t_negative *negative)
{
  t_coord		coord;

  coord.x = (rt->k * neg->vision->vector->x
	     + neg->vision->eye->coord.x) - prov->coord.x;
  coord.y = (rt->k * neg->vision->vector->y
	     + neg->vision->eye->coord.y) - prov->coord.y;
  coord.z = (rt->k * neg->vision->vector->z
	     + neg->vision->eye->coord.z) - prov->coord.z;
  negative->prov_eye.coord.x = matrice_rotate_x(rt, &coord, prov, -1);
  negative->prov_eye.coord.y = matrice_rotate_y(rt, &coord, prov, -1);
  negative->prov_eye.coord.z = matrice_rotate_z(rt, &coord, prov, -1);
  coord.x = neg->light->coord.x - (rt->k * neg->vision->vector->x
				   + neg->vision->eye->coord.x);
  coord.y = neg->light->coord.y - (rt->k * neg->vision->vector->y
				   + neg->vision->eye->coord.y);
  coord.z = neg->light->coord.z - (rt->k * neg->vision->vector->z
				   + neg->vision->eye->coord.z);
  negative->prov_vector.x = matrice_rotate_x(rt, &coord, prov, -1);
  negative->prov_vector.y = matrice_rotate_y(rt, &coord, prov, -1);
  negative->prov_vector.z = matrice_rotate_z(rt, &coord, prov, -1);
}

void			negative_matrice(t_rt *rt, t_negative *neg,
					 t_object *prov, t_negative *negative)
{
  t_coord		coord;

  if (rt->shadow == FALSE)
    {
      coord.x = (neg->vision->eye->coord.x - prov->coord.x);
      coord.y = (neg->vision->eye->coord.y - prov->coord.y);
      coord.z = (neg->vision->eye->coord.z - prov->coord.z);
      negative->prov_eye.coord.x = matrice_rotate_x(rt, &coord, prov, -1);
      negative->prov_eye.coord.y = matrice_rotate_y(rt, &coord, prov, -1);
      negative->prov_eye.coord.z = matrice_rotate_z(rt, &coord, prov, -1);
      negative->prov_vector.x =
	matrice_rotate_x(rt, neg->vision->vector, prov, -1);
      negative->prov_vector.y =
	matrice_rotate_y(rt, neg->vision->vector, prov, -1);
      negative->prov_vector.z =
	matrice_rotate_z(rt, neg->vision->vector, prov, -1);
    }
  else
    negative_shadow(rt, neg, prov, negative);
}

double			negative_object(t_rt *rt, double k_obj,
					double behind, t_negative *neg)
{
  t_object		*prov;
  t_negative		negative;

  prov = rt->first_object;
  rt->inter_neg.neg_forward = -1;
  rt->inter_neg.obj_forward = k_obj;
  rt->inter_neg.obj_backward = behind;
  while (prov != NULL)
    {
      if (prov->limit != 0)
        {
	  negative_matrice(rt, neg, prov, &negative);
	  negative.eye = &negative.prov_eye;
	  negative.vector = &negative.prov_vector;
	  negative_modify(rt, &negative, prov, neg);
        }
      prov = prov->next;
    }
  rt->negative = 1;
  if (rt->inter_neg.obj_forward != rt->inter_neg.obj_backward ||
      rt->shadow == TRUE)
    rt->negative = 0;
  return (rt->inter_neg.obj_forward);
}
