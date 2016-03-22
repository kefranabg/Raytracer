/*
** calc_matrice.c for calc_matrice.c in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g/src
**
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
**
** Started on  Fri May 17 00:58:59 2013 franck abgrall
** Last update Fri May 31 18:08:38 2013 alan chauchet
*/

#include	"raytracer.h"

void		calc_matrice_vector(t_rt *rt, t_object *object,
				    t_coord *vector, t_coord *new_vector)
{
  new_vector->x = matrice_rotate_x(rt, vector, object, -1);
  new_vector->y = matrice_rotate_y(rt, vector, object, -1);
  new_vector->z = matrice_rotate_z(rt, vector, object, -1);
}

void		calc_matrice_eye(t_rt *rt, t_object *object,
				 t_eye *eye, t_eye *new_eye)
{
  t_coord	coord;

  coord.x = (eye->coord.x - object->coord.x);
  coord.y = (eye->coord.y - object->coord.y);
  coord.z = (eye->coord.z - object->coord.z);
  new_eye->coord.x = matrice_rotate_x(rt, &coord, object, -1);
  new_eye->coord.y = matrice_rotate_y(rt, &coord, object, -1);
  new_eye->coord.z = matrice_rotate_z(rt, &coord, object, -1);
}
