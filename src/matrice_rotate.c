/*
** matrice_rotate.c for rt in /home/chauch_a//Dropbox/Raytracer/raytracer-2017-chanut_g
**
** Made by alan chauchet
** Login   <chauch_a@epitech.net>
**
** Started on  Thu May 16 15:18:15 2013 alan chauchet
** Last update Fri May 31 17:19:44 2013 alan chauchet
*/

#include	"raytracer.h"

double		matrice_rotate_x(t_rt *rt, t_coord *coord,
				 t_object *object, int mat_val)
{
  return (rt->cosinus[ANG(mat_val * object->rotate.rz)]
	  * rt->cosinus[ANG(mat_val * object->rotate.ry)]
	  * coord->x
	  - rt->sinus[ANG(mat_val * object->rotate.rz)]
	  * coord->y
	  + rt->cosinus[ANG(mat_val * object->rotate.rz)]
	  * rt->sinus[ANG(mat_val * object->rotate.ry)]
	  * coord->z);
}

double		matrice_rotate_y(t_rt *rt, t_coord *coord,
				 t_object *object, int mat_val)
{
  return ((rt->cosinus[ANG(mat_val * object->rotate.rx)]
	   * rt->sinus[ANG(mat_val * object->rotate.rz)]
	   * rt->cosinus[ANG(mat_val * object->rotate.ry)]
	   + rt->sinus[ANG(mat_val * object->rotate.rx)]
	   * rt->sinus[ANG(mat_val * object->rotate.ry)])
	  * coord->x
	  + rt->cosinus[ANG(mat_val * object->rotate.rx)]
	  * rt->cosinus[ANG(mat_val * object->rotate.rz)]
	  * coord->y
	  + (rt->cosinus[ANG(mat_val * object->rotate.rx)]
	     * rt->sinus[ANG(mat_val * object->rotate.rz)]
	     * rt->sinus[ANG(mat_val * object->rotate.ry)]
	     - rt->sinus[ANG(mat_val * object->rotate.rx)]
	     * rt->cosinus[ANG(mat_val * object->rotate.ry)])
	  * coord->z);
}

double		matrice_rotate_z(t_rt *rt, t_coord *coord,
				 t_object *object, int mat_val)
{
  return ((rt->sinus[ANG(mat_val * object->rotate.rx)]
	   * rt->sinus[ANG(mat_val * object->rotate.rz)]
	   * rt->cosinus[ANG(mat_val * object->rotate.ry)]
	   - rt->cosinus[ANG(mat_val * object->rotate.rx)]
	   * rt->sinus[ANG(mat_val * object->rotate.ry)])
	  * coord->x
	  + rt->sinus[ANG(mat_val * object->rotate.rx)]
	  * rt->cosinus[ANG(mat_val * object->rotate.rz)]
	  * coord->y
	  + (rt->sinus[ANG(mat_val * object->rotate.rx)]
	     * rt->sinus[ANG(mat_val * object->rotate.rz)]
	     * rt->sinus[ANG(mat_val * object->rotate.ry)]
	     + rt->cosinus[ANG(mat_val * object->rotate.rx)]
	     * rt->cosinus[ANG(mat_val * object->rotate.ry)])
	  * coord->z);
}
