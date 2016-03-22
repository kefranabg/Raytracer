/*
** my_atoi_base.c for my_atoi_base.c in /home/abgral_f//Projets/RTV1/source
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Thu Feb 28 17:39:03 2013 franck abgrall
** Last update Wed May 15 00:34:24 2013 franck abgrall
*/

#include	"raytracer.h"

int             my_pow(int nb, int pw)
{
  int           result;

  result = 1;
  while (pw > 0)
    {
      result = result * nb;
      pw--;
    }
  return (result);
}

int             is_in_base(char c, char *base)
{
  int           i;

  i = 0;
  while (base[i] != '\0')
    {
      if (base[i] == c)
        return (1);
      i++;
    }
  return (0);
}

int             is_neg(char *nb, char *base)
{
  if (nb[0] == '-' && is_in_base('-', base) == 0)
    return (1);
  else
    return (0);
}

int             my_atoi_base(char *nb, char *base)
{
  int           result;
  int           i;
  int           a;
  int           neg;

  neg = is_neg(nb, base);
  if (my_strlen(base) < 1)
    return (1);
  result = 0;
  i = my_strlen(nb) - 1;
  while (i >= 0)
    {
      a = 0;
      while (base[a] != nb[i] && base[a] != '\0')
        a++;
      if (base[a] == '\0' && !(neg == 1 && i == 0))
        return (1);
      if (!(neg == 1 && i == 0))
        result = result + a * my_pow(my_strlen(base), (my_strlen(nb) - i - 1));
      i--;
    }
  if (neg == 1)
    result = result * (-1);
  return (result);
}
