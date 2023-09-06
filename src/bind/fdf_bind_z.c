/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bind_z.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:37:54 by ale-boud          #+#    #+#             */
/*   Updated: 2023/09/06 19:42:13 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf_binding.h"

void	fdf_bind_z(t_rendctx *rctx, t_keybind key, void *null)
{
	(void *)(null);
	if (key == KEYBIND__ZP)
		rctx->z_mul += 0.005;
	else if (key == KEYBIND__ZM)
		rctx->z_mul -= 0.005;
}

void	fdf_bind_z_init(t_binding_ctx *ctx)
{
	ctx->rctx->z_mul = 1.;
	fdf_bind_set_status_down_cb(&ctx->bindings[KEYBIND__ZP],
		fdf_bind_z, KEY_X, NULL);
	fdf_bind_set_status_down_cb(&ctx->bindings[KEYBIND__ZM],
		fdf_bind_z, KEY_Z, NULL);
}
