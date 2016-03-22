/*
** pixel_put_to_image.c for pixel_put_to_image.c in /home/abgral_f//Projets/RTV1/source
** 
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
** 
** Started on  Fri Feb 15 19:16:53 2013 franck abgrall
** Last update Sun Jun  9 16:02:16 2013 alan chauchet
*/

#include	"raytracer.h"

void		masc_bin(t_object *tmp, t_rtv *rtv)
{
  rtv->pix->data_one = (tmp->color & 0xFF0000) >> 16;
  rtv->pix->data_two = (tmp->color & 0x00FF00) >> 8;
  rtv->pix->data_three = (tmp->color & 0x0000FF);
}

void		my_pixel_put_to_image(t_rtv *rtv)
{
  int		i;

  if (rtv->pix->x >= 0 && rtv->pix->x <= WINX
      && rtv->pix->y >= 0 && rtv->pix->y <= WINY)
    {
      i = rtv->pix->x * 4 + rtv->pix->y * rtv->init->size_line;
      rtv->init->data[i] = rtv->pix->data_three;
      rtv->init->data[i + 1] = rtv->pix->data_two;
      rtv->init->data[i + 2] = rtv->pix->data_one;
    }
}
