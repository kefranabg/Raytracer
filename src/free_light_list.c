/*
** free_light_list.c for free_light_list.c in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g/src
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Fri May 17 01:05:09 2013 franck abgrall
** Last update Sun Jun  9 16:08:47 2013 alan chauchet
*/

#include	"raytracer.h"

int		free_light_list(t_rt *rt)
{
  t_light	*tmp;
  t_light	*tmp_to_free;

  tmp = rt->first_light;
  while (tmp != NULL)
    {
      tmp_to_free = tmp;
      tmp = tmp->next;
      free(tmp_to_free);
    }
  return (EXIT_SUCCESS);
}
