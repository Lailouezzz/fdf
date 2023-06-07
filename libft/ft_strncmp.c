/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:49:59 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/13 15:46:59 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	k;

	if (s1 == s2 || n == 0)
		return (0);
	k = 0;
	while (k < n - 1 && s1[k] != '\0' && s2[k] != '\0' && s1[k] == s2[k])
		++k;
	return ((unsigned char)(s1[k]) - (unsigned char)(s2[k]));
}
