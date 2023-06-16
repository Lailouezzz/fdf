/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 01:50:28 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/16 18:02:17 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_realloc(void *src, size_t size, size_t newsize)
{
	void	*dst;
	size_t	k;

	dst = malloc(newsize);
	if (dst == NULL)
	{
		free(src);
		return (NULL);
	}
	k = 0;
	while (k < size)
	{
		((char *)dst)[k] = ((char *)src)[k];
		++k;
	}
	free(src);
	return (dst);
}

int	fdf_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

/* -1 EOF -2 error */
int	fdf_getchar(int fd)
{
	unsigned char	c;
	ssize_t			r;

	r = read(fd, &c, 1);
	if (r == 0)
		return (-1);
	if (r != 1)
		return (-2);
	return (c);
}

/* 0 success 1 NL 2 error 3 EOF */
int	fdf_read_nb(int fd, int *nb)
{
	unsigned int	nbr;
	int				sign;
	int				c;

	c = fdf_getchar(fd);
	while (c >= 0 && c == ' ')
		c = fdf_getchar(fd);
	if (c == -2 || c == '\n')
		return (2);
	if (c == -1)
		return (3);
	if (c == '-')
	{
		sign = -1;
		c = fdf_getchar(fd);
	}
	else
		sign = 1;
	nbr = 0;
	while (c >= 0 && ft_isdigit(c))
	{
		nbr = (nbr * 10) + c - '0';
		c = fdf_getchar(fd);
	}
	if (c <= -1 || (c != '\n' && c != ' '))
		return (2);
	*nb = (int)nbr * sign;
	if (c == '\n')
		return (1);
	return (0);
}
