/*
** check_color_syntax.c for check_clor_syntax in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g/src
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Mon May 13 22:40:49 2013 franck abgrall
** Last update Sun Jun  9 16:39:58 2013 alan chauchet
*/

#include	"raytracer.h"

int		error_color_syntax(t_list *list)
{
  my_puterror(COLOR_SYNTAX);
  my_putnbr(list->line_nb);
  return (EXIT_FAILURE);
}

int		my_strlen_column(char *str, t_list *list)
{
  int		count;

  count = 0;
  while (str[count] != '\0' && str[count] != SEPARATOR)
    count++;
  if (count != 8)
    return (error_color_syntax(list));
  return (EXIT_SUCCESS);
}

int		check_color_syntax(char *str, t_list *list)
{
  int		count;

  if (my_strlen_column(str, list) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  count = 0;
  while (str[count] != '\0' && str[count] != SEPARATOR)
    {
      if (count == 0)
	if (str[count] != '0')
	  return (error_color_syntax(list));
      if (count == 1)
	if (str[count] != 'x')
	  return (error_color_syntax(list));
      if (count > 1 && (str[count] < '0' ||
			(str[count] > '9' &&
			 str[count] < 'A')
			|| str[count] > 'F'))
	return (error_color_syntax(list));
      count++;
    }
  return (EXIT_SUCCESS);
}
