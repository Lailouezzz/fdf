/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:28:17 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/26 15:11:29 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_conv.h"
#include "ft_printf_utils.h"

int	ft_vprintf(const char *fmt, va_list param)
{
	int				written;
	t_printf_arg	arg;

	written = 0;
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			++fmt;
			arg = ft_printf_parse_arg(&fmt);
			if (arg.convf != ft_print_prc && arg.convf != 0)
				arg.d = va_arg(param, t_printf_data);
			if (arg.convf == 0)
				write(STDOUT_FILENO, "%", 1);
			else
				written += arg.convf(&arg);
		}
		else
		{
			write(STDOUT_FILENO, fmt, 1);
			++fmt;
			++written;
		}
	}
	return (written);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	param;
	int		written;

	va_start(param, fmt);
	written = ft_vprintf(fmt, param);
	va_end(param);
	return (written);
}
