/*
** my_putchar.c for  in /home/domois_a//Projets/tmp/Raytracer/src/lib
** 
** Made by adrien domoison
** Login   <domois_a@epitech.net>
** 
** Started on  Mon Apr 29 21:14:45 2013 adrien domoison
** Last update Sun Jun  9 16:21:11 2013 alan chauchet
*/

#include	"raytracer.h"

int		my_putchar(char c)
{
  return (write(STDIN_FILENO, &c, 1));
}
