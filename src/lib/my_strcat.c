/*
** my_strcat.c for my_strcat.c in /home/loeb_t//projets/corewar/asm/source
**
** Made by thomas loeb
** Login   <loeb_t@epitech.net>
**
** Started on  Wed Jan 30 11:35:41 2013 thomas loeb
** Last update Sun Jun  9 16:43:39 2013 alan chauchet
*/

#include		"raytracer.h"

char			*my_strcat(char *s1, char *s2,
				   int free1, int free2)
{
  char			*tmp;
  int			i;
  int			j;

  if (s1 == NULL || s2 == NULL)
    return ("");
  if ((tmp = malloc(my_strlen(s1) + my_strlen(s2) + 1)) == NULL)
    {
      my_puterror(MALLOC_ERROR);
      return (NULL);
    }
  i = 0;
  j = 0;
  while (s1[i] != '\0')
    tmp[j++] = s1[i++];
  if (free1 == 1)
    free(s1);
  i = 0;
  while (s2[i] != '\0')
    tmp[j++] = s2[i++];
  if (free2 == 1)
    free(s2);
  tmp[j] = '\0';
  return (tmp);
}
