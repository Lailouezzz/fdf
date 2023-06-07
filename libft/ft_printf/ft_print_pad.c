/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:37:14 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/26 12:38:16 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_utils.h"

void	ft_print_pad(unsigned int n, char c)
{
	while (n-- != 0)
		write(STDOUT_FILENO, &c, 1);
}
