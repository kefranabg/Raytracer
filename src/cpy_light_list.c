/*
** cpy_light_list.c for cpy_light_list.c in /home/abgral_f//Projetsave/rt3/src
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Mon May 27 13:16:54 2013 franck abgrall
** Last update Sun Jun  9 16:09:42 2013 alan chauchet
*/

#include		"raytracer.h"

static void		fill_light_cpy(t_light *cpy, t_light *ref)
{
  cpy->coord.x = ref->coord.x;
  cpy->coord.y = ref->coord.y;
  cpy->coord.z = ref->coord.z;
  cpy->intensity = ref->intensity;
  cpy->color = ref->color;
}

static int		add_first_light_cpy(t_rt *cpy, t_rt *rt)
{
  t_light		*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (my_puterror(MALLOC_ERROR));
  cpy->first_light = new;
  cpy->last_light = new;
  new->next = NULL;
  fill_light_cpy(new, rt->first_light);
  return (EXIT_SUCCESS);
}

static int		add_other_light_cpy(t_rt *cpy, t_rt *rt)
{
  t_light		*new;
  t_light		*tmp_cpy;
  t_light		*tmp;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (my_puterror(MALLOC_ERROR));
  tmp = rt->first_light;
  tmp_cpy = cpy->first_light;
  while (tmp_cpy->next != NULL)
    {
      tmp_cpy = tmp_cpy->next;
      tmp = tmp->next;
    }
  tmp = tmp->next;
  cpy->last_light = new;
  tmp_cpy->next = new;
  new->next = NULL;
  fill_light_cpy(new, tmp);
  return (EXIT_SUCCESS);
}

static int		add_light_cpy(t_rt *cpy, t_rt *rt)
{
  if (cpy->first_light == NULL)
    {
      if (add_first_light_cpy(cpy, rt) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    }
  else
    if (add_other_light_cpy(cpy, rt) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		cpy_light_list(t_rt *cpy, t_rt *rt)
{
  t_light	*tmp;

  tmp = rt->first_light;
  while (tmp != NULL)
    {
      if (add_light_cpy(cpy, rt) == EXIT_FAILURE)
        return (EXIT_FAILURE);
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}
