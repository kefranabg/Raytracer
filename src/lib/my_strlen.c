/*
** my_strlen.c for  in /home/domois_a//Projets/tmp/Raytracer/src/lib
** 
** Made by adrien domoison
** Login   <domois_a@epitech.net>
** 
** Started on  Tue Apr 29 14:04:07 2013 adrien domoison
** Last update Tue May 14 21:05:59 2013 franck abgrall
*/

#include	"raytracer.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i++;
  return (i);
}

int		my_strlen_rt(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != SEPARATOR && str[i] != '\0')
    i++;
  return (i);
}
