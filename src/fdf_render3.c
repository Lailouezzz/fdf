/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:06:01 by ale-boud          #+#    #+#             */
/*   Updated: 2023/09/10 21:05:45 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <libft.h>
#include "fdf_utils.h"
#include "fdf.h"

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

void	fdf_ctx_destroy(t_rendctx *ctx)
{
	if (ctx == NULL)
		return ;
	if (ctx->fbuf.img != NULL)
		mlx_destroy_image(ctx->mlx, ctx->fbuf.img);
	if (ctx->mlx_win != NULL)
		mlx_destroy_window(ctx->mlx, ctx->mlx_win);
	if (ctx->mlx != NULL)
		mlx_destroy_display(ctx->mlx);
	free(ctx->mlx);
	free(ctx);
}

t_mat4	fdf_scalemat4(t_coord scale)
{
	t_mat4	mat;

	mat = fdf_mat4empty();
	mat.x[0] = scale;
	mat.y[1] = scale;
	mat.z[2] = 1.;
	mat.w[3] = 1.;
	return (mat);
}
