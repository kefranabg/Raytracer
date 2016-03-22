/*
** check_eyes_number.c for check_eyes_number.c in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g/src
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Tue May 14 21:41:30 2013 franck abgrall
** Last update Sun Jun  9 16:41:16 2013 alan chauchet
*/

#include	"raytracer.h"

int		check_eyes_number(t_rt *rt)
{
  t_object	*tmp;
  int		count;

  count = 0;
  tmp = rt->first_object;
  while (tmp != NULL)
    {
      if (tmp->object_nb == EYES_NB)
	count++;
      tmp = tmp->next;
    }
  if (count == 0)
    {
      my_puterror(NO_EYES);
      return (EXIT_FAILURE);
    }
  if (count > 1)
    {
      my_puterror(TOO_MANY_EYES);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
