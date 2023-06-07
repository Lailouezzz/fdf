/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:29:17 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/13 16:56:55 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s, size_t len)
{
	char	*p;

	if (ft_strlen(s) >= len)
		p = malloc(len + 1);
	else
		p = malloc(ft_strlen(s) + 1);
	if (p == NULL)
		return (NULL);
	if (ft_strlen(s) >= len)
	{
		ft_memcpy(p, s, len);
		p[len] = '\0';
	}
	else
		ft_memcpy(p, s, ft_strlen(s) + 1);
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (start > ft_strlen(s))
		return (ft_strndup(s + ft_strlen(s), len));
	return (ft_strndup(s + start, len));
}
