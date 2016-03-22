/*
** main.c for main.c in /home/acca_b/Dropbox/EPITECH/Tek1/Raytracer/bmp
**
** Made by baptiste acca
** Login   <acca_b@epitech.net>
**
** Started on  Mon Jun  3 13:15:14 2013 baptiste acca
** Last update Sun Jun  9 21:19:47 2013 baptiste acca
*/

#include		<sys/types.h>
#include		<sys/wait.h>
#include		<fcntl.h>
#include		"raytracer.h"

void			make_img_header(t_bitmapinfoheader *i_header, t_rt *rt)
{
  i_header->biSize = sizeof(*i_header);
  if (rt->general_param.anti_aliasing >= 1)
    {
      i_header->biWidth = rt->size.size_x / rt->general_param.anti_aliasing;
      i_header->biHeight = rt->size.size_y / rt->general_param.anti_aliasing;
    }
  if (rt->general_param.aliasing > 1)
    {
      i_header->biWidth = rt->size.size_x * rt->general_param.aliasing;
      i_header->biHeight = rt->size.size_y * rt->general_param.aliasing;
    }
  i_header->biPlanes = 1;
  i_header->biBitCount = 32;
  i_header->biCompression = 0;
  i_header->biSizeImage = i_header->biWidth * i_header->biHeight * 4;
  i_header->biXPelsPerMeter = 0;
  i_header->biYPelsPerMeter = 0;
  i_header->biClrUsed = 0;
  i_header->biClrImportant = 0;
}

void			make_file_header(t_bitmapfileheader *f_header,
					 t_bitmapinfoheader *i_header)
{
  f_header->bftype = 0x4D42;
  f_header->bfReserved1 = 0;
  f_header->bfReserved2 = 0;
  f_header->bfOffBits = sizeof(*f_header) + sizeof(*i_header);
  f_header->bfSize = f_header->bfOffBits + i_header->biSizeImage;
}

char			*get_save_name(t_rt *rt)
{
  char			*file_name;
  int			ret;

  my_putstr(BMP_FILE);
  file_name = malloc(sizeof(*file_name) * 512);
  if (file_name == NULL)
    {
      my_puterror(MALLOC_ERROR);
      return (NULL);
    }
  if ((ret = read(0, file_name, 511)) == -1)
    {
      my_puterror(READ_ERROR);
      return (NULL);
    }
  file_name[ret - 1] = '\0';
  file_name = my_strcat(file_name, ".bmp", 1, 0);
  if (file_name == NULL || my_strlen(file_name) <= 4)
    {
      my_putstr(BMP_ERROR);
      return (get_save_name(rt));
    }
  if ((rt->scene_name = my_strdup(file_name, 1)) == NULL)
    return (NULL);
  return (file_name);
}

int			bmp(t_rt *rt)
{
  t_bitmapfileheader	f_header;
  t_bitmapinfoheader	i_header;
  int			fd;
  int			i;
  char			*file_name;

  make_img_header(&i_header, rt);
  make_file_header(&f_header, &i_header);
  if ((file_name = get_save_name(rt)) == NULL)
    return (EXIT_FAILURE);
  if ((fd = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
    {
      my_puterror(FOPEN_ERROR);
      return (EXIT_FAILURE);
    }
  write(fd, &f_header, sizeof(f_header));
  write(fd, &i_header, sizeof(i_header));
  i = i_header.biSizeImage - i_header.biWidth * 4;
  while (i >= 0)
    {
      write(fd, &rt->img_tab[rt->pos].data[i], i_header.biWidth * 4);
      i -= (i_header.biWidth * 4);
    }
  close(fd);
  return (EXIT_SUCCESS);
}
