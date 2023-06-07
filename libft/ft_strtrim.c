/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:24:54 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/13 13:45:13 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		++set;
	}
	return (0);
}

size_t	ft_strtrim_len(char const *s1, char const *set)
{
	const void	*p;

	p = s1;
	s1 = s1 + ft_strlen(s1);
	if (p == s1)
		return (0);
	--s1;
	while (s1 != p && ft_isinset(*s1, set))
		--s1;
	return (s1 - (const char *)p + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*r;

	while (*s1 != '\0' && ft_isinset(*s1, set))
		++s1;
	r = malloc(ft_strtrim_len(s1, set) + 1);
	if (r == NULL)
		return (NULL);
	ft_strlcpy(r, s1, ft_strtrim_len(s1, set) + 1);
	return (r);
}
