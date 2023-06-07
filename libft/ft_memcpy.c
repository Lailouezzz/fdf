/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:42:14 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/23 20:02:38 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	k;

	if (dest == src)
		return (NULL);
	k = 0;
	while (k < n)
	{
		((char *)dest)[k] = ((char *)src)[k];
		++k;
	}
	return (dest);
}
