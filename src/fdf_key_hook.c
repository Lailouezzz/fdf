/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:37:31 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/17 23:40:15 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf_hook.h"

static void	fdf_key_hook_handler(int keycode, t_hook_ctx *ctx)
{
	if (keycode == KEY_LEFT)
		ctx->rot -= 0.05;
	else if (keycode == KEY_RIGHT)
		ctx->rot += 0.05;
	else if (keycode == KEY_UP)
		ctx->rendctx->zoom += 0.5;
	else if (keycode == KEY_DOWN)
		ctx->rendctx->zoom -= 0.5;
	else if (keycode == KEY_Q)
		ctx->rendctx->z_mul -= 0.025;
	else if (keycode == KEY_W)
		ctx->rendctx->z_mul += 0.025;
	else
		printf("%d\n", keycode);
}

static void	fdf_key_hook_update(t_hook_ctx *ctx)
{
	ctx->rendctx->cam.x = (cos(ctx->rot)) * 200 + ctx->map->width / 2;
	ctx->rendctx->cam.y = (-sin(ctx->rot)) * 200 - ctx->map->height / 2;
	ctx->rendctx->focal.x = (-cos(ctx->rot));
	ctx->rendctx->focal.y = (sin(ctx->rot));
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
