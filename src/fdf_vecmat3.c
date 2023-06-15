/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vecmat3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:56:58 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/15 16:21:04 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "libft.h"
#include "fdf_vecmat.h"

t_coord	fdf_vec3dista(const t_vec3 vec)
{
	return (sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z)));
}

t_mat4	fdf_mat4xmat4(const t_mat4 mat1, const t_mat4 mat2)
{
	t_mat4	rmat;
	int		k;

	k = 0;
	while (k < 4)
	{
		rmat.x[k] = mat1.x[0] * mat2.x[k] + mat1.x[1] * mat2.y[k]
			+ mat1.x[2] * mat2.z[k] + mat1.x[3] * mat2.w[k];
		rmat.y[k] = mat1.y[0] * mat2.x[k] + mat1.y[1] * mat2.y[k]
			+ mat1.y[2] * mat2.z[k] + mat1.y[3] * mat2.w[k];
		rmat.z[k] = mat1.z[0] * mat2.x[k] + mat1.z[1] * mat2.y[k]
			+ mat1.z[2] * mat2.z[k] + mat1.z[3] * mat2.w[k];
		rmat.w[k] = mat1.w[0] * mat2.x[k] + mat1.w[1] * mat2.y[k]
			+ mat1.w[2] * mat2.z[k] + mat1.w[3] * mat2.w[k];
		++k;
	}
	return (rmat);
}

t_angle	fdf_vec2angle(const t_vec2 nvec)
{
	if (nvec.x == 0 && nvec.y == 0)
		return (0.);
	if (nvec.x == 0 && nvec.y > 0)
		return (atan(1. / 0.));
	else if (nvec.x == 0 && nvec.y < 0)
		return (-atan(1. / 0.));
	if (nvec.x >= 0)
	{
		if (nvec.y >= 0)
			return (atan(nvec.y / nvec.x));
		else
			return (-atan(-nvec.y / nvec.x));
	}
	else
	{
		if (nvec.y >= 0)
			return (atan(-nvec.x / nvec.y) + atan(1. / 0.));
		else
			return (-(atan(-nvec.x / -nvec.y) + atan(1. / 0.)));
	}
}

t_mat4	fdf_rotatmat4(const	t_vec3 nvec)
{
	t_mat4	mat1;
	t_mat4	mat2;
	t_angle	angxy;
	t_angle	angzy;

	angxy = fdf_vec2angle((t_vec2){nvec.y, nvec.x});
	angzy = fdf_vec2angle((t_vec2){nvec.z, nvec.y});
	if (angzy < 0)
		angzy = -angzy;
	printf("%lf %lf\n", angxy, angzy);
	mat1 = fdf_mat4ident();
	mat2 = fdf_mat4ident();
	mat1.y[1] = cos(angzy);
	mat1.y[2] = -sin(angzy);
	mat1.z[1] = sin(angzy);
	mat1.z[2] = cos(angzy);
	mat2.x[0] = cos(angxy);
	mat2.x[1] = -sin(angxy);
	mat2.y[0] = sin(angxy);
	mat2.y[1] = cos(angxy);
	return (fdf_mat4xmat4(mat1, mat2));
}

t_vec3	fdf_invervec3(t_vec3 vec)
{
	vec.x = -vec.x;
	vec.y = -vec.y;
	vec.z = -vec.z;
	return (vec);
}
