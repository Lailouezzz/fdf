/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:21:26 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/13 13:45:58 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*s;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s = malloc(s1len + s2len + 1);
	if (s == NULL)
		return (NULL);
	ft_memcpy(s, s1, s1len);
	ft_memcpy(s + s1len, s2, s2len);
	s[s1len + s2len] = '\0';
	return (s);
}
