/*
** get_specs.c for get_specs.c in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g/src
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Mon May 13 18:31:47 2013 franck abgrall
** Last update Sun Jun  9 16:05:33 2013 alan chauchet
*/

#include	"raytracer.h"

int		get_color(t_list *list, t_rt *rt, int specs_nb)
{
  int		column_nb;
  int		adress_specs;
  int		result;
  char		*color_hex;

  if ((column_nb = get_column_number(specs_nb, rt)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((adress_specs = get_adress_specs(list, column_nb)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (check_color_syntax(&(list->line[adress_specs]), list) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (get_color_hex_str(&color_hex,
			&(list->line[adress_specs + 2])) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  result = my_atoi_base(color_hex, "0123456789ABCDEF");
  free(color_hex);
  return (result);
}

int		get_effects(t_list *list, t_rt *rt)
{
  if ((rt->last_object->effects.reflexion =
       get_specs(list, rt, REFLEXION_NB)) == -1)
    return (EXIT_FAILURE);
  if ((rt->last_object->effects.opacity =
       get_specs(list, rt, OPACITY_NB)) == -1)
    return (EXIT_FAILURE);
  if ((rt->last_object->effects.brightness =
       get_specs(list, rt, BRIGHTNESS_NB)) == -1)
    return (EXIT_FAILURE);
  if ((rt->last_object->effects.disturb_x =
       get_specs(list, rt, DISTURB_X_NB)) == -1)
    return (EXIT_FAILURE);
  if ((rt->last_object->effects.disturb_y =
       get_specs(list, rt, DISTURB_Y_NB)) == -1)
    return (EXIT_FAILURE);
  if ((rt->last_object->effects.check_frequency =
       get_specs(list, rt, CHECK_FREQUENCY_NB)) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		get_rotate(t_list *list, t_rt *rt)
{
  if ((rt->last_object->rotate.rx =
       get_specs(list, rt, ROTX_NB)) == -1)
    return (EXIT_FAILURE);
  if ((rt->last_object->rotate.ry =
       get_specs(list, rt, ROTY_NB)) == -1)
    return (EXIT_FAILURE);
  if ((rt->last_object->rotate.rz =
       get_specs(list, rt, ROTZ_NB)) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		get_coord(t_list *list, t_rt *rt)
{
  if ((rt->last_object->coord.x =
       get_specs(list, rt, POSX_NB)) == -1)
    return (EXIT_FAILURE);
  if ((rt->last_object->coord.y =
       get_specs(list, rt, POSY_NB)) == -1)
    return (EXIT_FAILURE);
  if ((rt->last_object->coord.z =
       get_specs(list, rt, POSZ_NB)) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

double		get_specs(t_list *list, t_rt *rt, int specs_nb)
{
  int		column_nb;
  int		adress_specs;
  double	result;

  if ((column_nb = get_column_number(specs_nb, rt)) == EXIT_FAILURE)
    return (-1);
  if ((adress_specs = get_adress_specs(list, column_nb)) == EXIT_FAILURE)
    return (-1);
  if (check_isnum(&(list->line[adress_specs]), list) == -1)
    return (-1);
  result = atof(&(list->line[adress_specs]));
  return (result);
}
