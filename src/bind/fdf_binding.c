/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_binding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:21:47 by ale-boud          #+#    #+#             */
/*   Updated: 2023/09/07 15:27:12 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf_binding.h"

t_binding_ctx	*fdf_bind_init(t_rendctx *rctx)
{
	t_binding_ctx	*ctx;
	int				k;

	if (rctx == NULL)
		return (NULL);
	ctx = malloc(sizeof(*ctx));
	if (ctx == NULL)
		return (NULL);
	ctx->rctx = rctx;
	k = 0;
	while (k < KEYBIND_COUNT)
	{
		ft_memset(&ctx->bindings[k], 0, sizeof(*ctx->bindings));
		ctx->bindings[k].curact = KEY_ACTION__NONE;
		ctx->bindings[k].st = KEY_STATUS__UP;
		++k;
	}
	ctx->bindings[KEYBIND__EXIT].keycode = KEY_ECHAP;
	return (ctx);
}

void	fdf_bind_process(t_binding_ctx *ctx)
{
	int	k;

	k = 0;
	while (k < KEYBIND_COUNT)
	{
		if (ctx->bindings[k].curact != KEY_ACTION__NONE)
			if (ctx->bindings[k].action[ctx->bindings[k].curact] != NULL)
				ctx->bindings[k].action[ctx->bindings[k].curact](ctx->rctx,
					k, ctx->bindings[k].data);
		if (ctx->bindings[k].curact == KEY_ACTION__PRESS)
			ctx->bindings[k].st = KEY_STATUS__DOWN;
		else if (ctx->bindings[k].curact == KEY_ACTION__RELEASE)
			ctx->bindings[k].st = KEY_STATUS__UP;
		if (ctx->bindings[k].status[ctx->bindings[k].st] != NULL)
			ctx->bindings[k].status[ctx->bindings[k].st](ctx->rctx,
				k, ctx->bindings[k].data);
		ctx->bindings[k].curact = KEY_ACTION__NONE;
		++k;
	}
}

void	fdf_bind_destroy(t_binding_ctx *ctx)
{
	free(ctx);
}
