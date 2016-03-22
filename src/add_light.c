/*
** add_light.c for rt in /home/acca_b/Dropbox/EPITECH/Tek1/Raytracer/raytracer-2017-chanut_g/src
**
** Made by baptiste acca
** Login   <acca_b@epitech.net>
**
** Started on  Thu May 16 14:39:33 2013 baptiste acca
** Last update Sun Jun  9 16:13:36 2013 alan chauchet
*/

#include	"raytracer.h"

int		add_first_light(t_rt *rt)
{
  t_light	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (my_puterror(MALLOC_ERROR));
  rt->first_light = new;
  rt->last_light = new;
  new->next = NULL;
  return (EXIT_SUCCESS);
}

int		add_other_light(t_rt *rt)
{
  t_light	*new;
  t_light	*tmp;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (my_puterror(MALLOC_ERROR));
  tmp = rt->first_light;
  while (tmp->next != NULL)
    tmp = tmp->next;
  rt->last_light = new;
  tmp->next = new;
  new->next = NULL;
  return (EXIT_SUCCESS);
}

int		add_light(t_rt *rt)
{
  if (rt->first_light == NULL)
    {
      if (add_first_light(rt) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else
    if (add_other_light(rt) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
