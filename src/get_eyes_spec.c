/*
** object_list_two.c for object_list_two.c in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g/src
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Sun May 12 14:16:08 2013 franck abgrall
** Last update Sun Jun  9 16:07:59 2013 alan chauchet
*/

#include	"raytracer.h"

int		get_rotate_eyes(t_list *list, t_rt *rt)
{
  if ((rt->eye.rotate.rx =
       get_specs(list, rt, ROTX_NB)) == -1)
    return (EXIT_FAILURE);
  if ((rt->eye.rotate.ry =
       get_specs(list, rt, ROTY_NB)) == -1)
    return (EXIT_FAILURE);
  if ((rt->eye.rotate.rz =
       get_specs(list, rt, ROTZ_NB)) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		get_coord_eyes(t_list *list, t_rt *rt)
{
  if ((rt->eye.coord.x =
       get_specs(list, rt, POSX_NB)) == -1)
    return (EXIT_FAILURE);
  if ((rt->eye.coord.y =
       get_specs(list, rt, POSY_NB)) == -1)
    return (EXIT_FAILURE);
  if ((rt->eye.coord.z =
       get_specs(list, rt, POSZ_NB)) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		get_eyes_specs(t_list *list, int object_nb, t_rt *rt)
{
  if (object_nb == EYES_NB)
    {
      (void)object_nb;
      rt->eye.check = TRUE;
      if (get_coord_eyes(list, rt) == EXIT_FAILURE)
        return (EXIT_FAILURE);
      if (get_rotate_eyes(list, rt) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
