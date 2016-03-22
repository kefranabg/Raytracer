/*
** my_strdup.c for  in /home/domois_a//Projets/tmp/Raytracer/src/lib
** 
** Made by adrien domoison
** Login   <domois_a@epitech.net>
** 
** Started on  Mon Apr 29 21:16:22 2013 adrien domoison
** Last update Tue Apr 30 14:34:50 2013 adrien domoison
*/

#include	<stdlib.h>
#include	"raytracer.h"

char		*my_strdup(char *str, int free_str)
{
  unsigned int	count;
  char		*res;

  count = 0;
  if ((res = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    {
      my_puterror(MALLOC_ERROR);
      return (NULL);
    }
  while (str[count] != '\0')
    {
      res[count] = str[count];
      count++;
    }
  res[count] = '\0';
  if (free_str == TRUE)
    free(str);
  return (res);
}
