/*
** raytracer.h for rt in /home/chauch_a//raytracer-2017-chanut_g
**
** Made by alan chauchet
** Login   <chauch_a@epitech.net>
**
** Started on  Wed Apr  3 11:32:06 2013 alan chauchet
** Last update Sun Jun  9 18:30:50 2013 adrien domoison
*/

#ifndef		_RAYTRACER_
# define	_RAYTRACER_

/*
** INCLUDES
*/

# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<mlx.h>
# include	<math.h>

/*
** DEFINES
*/

# define	RAD(x)		((x) * (M_PI / 180))
# define	ANG(x)		(((x) < 0) ? (((x) % 360) + 360) : ((x) % 360))
# define	ESC_KEY		65307
# define	UP_KEY		65362
# define	DOWN_KEY	65364
# define	LEFT_KEY	65361
# define	RIGHT_KEY	65363
# define	PLUS_KEY	65451
# define	MINUS_KEY	65453

# define	S_KEY		115

# define	OPT_S		"-s"
# define	OPT_W		"-w"

# define	DIST		1000
# define	DEFAULT_SIZE_X	1000
# define	DEFAULT_SIZE_Y	1000

# define	N_ALIASING	"*anti-aliasing=>"
# define	ALIASING	"*aliasing=>"
# define	THREADS		"*threads=>"
# define	AMBIANCE	"*ambiance_light=>"
# define	FILTER		"*filter=>"
# define	BACKSCREEN	"*backscreen=>"

# define	EYES		"eyes"
# define	LIGHT		"light"
# define	CONE		"cone"
# define	PLAN		"plan"
# define	CYLINDER	"cylinder"
# define	SPHERE		"sphere"
# define	PARABOLE	"parabole"
# define	HYPERBOLE	"hyperbole"

# define	OBJECT		"object"
# define	POSX		"pos_x"
# define	POSY		"pos_y"
# define	POSZ		"pos_z"
# define	ROTX		"rot_x"
# define	ROTY		"rot_y"
# define	ROTZ		"rot_z"
# define	COLOR		"color"
# define	REFLEXION	"reflexion"
# define	OPACITY		"opacity"
# define	RADIUS		"radius"
# define	ANGLE		"angle"
# define	BRIGHTNESS	"brightness"
# define	LIMIT		"limit"
# define	DISTURB_X	"disturb_x"
# define	DISTURB_Y	"disturb_y"
# define	CHECK_FREQUENCY	"check_frequency"

# define	EYES_NB		1
# define	LIGHT_NB	2
# define	CONE_NB		3
# define	CYLINDER_NB	4
# define	SPHERE_NB	5
# define	PLAN_NB		6
# define	PARABOLE_NB	7
# define	HYPERBOLE_NB	8

# define	OBJECT_NB		1
# define	POSX_NB			2
# define	POSY_NB			3
# define	POSZ_NB			4
# define	ROTX_NB			5
# define	ROTY_NB			6
# define	ROTZ_NB			7
# define	COLOR_NB		8
# define	REFLEXION_NB		9
# define	OPACITY_NB		10
# define	BRIGHTNESS_NB		11
# define	RADIUS_NB		12
# define	ANGLE_NB		13
# define	LIMIT_NB		14
# define	DISTURB_X_NB		15
# define	DISTURB_Y_NB		16
# define	CHECK_FREQUENCY_NB	17

# define	WINDOW_NAME		"Raytracer by Gros-porc"

# define	IMG_SAVED		"Saving img as "

# define	SEPARATOR		'|'
# define	COMMENT			'#'

# define	SIZE_TAB		17
# define	SIZE_STRUCT_TAB		8

# define	NB_SEPARATOR		18
# define	NB_OBJECT		8

# define	FOPEN_MODE		"r"
# define	EXTENSION		".conf"

/*
** ERROR
*/

