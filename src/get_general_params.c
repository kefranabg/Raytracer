/*
** get_general_params.c for get_general_params.c in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g/src
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Tue May 21 16:30:24 2013 franck abgrall
** Last update Sun Jun  9 16:16:08 2013 alan chauchet
*/

#include	<string.h>
#include	"raytracer.h"

int		get_general_params(char *line, int line_nb, t_rt *rt)
{
  if (strncmp(line, THREADS, strlen(THREADS)) == 0 &&
      get_threads(&(line[strlen(THREADS)]), line_nb, rt) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (strncmp(line, ALIASING, strlen(ALIASING)) == 0 &&
      get_aliasing(&(line[strlen(ALIASING)]), line_nb, rt) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (strncmp(line, AMBIANCE, strlen(AMBIANCE)) == 0 &&
      get_ambiance(&(line[strlen(AMBIANCE)]), line_nb, rt) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (strncmp(line, FILTER, strlen(FILTER)) == 0 &&
      get_filtre(&(line[strlen(FILTER)]), line_nb, rt) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (strncmp(line, BACKSCREEN, strlen(BACKSCREEN)) == 0 &&
      get_backscreen(&(line[strlen(BACKSCREEN)]),
		     line_nb, rt) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (strncmp(line, N_ALIASING, strlen(N_ALIASING)) == 0 &&
      get_anti_aliasing(&(line[strlen(N_ALIASING)]),
			line_nb, rt) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
