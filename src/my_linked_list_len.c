/*
** my_linked_list_len.c for  in /home/domois_a//Projets/tmp/raytracer-2017-chanut_g/src
** 
** Made by adrien domoison
** Login   <domois_a@epitech.net>
** 
** Started on  Tue Apr 30 15:53:44 2013 adrien domoison
** Last update Sun Jun  9 16:14:47 2013 alan chauchet
*/

#include	"raytracer.h"

int		my_linked_list_len(t_list *list)
{
  t_list	*tmp;
  int		i;

  i = 0;
  tmp = list;
  while (tmp != NULL)
    {
      ++i;
      tmp = tmp->next;
    }
  return (i);
}
