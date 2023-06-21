/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 01:19:01 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/17 20:58:31 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <libft.h>
#include "fdf_utils.h"
#include "fdf.h"

int	fdf_ctx_clear_buffer(t_rendctx *ctx)
{
	mlx_destroy_image(ctx->mlx, ctx->fbuf.img);
	ctx->fbuf.img = NULL;
	/*free(ctx->zbuf.zbuf);*/
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

static void	fdf_print_map_rend_line(t_rendctx *ctx, t_point p, t_mat4 mat,
		const t_map *map)
{
	t_vec3	p1;
	t_vec3	p2;

	p1 = fdf_vec4tvec3(fdf_mat4xvec4(mat,
				fdf_vec3tvec4(map->map[p.x + p.y * map->width],
					1. / ctx->zoom)));
	if (p.x != 0)
	{
		p2 = fdf_vec4tvec3(fdf_mat4xvec4(mat,
					fdf_vec3tvec4(map->map[p.x - 1 + p.y * map->width],
						1. / ctx->zoom)));
		fdf_draw_line(ctx, (t_point){p1.x, p1.y},
			(t_point){p2.x, p2.y}, 0x00FFFFFF);
	}
	if (p.y + 1 != map->height)
	{
		p2 = fdf_vec4tvec3(fdf_mat4xvec4(mat,
					fdf_vec3tvec4(map->map[p.x + (p.y + 1) * map->width],
						1. / ctx->zoom)));
		fdf_draw_line(ctx, (t_point){p1.x, p1.y},
			(t_point){p2.x, p2.y}, 0x00FFFFFF);
	}
}

void	fdf_print_map_buffer(t_rendctx *ctx, const t_map *map)
{
	t_mat4	mat;
	t_mat4	z_mulmat;
	int		x;
	int		y;

	mat = fdf_transmat4(fdf_invervec3(fdf_vec4tvec3(
					fdf_vec3tvec4(ctx->cam, 1. / ctx->zoom))));
	mat = fdf_mat4xmat4(fdf_rotatmat4(ctx->focal), mat);
	z_mulmat = fdf_mat4ident();
	z_mulmat.z[2] = ctx->z_mul;
	mat = fdf_mat4xmat4(mat, z_mulmat);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			fdf_print_map_rend_line(ctx, (t_point){x, y}, mat, map);
			++x;
		}
		++y;
	}
}

void	fdf_pixel3_put(t_rendctx *ctx, t_point3 p, t_color c)
{
	char	*dst;
	t_coord	*zdst;

	if (p.x < 0 || p.y < 0 || p.x >= SCREEN_WIDTH || p.y >= SCREEN_HEIGHT
		|| p.z <= 0.)
		return ;
	zdst = ctx->zbuf.zbuf
		+ (p.y * SCREEN_WIDTH + p.x);
	dst = ctx->fbuf.data
		+ (p.y * ctx->fbuf.line_len + p.x * (ctx->fbuf.bits_per_pixel / 8));
	if (p.z >= *zdst && *zdst != 0)
		return ;
	*zdst = p.z;
	*(t_color *)dst = c;
}
