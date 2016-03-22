/*
** general_params.c for general_params.c in /home/abgral_f//Dropbox/Raytracer/transparence/src
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Sat Jun  8 06:32:58 2013 franck abgrall
** Last update Sun Jun  9 16:27:07 2013 alan chauchet
*/

#include	"raytracer.h"

int		get_threads(char *nb, int line_nb, t_rt *rt)
{
  if (nb[0] < '0' || nb[0] > '9')
    {
      my_puterror(THREAD_BAD_ARG);
      my_putnbr(line_nb);
      return (EXIT_FAILURE);
    }
  rt->general_param.threads = atoi(nb);
  if (rt->general_param.threads > 4 || rt->general_param.threads < 1)
    {
      my_puterror(THREAD_BAD_ARG);
      my_putnbr(line_nb);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int		get_anti_aliasing(char *nb, int line_nb, t_rt *rt)
{
  if (nb[0] < '0' || nb[0] > '9')
    {
      my_puterror(ANTI_ALIASING_BAD_ARG);
      my_putnbr(line_nb);
      return (EXIT_FAILURE);
    }
  rt->general_param.anti_aliasing = atoi(nb);
  if (rt->general_param.anti_aliasing < 1
      || rt->general_param.anti_aliasing > 16)
    {
      my_puterror(ANTI_ALIASING_BAD_ARG);
      my_putnbr(line_nb);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int		get_aliasing(char *nb, int line_nb, t_rt *rt)
{
  if (nb[0] < '0' || nb[0] > '9')
    {
      my_puterror(ALIASING_BAD_ARG);
      my_putnbr(line_nb);
      return (EXIT_FAILURE);
    }
  rt->general_param.aliasing = atoi(nb);
  if (rt->general_param.aliasing < 1 || rt->general_param.aliasing > 30)
    {
      my_puterror(ALIASING_BAD_ARG);
      my_putnbr(line_nb);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int		get_filtre(char *nb, int line_nb, t_rt *rt)
{
  if (nb[0] < '0' || nb[0] > '9')
    {
      my_puterror(FILTER_BAD_ARG);
      my_putnbr(line_nb);
      return (EXIT_FAILURE);
    }
  rt->general_param.filter = atoi(nb);
  if (rt->general_param.filter < 0 || rt->general_param.filter > 10)
    {
      my_puterror(FILTER_BAD_ARG);
      my_putnbr(line_nb);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int		get_ambiance(char *nb, int line_nb, t_rt *rt)
{
  if (nb[0] < '0' || nb[0] > '9')
    {
      my_puterror(AMBIANCE_BAD_ARG);
      my_putnbr(line_nb);
      return (EXIT_FAILURE);
    }
  rt->general_param.ambiance_light = atof(nb);
  if (rt->general_param.ambiance_light < 0
      || rt->general_param.ambiance_light > 1)
    {
      my_puterror(AMBIANCE_BAD_ARG);
      my_putnbr(line_nb);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
