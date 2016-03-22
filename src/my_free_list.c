/*
** free_list.c for  in /home/domois_a//Projets/tmp/raytracer-2017-chanut_g
** 
** Made by adrien domoison
** Login   <domois_a@epitech.net>
** 
** Started on  Tue Apr 30 15:33:09 2013 adrien domoison
** Last update Sun Jun  9 16:14:50 2013 alan chauchet
*/

#include	"raytracer.h"

void		my_free_list(t_list *list)
{
  t_list	*tmp;

  tmp = NULL;
  while (list != NULL)
    {
      tmp = list;
      list = list->next;
      free(tmp->line);
      free(tmp);
    }
}
