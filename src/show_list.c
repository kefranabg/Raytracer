/*
** show_list.c for  in /home/domois_a//Projets/tmp/Raytracer/src
** 
** Made by adrien domoison
** Login   <domois_a@epitech.net>
** 
** Started on  Tue Apr 30 14:42:41 2013 adrien domoison
** Last update Tue Apr 30 14:53:01 2013 adrien domoison
*/

#include	"raytracer.h"

int		show_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp->line);
      my_putchar('\n');
      tmp = tmp->next;
    }
  return (0);
}
