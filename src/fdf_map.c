/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:04:30 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/16 18:15:48 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "fdf_utils.h"
#include "fdf_map.h"

typedef struct s_fdf_read_ctx
{
	t_map	*map;
	size_t	allocated;
	size_t	pos;
}	t_fdf_read_ctx;

/* 0 OK 1 error */
static int	fdf_read_map_insert(t_fdf_read_ctx *ctx, const t_coord z)
{
	if (ctx->pos >= ctx->allocated)
	{
		ctx->map->map = ft_realloc(ctx->map->map,
				ctx->allocated * sizeof(*ctx->map->map),
				ctx->allocated * sizeof(*ctx->map->map) * 2);
		if (ctx->map->map == NULL)
			return (1);
		ctx->allocated *= 2;
	}
	if (ctx->map->width != 0)
		ctx->map->map[ctx->pos] = (t_vec3){
			(ctx->pos % ctx->map->width) * 10,
			(t_coord)((ctx->pos / ctx->map->width) * 10) * -1.,
			z};
	else
		ctx->map->map[ctx->pos] = (t_vec3){
			ctx->pos * 10,
			0,
			z};
	++ctx->pos;
	return (0);
}

static void	*fdf_read_map_free(t_fdf_read_ctx *ctx)
{
	free(ctx->map->map);
	free(ctx->map);
	return (NULL);
}

static t_map	*fdf_read_map_aux(int fd, t_fdf_read_ctx *ctx)
{
	int	r;
	int	nb;

	r = fdf_read_nb(fd, &nb);
	if (r != 0)
		return (fdf_read_map_free(ctx));
	while (r == 0 || r == 1)
	{
		if (fdf_read_map_insert(ctx, nb) == 1)
			return (fdf_read_map_free(ctx));
		if (r == 1)
		{
			if (ctx->map->width == 0)
				ctx->map->width = ctx->pos;
			++ctx->map->height;
		}
		r = fdf_read_nb(fd, &nb);
	}
	if (r != 3)
		return (fdf_read_map_free(ctx));
	return (ctx->map);
}

t_map	*fdf_read_map(int fd)
{
	t_fdf_read_ctx	ctx;

	ctx.allocated = 1;
	ctx.pos = 0;
	ctx.map = malloc(sizeof(*ctx.map));
	if (ctx.map == NULL)
		return (NULL);
	ctx.map->map = malloc(ctx.allocated * sizeof(*ctx.map->map));
	if (ctx.map->map == NULL)
	{
		free(ctx.map);
		return (NULL);
	}
	ctx.map->width = 0;
	ctx.map->height = 0;
	return (fdf_read_map_aux(fd, &ctx));
}