# define USAGE			"[USAGE]:\tFile, [-s] [-w].\n"
# define USAGE_S		"[USAGE]:\tFile, [-s win_size_x win_size_y].\n"
# define USAGE_W		"[USAGE]:\tFile, [-w nb_img speed].\n"
# define BAD_ARG_S		"[RAYTRACER]:\tWindow size must be a number.\n"
# define SIZE_ZERO		"[RAYTRACER]:\tWindow size error\n"

# define FOPEN_ERROR		"[RAYTRACER]:\tError on open.\n"
# define BAD_EXTENSION		"[RAYTRACER]:\tWrong extension file\n"
# define EMPTY_FILE		"[RAYTRACER]: There is an error in the file.\n"
# define BAD_SCREEN		"Invalid file for texture (.xpm needed)\n"
# define ANTI_ALIASING_BAD_ARG	"[RAYTRACER]:\tAnti-aliasing error line "
# define ALIASING_BAD_ARG	"[RAYTRACER]:\tAliasing nb error line "
# define ALIASING_ERROR		"[RAYTRACER]: Window too small for aliasing\n"
# define ERROR_ALIASING		"[RAYTRACER]: aliasing / anti-aliasing error\n"
# define THREAD_BAD_ARG		"[RAYTRACER]:\tThreads number error line "
# define AMBIANCE_BAD_ARG	"[RAYTRACER]:\tAmbiance number error line "
# define FILTER_BAD_ARG		"[RAYTRACER]:\tfilter number error line "

# define BAD_SEPARATOR_NB	"[RAYTRACER]:\tBad separators number.\n"
# define EMPTY_BOX		"[RAYTRACER]:\tempty box in the file line "
# define BAD_NAME		"[RAYTRACER]:\tBad column name in the file.\n"
# define TWICE_NAME_USE		"[RAYTRACER]:\tcolumn used twice in file.\n"
# define WRONG_OBJECT		"[RAYTRACER]:\twrong object in file line "
# define WRONG_COLUMN		"[RAYTRACER]:\tunknown column in file\n"
# define COLOR_SYNTAX		"[RAYTRACER]: Line %d : expected hexadecimal\n"
# define NO_EYES		"[RAYTRACER]:\tNo eyes in the conf file\n"
# define TOO_MANY_EYES		"[RAYTRACER]:\tToo many eyes in file\n"

# define CONNECT_ERROR		"[RAYTRACER]: Cannot connect to the server X\n"

# define MALLOC_ERROR		"[RAYTRACER]:\tError on malloc.\n"
# define FPRINTF_ERROR		"[RAYTRACER]:\tError on fprintf.\n"
# define THREAD_ERROR		"[RAYTRACER]:\tError on pthread_create.\n"
# define READ_ERROR		"[RAYTRACER]:\tError on read.\n"
# define BMP_ERROR		"File name must be at least one character.\n"
# define BMP_FILE		"Enter the file name : \n > "

typedef enum
  {
    TRUE,
    FALSE
  }	bool;

/*
** BITMAP
*/

typedef	struct __attribute__((packed))	s_bitmapfileheader
{
  unsigned short			bftype;
  unsigned int				bfSize;
  unsigned short			bfReserved1;
  unsigned short			bfReserved2;
  unsigned int				bfOffBits;
}					t_bitmapfileheader;

typedef	struct __attribute__((packed))	s_bitmapinfoheader
{
  unsigned int				biSize;
  int					biWidth;
  int					biHeight;
  unsigned short			biPlanes;
  unsigned short			biBitCount;
  unsigned int				biCompression;
  unsigned int				biSizeImage;
  int					biXPelsPerMeter;
  int					biYPelsPerMeter;
  unsigned int				biClrUsed;
  unsigned int				biClrImportant;
}					t_bitmapinfoheader;

/*
** STRUCTURES
*/

typedef	struct		s_cmp
{
  char			*name;
  bool			visited;
  int			nb_ref;
}			t_cmp;

typedef	struct		s_list
{
  char			*line;
  int			line_nb;
  struct s_list		*next;
}			t_list;

typedef	struct		s_coord
{
  double		x;
  double		y;
  double		z;
}			t_coord;

