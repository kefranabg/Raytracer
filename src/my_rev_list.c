/*
** my_rev_list.c for  in /home/domois_a//Projets/tmp/Raytracer
** 
** Made by adrien domoison
** Login   <domois_a@epitech.net>
** 
** Started on  Tue Apr 30 14:54:15 2013 adrien domoison
** Last update Tue Apr 30 14:55:09 2013 adrien domoison
*/

#include	"raytracer.h"

void		my_rev_list(t_list **list)
{
  t_list	*tmp;
  t_list	*tmp2;

  tmp = NULL;
  while (*list != NULL)
    {
      tmp2 = (*list)->next;
      (*list)->next = tmp;
      tmp = *list;
      *list = tmp2;
    }
  *list = tmp;
}
