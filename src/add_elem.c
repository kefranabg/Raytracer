/*
** add_elem.c for  in /home/domois_a//Projets/tmp/Raytracer
** 
** Made by adrien domoison
** Login   <domois_a@epitech.net>
** 
** Started on  Tue Apr 30 14:24:42 2013 adrien domoison
** Last update Sun Jun  9 16:13:40 2013 alan chauchet
*/

#include	"raytracer.h"

int		add_elem(t_list **list, char *str, int count)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(t_list))) == NULL)
    return (my_puterror(MALLOC_ERROR));
  elem->line = my_strdup(str, FALSE);
  elem->next = *list;
  elem->line_nb = count;
  *list = elem;
  return (EXIT_SUCCESS);
}
