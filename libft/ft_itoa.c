/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:36:12 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/23 20:01:49 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itoa_len(int n)
{
	size_t	k;

	k = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		++k;
	while (n != 0)
	{
		n /= 10;
		++k;
	}
	return (k);
}

char	*ft_itoa(int n)
{
	char			*s;
	size_t			nlen;
	unsigned int	nabs;

	nlen = ft_itoa_len(n);
	s = malloc(nlen + 1);
	if (s == NULL)
		return (NULL);
	s[nlen] = '\0';
	if (n < 0)
		*s = '-';
	if (n == 0)
		*s = '0';
	if (n < 0)
		nabs = -n;
	else
		nabs = n;
	while (nabs != 0)
	{
		--nlen;
		s[nlen] = '0' + (nabs % 10);
		nabs /= 10;
	}
	return (s);
}
