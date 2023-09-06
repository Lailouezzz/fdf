/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_binding.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:35:00 by ale-boud          #+#    #+#             */
/*   Updated: 2023/09/06 19:37:44 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BINDING_H
# define FDF_BINDING_H

# include "fdf_key.h"
# include "fdf_render.h"

typedef enum e_key_status {
	KEY_STATUS__DOWN,
	KEY_STATUS__UP,
	KEY_STATUS_COUNT
}	t_key_status;

typedef enum e_key_action {
	KEY_ACTION__PRESS,
	KEY_ACTION__RELEASE,
	KEY_ACTION_COUNT,
	KEY_ACTION__NONE
}	t_key_action;

typedef enum e_keybind {
	KEYBIND__SWITCHPROJ,
	KEYBIND__ZOOMP,
	KEYBIND__ZOOMM,
	KEYBIND__ROTLEFT,
	KEYBIND__ROTRIGHT,
	KEYBIND__ROTUP,
	KEYBIND__ROTDOWN,
	KEYBIND__ZP,
	KEYBIND__ZM,
	KEYBIND__TRANSLEFT,
	KEYBIND__TRANSRIGHT,
	KEYBIND__TRANSUP,
	KEYBIND__TRANSDOWN,
	KEYBIND_COUNT
}	t_keybind;

typedef void	(*t_func_cb)(t_rendctx *, t_keybind, void *);

typedef struct s_binding {
	t_func_cb		status[KEY_STATUS_COUNT];
	t_func_cb		action[KEY_ACTION_COUNT];
	t_key_action	curact;
	t_key_status	st;
	int				keycode;
	void			*data;
}	t_binding;

typedef struct s_binding_ctx {
	t_binding	bindings[KEYBIND_COUNT];
	t_rendctx	*rctx;
}	t_binding_ctx;

/* Alloc and initialize bind table */
t_binding_ctx	*fdf_bind_init(t_rendctx *rctx);
/* Free */
void			fdf_bind_destroy(t_binding_ctx *ctx);
/* Process events */
void			fdf_bind_process(t_binding_ctx *ctx);

/* General callback */

int				_keypress_cb(int keycode, t_binding_ctx *ctx);
int				_keyrelease_cb(int keycode, t_binding_ctx *ctx);

/* Utils */

void			fdf_bind_set_status_down_cb(t_binding *binding,
					t_func_cb cb, int keycode, void *data);
void			fdf_bind_set_action_press_cb(t_binding *binding,
					t_func_cb cb, int keycode, void *data);

/* BINDING CALLBACK AND LOCAL STRUCTURE */

void			fdf_bind_zoom_init(t_binding_ctx *ctx);
void			fdf_bind_zoom(t_rendctx *rctx, t_keybind key, void *null);

typedef struct s_rotctx {
	float	x;
	float	y;
}	t_rotctx;
int				fdf_bind_rot_init(t_binding_ctx *ctx);
void			fdf_bind_rot(t_rendctx *rctx, t_keybind key, t_rotctx *ctx);

void			fdf_bind_z_init(t_binding_ctx *ctx);
void			fdf_bind_z(t_rendctx *rctx, t_keybind key, void *null);

#endif
