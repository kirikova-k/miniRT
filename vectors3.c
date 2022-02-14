/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:20:39 by fbeatris          #+#    #+#             */
/*   Updated: 2022/02/14 15:24:05 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	rotate_z(t_vector dir, float a)
{
	float	n_x;
	float	n_y;

	n_x = dir.x * cos(a) - dir.y * sin(a);
	n_y = dir.x * sin(a) + dir.y * cos(a);
	dir = v_norm(vector(n_x, n_y, dir.z));
	return (dir);
}

t_vector	rotate_y(t_vector dir, float a)
{
	float	n_x;
	float	n_z;

	n_x = dir.x * cos(a) - dir.z * sin(a);
	n_z = dir.x * sin(a) + dir.z * cos(a);
	dir = v_norm(vector(n_x, dir.y, n_z));
	return (dir);
}

t_vector	rotate_vector(t_vector vect, float alpha)
{
	float	new_y;
	float	new_z;

	new_y = vect.y * cos(alpha) + vect.z * sin(alpha);
	new_z = -vect.y * sin(alpha) + vect.z * cos(alpha);
	vect = v_norm(vector(vect.x, new_y, new_z));
	return (vect);
}

t_vector	rotate_dir(t_vector dir, t_data *data)
{
	float	n_x;
	float	n_y;
	float	n_z;
	float	a;

	a = data->camera->angle_y;
	n_x = dir.x * cos(a) - dir.z * sin(a);
	n_z = dir.x * sin(a) + dir.z * cos(a);
	dir = v_norm(vector(n_x, dir.y, n_z));
	a = data->camera->angle_z;
	n_x = dir.x * cos(a) - dir.y * sin(a);
	n_y = dir.x * sin(a) + dir.y * cos(a);
	dir = v_norm(vector(n_x, n_y, dir.z));
	return (dir);
}
