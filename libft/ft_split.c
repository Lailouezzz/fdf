/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:47:50 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/23 20:01:33 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split_nb_str(char const *str, char c)
{
	int	k;

	k = 0;
	if (*str == '\0')
		return (0);
	while (*str == c)
		++str;
	while (*str != '\0')
	{
		if (*str == c)
		{
			++k;
			while (*str == c)
				++str;
		}
		else
			++str;
	}
	if (*(str - 1) != c)
		++k;
	return (k);
}

static char	*ft_strduptol(char const *src, char c)
{
	int		k;
	char	*p;

	k = 0;
	while (src[k] != c && src[k] != '\0')
		++k;
	if (k == 0)
		return (NULL);
	p = malloc((k + 1) * sizeof(*p));
	if (p == NULL)
		return (NULL);
	p[k] = '\0';
	--k;
	while (k != 0)
	{
		p[k] = src[k];
		--k;
	}
	*p = *src;
	return (p);
}

char	**ft_split(char const *str, char c)
{
	char	**stab;
	int		k;

	stab = malloc((ft_split_nb_str(str, c) + 1) * sizeof(*stab));
	if (stab == NULL)
		return (NULL);
	k = 0;
	while (*str == c && *str != '\0')
		++str;
	while (*str != '\0')
	{
		if (*str == c)
			while (*str == c)
				++str;
		else
		{
			stab[k] = ft_strduptol(str, c);
			str += ft_strlen(stab[k++]);
		}
	}
	stab[k] = NULL;
	return (stab);
}
