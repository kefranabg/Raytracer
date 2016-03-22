##
## Makefile for rt in /home/chauch_a//raytracer-2017-chanut_g
## 
## Made by alan chauchet
## Login   <chauch_a@epitech.net>
## 
## Started on  Wed Apr  3 11:32:46 2013 alan chauchet
## Last update Sun Jun  9 18:27:00 2013 adrien domoison
##

NAME	= rt

PATH1	= include/

PATH2	= src/

PATH3	= src/lib/

SCENE	= scene/

SRC	= $(PATH2)main.c				\
	  $(PATH2)bsc.c					\
	  $(PATH2)general_params.c			\
	  $(PATH2)bmp.c					\
	  $(PATH2)resize_aliasing.c			\
	  $(PATH2)init_rt.c				\
	  $(PATH2)object_list_two.c			\
	  $(PATH2)get_file.c				\
	  $(PATH2)read_file.c				\
	  $(PATH2)open_file.c				\
	  $(PATH2)add_elem.c				\
	  $(PATH2)my_rev_list.c				\
	  $(PATH2)show_list.c				\
	  $(PATH2)pars_first_line.c			\
	  $(PATH2)my_linked_list_len.c			\
	  $(PATH2)my_free_list.c			\
	  $(PATH2)check_right_name.c			\
	  $(PATH2)check_separator_number.c		\
	  $(PATH2)fill_struct_tab.c			\
	  $(PATH2)redirect_appropriate_function.c	\
	  $(PATH2)object_list_one.c			\
	  $(PATH2)get_eyes_spec.c			\
	  $(PATH2)get_light_specs.c			\
	  $(PATH2)get_column_number.c			\
	  $(PATH2)get_specs.c				\
	  $(PATH2)add_object.c				\
	  $(PATH2)get_adress_specs.c			\
	  $(PATH2)check_color_syntax.c			\
	  $(PATH2)check_eyes_number.c			\
	  $(PATH2)free_object_list.c			\
	  $(PATH2)get_color_hex_str.c			\
	  $(PATH2)check_option.c			\
	  $(PATH2)get_wolf_param.c			\
	  $(PATH2)default_size_window.c			\
	  $(PATH2)get_window_size.c			\
	  $(PATH2)init_param.c				\
	  $(PATH2)raytracing.c				\
	  $(PATH2)search_inter.c			\
	  $(PATH2)load_cos_and_sin.c			\
	  $(PATH2)aff_loading.c				\
	  $(PATH2)clear_img.c				\
	  $(PATH2)key_hook.c				\
	  $(PATH2)calc_rot_eye.c			\
	  $(PATH2)object_loop.c				\
	  $(PATH2)matrice_rotate.c			\
	  $(PATH2)calc_matrice.c			\
	  $(PATH2)add_light.c				\
	  $(PATH2)sphere.c				\
	  $(PATH2)cylinder.c				\
	  $(PATH2)plan.c				\
	  $(PATH2)cone.c				\
	  $(PATH2)parabole.c				\
	  $(PATH2)hyperbole.c				\
	  $(PATH2)apply_color.c				\
	  $(PATH2)free_light_list.c			\
	  $(PATH2)my_pixel_put.c			\
	  $(PATH2)get_general_params.c			\
	  $(PATH2)expose_hook.c				\
	  $(PATH2)loop_light.c				\
	  $(PATH2)check_shadow.c			\
	  $(PATH2)cpy_general_struct.c			\
	  $(PATH2)cpy_object_list.c			\
	  $(PATH2)cpy_light_list.c			\
	  $(PATH2)thread_create.c			\
	  $(PATH2)transparency.c			\
	  $(PATH2)reflexion.c				\
	  $(PATH2)reflexion_calc.c			\
	  $(PATH2)resize_window_aliasing.c		\
	  $(PATH2)resize_window_anti_aliasing.c		\
	  $(PATH2)antialiasing.c			\
	  $(PATH2)aliasing.c				\
	  $(PATH2)negative_object.c			\
	  $(PATH2)normal_perturbation.c			\
	  $(PATH2)filter_color.c			\
	  $(PATH2)apply_filter1.c			\
	  $(PATH2)apply_filter2.c			\
	  $(PATH2)damier.c				\
	  $(PATH2)get_backscreen.c			\
	  $(PATH2)pixel_backscreen.c			\
	  $(PATH3)epur_line.c				\
	  $(PATH3)my_puterror.c				\
	  $(PATH3)my_putstr.c				\
	  $(PATH3)my_strcat.c				\
	  $(PATH3)my_strlen.c				\
	  $(PATH3)my_strcmp.c				\
	  $(PATH3)my_memset.c				\
	  $(PATH3)my_strdup.c				\
	  $(PATH3)my_str_isnum.c			\
	  $(PATH3)my_putchar.c				\
	  $(PATH3)my_putnbr.c				\
	  $(PATH3)my_atoi_base.c			\

OBJ	= $(SRC:.c=.o)

CFLAGS	= -W -Wall -Werror -Wextra -Wshadow -I$(PATH1)

LIB	=  -L/usr/X11/lib -lmlx -lXext -lX11 -lm -lpthread

all: $(NAME)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ) $(LIB)
	@echo -en "\t\033[32m> " $(NAME) " compiled\033[0m\n"

clean:
	clean
	rm -f $(OBJ)
	@echo -en "\t\033[35m> " $(NAME) " cleaned\033[0m\n"

fclean: clean
	rm -f $(NAME)
	@echo -en "\t\033[31m> " $(NAME) " executable removed\033[0m\n"

re: fclean all
