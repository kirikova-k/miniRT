/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:07:28 by fbeatris          #+#    #+#             */
/*   Updated: 2022/02/14 15:23:51 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	draw_pixel(t_img *img, int x, int y, int color)
{
	char	*dest;

	if (x < WIN_WIDTH && x > 0 && y < WIN_HEIGHT && y > 0)
	{
		dest = img->address + (y * img->line_len + x * img->bpp / 8);
		*(unsigned int *)dest = color;
	}
}

float	find_dist(t_object *object, t_vector start, t_vector direction)
{
	float	distance;

	distance = 0;
	if (object->type == 0)
		distance = inter_sphere(start, direction, object);
	else if (object->type == 1)
		distance = inter_plane(start, direction, object);
	else if (object->type == 2)
		distance = inter_cylinder(start, direction, object);
	return (distance);
}

int	intersection(t_object **objects, t_vector direction, t_data *data)
{
	int		i;
	float	distance;
	float	min_dist;
	int		color;

	min_dist = MAXFLOAT;
	color = BG_COLOR;
	i = 0;
	while (i < data->qty)
	{
		distance = find_dist(objects[i], data->camera->point, direction);
		if (distance > 0 && distance < min_dist)
		{
			min_dist = distance;
			color = lighting(objects[i], direction, data, distance);
		}
		i++;
	}
	return (color);
}

t_vector	find_dir(float dst, float x, float y, t_vector norm)
{
	t_vector	a;
	t_vector	b;
	t_vector	c;
	t_vector	dir;

	a = vector(dst, x - WIN_WIDTH / 2, -(y - WIN_HEIGHT / 2));
	b = vector(-(x - WIN_WIDTH / 2), dst, -(y - WIN_HEIGHT / 2));
	c = vector(-(y - WIN_HEIGHT / 2), x - WIN_WIDTH / 2, dst);
	dir = v_sum3(v_muls(a, norm.x), v_muls(b, norm.y), v_muls(c, norm.z));
	return (dir);
}

void	draw_loop(t_data *data)
{
	int			x;
	int			y;
	int			color;
	t_vector	direction;
	float		dst;

	y = 0;
	dst = WIN_WIDTH / (2 * tanf(data->camera->fov * M_PI / 360));
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			direction = find_dir(dst, x, y, v_norm(data->camera->norm));
			direction = rotate_dir(direction, data);
			color = intersection(data->objects, direction, data);
			draw_pixel(data->img, x, y, color);
			x++;
		}
		y++;
	}
}
