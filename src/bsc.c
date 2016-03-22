/*
** bsc.c for rt in /home/acca_b/Dropbox/EPITECH/Tek1/Raytracer/raytracer-2017-chanut_g/src
**
** Made by baptiste acca
** Login   <acca_b@epitech.net>
**
** Started on  Wed May 15 14:18:22 2013 baptiste acca
** Last update Sun Jun  9 20:47:25 2013 alan chauchet
*/

#include		<X11/X.h>
#include		"raytracer.h"

int			parse_arg_file(t_rt *rt, char **av)
{
  init_rt(rt);
  default_size_window(rt);
  if (get_file(av[1], rt) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (rt->eye.check == FALSE)
    return (my_puterror(NO_EYES));
  if (check_option(av, rt) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (resize_aliasing(rt) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (init_param(rt) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int			copy_img(t_rt *rt)
{
  int			count;

  if ((rt->img_tab[rt->pos].img_ptr =
       mlx_new_image(rt->mlx_init.mlx_ptr,
		     rt->size.win_x,
		     rt->size.win_y)) == NULL)
    return (my_puterror(CONNECT_ERROR));
  rt->img_tab[rt->pos].data = (unsigned char *)mlx_get_data_addr
    (rt->img_tab[rt->pos].img_ptr,
     &rt->img_tab[rt->pos].bits_per_pixel,
     &rt->img_tab[rt->pos].size_line,
     &rt->img_tab[rt->pos].endian);
  count = 0;
  while (count <= ((rt->size.win_x) * (rt->size.win_y) * 4))
    {
      rt->img_tab[rt->pos].data[count] = rt->mlx_init.data_resize[count];
      count++;
    }
  return (EXIT_SUCCESS);
}

int			fill_imgs(t_rt *rt)
{
  if ((rt->img_tab = malloc(sizeof(*rt->img_tab)
			    * rt->general_param.nb_img)) == NULL)
    return (EXIT_FAILURE);
  rt->pos = 0;
  while (rt->pos < rt->general_param.nb_img)
    {
      aff_load_bar(rt);
      if (thread_creation(rt) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (rt->general_param.anti_aliasing >= 1)
	antialiasing(rt);
      if (rt->general_param.aliasing > 1)
	aliasing(rt);
      if (copy_img(rt) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      rt->pos++;
      rt->eye.coord.x += rt->general_param.speed;
    }
  rt->pos = 0;
  return (EXIT_SUCCESS);
}

int			bsc(char **av)
{
  t_rt			rt;

  if (parse_arg_file(&rt, av) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (rt.general_param.aliasing >= 1)
    {
      rt.size.win_x = rt.size.size_x * rt.general_param.aliasing;
      rt.size.win_y = rt.size.size_y * rt.general_param.aliasing;
    }
  if (rt.general_param.anti_aliasing > 1)
    {
      rt.size.win_x = rt.size.size_x / rt.general_param.anti_aliasing;
      rt.size.win_y = rt.size.size_y / rt.general_param.anti_aliasing;
    }
  if (rt.general_param.backscreen.name != NULL)
    recup_backscreen(&rt);
  if (fill_imgs(&rt) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  mlx_hook(rt.mlx_init.win_ptr, KeyPress, KeyPressMask, &key_hook, &rt);
  mlx_expose_hook(rt.mlx_init.win_ptr, &expose_hook, &rt);
  mlx_loop(rt.mlx_init.mlx_ptr);
  return (EXIT_SUCCESS);
}
