/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:03:21 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/13 16:41:59 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	k;

	if (s1 == s2 || n == 0)
		return (0);
	k = 0;
	while (k < n)
	{
		if (((const char *)s1)[k] != ((const char *)s2)[k])
			return (((unsigned char *)s1)[k] - ((unsigned char *)s2)[k]);
		++k;
	}
	return (0);
}
