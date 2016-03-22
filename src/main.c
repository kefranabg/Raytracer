/*
** main.c for rt in /home/chauch_a//raytracer-2017-chanut_g
**
** Made by alan chauchet
** Login   <chauch_a@epitech.net>
**
** Started on  Wed Apr  3 11:31:07 2013 alan chauchet
** Last update Mon May 27 14:22:55 2013 thomas loeb
*/

#include	"raytracer.h"

int		main(int ac, char **av)
{
  if (ac < 2)
    return (my_puterror(USAGE));
  return (bsc(av), ac);
}
