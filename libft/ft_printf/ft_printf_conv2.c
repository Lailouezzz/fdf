/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:32:33 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/27 20:32:42 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "ft_printf_conv.h"

int	ft_print_hxm(t_printf_arg *arg)
{
	int		written;
	char	*str;

	str = ft_printf_uitoabase(arg->d.unb, "0123456789abcdef", arg);
	arg->precflag = -1;
	arg->d.str = str;
	written = ft_print_str(arg);
	free(str);
	return (written);
}

int	ft_print_hxc(t_printf_arg *arg)
{
	int		written;
	char	*str;

	str = ft_printf_uitoabase(arg->d.unb, "0123456789ABCDEF", arg);
	arg->precflag = -1;
	arg->d.str = str;
	written = ft_print_str(arg);
	free(str);
	return (written);
}

int	ft_print_prc(t_printf_arg *arg)
{
	arg->d.c = '%';
	ft_putchar_fd(arg->d.c, STDOUT_FILENO);
	return (1);
}
