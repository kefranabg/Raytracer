/*
** my_puterror.c for  in /home/domois_a//Projets/tmp/Raytracer/src/lib
** 
** Made by adrien domoison
** Login   <domois_a@epitech.net>
** 
** Started on  Mon Apr 29 21:14:37 2013 adrien domoison
** Last update Sun Jun  9 16:13:51 2013 alan chauchet
*/

#include	"raytracer.h"

int		my_puterror(char *str)
{
  if (str != NULL)
    write(STDERR_FILENO, str, my_strlen(str));
  else
    write(STDERR_FILENO, "(null)", 6);
  return (EXIT_FAILURE);
}
