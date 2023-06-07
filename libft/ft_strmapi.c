/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:57:15 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/13 15:02:54 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	k;
	char			*p;

	p = malloc(ft_strlen(s) + 1);
	if (p == NULL)
		return (NULL);
	k = 0;
	while (s[k] != '\0')
	{
		p[k] = f(k, s[k]);
		++k;
	}
	p[k] = '\0';
	return (p);
}
