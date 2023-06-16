/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:14:26 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/16 16:32:07 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FDF_MAP_H
# define FDF_MAP_H

# include "fdf_vecmat.h"

typedef struct s_map {
	t_vec3	*map;
	int		width;
	int		height;
}	t_map;

t_map	*fdf_read_map(int fd);

#endif
