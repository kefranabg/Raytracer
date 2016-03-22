/*
** get_color_hex_str.c for get_color_hex_str.c in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g/src
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Wed May 15 00:18:37 2013 franck abgrall
** Last update Sun Jun  9 16:08:13 2013 alan chauchet
*/

#include	"raytracer.h"

int		get_color_hex_str(char **color_hex, char *str)
{
  int		count;

  if (((*color_hex) = malloc(sizeof(*(*color_hex))
			     * (my_strlen_rt(str) + 1))) == NULL)
    return (my_puterror(MALLOC_ERROR));
  count = 0;
  while (str[count] != SEPARATOR)
    {
      (*color_hex)[count] = str[count];
      count++;
    }
  (*color_hex)[count] = '\0';
  return (EXIT_SUCCESS);
}
