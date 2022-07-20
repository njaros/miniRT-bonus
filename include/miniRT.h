/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:19:13 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/20 14:54:55 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <pthread.h>

# define PI 3.14159265358979323
# define K_ESC 53
# define K_RIGHT 124
# define K_LEFT 123
# define K_UP 126
# define K_DOWN 125
# define K_FRONT 13
# define K_BACK 1
# define K_SPHERE 3
# define K_CYLINDER 16
# define K_CAMERA 8
# define K_PLANE 35
# define K_LIGHT 11
# define K_REFLEXION 15
# define K_PLUS 69
# define K_MINUS 78
# define K_E 14
# define K_Q 12
# define K_Z 6
# define K_X 7
# define K_I 34
# define K_J 38
# define K_K 40
# define K_L 37
# define PLAN 0
# define SPHERE 1
# define CYLINDER 2

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

typedef struct s_coord
{
	float	x;
	float	y;
	float	z;
}	t_coord;

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

typedef struct s_line
{
	t_vec	dir;
	t_coord	point;
	int		ref;
}	t_line;

typedef struct s_mat
{
	float	a_a;
	float	a_b;
	float	a_c;
	float	b_a;
	float	b_b;
	float	b_c;
	float	c_a;
	float	c_b;
	float	c_c;
}	t_mat;

typedef struct s_a
{
	float	light_r;
	t_color	color;
}	t_a;

typedef struct s_c
{
	t_coord	coord;
	t_vec	vec;
	float	angle_z;
	float	angle_x;
	float	fov;
}	t_c;

typedef struct s_l
{
	t_coord	coord;
	float	light_r;
	t_color	color;
}	t_l;

typedef struct s_sp
{
	t_coord	coord;
	float	diam;
	t_color	color;
}	t_sp;

typedef struct s_pl
{
	t_coord	coord;
	t_vec	vec;
	float	angle_z;
	float	angle_x;
	t_mat	mat_rot;
	t_color	color;
}	t_pl;

typedef struct s_cy
{
	t_coord	coord;
	t_vec	vec;
	float	diam;
	float	height;
	float	angle_z;
	float	angle_x;
	t_mat	mat_rot;
	t_color	color;
	t_pl	plan_up;
	t_pl	plan_down;
}	t_cy;

typedef struct s_ele
{
	int		a;
	t_a		struc_a;
	int		c;
	t_c		struc_c;
	int		l;
	t_l		*struc_l;
	int		sp;
	t_sp	*struc_sp;
	int		pl;
	t_pl	*struc_pl;
	int		cy;
	t_cy	*struc_cy;
}	t_ele;

typedef struct s_inter
{
	bool	exist;
	float	dist;
	t_vec	normal;
	t_coord	point;
	t_color	color;
	int		object;
	int		cyl_touch;
}	t_inter;

typedef struct s_pix
{
	t_color	color;
}	t_pix;

typedef struct s_img
{
	void	*ptr;
	char	*adr;
	int		bpp;
	int		line_lengh;
	int		endian;
	t_pix	p;
}	t_img;

typedef struct s_win
{
	void	*ptr;
	int		lenght;
	int		height;
}	t_win;

typedef struct s_var t_var;

typedef struct	s_pixel_task
{
	int				i;
	int				j;
	int				transit;
	pthread_mutex_t	check;
}	t_pixel_task;

typedef struct	s_shared
{
	t_pixel_task	*to_do;
	t_var			*m;
	int				rdy_count;
	bool			work_finished;
	pthread_mutex_t	sleep;
	pthread_mutex_t	work;
}	t_shared;

typedef struct s_var{
	void			*init;
	int				ref_num;
	float			ref_coef;
	t_img			img;
	t_win			win;
	t_color			amb;
	t_color			shad;
	t_color			refl;
	t_color			color;
	t_ele			ele;
	t_vec			*vec;
	t_mat			mat_rot;
	t_shared		to_do_list;
	pthread_t		*cpu;
	unsigned int	size;
	int				nb_cpu;
}	t_var;

/* UTILS */
/**
 * @brief convert ASCII to float
 */
float	ft_atof(char *line);
/**
 * @brief convert ASCII to int
 */
int		ft_atoi(char *string);
/**
 * @brief convert ASCII to long
 */
