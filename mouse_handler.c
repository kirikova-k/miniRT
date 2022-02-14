/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:22:39 by fbeatris          #+#    #+#             */
/*   Updated: 2022/02/14 13:26:22 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_select(t_object **objects, t_vector direction, t_data *data)
{
	int		i;
	float	distance;
	float	min_dist;
	int		id;

	id = -1;
	min_dist = MAXFLOAT;
	i = 0;
	while (i < data->qty)
	{
		distance = find_dist(objects[i], data->camera->point, direction);
		if (distance > 0 && distance < min_dist)
		{
			min_dist = distance;
			id = i;
		}
		i++;
	}
	return (id);
}

void	mouse_left(t_data *data, int x, int y, int id)
{
	t_vector	direction;
	float		dst;

	dst = WIN_WIDTH / (2 * tanf(data->camera->fov * M_PI / 360));
	direction = find_dir(dst, x, y, data->camera->norm);
	direction = rotate_dir(direction, data);
	id = ft_select(data->objects, direction, data);
	if (id > -1)
	{
		if (data->select_obj > -1)
			data->objects[data->select_obj]->color = \
				add_color(data->objects[data->select_obj]->color, -SELECT_COEF);
		data->objects[id]->color = \
			add_color(data->objects[id]->color, SELECT_COEF);
		data->select_obj = id;
		remake_image(data);
		mlx_hook(data->mlx_window, 2, (1L << 0), key_hook, data->objects[id]);
	}
	else
		mlx_hook(data->mlx_window, 2, (1L << 0), key_hook, data->objects[0]);
}

void	mouse_right(t_data *data)
{
	if (data->select_obj > -1)
		data->objects[data->select_obj]->color = \
			add_color(data->objects[data->select_obj]->color, -SELECT_COEF);
	data->select_obj = data->light->id;
	remake_image(data);
	mlx_hook(data->mlx_window, 2, (1L << 0), key_hook, data->light);
}

int	mouse_handler(int button, int x, int y, void *data1)
{
	t_data	*data;
	int		id;

	id = 0;
	data = (t_data *)data1;
	if (button == 1)
	{
		mouse_left(data, x, y, id);
	}
	if (button == 2)
		mouse_right(data);
	return (0);
}
