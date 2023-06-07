/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:31:28 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/24 13:05:49 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size != 0 && (nmemb * size) / size != nmemb)
		return (NULL);
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	ft_memset(p, (unsigned char)0, nmemb * size);
	return (p);
}
