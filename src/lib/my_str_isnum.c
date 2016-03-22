/*
** my_str_isnum.c for  in /home/domois_a//Projets/tmp/Raytracer/src/lib
**
** Made by adrien domoison
** Login   <domois_a@epitech.net>
**
** Started on  Tue Apr 30 10:39:36 2013 adrien domoison
** Last update Sun Jun  9 16:33:55 2013 alan chauchet
*/

#include	"raytracer.h"

int		my_str_isnum(char *str, int do_neg)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < '0' || str[i] > '9') && str[i] != '+')
	{
	  if (str[i] == '-' && do_neg == 0)
	    return (1);
	  else if (str[i] != '-')
	    return (1);
	}
      i++;
    }
  return (0);
}

int		check_isnum(char *str, t_list *list)
{
  int		count;

  count = 0;
  if (str[count] == SEPARATOR)
    {
      my_puterror(EMPTY_BOX);
      my_putnbr(list->line_nb);
      return (-1);
    }
  if ((str[count] < '0' || str[count] > '9') && str[count] != '-')
    {
      my_puterror(WRONG_COLUMN);
      return (-1);
    }
  while (str[count] != SEPARATOR && str[count] != '\0')
    {
      if ((str[count] < '0' || str[count] > '9') && count != 0
	  && str[count] != '.')
	{
	  my_puterror(WRONG_COLUMN);
	  return (-1);
	}
      count++;
    }
  return (0);
}
