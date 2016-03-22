/*
** my_putnbr.c for  in /home/domois_a//Projets/tmp/Raytracer/src/lib
** 
** Made by adrien domoison
** Login   <domois_a@epitech.net>
** 
** Started on  Mon Apr 29 21:14:59 2013 adrien domoison
** Last update Sun Jun  9 18:17:23 2013 alan chauchet
*/

#include	"raytracer.h"

void		my_putchar_error(char c)
{
  write(2, &c, 1);
}

void		my_putnbr(int nb)
{
  int		multip;
  int		count;

  multip = 1;
  count = 0;
  if (nb < 0)
    {
      my_putchar('-');
      count = 1;
      nb = (nb + 1) * (-1);
    }
  while ((nb / multip) >= 10)
    multip = multip * 10;
  while (multip != 1)
    {
      my_putchar((nb / multip) % 10 + '0');
      multip = multip / 10;
    }
  if (count == 0)
    my_putchar_error((nb / multip) % 10 + '0');
  else
    my_putchar_error((nb / multip) % 10 + '0' + 1);
  my_putchar_error('\n');
}
