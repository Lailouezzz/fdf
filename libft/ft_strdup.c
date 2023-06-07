/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:55:53 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/12 20:57:07 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;

	p = malloc(ft_strlen(s) + 1);
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, s, ft_strlen(s) + 1);
	return (p);
}
