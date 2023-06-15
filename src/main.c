/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:07:55 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/15 16:58:30 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include "libft.h"
#include "fdf.h"

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
}	t_vars;

int	main(void)
{
	t_rendctx	*ctx;
	t_map		map;

	map.width = 2;
	map.height = 2;
	map.map[0] = (t_vec3){0, 0, 0};
	map.map[1] = (t_vec3){0, 10, 10};
	map.map[2] = (t_vec3){10, 0, 0};
	map.map[3] = (t_vec3){10, 10, 0};
	ctx = fdf_ctx_init();
	fdf_ctx_init_buffer(&ctx);
	ctx->cam = (t_vec3){-200, -200, 0};
	ctx->focal = (t_vec3){1, 1, 1};
	fdf_print_map_buffer(ctx, &map);
	fdf_print_buffer(ctx);
	getchar();
	return (0);

	t_vec3	vec1;
	t_vec3	vec2;
	t_mat4	mat1;

	vec1 = (t_vec3){0, 0, 1};
	vec2 = (t_vec3){0, 1, 0};
	vec1 = fdf_normavec3(vec1);
	printf("{%lf, %lf, %lf}\n", vec1.x, vec1.y, vec1.z);
	printf("{%lf, %lf, %lf}\n", vec2.x, vec2.y, vec2.z);
	mat1 = fdf_rotatmat4(vec1);
	vec2 = fdf_vec4tvec3(fdf_mat4xvec4(mat1, fdf_vec3tvec4(vec2, 1)));
	printf("{%lf, %lf, %lf}\n", vec2.x, vec2.y, vec2.z);
	vec1 = (t_vec3){0, 0, -1};
	vec1 = fdf_normavec3(vec1);
	printf("{%lf, %lf, %lf}\n", vec1.x, vec1.y, vec1.z);
	printf("{%lf, %lf, %lf}\n", vec2.x, vec2.y, vec2.z);
	mat1 = fdf_rotatmat4(vec1);
	vec2 = fdf_vec4tvec3(fdf_mat4xvec4(mat1, fdf_vec3tvec4(vec2, 1)));
	printf("{%lf, %lf, %lf}\n", vec2.x, vec2.y, vec2.z);
	return (0);
	vec1 = (t_vec3){5, 4, -1};
	vec2 = (t_vec3){5, 10, 0};
	mat1 = fdf_transmat4(vec2);
	printf("{%lf, %lf, %lf}\n", vec1.x, vec1.y, vec1.z);
	vec1 = fdf_vec4tvec3(fdf_mat4xvec4(mat1, fdf_vec3tvec4(vec1, 1)));
	vec1 = fdf_normavec3(vec1);
	printf("{%lf, %lf, %lf}\n", vec1.x, vec1.y, vec1.z);
	return (EXIT_SUCCESS);
}
