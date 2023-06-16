/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:07:55 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/16 18:26:35 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <mlx.h>
#include "libft.h"
#include "fdf.h"

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
}	t_vars;

int	main(void)
{
	t_rendctx	*ctx;
	t_map		*map;
	double		x;

	map = fdf_read_map(STDIN_FILENO);
	ctx = fdf_ctx_init();
	ctx->cam = (t_vec3){0, 0, 100};
	ctx->focal = (t_vec3){0, 0, -0.5};
	x = 0;
	while (1)
	{
		fdf_ctx_init_buffer(&ctx);
		fdf_print_map_buffer(ctx, map);
		fdf_print_buffer(ctx);
		fdf_ctx_clear_buffer(ctx);
		x += 0.005;
		ctx->cam.x = (cos(x)) * 200 + (map->width * 10) / 2;
		ctx->cam.y = (-sin(x)) * 200 - (map->height * 10) / 2;
		ctx->focal.x = (-cos(x));
		ctx->focal.y = (sin(x));
		printf("%lf %lf\n", ctx->focal.x, ctx->focal.y);
		//getchar();
	}
	return (0);
}
