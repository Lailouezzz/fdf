/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:06:37 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/12 10:31:59 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		k;
	size_t		dstlen;
	char		*d;
	const char	*s;

	d = dst;
	k = size;
	while (*d != '\0' && k-- != 0)
		++d;
	dstlen = d - dst;
	k = size - dstlen;
	if (k == 0)
		return (dstlen + ft_strlen(src));
	s = src;
	while (*s != '\0')
	{
		if (k > 1)
		{
			*(d++) = *s;
			--k;
		}
		++s;
	}
	*d = '\0';
	return (dstlen + (s - src));
}
