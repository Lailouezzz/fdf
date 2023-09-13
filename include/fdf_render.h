/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:27:14 by ale-boud          #+#    #+#             */
/*   Updated: 2023/09/13 15:56:48 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_RENDER_H
# define FDF_RENDER_H

# include "fdf_vecmat.h"
# include "fdf_map.h"

# define SCREEN_WIDTH  800
# define SCREEN_HEIGHT 500

typedef int	t_color;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_point3
{
	int		x;
	int		y;
	t_coord	z;
}	t_point3;

typedef struct s_framebuffer {
	void	*img;
	char	*data;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_framebuffer;

typedef struct s_zbuffer {
	t_coord	*zbuf;
}	t_zbuffer;

typedef struct s_rendctx {
	void			*mlx;
	void			*mlx_win;
	t_framebuffer	fbuf;
	t_zbuffer		zbuf;
	t_mat4			mat;
	t_vec3			cam;
	t_vec3			focal;
	t_vec2			trans;
	double			z_mul;
	double			zoom;
}	t_rendctx;

void		fdf_pixel_put(t_rendctx *ctx, t_point p, t_color c);
void		fdf_pixel3_put(t_rendctx *ctx, t_point3 p, t_color c);
t_color		fdf_encode_trgb(int r, int g, int b, int t);
void		fdf_print_buffer(t_rendctx *ctx);
t_rendctx	*fdf_ctx_init(void);
void		fdf_ctx_init_buffer(t_rendctx **ctx);
/* Return 1 in success */
int			fdf_ctx_clear_buffer(t_rendctx *ctx);
void		fdf_ctx_destroy(t_rendctx *ctx);
void		fdf_draw_line(t_rendctx *ctx, t_point p1, t_point p2, t_color c);
void		fdf_draw3_line(t_rendctx *ctx, t_point3 p1, t_point3 p2, t_color c);
void		fdf_print_map_buffer(t_rendctx *ctx, const t_map *map);

#endif
