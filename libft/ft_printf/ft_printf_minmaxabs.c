/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_minmaxabs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:27:18 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/27 21:28:38 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}
