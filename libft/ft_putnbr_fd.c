/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:53:45 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/13 15:12:08 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_aux(unsigned int nb, int fd)
{
	char	buf;

	if (nb == 0)
	{
		return ;
	}
	ft_putnbr_aux(nb / 10, fd);
	buf = nb % 10 + '0';
	write(fd, &buf, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	buf;

	if (n == 0)
	{
		buf = '0';
		write(fd, &buf, 1);
		return ;
	}
	else if (n < 0)
	{
		buf = '-';
		write(fd, &buf, 1);
		n = -n;
	}
	ft_putnbr_aux(n, fd);
}
