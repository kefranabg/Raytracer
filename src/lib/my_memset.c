/*
** my_memset.c for  in /home/domois_a//Projets/tmp/Raytracer/src
** 
** Made by adrien domoison
** Login   <domois_a@epitech.net>
** 
** Started on  Mon Apr 29 21:48:11 2013 adrien domoison
** Last update Mon Apr 29 21:48:12 2013 adrien domoison
*/

#include	"raytracer.h"

void		my_memset(char *str, char set, unsigned int size)
{
  unsigned int	count;

  count = 0;
  while (count < size)
    {
      str[count] = set;
      ++count;
    }
}
