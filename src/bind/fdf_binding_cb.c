/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_binding_cb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:08:56 by ale-boud          #+#    #+#             */
/*   Updated: 2023/09/07 16:49:41 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf_binding.h"

void	fdf_bind_set_status_down_cb(t_binding *binding, t_func_cb cb,
									int keycode, void *data)
{
	binding->status[KEY_STATUS__DOWN] = cb;
	binding->data = data;
	binding->keycode = keycode;
}

void	fdf_bind_set_action_press_cb(t_binding *binding,
										t_func_cb cb, int keycode, void *data)
{
	binding->action[KEY_ACTION__PRESS] = cb;
	binding->data = data;
	binding->keycode = keycode;
}

static t_binding	*fdf_get_binding(int keycode, t_binding_ctx *ctx)
{
	int	k;

	k = 0;
	while (k < KEYBIND_COUNT)
	{
		if (ctx->bindings[k].keycode == keycode)
			return (&ctx->bindings[k]);
		++k;
	}
	return (NULL);
}

int	_keypress_cb(int keycode, t_binding_ctx *ctx)
{
	t_binding	*bind;

	bind = fdf_get_binding(keycode, ctx);
	if (bind != NULL)
		bind->curact = KEY_ACTION__PRESS;
	return (0);
}

int	_keyrelease_cb(int keycode, t_binding_ctx *ctx)
{
	t_binding	*bind;

	bind = fdf_get_binding(keycode, ctx);
	if (bind != NULL)
		bind->curact = KEY_ACTION__RELEASE;
	return (0);
}
