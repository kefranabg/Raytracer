/*
** add_object.c for add_object.c in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Mon May 13 17:53:07 2013 franck abgrall
** Last update Sun Jun  9 16:13:24 2013 alan chauchet
*/

#include	"raytracer.h"

int		add_first_object(t_rt *rt, int object_nb)
{
  t_object	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (my_puterror(MALLOC_ERROR));
  rt->first_object = new;
  rt->last_object = new;
  new->next = NULL;
  new->object_nb = object_nb;
  return (EXIT_SUCCESS);
}

int		add_other_object(t_rt *rt, int object_nb)
{
  t_object	*new;
  t_object	*tmp;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (my_puterror(MALLOC_ERROR));
  tmp = rt->first_object;
  while (tmp->next != NULL)
    tmp = tmp->next;
  rt->last_object = new;
  tmp->next = new;
  new->next = NULL;
  new->object_nb = object_nb;
  return (EXIT_SUCCESS);
}

int		add_object(t_rt *rt, int object_nb)
{
  if (rt->first_object == NULL)
    {
      if (add_first_object(rt, object_nb) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else
    if (add_other_object(rt, object_nb) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
