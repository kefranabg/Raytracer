/*
** get_file.c for  in /home/domois_a//Projets/tmp/Raytracer/src
**
** Made by adrien domoison
** Login   <domois_a@epitech.net>
**
** Started on  Tue Apr 30 10:40:51 2013 adrien domoison
** Last update Sun Jun  9 16:07:38 2013 alan chauchet
*/

#include	"raytracer.h"

int		get_file(char *file_name, t_rt *rt)
{
  t_list	*list;

  list = NULL;
  if (open_file(file_name, &list, rt) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (list == NULL)
    return (my_puterror(EMPTY_FILE));
  if (pars_first_line(list, rt) == EXIT_FAILURE)
    {
      my_free_list(list);
      return (EXIT_FAILURE);
    }
  my_free_list(list);
  return (EXIT_SUCCESS);
}
