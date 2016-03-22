/*
** cpy_object_list.c for cpy_object_list.c in /home/abgral_f//Projetsave/rt3/src
**
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
**
** Started on  Mon May 27 13:10:26 2013 franck abgrall
** Last update Sun Jun  9 16:09:29 2013 alan chauchet
*/

#include		"raytracer.h"

static void		fill_object_cpy(t_object *cpy, t_object *ref)
{
  cpy->effects.reflexion = ref->effects.reflexion;
  cpy->effects.opacity = ref->effects.opacity;
  cpy->effects.brightness = ref->effects.brightness;
  cpy->effects.disturb_x = ref->effects.disturb_x;
  cpy->effects.disturb_y = ref->effects.disturb_y;
  cpy->effects.check_frequency = ref->effects.check_frequency;
  cpy->rotate.rx = ref->rotate.rx;
  cpy->rotate.ry = ref->rotate.ry;
  cpy->rotate.rz = ref->rotate.rz;
  cpy->coord.x = ref->coord.x;
  cpy->coord.y = ref->coord.y;
  cpy->coord.z = ref->coord.z;
  cpy->param = ref->param;
  cpy->radius = ref->radius;
  cpy->limit = ref->limit;
  cpy->object_nb = ref->object_nb;
  cpy->color = ref->color;
}

static int		add_first_object_cpy(t_rt *cpy, t_rt *rt)
{
  t_object		*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (my_puterror(MALLOC_ERROR));
  cpy->first_object = new;
  cpy->last_object = new;
  new->next = NULL;
  fill_object_cpy(new, rt->first_object);
  return (EXIT_SUCCESS);
}

static int		add_other_object_cpy(t_rt *cpy, t_rt *rt)
{
  t_object		*new;
  t_object		*tmp_cpy;
  t_object		*tmp;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (my_puterror(MALLOC_ERROR));
  tmp = rt->first_object;
  tmp_cpy = cpy->first_object;
  while (tmp_cpy->next != NULL)
    {
      tmp_cpy = tmp_cpy->next;
      tmp = tmp->next;
    }
  tmp = tmp->next;
  cpy->last_object = new;
  tmp_cpy->next = new;
  new->next = NULL;
  fill_object_cpy(new, tmp);
  return (EXIT_SUCCESS);
}

static int		add_object_cpy(t_rt *cpy, t_rt *rt)
{
  if (cpy->first_object == NULL)
    {
      if (add_first_object_cpy(cpy, rt) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    }
  else
    if (add_other_object_cpy(cpy, rt) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		cpy_object_list(t_rt *cpy, t_rt *rt)
{
  t_object		*tmp;

  tmp = rt->first_object;
  while (tmp != NULL)
    {
      if (add_object_cpy(cpy, rt) == EXIT_FAILURE)
        return (EXIT_FAILURE);
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}
