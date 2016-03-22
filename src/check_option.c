/*
** check_option.c for check_option.c in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g/src
**
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
**
** Started on  Wed May 15 16:05:13 2013 franck abgrall
** Last update Sun Jun  9 18:19:03 2013 adrien domoison
*/

#include		<string.h>
#include		"raytracer.h"

int			check_s_option(t_rt *rt, char **av, int count)
{
  if (strcmp(OPT_S, av[count]) == 0)
    {
      if (av[count + 1] == NULL || av[count + 2] == NULL)
	return (my_puterror(USAGE_S));
      if (get_window_size(rt, av[count + 1], av[count + 2]) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int			check_w_option(t_rt *rt, char **av, int count)
{
  if (strcmp(OPT_W, av[count]) == 0)
    {
      if (av[count + 1] == NULL || av[count + 2] == NULL)
	return (my_puterror(USAGE_W));
      if (get_wolf_param(rt, av[count + 1], av[count + 2]) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int			check_option(char **av, t_rt *rt)
{
  int			count;

  count = 2;
  while (av[count] != NULL)
    {
      if (check_s_option(rt, av, count) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (check_w_option(rt, av, count) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      count++;
    }
  return (EXIT_SUCCESS);
}
