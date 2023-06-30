/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:35:00 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/30 08:56:12 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FDF_HOOK_H
# define FDF_HOOK_H

# include "fdf_render.h"
# include "fdf_map.h"

typedef struct s_hook_ctx {
	t_rendctx	*rendctx;
	t_map		*map;
	double		rot;
	double		rrot;
}	t_hook_ctx;

# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_ECHAP 65307
# define KEY_Q 113
# define KEY_W 119
# define KEY_J 106
# define KEY_I 105
# define KEY_L 108
# define KEY_K 107
# define KEY_A 97
# define KEY_Z 122

int	fdf_key_hook(int keycode, t_hook_ctx *ctx);

#endif
