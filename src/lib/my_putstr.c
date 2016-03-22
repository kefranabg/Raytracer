/*
** my_putstr.c for  in /home/domois_a//Projets/tmp/Raytracer/src/lib
** 
** Made by adrien domoison
** Login   <domois_a@epitech.net>
** 
** Started on  Mon Apr 29 21:15:07 2013 adrien domoison
** Last update Mon Apr 29 21:22:27 2013 adrien domoison
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"raytracer.h"

int		my_putstr(char *str)
{
  if (str != NULL)
    return (write(STDOUT_FILENO, str, my_strlen(str)));
  return (write(STDOUT_FILENO, "(null)", 6));
}
