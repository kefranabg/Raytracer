/*
** read_file.c for  in /home/domois_a//Projets/tmp/Raytracer
** 
** Made by adrien domoison
** Login   <domois_a@epitech.net>
** 
** Started on  Tue Apr 30 14:13:07 2013 adrien domoison
** Last update Sun Jun  9 16:14:08 2013 alan chauchet
*/

#include	"raytracer.h"

int		check_valid_line(char *line)
{
  int		count;
  int		ret;

  count = 0;
  ret = 0;
  while (line[count] != '\0')
    {
      if (line[count] == SEPARATOR)
	ret++;
      count++;
    }
  if (ret != NB_SEPARATOR)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		read_file(FILE *fd, t_list **list, t_rt *rt)
{
  char		*line;
  size_t	len;
  int		count;

  count = 0;
  len = 0;
  line = NULL;
  while (getline(&line, &len, fd) != -1)
    {
      epur_line(line);
      if (get_general_params(line, count, rt) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (check_valid_line(line) == EXIT_SUCCESS)
	{
	  if (line[0] != COMMENT && add_elem(list, line, count) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
      else
	if (count == 0)
	  return (my_puterror(BAD_SEPARATOR_NB));
      count++;
    }
  my_rev_list(list);
  free(line);
  return (EXIT_SUCCESS);
}
