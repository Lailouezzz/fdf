/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:07:55 by ale-boud          #+#    #+#             */
/*   Updated: 2023/09/07 16:38:06 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>
#include <X11/Xlib.h>
#include "libft.h"
#include "fdf.h"

typedef struct s_ctx {
	t_rendctx		*rctx;
	t_binding_ctx	*bctx;
	t_map			*map;
}	t_ctx;

static int	fdf_exit(t_ctx *ctx)
{
	fdf_bind_destroy(ctx->bctx);
	fdf_ctx_destroy(ctx->rctx);
	fdf_destroy_map(ctx->map);
	exit(EXIT_SUCCESS);
	return (0);
}

static int	fdf_loop(t_ctx *ctx)
{
	fdf_bind_process(ctx->bctx);
	fdf_ctx_clear_buffer(ctx->rctx);
	fdf_print_map_buffer(ctx->rctx, ctx->map);
	fdf_print_buffer(ctx->rctx);
	if (ctx->bctx->bindings[KEYBIND__EXIT].st == KEY_STATUS__DOWN)
		fdf_exit(ctx);
	return (0);
}

static int	fdf_init_map(t_ctx *ctx, const char *fn)
{
	int	fd;

	fd = open(fn, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	ctx->map = fdf_read_map(fd);
	close(fd);
	if (ctx->map == NULL)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	fdf_init(t_ctx *ctx, const char *fn)
{
	if (fdf_init_map(ctx, fn) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ctx->rctx = fdf_ctx_init();
	fdf_ctx_init_buffer(&ctx->rctx);
	ctx->bctx = fdf_bind_init(ctx->rctx);
	if (ctx->rctx == NULL || ctx->bctx == NULL)
	{
		fdf_destroy_map(ctx->map);
		fdf_ctx_destroy(ctx->rctx);
		fdf_bind_destroy(ctx->bctx);
		return (EXIT_FAILURE);
	}
	fdf_bind_z_init(ctx->bctx);
	fdf_bind_zoom_init(ctx->bctx);
	fdf_bind_trans_init(ctx->bctx);
	fdf_bind_rot_init(ctx->bctx);
	fdf_bind_proj_init(ctx->bctx);
	return (EXIT_SUCCESS);
}

typedef enum e_prog {
	PROG__NAME,
	PROG__FN,
	PROG_COUNT,
	PROG_EXCEPTED = PROG_COUNT
}	t_prog;

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc != PROG_EXCEPTED)
	{
		ft_putstr_fd("Usage: ", STDOUT_FILENO);
		ft_putstr_fd(argv[PROG__NAME], STDOUT_FILENO);
		ft_putstr_fd(" [map.fdf]\n", STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	if (fdf_init(&ctx, argv[PROG__FN]) == EXIT_FAILURE)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	mlx_hook(ctx.rctx->mlx_win, KeyPress, KeyPressMask, _keypress_cb, ctx.bctx);
	mlx_hook(ctx.rctx->mlx_win, KeyRelease, KeyReleaseMask, _keyrelease_cb,
		ctx.bctx);
	mlx_hook(ctx.rctx->mlx_win, DestroyNotify, NoEventMask, fdf_exit, &ctx);
	mlx_loop_hook(ctx.rctx->mlx, fdf_loop, &ctx);
	mlx_loop(ctx.rctx->mlx);
	return (0);
}
