/*
** calc_rot_eye.c for rt in /home/chauch_a//Dropbox/Raytracer/raytracer-2017-chanut_g
**
** Made by alan chauchet
** Login   <chauch_a@epitech.net>
**
** Started on  Thu May 16 12:12:09 2013 alan chauchet
** Last update Sat Jun  8 06:38:44 2013 franck abgrall
*/

#include	"raytracer.h"

void		rot_x_eye(t_rt *rt, int x, int y)
{
  int		resize_view;

  if (rt->general_param.aliasing > 1)
    resize_view = DIST / rt->general_param.aliasing;
  else
    resize_view = DIST * rt->general_param.anti_aliasing;
  rt->vector.x = (rt->cosinus[ANG(rt->eye.rotate.rz % 360)]
		  * rt->cosinus[ANG(rt->eye.rotate.ry % 360)]
		  * resize_view
		  - rt->sinus[ANG(rt->eye.rotate.rz % 360)]
		  * ((rt->size.size_x / 2) - x)
		  + rt->cosinus[ANG(rt->eye.rotate.rz % 360)]
		  * rt->sinus[ANG(rt->eye.rotate.ry % 360)]
		  * ((rt->size.size_y / 2) - y));
}

void		rot_y_eye(t_rt *rt, int x, int y)
{
  int		resize_view;

  if (rt->general_param.aliasing > 1)
    resize_view = DIST / rt->general_param.aliasing;
  else
    resize_view = DIST * rt->general_param.anti_aliasing;
  rt->vector.y = ((rt->cosinus[ANG(rt->eye.rotate.rx % 360)]
		   * rt->sinus[ANG(rt->eye.rotate.rz % 360)]
		   * rt->cosinus[ANG(rt->eye.rotate.ry % 360)]
		   + rt->sinus[ANG(rt->eye.rotate.rx % 360)]
		   * rt->sinus[ANG(rt->eye.rotate.ry % 360)])
		  * resize_view
		  + rt->cosinus[ANG(rt->eye.rotate.rx % 360)]
		  * rt->cosinus[ANG(rt->eye.rotate.rz % 360)]
		  * ((rt->size.size_x / 2) - x)
		  + (rt->cosinus[ANG(rt->eye.rotate.rx % 360)]
		     * rt->sinus[ANG(rt->eye.rotate.rz % 360)]
		     * rt->sinus[ANG(rt->eye.rotate.ry % 360)]
		     - rt->sinus[ANG(rt->eye.rotate.rx % 360)]
		     * rt->cosinus[ANG(rt->eye.rotate.ry % 360)])
		  * ((rt->size.size_y / 2) - y));
}

void		rot_z_eye(t_rt *rt, int x, int y)
{
  int		resize_view;

  if (rt->general_param.aliasing > 1)
    resize_view = DIST / rt->general_param.aliasing;
  else
    resize_view = DIST * rt->general_param.anti_aliasing;
  rt->vector.z = ((rt->sinus[ANG(rt->eye.rotate.rx % 360)]
		   * rt->sinus[ANG(rt->eye.rotate.rz % 360)]
		   * rt->cosinus[ANG(rt->eye.rotate.ry % 360)]
		   - rt->cosinus[ANG(rt->eye.rotate.rx % 360)]
		   * rt->sinus[ANG(rt->eye.rotate.ry % 360)])
		  * resize_view
		  + rt->sinus[ANG(rt->eye.rotate.rx % 360)]
		  * rt->cosinus[ANG(rt->eye.rotate.rz % 360)]
		  * ((rt->size.size_x / 2) - x)
		  + (rt->sinus[ANG(rt->eye.rotate.rx % 360)]
		     * rt->sinus[ANG(rt->eye.rotate.rz % 360)]
		     * rt->sinus[ANG(rt->eye.rotate.ry % 360)]
		     + rt->cosinus[ANG(rt->eye.rotate.rx % 360)]
		     * rt->cosinus[ANG(rt->eye.rotate.ry % 360)])
		  * ((rt->size.size_y / 2) - y));
}

void		calc_rot_eye(t_rt *rt, int x, int y)
{
  rot_x_eye(rt, x, y);
  rot_y_eye(rt, x, y);
  rot_z_eye(rt, x, y);
}
