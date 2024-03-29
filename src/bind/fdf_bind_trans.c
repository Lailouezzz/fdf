/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bind_trans.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:58:58 by ale-boud          #+#    #+#             */
/*   Updated: 2023/09/13 16:22:55 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf_binding.h"

void	fdf_bind_trans(t_rendctx *rctx, t_keybind key, void *null)
{
	(void)(null);
	if (key == KEYBIND__TRANSUP)
		rctx->cam.y -= 4. / rctx->zoom;
	else if (key == KEYBIND__TRANSDOWN)
		rctx->cam.y += 4. / rctx->zoom;
	if (key == KEYBIND__TRANSLEFT)
		rctx->cam.x -= 4. / rctx->zoom;
	else if (key == KEYBIND__TRANSRIGHT)
		rctx->cam.x += 4. / rctx->zoom;
	if (key == KEYBIND__TRANSABOVE)
		rctx->cam.z += 4. / rctx->zoom;
	else if (key == KEYBIND__TRANSBELLOW)
		rctx->cam.z -= 4. / rctx->zoom;
}

void	fdf_bind_trans_init(t_binding_ctx *ctx, t_map *map)
{
	ctx->rctx->cam = (t_vec3){map->width / 2, map->height / 2, 30.};
	fdf_bind_set_status_down_cb(&ctx->bindings[KEYBIND__TRANSUP],
		fdf_bind_trans, KEY_W, NULL);
	fdf_bind_set_status_down_cb(&ctx->bindings[KEYBIND__TRANSLEFT],
		fdf_bind_trans, KEY_A, NULL);
	fdf_bind_set_status_down_cb(&ctx->bindings[KEYBIND__TRANSDOWN],
		fdf_bind_trans, KEY_S, NULL);
	fdf_bind_set_status_down_cb(&ctx->bindings[KEYBIND__TRANSRIGHT],
		fdf_bind_trans, KEY_D, NULL);
	fdf_bind_set_status_down_cb(&ctx->bindings[KEYBIND__TRANSABOVE],
		fdf_bind_trans, KEY_R, NULL);
	fdf_bind_set_status_down_cb(&ctx->bindings[KEYBIND__TRANSBELLOW],
		fdf_bind_trans, KEY_F, NULL);
}
