/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bind_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:18:51 by ale-boud          #+#    #+#             */
/*   Updated: 2023/09/07 15:31:58 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "fdf_binding.h"

static void	fdf_bind_rot_update(t_rendctx *rctx, t_rotctx *ctx)
{
	rctx->cam.x = (cos(ctx->x))
		* (cos(ctx->y));
	rctx->cam.y = (-sin(ctx->x))
		* (-cos(ctx->y));
	rctx->cam.z = (-sin(ctx->y));
	rctx->focal.x = -((cos(ctx->x)) * (cos(ctx->y)));
	rctx->focal.y = -((-sin(ctx->x)) * (-cos(ctx->y)));
	rctx->focal.z = (-sin(ctx->y));
}

void	fdf_bind_rot(t_rendctx *rctx, t_keybind key, t_rotctx *ctx)
{
	if (key == KEYBIND__ROTUP)
		ctx->y += 0.01;
	else if (key == KEYBIND__ROTDOWN)
		ctx->y -= 0.01;
	if (key == KEYBIND__ROTLEFT)
		ctx->x -= 0.01;
	else if (key == KEYBIND__ROTRIGHT)
		ctx->x += 0.01;
	fdf_bind_rot_update(rctx, ctx);
}

void	fdf_bind_rot_init(t_binding_ctx *ctx)
{
	static t_rotctx	rctx;

	rctx.x = 0.5;
	rctx.y = 0.5;
	fdf_bind_rot_update(ctx->rctx, &rctx);
	fdf_bind_set_status_down_cb(&ctx->bindings[KEYBIND__ROTUP],
		(t_func_cb)fdf_bind_rot, KEY_I, &rctx);
	fdf_bind_set_status_down_cb(&ctx->bindings[KEYBIND__ROTDOWN],
		(t_func_cb)fdf_bind_rot, KEY_K, &rctx);
	fdf_bind_set_status_down_cb(&ctx->bindings[KEYBIND__ROTLEFT],
		(t_func_cb)fdf_bind_rot, KEY_J, &rctx);
	fdf_bind_set_status_down_cb(&ctx->bindings[KEYBIND__ROTRIGHT],
		(t_func_cb)fdf_bind_rot, KEY_L, &rctx);
}
