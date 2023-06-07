/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:38:52 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/12 20:53:19 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r');
}

int	ft_atoi(const char *nptr)
{
	unsigned int	nbr;
	int				sign;

	while (ft_isspace(*nptr))
		++nptr;
	if (*nptr == '-')
		sign = -1;
	else
		sign = 1;
	if (*nptr == '-' || *nptr == '+')
		++nptr;
	nbr = 0;
	while (ft_isdigit(*nptr) && *nptr != '\0')
	{
		nbr *= 10;
		nbr += (*nptr - '0');
		++nptr;
	}
	return ((int)nbr * sign);
}
