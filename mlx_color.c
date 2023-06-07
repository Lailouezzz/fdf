/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:29:00 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/05 00:37:54 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

int	mlxx_create_trgb(unsigned char t, unsigned char r, unsigned char g,
	unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}
