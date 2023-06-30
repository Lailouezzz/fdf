/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:37:31 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/30 09:07:57 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "fdf_hook.h"

static void	fdf_exit(t_hook_ctx *ctx)
{
	fdf_ctx_destroy(ctx->rendctx);
	fdf_destroy_map(ctx->map);
	exit(EXIT_SUCCESS);
}

static void	fdf_key_hook_handler(int keycode, t_hook_ctx *ctx)
{
	if (keycode == KEY_LEFT)
		ctx->rot -= 0.05;
	else if (keycode == KEY_RIGHT)
		ctx->rot += 0.05;
	else if (keycode == KEY_A)
		ctx->rrot += 0.05;
	else if (keycode == KEY_Z)
		ctx->rrot -= 0.05;
	else if (keycode == KEY_UP)
		ctx->rendctx->zoom *= 1.1;
	else if (keycode == KEY_DOWN)
		ctx->rendctx->zoom /= 1.1;
	else if (keycode == KEY_Q)
		ctx->rendctx->z_mul -= 0.025 / 2;
	else if (keycode == KEY_W)
		ctx->rendctx->z_mul += 0.025 / 2;
	else if (keycode == KEY_J)
		ctx->rendctx->trans.x += 1. / ctx->rendctx->zoom * 10;
	else if (keycode == KEY_I)
		ctx->rendctx->trans.y += 1. / ctx->rendctx->zoom * 10;
	else if (keycode == KEY_L)
		ctx->rendctx->trans.x -= 1. / ctx->rendctx->zoom * 10;
	else if (keycode == KEY_K)
		ctx->rendctx->trans.y -= 1. / ctx->rendctx->zoom * 10;
	else if (keycode == KEY_ECHAP)
		fdf_exit(ctx);
}

static void	fdf_key_hook_update(t_hook_ctx *ctx)
{
	ctx->rendctx->cam.x = (cos(ctx->rot))
		* (cos(ctx->rrot)) + ctx->map->width / 2;
	ctx->rendctx->cam.y = (-sin(ctx->rot))
		* (-cos(ctx->rrot)) - ctx->map->height / 2;
	ctx->rendctx->cam.z = (-sin(ctx->rrot));
	ctx->rendctx->focal.x = -((cos(ctx->rot)) * (cos(ctx->rrot)));
	ctx->rendctx->focal.y = -((-sin(ctx->rot)) * (-cos(ctx->rrot)));
	ctx->rendctx->focal.z = (-sin(ctx->rrot));
	fdf_ctx_init_buffer(&ctx->rendctx);
	fdf_print_map_buffer(ctx->rendctx, ctx->map);
	fdf_print_buffer(ctx->rendctx);
	fdf_ctx_clear_buffer(ctx->rendctx);
}

int	fdf_key_hook(int keycode, t_hook_ctx *ctx)
{
	fdf_key_hook_handler(keycode, ctx);
	fdf_key_hook_update(ctx);
	return (0);
}
