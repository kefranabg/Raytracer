/*
** epur_tmp.c for  in /home/domois_a//Projets/tmp/Raytracer/src
** 
** Made by adrien domoison
** Login   <domois_a@epitech.net>
** 
** Started on  Mon Apr 29 20:53:08 2013 adrien domoison
** Last update Mon Apr 29 21:37:22 2013 adrien domoison
*/

#include	"raytracer.h"

char		*epur_line(char *str)
{
  int		pos_cur;
  int		pos_dest;

  pos_cur = 0;
  pos_dest = 0;
  while (str[pos_cur] != '\0' && (str[pos_cur] == ' ' || str[pos_cur] == '\t'))
    ++pos_cur;
  while (str[pos_cur] != '\0')
    {
      if (str[pos_cur] == ' ' || str[pos_cur] == '\t')
	++pos_cur;
      else
	{
	  if (str[pos_cur] == '\t')
	    str[pos_cur] = ' ';
	  if (str[pos_cur] == '\n')
	    str[pos_cur] = '\0';
	  str[pos_dest++] = str[pos_cur++];
	}
    }
  str[pos_dest] = '\0';
  return (str);
}
