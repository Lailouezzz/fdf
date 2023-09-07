/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bind_trans.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:58:58 by ale-boud          #+#    #+#             */
/*   Updated: 2023/09/07 15:34:36 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf_binding.h"

void	fdf_bind_trans(t_rendctx *rctx, t_keybind key, void *null)
{
	(void *)(null);
	if (key == KEYBIND__TRANSUP)
		rctx->trans.y -= 4. / rctx->zoom;
	else if (key == KEYBIND__TRANSDOWN)
		rctx->trans.y += 4. / rctx->zoom;
	if (key == KEYBIND__TRANSLEFT)
		rctx->trans.x += 4. / rctx->zoom;
	else if (key == KEYBIND__TRANSRIGHT)
		rctx->trans.x -= 4. / rctx->zoom;
}

void	fdf_bind_trans_init(t_binding_ctx *ctx)
{
	ctx->rctx->trans = (t_vec2){0., 0.};
	fdf_bind_set_status_down_cb(&ctx->bindings[KEYBIND__TRANSUP],
		fdf_bind_trans, KEY_W, NULL);
	fdf_bind_set_status_down_cb(&ctx->bindings[KEYBIND__TRANSLEFT],
		fdf_bind_trans, KEY_A, NULL);
	fdf_bind_set_status_down_cb(&ctx->bindings[KEYBIND__TRANSDOWN],
		fdf_bind_trans, KEY_S, NULL);
	fdf_bind_set_status_down_cb(&ctx->bindings[KEYBIND__TRANSRIGHT],
		fdf_bind_trans, KEY_D, NULL);
}