typedef	struct		s_rotate
{
  int			rx;
  int			ry;
  int			rz;
}			t_rotate;

typedef	struct		s_color
{
  unsigned char		red;
  unsigned char		green;
  unsigned char		blue;
}			t_color;

typedef	struct		s_effects
{
  double		reflexion;
  double		opacity;
  double		brightness;
  int			disturb_x;
  int			disturb_y;
  int			check_frequency;
}			t_effects;

typedef	struct		s_object
{
  struct s_effects	effects;
  struct s_rotate	rotate;
  struct s_coord	coord;
  int			radius;
  int			param;
  int			object_nb;
  int			color;
  int			limit;
  struct s_object	*next;
}			t_object;

typedef	struct		s_light
{
  struct s_coord	coord;
  double		intensity;
  int			color;
  struct s_light	*next;
}			t_light;

typedef	struct		s_light_var
{
  struct s_color	color;
  struct s_coord	norm;
  struct s_coord	vector;
  double		norme_n;
  double		norme_l;
  double		brightness;
  double		shadow;
  double		cos_a;
}			t_light_var;

typedef	struct		s_option
{
  int			opt_g;
  int			opt_m;
  int			opt_w;
}			t_option;

typedef	struct		s_window
{
  int			size_x;
  int			size_y;
  int			win_x;
  int			win_y;
}			t_window;

typedef	struct		s_mlx
{
  void			*mlx_ptr;
  void			*win_ptr;
  void			*img_ptr;
  void			*img_ptr_resize;
  void			*img_ptr_aliasing;
  unsigned char		*data;
  unsigned char		*data_resize;
  unsigned char		*data_aliasing;
  int			bits_per_pixel;
  int			size_line;
  int			endian;
  int			bits_per_pixel_aliasing;
  int			size_line_aliasing;
  int			endian_aliasing;
  int			bits_per_pixel_resize;
  int			size_line_resize;
  int			endian_resize;
}			t_mlx;

typedef	struct		s_eye
{
  struct s_coord	coord;
  struct s_rotate	rotate;
  bool			check;
}			t_eye;

typedef	struct		s_backscreen
{
  unsigned char		*data;
  void			*img;
  int			bpp;
  int			size_line;
  int			endian;
  char			*name;
  int			a;
  int			b;
}			t_backscreen;

typedef	struct		s_gen_param
{
  int			filter;
  int			anti_aliasing;
  int			aliasing;
  int			threads;
  double		ambiance_light;
  t_backscreen		backscreen;
  int			speed;
  int			nb_img;
}			t_gen_param;

typedef	struct		s_pixel
{
  int			nb_pixel;
  int			pixel_pos;
}			t_pixel;

typedef	struct		s_vision
{
  t_eye			*eye;
  t_coord		*vector;
  t_eye			*new_eye;
  t_coord		*new_vector;
}			t_vision;

typedef	struct		s_negative
{
  t_eye			prov_eye;
  t_coord		prov_vector;
  t_eye			*eye;
  t_coord		*vector;
  t_object		*object;
  t_light		*light;
  t_vision		*vision;
}			t_negative;

typedef	struct		s_transparency
{
  t_object		**inter;
  int			size_tab;
}			t_transparency;

typedef	struct		s_intersection
{
  double		neg_forward;
  double		neg_backward;
  double		obj_forward;
  double		obj_backward;
}			t_intersection;

typedef	struct		s_filter
{
  int			(*filter_fctn)(int);
}			t_filter;

typedef	struct		s_rt
{
  char			*scene_name;
  bool			inside;
  bool			shadow;
  char			negative;
  t_gen_param		general_param;
  t_pixel		pix_calc;
  int			*ref_tab;
  t_eye			eye;
  t_coord		vector;
  t_list		*first_line;
  t_object		*first_object;
  t_object		*last_object;
  t_light		*first_light;
  t_light		*last_light;
  t_light_var		light_var;
  t_window		size;
  t_mlx			mlx_init;
  int			color;
  double		cosinus[360];
  double		sinus[360];
  double		k;
  bool			inter;
  t_object		*final_obj;
  t_transparency	transp;
  int			stop_reflexion;
  int			*count_pixel;
  int			thread_nb;
  t_intersection	inter_neg;
  int			pos_x;
  int			pos_y;
  int			pos;
  t_mlx			*img_tab;
}			t_rt;

