/*
** object_list_one.c for objecy_list_one.c in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g/src
**
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
**
** Started on  Sat May 11 19:44:11 2013 franck abgrall
** Last update Sun Jun  9 16:03:56 2013 alan chauchet
*/

#include	"raytracer.h"

int		get_sphere_specs(t_list *list, int object_nb, t_rt *rt)
{
  if (object_nb == SPHERE_NB)
    {
      if (add_object(rt, object_nb) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (get_coord(list, rt) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (get_rotate(list, rt) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if ((rt->last_object->color =
	   get_color(list, rt, COLOR_NB)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (get_effects(list, rt) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if ((rt->last_object->param =
	   get_specs(list, rt, RADIUS_NB)) == -1)
	return (EXIT_FAILURE);
      if ((rt->last_object->limit = get_specs(list, rt, LIMIT_NB))
          == -1)
        return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int		get_cylinder_specs(t_list *list, int object_nb, t_rt *rt)
{
  if (object_nb == CYLINDER_NB)
    {
      if (add_object(rt, object_nb) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (get_coord(list, rt) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if ((rt->last_object->color =
	   get_color(list, rt, COLOR_NB)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (get_rotate(list, rt) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (get_effects(list, rt) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if ((rt->last_object->param =
	   get_specs(list, rt, RADIUS_NB)) == -1)
	return (EXIT_FAILURE);
      if ((rt->last_object->limit = get_specs(list, rt, LIMIT_NB))
          == -1)
        return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int		get_plan_specs(t_list *list, int object_nb, t_rt *rt)
{
  if (object_nb == PLAN_NB)
    {
      if (add_object(rt, object_nb) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (get_coord(list, rt) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if ((rt->last_object->color =
	  get_color(list, rt, COLOR_NB)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (get_rotate(list, rt) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (get_effects(list, rt) == -1)
	return (EXIT_FAILURE);
      if ((rt->last_object->limit = get_specs(list, rt, LIMIT_NB))
          == -1)
        return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int		get_parabole_specs(t_list *list, int object_nb, t_rt *rt)
{
  if (object_nb == PARABOLE_NB)
    {
      if (add_object(rt, object_nb) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (get_coord(list, rt) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (get_rotate(list, rt) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if ((rt->last_object->color =
	   get_color(list, rt, COLOR_NB)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (get_effects(list, rt) == -1)
	return (EXIT_FAILURE);
      if ((rt->last_object->param = get_specs(list, rt, ANGLE_NB))
	  == -1)
	return (EXIT_FAILURE);
      if ((rt->last_object->limit = get_specs(list, rt, LIMIT_NB))
          == -1)
        return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int		get_hyperbole_specs(t_list *list, int object_nb, t_rt *rt)
{
  if (object_nb == HYPERBOLE_NB)
    {
      if (add_object(rt, object_nb) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (get_coord(list, rt) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (get_rotate(list, rt) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if ((rt->last_object->color =
	   get_color(list, rt, COLOR_NB)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (get_effects(list, rt) == -1)
	return (EXIT_FAILURE);
      if ((rt->last_object->radius =
	   get_specs(list, rt, RADIUS_NB)) == -1)
	return (EXIT_FAILURE);
      if ((rt->last_object->param = get_specs(list, rt, ANGLE_NB))
	  == -1)
	return (EXIT_FAILURE);
      if ((rt->last_object->limit = get_specs(list, rt, LIMIT_NB))
          == -1)
        return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
