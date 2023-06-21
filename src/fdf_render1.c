/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:37:16 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/17 20:49:06 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <libft.h>
#include "fdf.h"

t_rendctx	*fdf_ctx_init(void)
{
	t_rendctx	*ctx;

	ctx = malloc(sizeof(*ctx));
	if (ctx == NULL)
		return (NULL);
	ctx->mlx = mlx_init();
	if (ctx->mlx == NULL)
	{
		free(ctx);
		return (NULL);
	}
	ctx->mlx_win = mlx_new_window(ctx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "FdF");
	if (ctx->mlx_win == NULL)
	{
		/* TODO : free mlx ?*/
		free(ctx);
		return (NULL);
	}
	ctx->fbuf.img = NULL;
	return (ctx);
}

void	fdf_ctx_init_buffer(t_rendctx **ctx)
{
	(*ctx)->fbuf.img = mlx_new_image((*ctx)->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if ((*ctx)->fbuf.img == NULL)
	{
		/* TODO : destroy *ctx,  *ctx = NULL */
	}
	/*(*ctx)->zbuf.zbuf
		= ft_calloc(SCREEN_WIDTH * SCREEN_HEIGHT, sizeof(*(*ctx)->zbuf.zbuf));*/
	(*ctx)->fbuf.data = mlx_get_data_addr((*ctx)->fbuf.img,
			&(*ctx)->fbuf.bits_per_pixel, &(*ctx)->fbuf.line_len,
			&(*ctx)->fbuf.endian);
}

void	fdf_pixel_put(t_rendctx *ctx, t_point p, t_color c)
{
	char	*dst;

	p.x += (SCREEN_WIDTH / 2);
	p.y += (SCREEN_HEIGHT / 2);
	if (p.x < 0 || p.y < 0 || p.x >= SCREEN_WIDTH || p.y >= SCREEN_HEIGHT)
		return ;
	dst = ctx->fbuf.data
		+ (p.y * ctx->fbuf.line_len + p.x * (ctx->fbuf.bits_per_pixel / 8));
	*(t_color *)dst = c;
}

t_color	fdf_encode_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	fdf_print_buffer(t_rendctx *ctx)
{
	mlx_put_image_to_window(ctx->mlx, ctx->mlx_win, ctx->fbuf.img, 0, 0);
}
