/*
** open_file.c for  in /home/domois_a//Projets/tmp/Raytracer/src
** 
** Made by adrien domoison
** Login   <domois_a@epitech.net>
** 
** Started on  Mon Apr 29 21:07:16 2013 adrien domoison
** Last update Sun Jun  9 16:43:10 2013 alan chauchet
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"raytracer.h"

int		check_extension(char *file_name)
{
  int		count;
  int		count_extension;

  count = 0;
  while (file_name[count] != '\0')
    count++;
  count_extension = 0;
  while (EXTENSION[count_extension] != '\0')
    count_extension++;
  while ((EXTENSION[count_extension] == file_name[count])
	 && count > 0 && count_extension > 0)
    {
      if (count_extension == 1)
	return (EXIT_SUCCESS);
      count--;
      count_extension--;
    }
  my_puterror(BAD_EXTENSION);
  return (EXIT_FAILURE);
}

int		open_file(char *file_name, t_list **list, t_rt *rt)
{
  FILE		*fd;

  if (check_extension(file_name) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((fd = fopen(file_name, FOPEN_MODE)) == NULL)
    return (my_puterror(FOPEN_ERROR));
  if (read_file(fd, list, rt) == EXIT_FAILURE)
    {
      fclose(fd);
      return (EXIT_FAILURE);
    }
  fclose(fd);
  return (EXIT_SUCCESS);
}
