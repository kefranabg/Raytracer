/*
** thread_create.c for thread_create.c in /home/abgral_f//Projetsave/rt3/src
**
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
**
** Started on  Mon May 27 13:29:25 2013 franck abgrall
** Last update Sat Jun  8 06:49:50 2013 franck abgrall
*/

#include		<pthread.h>
#include		"raytracer.h"

int			thread_creation(t_rt *rt)
{
  int			count;
  int			repart;
  pthread_t		thread[4];
  void			*ret;

  count = 0;
  repart = rt->size.size_x * rt->size.size_y / rt->general_param.threads;
  rt->pix_calc.nb_pixel = repart;
  rt->pix_calc.pixel_pos = 0;
  rt->thread_nb = 1;
  while (count != rt->general_param.threads)
    {
      if (pthread_create(&(thread[count]), NULL,
			 raytracing, cpy_general_struct(rt)) == -1)
	return (my_puterror(THREAD_ERROR));
      rt->pix_calc.nb_pixel += repart;
      rt->pix_calc.pixel_pos += repart;
      rt->thread_nb++;
      count++;
    }
  count = 0;
  while (count != rt->general_param.threads)
    pthread_join(thread[count++], &ret);
  return (EXIT_SUCCESS);
}
