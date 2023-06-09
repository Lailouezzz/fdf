/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vecmat2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:31:34 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/08 15:16:21 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf_vecmat.h"

t_mat4	fdf_transmat4(const t_vec3 vec)
{
	t_mat4	mat;

	mat = fdf_mat4ident();
	mat.x[3] = vec.x;
	mat.y[3] = vec.y;
	mat.z[3] = vec.z;
	return (mat);
}

t_vec4	fdf_mat4xvec4(const t_mat4 mat, const t_vec4 vec)
{
	t_vec4	rvec;

	rvec.x = (mat.x[0] * vec.x) + (mat.x[1] * vec.y)
		+ (mat.x[2] * vec.z) + (mat.x[3] * vec.w);
	rvec.y = (mat.y[0] * vec.x) + (mat.y[1] * vec.y)
		+ (mat.y[2] * vec.z) + (mat.y[3] * vec.w);
	rvec.z = (mat.z[0] * vec.x) + (mat.z[1] * vec.y)
		+ (mat.z[2] * vec.z) + (mat.z[3] * vec.w);
	rvec.w = (mat.w[0] * vec.x) + (mat.w[1] * vec.y)
		+ (mat.w[2] * vec.z) + (mat.w[3] * vec.w);
	return (rvec);
}

t_vec4	fdf_vec3tvec4(const t_vec3 vec, t_coord w)
{
	return ((t_vec4){vec.x, vec.y, vec.z, w});
}

t_vec3	fdf_vec4tvec3(const t_vec4 vec)
{
	return ((t_vec3){vec.x / vec.w, vec.y / vec.w, vec.z / vec.w});
}

t_vec3	fdf_normavec3(const t_vec3 vec)
{
	t_coord	dist;

	dist = fdf_vec3dista(vec);
	return ((t_vec3){vec.x / dist, vec.y / dist, vec.z / dist});
}
