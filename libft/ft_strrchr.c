/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:45:01 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/23 19:58:03 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	k;

	k = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + k);
	while (k != 0)
	{
		--k;
		if (s[k] == (char)c)
			return ((char *)s + k);
	}
	return (NULL);
}
