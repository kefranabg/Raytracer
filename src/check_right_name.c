/*
** check_right_name.c for check_right_name.c in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g/src
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Tue Apr 30 23:00:20 2013 franck abgrall
** Last update Sun Jun  9 16:10:33 2013 alan chauchet
*/

#include	"raytracer.h"

static	t_cmp	struct_tab[] =
  {
    {OBJECT, FALSE, OBJECT_NB},
    {POSX, FALSE, POSX_NB},
    {POSY, FALSE, POSY_NB},
    {POSZ, FALSE, POSZ_NB},
    {ROTX, FALSE, ROTX_NB},
    {ROTY, FALSE, ROTY_NB},
    {ROTZ, FALSE, ROTZ_NB},
    {COLOR, FALSE, COLOR_NB},
    {REFLEXION, FALSE, REFLEXION_NB},
    {OPACITY, FALSE, OPACITY_NB},
    {BRIGHTNESS, FALSE, BRIGHTNESS_NB},
    {RADIUS, FALSE, RADIUS_NB},
    {ANGLE, FALSE, ANGLE_NB},
    {LIMIT, FALSE, LIMIT_NB},
    {DISTURB_X, FALSE, DISTURB_X_NB},
    {DISTURB_Y, FALSE, DISTURB_Y_NB},
    {CHECK_FREQUENCY, FALSE, CHECK_FREQUENCY_NB},
    {NULL, FALSE, 0}
  };

int		compare_name(char *str, int ref_tab[SIZE_TAB])
{
  int		count;
  int		count_two;

  count = 0;
  while (struct_tab[count].name != NULL)
    {
      if (my_strcmp_parser(str, struct_tab[count].name) == 0
	  && struct_tab[count].visited == FALSE)
	{
	  count_two = 0;
	  while (ref_tab[count_two] != 0)
	    count_two++;
	  ref_tab[count_two] = struct_tab[count].nb_ref;
	  struct_tab[count].visited = TRUE;
	  return (EXIT_SUCCESS);
	}
      if (my_strcmp_parser(str, struct_tab[count].name) == 0
          && struct_tab[count].visited == TRUE)
	return (my_puterror(TWICE_NAME_USE));
      count++;
    }
  return (my_puterror(BAD_NAME));
}

int		check_right_name(char *line, int ref_tab[SIZE_TAB])
{
  int		count;

  count = 0;
  while (line[count] != '\0')
    {
      if (line[count] != SEPARATOR)
        {
          if (compare_name(&line[count], ref_tab) == EXIT_FAILURE)
            return (EXIT_FAILURE);
          else
            {
              while (line[count] != SEPARATOR && line[count] != '\0')
                count++;
              if (line[count] == '\0')
                count--;
            }
        }
      count++;
    }
  return (EXIT_SUCCESS);
}