bool	ft_atol(char *string, float *r);
/**
 * @brief malloc count*eltsize bit and set them to 0
 * @param count number of element to be malloc
 * @param eltsize size of the element
 * @return void* memory adress of the malloced element
 */
void	*ft_calloc(int count, int eltsize);
/**
 * @brief put the content of a file in a char*
 * @return content of the file strjoined
 */
char	*ft_get_file(int fd);
void	ft_memset(void *block, int c, unsigned long size);
char	**ft_split(char const *s, char c);
char	*ft_strchr(char *string, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
int		ft_strlen_s(char *s);
int		ft_strncmp(char *s1, char *s2, int size);
int		ft_isdigit(int c);
void	ft_free_split(char **split);
/* UTILS */

/* ERROR */
/**
 * @brief return an error message and quit the programme
 * @param nb the message's number to be display
 */
void	ft_error(t_var *m, int nb);
void	ft_exit(t_var *m, int i);
/* ERROR */

/* MAIN */
/**
 * @brief open, check and save the data contained in the file specified by path
 */
void	ft_image_render(t_var *m);
void	ft_parsing(t_var *m, char *path);
/* MAIN */

/* CHECK */
/* OBJECT_CHECK */
/**
 * @brief check the format of the ambiante lightning object
 */
void	ft_check_ambiante_lightning(t_var *m, char *line);
/**
 * @brief check the format of the camera object
 */
void	ft_check_camera(t_var *m, char *line);
/**
 * @brief check the format of the cylinder object
 */
void	ft_check_cylinder(t_var *m, char *line);
/**
 * @brief check the format of the light object
 */
void	ft_check_light(t_var *m, char *line);
/**
 * @brief check the format of the plane object
 */
void	ft_check_plane(t_var *m, char *line);
/**
 * @brief check the format of the sphere object
 */
void	ft_check_sphere(t_var *m, char *line);
/* OBJECT_CHECK */
/* STR_CHECK */
/**
 * @brief check the format of the color arg
 */
void	ft_check_color(t_var *m, char *s);
/**
 * @brief check the format of the coordinate arg
 */
void	ft_check_coordinate(t_var *m, char *s);
/**
 * @brief check if the string make for a good float
 */
void	ft_check_correct_float_format(t_var *m, char *s);
/**
 * @brief check the format of the dimension arg
 */
void	ft_check_dimension(t_var *m, char *s);
/**
 * @brief check if the extension of the string match "".rt"
 */
void	ft_check_extension(t_var *m, char *path);
/**
 * @brief check the format of the fov arg
 */
void	ft_check_fov(t_var *m, char *s);
/**
 * @brief check the object's identifier and call the correct checker
 */
void	ft_check_imput(t_var *m, char *line);
/**
 * @brief check the format of the lightration arg
 */
void	ft_check_lightratio(t_var *m, char *s);
/**
 * @brief check the format of the normalized vector
 */
void	ft_check_normalization(t_var *m, char *s);
/**
 * @brief check if the string is only composed of digit and comma
 */
void	ft_check_only_digit_and_comma(t_var *m, char *s);
/* STR_CHECK */
/* CHECK */

/* INIT */
void	ft_imput_init(t_var *m, char *s);
void	ft_init_plane(t_var *m, char *s);
void	ft_init_cylinder(t_var *m, char *s);
t_pl	set_plan_down(t_cy cy);
t_pl	set_plan_up(t_cy cy);
void	ft_vec_init(t_var *m);
/* INIT */

/* MATH */
float	abs_float(float d);
float	quake_sqrt(float nb);
int		ft_min(int a, int b);
int		ft_max(int a, int b);

/* VEC */
float	ft_vec_lenght(t_vec x);
float	ft_square_length(t_vec x);
void	ft_vec_normalization(t_vec *old);
float	ft_dot_product(t_vec a, t_vec b);
t_vec	vector_product(t_vec a, t_vec b);
void	modif_pointline(t_line l, t_coord *point, float mu);
t_coord	set_pointline(t_line l, float coef);
float	coef_point(t_coord pt, t_line l);
t_vec	crea_vector(t_coord a, t_coord b);
float	plan_dist(t_line l, t_pl p);
t_line	cy_line(t_cy c);
t_vec	find_normal_line(t_line l, t_coord a, float *dist);
float	lines_normal_segment(t_line l1, t_line l2, t_inter *inter);
float	distance_projection(t_line l, t_coord a);
float	paralel_dist(t_line l1, t_line l2);
bool	side_plan(float dist);
/* VEC */
/* MATRIX */
void	ft_mat_vec(t_vec ov, t_mat mat, t_vec *nv);
void	ft_mat_mat(t_mat m1, t_mat m2, t_mat *new);
void	ft_add_mat_mat(t_mat m1, t_mat m2, t_mat *new);
float	ft_determinant(t_mat mat);
t_mat	mat_compose(t_vec v1, t_vec v2, t_vec v3);
t_mat	ft_mat_rotx(float angle);
t_mat	ft_mat_roty(float angle);
t_mat	ft_mat_rotz(float angle);
/* MATRIX */
/* INTERSECTION */
t_inter	inter_plan(t_line l, t_pl p);
t_inter	inter_sphere(t_line l, t_sp s);
void	fill_inter_c(t_inter *inter, t_cy c);
bool	set_ex_c(t_inter *inter, t_line l, t_cy c);
bool	min_mu(t_inter *i, t_line l, t_cy cy, float mu);
bool	plus_mu(t_inter *i, t_line l, t_cy cy, float mu);
t_inter	inter_cylinder(t_line l, t_cy cy);
t_inter	inter_checker(t_line l, t_ele e);
bool	side_plan_c(t_pl plan, t_coord point);
t_inter	check_inter_sphere(int nb, t_sp *s, t_line l, t_inter inter);
t_inter	check_inter_plan(int nb, t_pl *p, t_line l, t_inter inter);
/* INTERSECTION */

bool	ft_inter_light(t_var *m, t_l light, t_inter inter, float *ratio);

/* MATH */

/* KEYHOOK */
int		ft_imput_first(int key, void *mm);
int		ft_imput_sphere(int key, t_var *m);
int		ft_please_stop(void *m);
void	ft_move_cam(t_var *m, int s);
void	ft_change_sphere(int key, t_var *m, int i);
void	ft_change_cylinder(int key, t_var *m, int i);
void	ft_change_plane(int key, t_var *m, int i);
void	ft_change_light(int key, t_var *m, int i);
void	ft_change_plane_2(t_var *m, int i);
/* KEYHOOK */

/* COLOR */
void	ft_color_reset(t_var *m);
t_color	ft_skybox_color(t_var *m, t_vec v);
t_color	ft_shadow_light(t_var *m, int i, float ratio, t_color objcol);
t_color	ft_ambiant_light(t_var *m, t_color object_color);
t_color	ft_add_color(t_var *m, t_color amb, t_color shad, t_color refl);
void	ft_reflexion_light(t_var *m, t_color color);
t_color	ft_color_pixel(t_var *m, t_line line);
void	ft_add_color_2(t_color *color, t_color shad);
/* COLOR */

/* MULTI THREADING ADDS */
void	init_shared_data(t_var *m);
void	*thread_routine(void *arg);
void	thread_manager(t_var *m);
void	ft_pixel_put(t_var *m, int i, int j, t_vec v);
/* MULTI THREADING ADDS */

/* OTHER */
void	ft_display_struc_content(t_var *m);
void	ft_debug_mat(t_mat m);
bool	secure_glitch_cylinder(t_cy c, t_coord point);
bool	in_sphere(t_sp s, t_coord point);
bool	secure_glitch_plan(t_pl plan, t_coord point, float *dist);
bool	secure_glitch_sphere(t_sp s, t_coord point, float *dist);
bool	in_sphere_mem(float dist);
int		ft_check_check(t_var *m, t_line l_line, float lg_segment);
bool	check_light_inter_plan(t_var *m, t_line l, float coef);
bool	check_light_inter_sph(t_var *m, t_line l, float coef);
bool	check_light_inter_cyl(t_var *m, t_line l, float coef);
t_color	ft_reflexion(t_var *m, t_inter inter, t_line old_rt);
t_line	new_rt(t_line old_rt, t_inter i);
int		ft_imput_reflexion(int key, t_var *m);
void	ft_super_free_split(char **s1, char **s2, char **s3, char **s4);
/* OTHER */

#endif