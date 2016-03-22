/*
** get_backscreen.c for rt in /home/chauch_a//texture
** 
** Made by alan chauchet
** Login   <chauch_a@epitech.net>
** 
** Started on  Fri Jun  7 14:42:06 2013 alan chauchet
** Last update Fri Jun  7 23:09:39 2013 alan chauchet
*/

#include	"raytracer.h"

void		recup_backscreen(t_rt *rt)
{
  if (((rt->general_param.backscreen.img = mlx_xpm_file_to_image
	(rt->mlx_init.mlx_ptr, rt->general_param.backscreen.name,
	 &(rt->general_param.backscreen.a),
	 &(rt->general_param.backscreen.b))) == NULL)
      || ((rt->general_param.backscreen.data
	   = (unsigned char *)mlx_get_data_addr
	   (rt->general_param.backscreen.img,
	    &(rt->general_param.backscreen.bpp),
	    &(rt->general_param.backscreen.size_line),
	    &(rt->general_param.backscreen.endian))) == NULL))
    {
      rt->general_param.backscreen.name = NULL;
      my_puterror(BAD_SCREEN);
    }
}

void		verif_if_xpm(t_rt *rt)
{
  int		count;
  int		found;

  count = 0;
  found = 0;
  while (rt->general_param.backscreen.name[count] != '\0')
    {
      if (my_strncmp(&(rt->general_param.backscreen.name[count]), ".xpm", 4)
	  == 0 && rt->general_param.backscreen.name[count + 4] == '\0')
	found = 1;
      count++;
    }
  if (found == 0)
    {
      rt->general_param.backscreen.name = NULL;
      my_puterror(BAD_SCREEN);
    }
}

int		get_backscreen(char *nb, int line_nb, t_rt *rt)
{
  (void)line_nb;
  rt->general_param.backscreen.name = my_strdup(nb, FALSE);
  if (rt->general_param.backscreen.name
      [my_strlen(rt->general_param.backscreen.name) - 1] == '*')
    rt->general_param.backscreen.name
      [my_strlen(rt->general_param.backscreen.name) - 1] = '\0';
  if (my_strncmp(rt->general_param.backscreen.name, "NULL", 4) == 0)
    {
      rt->general_param.backscreen.name = NULL;
      return (EXIT_SUCCESS);
    }
  verif_if_xpm(rt);
  return (EXIT_SUCCESS);
}
