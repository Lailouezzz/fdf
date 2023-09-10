/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bind_zoom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:23:35 by ale-boud          #+#    #+#             */
/*   Updated: 2023/09/10 20:00:08 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf_binding.h"

void	fdf_bind_zoom(t_rendctx *rctx, t_keybind key, void *null)
{
	(void)(null);
	if (key == KEYBIND__ZOOMP)
		rctx->zoom *= 1.005;
	else if (key == KEYBIND__ZOOMM)
		rctx->zoom /= 1.005;
}

void	fdf_bind_zoom_init(t_binding_ctx *ctx)
{
	ctx->rctx->zoom = 10.;
	fdf_bind_set_status_down_cb(&ctx->bindings[KEYBIND__ZOOMP],
		fdf_bind_zoom, KEY_M, NULL);
	fdf_bind_set_status_down_cb(&ctx->bindings[KEYBIND__ZOOMM],
		fdf_bind_zoom, KEY_N, NULL);
}