typedef	struct		s_object_tab
{
  int			object_nb;
  void			(*fct_lum)(t_rt *, t_vision *, t_object *, t_coord *);
}			t_object_tab;

typedef	struct		s_inter_obj
{
  int			nb;
  double		(*inter_obj)(t_rt *, t_negative *);
}			t_inter_obj;

/*
** PROTOTYPES
*/

/*
** basics
*/

int		bsc(char **);
int		bmp(t_rt *);
void		init_rt(t_rt *);
int		check_option(char **, t_rt *);
int		get_window_size(t_rt *, char *, char *);
int		get_wolf_param(t_rt *, char *, char *);
void		default_size_window(t_rt *);
int		init_param(t_rt *);
void		load_cos_and_sin(t_rt *);
int		key_hook(int, t_rt *);
int		resize_aliasing(t_rt *);
int		expose_hook(t_rt *);
void		calc_rot_eye(t_rt *, int, int);
void		my_pixel_put(t_rt *, int, int, int);
void		color_no_spot(t_rt *);
double		negative_object(t_rt *, double, double, t_negative *);
void		normal_perturbation(t_rt *, t_object *, t_vision *, t_coord *);
void		filter_color(t_rt *, int *);
void		damier(t_rt *, t_object *, t_coord *, t_eye *);
int		sign(double);
int		get_backscreen(char *, int, t_rt *);
void		recup_backscreen(t_rt *);
int		pixel_backscreen(t_rt *, int, int);
int		get_ambiance(char *, int, t_rt *);
int		get_filtre(char *, int, t_rt *);
int		get_aliasing(char *, int, t_rt *);
int		get_anti_aliasing(char *, int, t_rt *);
int		get_threads(char *, int, t_rt *);

/*
** struct cpy
*/

t_rt		*cpy_general_struct(t_rt *);
int		cpy_object_list(t_rt *, t_rt *);
int		cpy_light_list(t_rt *, t_rt *);

/*
** anti_aliasing
*/

void		resize_window_anti_aliasing(t_rt *);
void		resize_window_aliasing(t_rt *);
int		antialiasing(t_rt *);
int		aliasing(t_rt *);

/*
** thread
*/

int		thread_creation(t_rt *);

/*
** loop
*/

void		*raytracing(void *);
void		search_inter(t_rt *, int, int);
int		object_loop(t_rt *, t_coord *, t_eye *, t_object **);

/*
** matrice
*/

double		matrice_rotate_x(t_rt *, t_coord *, t_object *, int);
double		matrice_rotate_y(t_rt *, t_coord *, t_object *, int);
double		matrice_rotate_z(t_rt *, t_coord *, t_object *, int);
void		calc_matrice_eye(t_rt *, t_object *, t_eye *, t_eye *);
void		calc_matrice_vector(t_rt *, t_object *, t_coord *, t_coord *);

/*
** intersect
*/

double		inter_sphere(t_rt *, t_negative *);
double		inter_cylinder(t_rt *, t_negative *);
double		inter_plan(t_rt *, t_negative *);
double		inter_cone(t_rt *, t_negative *);
double		inter_parabole(t_rt *, t_negative *);
double		inter_hyperbole(t_rt *, t_negative *);

/*
** lights
*/

void		sphere_luminosity(t_rt *, t_vision *, t_object *, t_coord *);
void		cylinder_luminosity(t_rt *, t_vision *, t_object *, t_coord *);
void		plan_luminosity(t_rt *, t_vision *, t_object *, t_coord *);
void		cone_luminosity(t_rt *, t_vision *, t_object *, t_coord *);
void		parabole_luminosity(t_rt *, t_vision *, t_object *, t_coord *);
void		hyperbole_luminosity(t_rt *, t_vision *, t_object *, t_coord *);
int		add_light(t_rt *);
int		get_light_specs(t_list *, int, t_rt *);
void		loop_light(t_rt *, t_object *, t_vision *);
char		check_shadow(t_rt *, t_light *, t_vision *);
int		apply_color(t_rt *);

