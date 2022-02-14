/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:53:39 by fbeatris          #+#    #+#             */
/*   Updated: 2022/02/14 13:21:40 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

t_vector	vector(float x, float y, float z);
t_vector	v_sum(t_vector a, t_vector b);
t_vector	v_sum3(t_vector v1, t_vector v2, t_vector v3);
t_vector	v_sub(t_vector a, t_vector b);
t_vector	v_muls(t_vector a, float s);
t_vector	v_mulv(t_vector a, t_vector b);
float		v_scal(t_vector a, t_vector b);
float		v_len(t_vector a);
float		v_dist(t_vector a, t_vector b);
t_vector	v_norm(t_vector a);
t_vector	rotate_z(t_vector dir, float a);
t_vector	rotate_y(t_vector dir, float a);
t_vector	rotate_vector(t_vector vect, float alpha);

#endif
