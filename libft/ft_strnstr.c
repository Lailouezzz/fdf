/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:10:14 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/23 19:57:39 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	littlelen;

	if (*little == '\0')
		return ((char *)big);
	littlelen = ft_strlen(little);
	if (ft_strlen(big) < ft_strlen(little) || ft_strlen(little) > len)
		return (NULL);
	while (ft_strncmp(big, little, littlelen) != 0)
	{
		if (*(big) == '\0' || len <= littlelen)
			return (NULL);
		++big;
		--len;
	}
	return ((char *)big);
}
