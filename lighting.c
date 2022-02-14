/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:08:15 by fbeatris          #+#    #+#             */
/*   Updated: 2022/02/14 13:17:11 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	cylinder_norm(t_object *cyl, t_vector inter)
{
	t_vector	norm;
	t_vector	top_center;
	float		t;
	t_vector	pt;

	top_center = v_sum(cyl->point, v_muls(cyl->norm, cyl->height));
	if (v_len(v_sub(inter, cyl->point)) < cyl->diameter / 2)
		norm = v_muls(cyl->norm, -1);
	else if (v_len(v_sub(inter, top_center)) < cyl->diameter / 2)
		norm = cyl->norm;
	else
	{
		t = v_scal(v_sub(inter, cyl->point), cyl->norm);
		pt = v_sum(cyl->point, v_muls(cyl->norm, t));
		norm = v_norm(v_sub(inter, pt));
	}
	return (norm);
}

float	specular_light(t_vector norm, t_vector dir, \
	t_vector inter_point, t_data *data)
{
	float		bright;
	t_vector	reflect;
	t_vector	spot;

	bright = data->light->brightness;
	spot = v_norm(v_sub(data->light->point, inter_point));
	reflect = v_norm(v_sub(dir, v_muls(norm, 2 * v_scal(norm, dir))));
	return (pow(fmax(v_scal(reflect, spot), 0), 32) * bright);
}

float	diff_light(t_vector norm, t_vector inter_point, t_data *data)
{
	t_vector	spot;

	spot = v_norm(v_sub(data->light->point, inter_point));
	return (v_scal(norm, spot) * data->light->brightness);
}

float	drop_shadow(t_vector inter, t_data *data, t_object *obj)
{
	int			i;
	t_vector	dir;
	float		distance;

	dir = v_norm(v_sub(data->light->point, inter));
	i = 0;
	while (i < data->qty)
	{
		distance = find_dist(data->objects[i], inter, dir);
		if (distance > 0 && distance < v_dist(inter, data->light->point) \
			&& obj->id != i)
			return (-1);
		i++;
	}
	return (0);
}

int	lighting(t_object *object, t_vector dir, t_data *data, float dist)
{
	t_vector	inter_point;
	t_vector	norm;
	float		drop;
	int			color;

	inter_point = v_sum(data->camera->point, v_muls(dir, dist));
	if (object->type == 0)
		norm = v_norm(v_sub(inter_point, object->point));
	if (object->type == 1)
		norm = v_norm(object->norm);
	if (object->type == 2)
		norm = cylinder_norm(object, inter_point);
	drop = drop_shadow(inter_point, data, object);
	if (drop == 0)
		color = add_color3(mul_color(object->color, data->ambient->ratio), \
			mul_color(object->color, \
			diff_light(norm, inter_point, data) * DIFF_COEF), \
			mul_color(object->color, \
			specular_light(norm, dir, inter_point, data) * SPEC_COEF));
	else
		color = add_color(add_color3 \
			(mul_color(object->color, data->ambient->ratio), \
			mul_color(object->color, \
			diff_light(norm, inter_point, data) * DIFF_COEF), 0), SHADOW_COEF);
	return (color);
}