/*
** transparency / reflexion
*/

void		transparency(t_rt *, int *, t_coord *, t_eye *);
void		reflexion(t_rt *, int *, t_coord *, t_eye *);
void		calc_norm_reflexion(t_rt *, t_vision *, t_coord *, t_object *);
void		calc_next_eye_reflexion(t_rt *, t_vision *, t_eye *);
void		calc_reflected_vector(t_coord *, t_coord *, t_vision *);
t_vision	assign_vision(t_coord *, t_eye *, t_coord *, t_eye *);

/*
** filter
*/

int		negativ_filter(int);
int		mix_filter(int);
int		sepia_filter(int);
int		black_white_filter(int);
int		red_filter(int);
int		green_filter(int);
int		blue_filter(int);
int		purple_filter(int);
int		cyan_filter(int);
int		grey_filter(int);

/*
** lib
*/

char		*epur_line(char *);
void		my_memset(char *, char, unsigned int);
int		my_putchar(char);
int		my_puterror(char *);
int		my_printf_error(char *);
void		my_putnbr(int);
int		my_putstr(char *);
int		my_str_isnum(char *, int);
char		*my_strcat(char *, char *, int, int);
int		my_strncmp(char *, char *, unsigned int);
int		my_strcmp(char *, char *);
int		my_strcmp_parser(char *, char *);
char		*my_strdup(char *, int);
int		my_strlen(char *);
int		check_isnum(char *, t_list *);
int		my_atoi_base(char *, char *);
int		my_strlen_rt(char *);

/*
** linked list
*/

int		add_elem(t_list **, char *, int);
int		show_list(t_list *);
int		my_linked_list_len(t_list *);
void		my_free_list(t_list *);
void		my_rev_list(t_list **);

/*
** parser
*/

int		get_general_params(char *, int , t_rt *);
int		get_file(char *, t_rt *);
int		open_file(char *, t_list **, t_rt *);
int		read_file(FILE *, t_list **, t_rt *);
int		pars_first_line(t_list *, t_rt *);
int		check_separator_number(t_list *);
int		check_if_empty_box(t_list *);
int		check_right_name(char *, int [SIZE_TAB]);
int		compare_name(char *, int [SIZE_TAB]);
int		fill_struct_tab(t_list *, t_rt *);
int		redirect_appropriate_function(int, t_list *, t_rt *);
int		get_light_specs(t_list *, int, t_rt *);
int		get_sphere_specs(t_list *, int, t_rt *);
int		get_cylinder_specs(t_list *, int, t_rt *);
int		get_plan_specs(t_list *, int, t_rt *);
int		get_parabole_specs(t_list *, int, t_rt *);
int		get_hyperbole_specs(t_list *, int, t_rt *);
int		get_eyes_specs(t_list *, int, t_rt *);
int		get_cone_specs(t_list *, int, t_rt *);
int		get_column_number(int, t_rt *);
int		add_object(t_rt *, int);
double		get_specs(t_list *, t_rt *, int);
int		get_adress_specs(t_list *, int);
int		get_coord(t_list *, t_rt *);
int		get_effects(t_list *, t_rt *);
int		get_rotate(t_list *, t_rt *);
int		get_color(t_list *, t_rt *, int);
int		check_color_syntax(char *, t_list *);
int		check_eyes_number(t_rt *);
int		get_color_hex_str(char **, char *);

/*
** misc
*/

void		aff_load_bar(t_rt *);
void		aff_loading(t_rt *, int, int, int);
void		clear_img(t_rt *);

/*
** free
*/

int		free_object_list(t_rt *);
int		free_light_list(t_rt *);

#endif
