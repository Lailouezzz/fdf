/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 01:19:01 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/15 16:54:13 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "fdf_utils.h"
#include "fdf.h"

int	fdf_ctx_clear_buffer(t_rendctx *ctx)
{
	mlx_destroy_image(ctx->mlx, ctx->fbuf.img);
	ctx->fbuf.img = NULL;
	return (1);
}

static t_point	fdf_draw_line_get_s(t_point p1, t_point p2)
{
	t_point	s;

	if (p1.x < p2.x)
		s.x = 1;
	else
		s.x = -1;
	if (p1.y < p2.y)
		s.y = 1;
	else
		s.y = -1;
	return (s);
}

void	fdf_draw_line(t_rendctx *ctx, t_point p1, t_point p2, t_color c)
{
	t_point	d;
	t_point	s;
	int		err;
	int		e2;

	d = (t_point){fdf_abs(p2.x - p1.x), -fdf_abs(p2.y - p1.y)};
	err = d.x + d.y;
	s = fdf_draw_line_get_s(p1, p2);
	while (p1.x != p2.x || p1.y != p2.y)
	{
		fdf_pixel_put(ctx, p1, c);
		e2 = err * 2;
		if (e2 >= d.y)
		{
			err += d.y;
			p1.x += s.x;
		}
		if (e2 <= d.x)
		{
			err += d.x;
			p1.y += s.y;
		}
	}
	fdf_pixel_put(ctx, p1, c);
}

void	fdf_print_map_buffer(t_rendctx *ctx, const t_map *map)
{
	t_mat4	mat;
	t_vec3	p1;
	t_vec3	p2;
	int		x;
	int		y;

	mat = fdf_transmat4(fdf_invervec3(ctx->cam));
	mat = fdf_mat4xmat4(mat, fdf_rotatmat4(ctx->focal));
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x + 1 < map->width)
		{
			p1 = fdf_vec4tvec3(fdf_mat4xvec4(mat,
						fdf_vec3tvec4(map->map[x + y * map->width], 0.2)));
			++x;
			p2 = fdf_vec4tvec3(fdf_mat4xvec4(mat,
						fdf_vec3tvec4(map->map[x + y * map->width], 0.2)));
			fdf_draw_line(ctx, (t_point){p1.x, p1.y}, (t_point){p2.x, p2.y}, 0x00FFFFFF);
			if (y + 1 < map->height)
			{
				p2 = fdf_vec4tvec3(fdf_mat4xvec4(mat,
							fdf_vec3tvec4(map->map[(x - 1) + (y + 1) * map->width], 0.2)));
				fdf_draw_line(ctx, (t_point){p1.x, p1.y}, (t_point){p2.x, p2.y}, 0x00FFFFFF);
			}
		}
		++y;
	}
}
