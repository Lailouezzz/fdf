/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bind_proj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:29:23 by ale-boud          #+#    #+#             */
/*   Updated: 2023/09/13 16:07:37 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "fdf_binding.h"

#define NEAR 2.
#define FAR 2000.

void	fdf_bind_proj(t_rendctx *rctx, t_keybind key, t_projctx *ctx)
{
	(void)(key);
	if (ctx->current == 0)
	{
		ctx->current = 1;
		rctx->mat = fdf_mat4empty();
		rctx->mat.x[0] = NEAR * 20;
		rctx->mat.y[1] = NEAR * 20;
		rctx->mat.z[2] = FAR + NEAR;
		rctx->mat.z[3] = -(NEAR * FAR);
		rctx->mat.w[2] = 1.;
	}
	else
	{
		ctx->current = 0;
		rctx->mat = fdf_mat4ident();
		rctx->mat.z[3] = 1.;
		rctx->mat.z[2] = 0.;
	}
}

void	fdf_bind_proj_init(t_binding_ctx *ctx)
{
	static t_projctx	pctx = (t_projctx){0};

	ctx->rctx->mat = fdf_mat4ident();
	ctx->rctx->mat.z[3] = 1.;
	ctx->rctx->mat.z[2] = 0.;
	fdf_bind_set_action_press_cb(&ctx->bindings[KEYBIND__SWITCHPROJ],
		(t_func_cb)fdf_bind_proj, KEY_P, &pctx);
}
