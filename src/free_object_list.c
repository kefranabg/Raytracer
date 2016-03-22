/*
** free_object_list.c for free_object_list.c in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g/src
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Tue May 14 21:17:59 2013 franck abgrall
** Last update Sun Jun  9 16:08:43 2013 alan chauchet
*/

#include	"raytracer.h"

int		free_object_list(t_rt *rt)
{
  t_object	*tmp;
  t_object	*tmp_to_free;

  tmp = rt->first_object;
  while (tmp != NULL)
    {
      tmp_to_free = tmp;
      tmp = tmp->next;
      free(tmp_to_free);
    }
  return (EXIT_SUCCESS);
}
