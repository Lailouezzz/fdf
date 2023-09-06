/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:07:55 by ale-boud          #+#    #+#             */
/*   Updated: 2023/09/06 19:41:02 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <mlx.h>
#include <X11/Xlib.h>
#include "libft.h"
#include "fdf.h"

typedef struct s_ctx {
	t_rendctx		*rctx;
	t_binding_ctx	*bctx;
	t_map			*map;
}	t_ctx;

static int	fdf_loop(t_ctx *ctx)
{
	fdf_ctx_init_buffer(&ctx->rctx);
	fdf_print_map_buffer(ctx->rctx, ctx->map);
	fdf_print_buffer(ctx->rctx);
	fdf_ctx_clear_buffer(ctx->rctx);
	fdf_bind_process(ctx->bctx);
	return (0);
}

int	main(void)
{
	t_ctx	ctx;

	ctx.map = fdf_read_map(STDIN_FILENO);
	if (ctx.map == NULL)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ctx.rctx = fdf_ctx_init();
	ctx.bctx = fdf_bind_init(ctx.rctx);
	fdf_bind_zoom_init(ctx.bctx);
	fdf_bind_z_init(ctx.bctx);
	if (fdf_bind_rot_init(ctx.bctx) != 0)
	{
		fdf_destroy_map(ctx.map);
		fdf_ctx_destroy(ctx.rctx);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	mlx_hook(ctx.rctx->mlx_win, KeyPress, KeyPressMask, _keypress_cb, ctx.bctx);
	mlx_hook(ctx.rctx->mlx_win, KeyRelease, KeyReleaseMask, _keyrelease_cb,
		ctx.bctx);
	mlx_loop_hook(ctx.rctx->mlx, fdf_loop, &ctx);
	mlx_loop(ctx.rctx->mlx);
	return (0);
}
