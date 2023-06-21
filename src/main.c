/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:07:55 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/20 02:07:05 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <mlx.h>
#include "libft.h"
#include "fdf.h"

static void	fdf_default(t_hook_ctx *ctx)
{
	ctx->rendctx->cam = (t_vec3){0, 0, 100};
	ctx->rendctx->focal = (t_vec3){0, 0, -0.5};
	ctx->rot = 0.;
	ctx->rendctx->zoom = 20;
	ctx->rendctx->z_mul = 0.01;
	fdf_key_hook(-1, ctx);
}

int	main(void)
{
	t_rendctx	*rctx;
	t_map		*map;
	t_hook_ctx	hctx;
	double		x;

	map = fdf_read_map(STDIN_FILENO);
	if (map == NULL)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	rctx = fdf_ctx_init();
	hctx.map = map;
	hctx.rendctx = rctx;
	fdf_default(&hctx);
	mlx_hook(rctx->mlx_win, 2, 1L << 0, fdf_key_hook, &hctx);
	mlx_loop(rctx->mlx);
	return (0);
}
