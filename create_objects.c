/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 00:00:21 by fbeatris          #+#    #+#             */
/*   Updated: 2022/02/13 05:58:02 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	count_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

t_object	*create_sphere(char **arr, int *count, t_data *data)
{
	t_object	*new;

	if (count_arr(arr) != 8)
		exit_error("Currupted file");
	new = malloc(sizeof(t_object));
	if (!new)
		exit_error("Malloc error");
	(*count)++;
	new->id = *count;
	new->type = 0;
	new->point.x = ft_atof(arr[1]);
	new->point.y = ft_atof(arr[2]);
	new->point.z = ft_atof(arr[3]);
	new->diameter = ft_atof(arr[4]);
	new->color = create_rgb(ft_atoi(arr[5]), \
		ft_atoi(arr[6]), ft_atoi(arr[7]));
	new->data = data;
	return (new);
}

t_object	*create_plane(char **arr, int *count, t_data *data)
{
	t_object	*new;

	if (count_arr(arr) != 10)
		exit_error("Currupted file");
	new = malloc(sizeof(t_object));
	if (!new)
		exit_error("Malloc error");
	(*count)++;
	new->id = *count;
	new->type = 1;
	new->point.x = ft_atof(arr[1]);
	new->point.y = ft_atof(arr[2]);
	new->point.z = ft_atof(arr[3]);
	new->norm.x = ft_atof(arr[4]);
	new->norm.y = ft_atof(arr[5]);
	new->norm.z = ft_atof(arr[6]);
	new->color = create_rgb(ft_atoi(arr[7]), \
		ft_atoi(arr[8]), ft_atoi(arr[9]));
	new->data = data;
	return (new);
}

t_object	*create_cylinder(char **arr, int *count, t_data *data)
{
	t_object	*new;

	if (count_arr(arr) != 12)
		exit_error("Currupted file");
	new = malloc(sizeof(t_object));
	if (!new)
		exit_error("Malloc error");
	(*count)++;
	new->id = *count;
	new->type = 2;
	new->point.x = ft_atof(arr[1]);
	new->point.y = ft_atof(arr[2]);
	new->point.z = ft_atof(arr[3]);
	new->norm.x = ft_atof(arr[4]);
	new->norm.y = ft_atof(arr[5]);
	new->norm.z = ft_atof(arr[6]);
	new->diameter = ft_atof(arr[7]);
	new->height = ft_atof(arr[8]);
	new->color = create_rgb(ft_atoi(arr[9]), \
		ft_atoi(arr[10]), ft_atoi(arr[11]));
	new->data = data;
	return (new);
}

t_object	*create_light(char **arr, int *count, t_data *data)
{
	t_object	*new;

	if (count_arr(arr) != 8)
		exit_error("Currupted file");
	new = malloc(sizeof(t_object));
	if (!new)
		exit_error("Malloc error");
	(*count)++;
	new->id = *count;
	new->type = 3;
	new->point.x = ft_atof(arr[1]);
	new->point.y = ft_atof(arr[2]);
	new->point.z = ft_atof(arr[3]);
	new->brightness = ft_atof(arr[4]);
	new->color = create_rgb(ft_atoi(arr[5]), \
		ft_atoi(arr[6]), ft_atoi(arr[7]));
	data->light = new;
	new->data = data;
	return (new);
}
