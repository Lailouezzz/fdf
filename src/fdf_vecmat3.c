/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vecmat3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:56:58 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/08 17:40:28 by ale-boud         ###   ########.fr       */
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

t_mat4	fdf_rotatmat4(const	t_vec3 nvec)
{
	t_mat4	mat1;
	t_mat4	mat2;
	t_angle	angxz;
	t_angle	angyz;

	angxz = atan(nvec.x / nvec.z);
	angyz = atan(nvec.y / nvec.z);
	if (angxz != angxz)
		angxz = 0;
	if (angyz != angyz)
		angyz = 0;
	printf("%lf %lf\n", angxz, angyz);
	mat1 = fdf_mat4ident();
	mat2 = fdf_mat4ident();
	mat1.y[1] = cos(angxz);
	mat1.y[2] = -sin(angxz);
	mat1.z[1] = sin(angxz);
	mat1.z[2] = cos(angxz);
	mat2.x[0] = cos(angyz);
	mat2.x[2] = sin(angyz);
	mat2.z[0] = -sin(angyz);
	mat2.z[2] = cos(angyz);
	return (fdf_mat4xmat4(mat1, mat2));
}
