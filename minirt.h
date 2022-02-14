/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:09:56 by fbeatris          #+#    #+#             */
/*   Updated: 2022/02/14 15:24:26 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define GREEN "\033[1;32m"
# define BLUE "\033[1;36m"
# define RED "\033[1;31m"
# define DEFAULT "\033[0;37m"
# define YELOW "\033[1;33m"
# define B_PINK "\033[3;45m"
# define B_GRAY "\033[1;47m"
# define VIOLET "\033[1;35m"

# define BG_COLOR 0x75BBFD

# define AMB_COEF 10
# define DIFF_COEF 2
# define SPEC_COEF 4
# define SHADOW_COEF -30
# define SELECT_COEF 50

# define ROTATE_STEP 0.2617994
# define MOVE_STEP 50
# define FOV_STEP 10

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "vectors.h"

typedef struct s_img
{
	void	*ptr;
	char	*address;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_ambient
{
	float	ratio;
	int		color;
}	t_ambient;

typedef struct s_camera
{
	t_vector	point;
	t_vector	norm;
	int			fov;
	float		angle_y;
	float		angle_z;
	t_vector	dir;
}	t_camera;

typedef struct s_light
{
	t_vector		point;
	float			brightness;
	int				color;
	struct s_light	*next;
}	t_light;

typedef struct s_object
{
	int				id;
	int				type;
	t_vector		point;
	t_vector		norm;
	float			diameter;
	float			height;
	int				color;
	float			brightness;
	struct s_data	*data;
}	t_object;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_window;
	t_img		*img;
	t_ambient	*ambient;
	t_camera	*camera;
	t_object	*light;
	t_object	**objects;
	int			qty;
	int			select_obj;
}	t_data;

void		parser(char *file_name, t_data *data);
int			count_arr(char **arr);

void		create_ambient(char **arr, t_data *data);
void		create_camera(char **arr, t_data *data);
t_object	*create_light(char **arr, int *count, t_data *data);
t_object	*create_sphere(char **arr, int *count, t_data *data);
t_object	*create_plane(char **arr, int *count, t_data *data);
t_object	*create_cylinder(char **arr, int *count, t_data *data);

void		draw_loop(t_data *data);
int			lighting(t_object *object, t_vector dir, t_data *data, float dist);
float		find_dist(t_object *object, t_vector start, t_vector direction);

float		inter_sphere(t_vector camera, t_vector dir, t_object *sphere);
float		inter_plane(t_vector camera, t_vector dir, t_object *plane);
float		inter_cylinder(t_vector camera, t_vector dir, t_object *cyl);
t_vector	cylinder_norm(t_object *cyl, t_vector inter);

int			create_rgb(int r, int g, int b);
int			rgb(int color, char level);
int			add_color(int color, float coef);
int			mul_color(int color1, float coef);
int			sum_color(int color1, int color2);
int			add_color3(int c1, int c2, int c3);

int			key_hook(int key_code, t_object *obj);

void		exit_error(char *function);
int			exit_hook(int key_code, t_data *data);

int			mouse_handler(int button, int x, int y, void *data);
t_vector	rotate_dir(t_vector dir, t_data *data);
void		remake_image(t_data *data);
t_vector	find_dir(float dst, float x, float y, t_vector norm);
t_vector	rotate_dir(t_vector dir, t_data *data);

#endif
