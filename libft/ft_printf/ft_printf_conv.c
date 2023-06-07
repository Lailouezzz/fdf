/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:43:43 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/27 21:28:47 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "ft_printf_conv.h"

int	ft_print_chr(t_printf_arg *arg)
{
	if (arg->pad != 0 && !arg->leftflag)
		ft_print_pad(arg->pad - 1, ' ');
	ft_putchar_fd(arg->d.c, STDOUT_FILENO);
	if (arg->pad != 0 && arg->leftflag)
		ft_print_pad(arg->pad - 1, ' ');
	if (arg->pad != 0)
		return (arg->pad);
	return (1);
}

int	ft_print_str(t_printf_arg *arg)
{
	size_t		slen;
	int			written;
	int			diff;
	const char	*s;

	if (arg->d.str == NULL && (arg->precflag >= 6 || arg->precflag == -1))
		arg->d.str = "(null)";
	else if (arg->d.str == NULL && arg->precflag < 6)
		arg->d.str = "";
	if (arg->precflag != -1)
		slen = min(ft_strlen(arg->d.str), (size_t) arg->precflag);
	else
		slen = ft_strlen(arg->d.str);
	written = max(slen, arg->pad);
	diff = arg->pad - slen;
	if (arg->pad != 0 && !arg->leftflag && diff > 0)
		ft_print_pad(diff, ' ');
	s = arg->d.str;
	while (*s != '\0' && slen-- != 0)
		ft_putchar_fd(*(s++), STDOUT_FILENO);
	if (arg->pad != 0 && arg->leftflag && diff > 0)
		ft_print_pad(diff, ' ');
	return (written);
}

int	ft_print_ptr(t_printf_arg *arg)
{
	int		written;
	char	*str;

	if (arg->d.ptr == 0)
	{
		arg->d.str = "(nil)";
		return (ft_print_str(arg));
	}
	arg->altflag = 1;
	arg->convf = ft_print_hxm;
	str = ft_printf_uitoabase(arg->d.ptr, "0123456789abcdef", arg);
	arg->precflag = -1;
	arg->d.str = str;
	written = ft_print_str(arg);
	free(str);
	return (written);
}

int	ft_print_dec(t_printf_arg *arg)
{
	int		written;
	char	*str;

	str = ft_printf_itoabase(arg->d.nb, "0123456789", arg);
	arg->precflag = -1;
	arg->d.str = str;
	written = ft_print_str(arg);
	free(str);
	return (written);
}

int	ft_print_uns(t_printf_arg *arg)
{
	int		written;
	char	*str;

	str = ft_printf_uitoabase(arg->d.unb, "0123456789", arg);
	arg->precflag = -1;
	arg->d.str = str;
	written = ft_print_str(arg);
	free(str);
	return (written);
}
