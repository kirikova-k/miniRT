/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:25:51 by fbeatris          #+#    #+#             */
/*   Updated: 2022/02/14 13:19:07 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	vector(float x, float y, float z)
{
	t_vector	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

t_vector	v_sum(t_vector a, t_vector b)
{
	t_vector	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

t_vector	v_sum3(t_vector v1, t_vector v2, t_vector v3)
{
	t_vector	result;

	result.x = v1.x + v2.x + v3.x;
	result.y = v1.y + v2.y + v3.y;
	result.z = v1.z + v2.z + v3.z;
	return (result);
}

t_vector	v_sub(t_vector a, t_vector b)
{
	t_vector	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}

t_vector	v_muls(t_vector a, float s)
{
	t_vector	result;

	result.x = a.x * s;
	result.y = a.y * s;
	result.z = a.z * s;
	return (result);
}
