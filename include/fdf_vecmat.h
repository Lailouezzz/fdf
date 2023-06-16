/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vecmat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:22:41 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/16 14:20:15 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FDF_VECMAT_H
# define FDF_VECMAT_H

typedef double	t_coord;
typedef double	t_angle;

/* Matrice 4x4 */

typedef struct s_mat4
{
	t_coord	x[4];
	t_coord	y[4];
	t_coord	z[4];
	t_coord	w[4];
}	t_mat4;

/* Matrice 3x3 */

typedef struct s_mat3
{
	t_coord	x[4];
	t_coord	y[4];
	t_coord	z[4];
}	t_mat3;

/* Vecteur 4 */

typedef struct s_vec4
{
	t_coord	x;
	t_coord	y;
	t_coord	z;
	t_coord	w;
}	t_vec4;

/* Vecteur 3 */

typedef struct s_vec3
{
	t_coord	x;
	t_coord	y;
	t_coord	z;
}	t_vec3;

/* Vecteur 2 */

typedef struct s_vec2
{
	t_coord	x;
	t_coord	y;
}	t_vec2;

t_mat3	fdf_mat3empty(void);
t_mat4	fdf_mat4empty(void);
t_mat3	fdf_mat3ident(void);
t_mat4	fdf_mat4ident(void);
t_mat4	fdf_mat4xmat4(const t_mat4 mat1, const t_mat4 mat2);
t_vec4	fdf_mat4xvec4(const t_mat4 mat, const t_vec4 vec);
t_vec4	fdf_vec3tvec4(const t_vec3 vec, t_coord w);
t_coord	fdf_vec3dista(const t_vec3 vec);
t_vec3	fdf_vec4tvec3(const t_vec4 vec);
t_mat4	fdf_transmat4(const t_vec3 vec);
t_mat4	fdf_rotatmat4(t_vec3 nvec);
t_vec3	fdf_normavec3(const t_vec3 vec);
t_vec3	fdf_invervec3(t_vec3 vec);

#endif
