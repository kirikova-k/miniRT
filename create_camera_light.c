/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:42:44 by fbeatris          #+#    #+#             */
/*   Updated: 2022/02/13 05:57:49 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_ambient(char **arr, t_data *data)
{
	static int	count = 0;

	if (count > 0)
		exit_error("Currupted file");
	if (count_arr(arr) != 5)
		exit_error("Currupted file");
	data->ambient = malloc(sizeof(t_ambient));
	if (!data->ambient)
		exit_error("Malloc error");
	data->ambient->ratio = ft_atof(arr[1]);
	data->ambient->color = create_rgb(ft_atoi(arr[2]), \
		ft_atoi(arr[3]), ft_atoi(arr[4]));
	count++;
}

void	create_camera(char **arr, t_data *data)
{
	static int	count = 0;

	if (count > 0)
		exit_error("Currupted file");
	if (count_arr(arr) != 8)
		exit_error("Currupted file");
	data->camera = malloc(sizeof(t_camera));
	if (!data->camera)
		exit_error("Malloc error");
	data->camera->point.x = ft_atof(arr[1]);
	data->camera->point.y = ft_atof(arr[2]);
	data->camera->point.z = ft_atof(arr[3]);
	data->camera->norm.x = ft_atof(arr[4]);
	data->camera->norm.y = ft_atof(arr[5]);
	data->camera->norm.z = ft_atof(arr[6]);
	data->camera->fov = ft_atoi(arr[7]);
	data->camera->angle_y = 0;
	data->camera->angle_z = 0;
	data->camera->dir = v_muls(data->camera->norm, 1);
	count++;
}
