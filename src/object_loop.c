/*
** object_loop.c for rt in /home/chauch_a//Dropbox/Raytracer/raytracer-2017-chanut_g
**
** Made by alan chauchet
** Login   <chauch_a@epitech.net>
**
** Started on  Thu May 16 14:42:52 2013 alan chauchet
** Last update Sun Jun  9 17:04:56 2013 alan chauchet
*/

#include	"raytracer.h"

static t_inter_obj	g_inter_obj[6] =
  {
    {CONE_NB, &inter_cone},
    {CYLINDER_NB, &inter_cylinder},
    {SPHERE_NB, &inter_sphere},
    {PLAN_NB, &inter_plan},
    {PARABOLE_NB, &inter_parabole},
    {HYPERBOLE_NB, &inter_hyperbole}
  };

void		check_if_inter(t_rt *rt, t_object *object,
			       t_vision *vision, t_negative *negative)
{
  int		count;
  double	prov_k;

  prov_k = -1;
  count = 0;
  while (count < 6 && object->object_nb != g_inter_obj[count].nb)
    count++;
  if (count != 6)
    prov_k = g_inter_obj[count].inter_obj(rt, negative);
  if (prov_k > 0 && (rt->inter == FALSE || prov_k < rt->k))
    {
      rt->k = prov_k;
      if (object->effects.check_frequency > 0)
	damier(rt, object, vision->vector, vision->eye);
      else
	rt->color = object->color;
      rt->inter = TRUE;
      rt->final_obj = object;
      if (rt->first_light != NULL)
	loop_light(rt, rt->final_obj, vision);
    }
}

void		check_object(t_rt *rt, t_object *object,
			     t_coord *vector, t_eye *eye)
{
  t_negative	negative;
  t_vision	vision;
  t_coord	new_vector;
  t_eye		new_eye;

  calc_matrice_eye(rt, object, eye, &new_eye);
  calc_matrice_vector(rt, object, vector, &new_vector);
  vision.eye = eye;
  vision.vector = vector;
  vision.new_eye = &new_eye;
  vision.new_vector = &new_vector;
  rt->shadow = FALSE;
  rt->negative = 0;
  negative.object = object;
  negative.eye = &new_eye;
  negative.vector = &new_vector;
  negative.light = NULL;
  negative.vision = &vision;
  check_if_inter(rt, object, &vision, &negative);
}

int		no_check_obj(t_rt *rt, t_object **no_obj,
			     t_object *object)
{
  int		count;

  count = 0;
  while (count < rt->transp.size_tab)
    {
      if (no_obj[count] == object)
	return (0);
      count++;
    }
  return (1);
}

int		object_loop(t_rt *rt, t_coord *vector,
			    t_eye *eye, t_object **no_obj)
{
  t_object	*object;

  object = rt->first_object;
  rt->final_obj = NULL;
  rt->inter = FALSE;
  rt->inside = FALSE;
  while (object != NULL)
    {
      if (object->limit == 0 &&
	  (no_obj == NULL || no_check_obj(rt, no_obj, object) == 1))
	check_object(rt, object, vector, eye);
      object = object->next;
    }
  if (rt->inter == FALSE)
    {
      if (rt->general_param.backscreen.name != NULL)
	return (pixel_backscreen(rt, rt->pos_x, rt->pos_y));
      return (0x000000);
    }
  else
    return (apply_color(rt));
}
