/*
** my_strcmp.c for  in /home/domois_a//Projets/tmp/Raytracer/src/lib
** 
** Made by adrien domoison
** Login   <domois_a@epitech.net>
** 
** Started on  Mon Apr 29 21:16:08 2013 adrien domoison
** Last update Fri Jun  7 15:25:02 2013 alan chauchet
*/

#include	<stdlib.h>
#include	"raytracer.h"

int		my_strncmp(char *s1, char *s2, unsigned int size)
{
  unsigned int	count;

  count = 0;
  while (s1[count] != '\0' && count < size)
    {
      if (s1[count] != s2[count])
	return (1);
      ++count;
    }
  return (0);
}

int		my_strcmp(char *s1, char *s2)
{
  unsigned int	count;

  count = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (1);
  while (s1[count] != '\0')
    {
      if (s1[count] != s2[count])
	return (1);
      ++count;
    }
  return (0);
}

int		my_strcmp_parser(char *s1, char *s2)
{
  unsigned int	count;

  count = 0;
  while (s1[count] != SEPARATOR && s1[count] != '\0')
    {
      if (s1[count] != s2[count])
	return (1);
      count++;
    }
  return (0);
}
