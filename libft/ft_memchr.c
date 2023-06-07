/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:59:39 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/12 09:53:50 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n)
	{
		if (((const unsigned char *)s)[k] == (unsigned char)c)
			return ((void *)((const unsigned char *)s + k));
		++k;
	}
	return (NULL);
}
