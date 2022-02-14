/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:40:15 by fbeatris          #+#    #+#             */
/*   Updated: 2022/02/14 15:23:27 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	inter_sphere2(float b, float d)
{
	float	t1;
	float	t2;
	float	min_t;
	float	max_t;
	float	t;

	t1 = -b + sqrtf(d);
	t2 = -b - sqrtf(d);
	min_t = fminf(t1, t2);
	max_t = fmaxf(t1, t2);
	if (min_t >= 0)
		t = min_t;
	else
		t = max_t;
	return (t);
}

float	inter_sphere(t_vector camera, t_vector dir, t_object *sphere)
{
	float		radius;
	float		b;
	float		c;
	float		d;
	t_vector	k;

	radius = sphere->diameter / 2;
	k = v_sub(camera, sphere->point);
	b = v_scal(k, dir);
	c = v_scal(k, k) - radius * radius;
	d = b * b - c;
	if (d >= 0)
		return (inter_sphere2(b, d));
	else
		return (0);
}

float	inter_plane(t_vector camera, t_vector dir, t_object *plane)
{
	float	t;
	float	dist;

	dist = v_dist(camera, plane->point);
	t = -(v_scal(v_sub(camera, plane->point), plane->norm)) \
		/ v_scal(dir, plane->norm);
	return (t);
}

float	calc_t(float caoc, float card, float caca, float y)
{
	float	t;

	if (y < 0)
		t = (0 - caoc) / card;
	else
		t = (caca - caoc) / card;
	return (t);
}

float	inter_cylinder(t_vector ro, t_vector rd, t_object *cyl)
{
	t_vector	ca;
	float		a;
	float		b;
	float		c;
	float		y;

	ca = v_sub(v_sum(cyl->point, v_muls(cyl->norm, cyl->height)), cyl->point);
	a = v_scal(ca, ca) - v_scal(ca, rd) * v_scal(ca, rd);
	b = v_scal(ca, ca) * v_scal(v_sub(ro, cyl->point), rd) \
		- v_scal(ca, v_sub(ro, cyl->point)) * v_scal(ca, rd);
	c = v_scal(ca, ca) * v_scal(v_sub(ro, cyl->point), v_sub(ro, cyl->point)) \
		- v_scal(ca, v_sub(ro, cyl->point)) * v_scal(ca, v_sub(ro, cyl->point)) \
		- (cyl->diameter / 2) * (cyl->diameter / 2) * v_scal(ca, ca);
	if ((b * b - a * c) < 0)
		return (0);
	y = v_scal(ca, v_sub(ro, cyl->point)) + ((-b - sqrt((b * b - a * c))) / a) \
		* v_scal(ca, rd);
	if (y > 0 && y < v_scal(ca, ca))
		return (((-b - sqrt((b * b - a * c))) / a));
	y = calc_t(v_scal(ca, v_sub(ro, cyl->point)), \
		v_scal(ca, rd), v_scal(ca, ca), y);
	if (fabs(b + a * y) < sqrt((b * b - a * c)))
		return (y);
	return (0);
}
