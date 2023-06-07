/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:50:46 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/12 09:35:58 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	k;

	if (n == 0 || dest == src)
		return (dest);
	if (dest < src)
	{
		k = 0;
		while (k < n)
		{
			((char *)dest)[k] = ((char *)src)[k];
			++k;
		}
	}
	else
	{
		k = n;
		while (k != 0)
		{
			--k;
			((char *)dest)[k] = ((char *)src)[k];
		}
	}
	return (dest);
}
