/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:21:01 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/13 15:27:50 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	k;

	if (size == 0)
		return (ft_strlen(src));
	k = 0;
	while (src[k] != '\0' && k < size - 1)
	{
		dst[k] = src[k];
		++k;
	}
	dst[k] = '\0';
	while (src[k] != '\0')
		++k;
	return (k);
}
