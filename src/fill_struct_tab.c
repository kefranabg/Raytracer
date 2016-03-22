/*
** fill_struct_tab.c for fill_strcut_tab.c in /home/abgral_f//Dropbox/Raytracer/raytracer-2017-chanut_g/src
**
** Made by franck abgrall
** Login   <abgral_f@epitech.net>
**
** Started on  Wed May  1 13:57:49 2013 franck abgrall
** Last update Sun Jun  9 16:29:08 2013 alan chauchet
*/

#include	"raytracer.h"

static  t_cmp   struct_tab[] =
  {
    {EYES, FALSE, EYES_NB},
    {LIGHT, FALSE, LIGHT_NB},
    {CONE, FALSE, CONE_NB},
    {PLAN, FALSE, PLAN_NB},
    {CYLINDER, FALSE, CYLINDER_NB},
    {SPHERE, FALSE, SPHERE_NB},
    {PARABOLE, FALSE, PARABOLE_NB},
    {HYPERBOLE, FALSE, HYPERBOLE_NB},
    {NULL, FALSE, 0}
  };

int		get_object_column_number(int *ref_tab)
{
  int		count;

  count = 0;
  while (count < SIZE_TAB)
    {
      if (ref_tab[count] == OBJECT_NB)
	return (count + 1);
      count++;
    }
  return (EXIT_SUCCESS);
}

int		check_object_name_existence(t_list *list, int column_nb)
{
  int		count;
  int		count_char;
  int		count_tab;

  count = 0;
  count_char = -1;
  while (count != column_nb && list->line[++count_char] != '\0')
    if (list->line[count_char] == SEPARATOR)
      {
	count++;
	if (count == column_nb)
	  {
	    count_tab = -1;
	    while (++count_tab != SIZE_STRUCT_TAB)
	      if (my_strcmp_parser(&(list->line[count_char + 1]),
				   struct_tab[count_tab].name) == 0)
		return (struct_tab[count_tab].nb_ref);
	    my_puterror(WRONG_OBJECT);
	    my_putnbr(list->line_nb);
	    return (-1);
	  }
      }
  return (-1);
}

int		fill_struct_tab(t_list *list, t_rt *rt)
{
  int		column_nb;
  int		object_nb;

  if (list->next != NULL)
    list = list->next;
  rt->first_line = list;
   column_nb = get_object_column_number(rt->ref_tab);
  while (list != NULL)
    {
      if ((object_nb = check_object_name_existence(list, column_nb))
	  == -1)
	return (EXIT_FAILURE);
      if (redirect_appropriate_function(object_nb, list, rt) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      list = list->next;
    }
  return (EXIT_SUCCESS);
}
