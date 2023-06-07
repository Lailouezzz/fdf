/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:16:13 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/27 21:19:36 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "ft_printf_conv.h"

static unsigned int	ft_uatoi(const char *nptr)
{
	unsigned int	nbr;

	nbr = 0;
	while (ft_isdigit(*nptr) && *nptr != '\0')
	{
		nbr *= 10;
		nbr += (*nptr - '0');
		++nptr;
	}
	return (nbr);
}

static void	ft_printf_parse_arg_flag(const char **str, t_printf_arg *arg)
{
	const char	*s;

	s = *str;
	if (*s == '0')
		arg->zflag = 1;
	else if (*s == '-')
		arg->leftflag = 1;
	else if (*s == '+')
		arg->signflag = 1;
	else if (*s == ' ')
		arg->spaceflag = 1;
	else if (*s == '#')
		arg->altflag = 1;
	if (*s == '0' || *s == '-' || *s == '+' || *s == ' ' || *s == '#')
	{	
		++s;
		ft_printf_parse_arg_flag(&s, arg);
	}
	*str = s;
}

static void	ft_printf_parse_arg_prec(const char **str, t_printf_arg *arg)
{
	const char	*s;

	s = *str;
	if (*s == '.')
	{
		arg->zflag = 0;
		++s;
		arg->precflag = ft_uatoi(s);
		while (ft_isdigit(*s))
			++s;
	}
	*str = s;
}

static void	ft_printf_parse_arg_conv(const char **str, t_printf_arg *arg)
{
	const char	*s;

	s = *str;
	if (*s == 'c')
		arg->convf = ft_print_chr;
	else if (*s == 's')
		arg->convf = ft_print_str;
	else if (*s == 'p')
		arg->convf = ft_print_ptr;
	else if (*s == 'd' || *s == 'i')
		arg->convf = ft_print_dec;
	else if (*s == 'u')
		arg->convf = ft_print_uns;
	else if (*s == 'x')
		arg->convf = ft_print_hxm;
	else if (*s == 'X')
		arg->convf = ft_print_hxc;
	else if (*s == '%')
		arg->convf = ft_print_prc;
	else
		return ;
	++s;
	*str = s;
}

t_printf_arg	ft_printf_parse_arg(const char **str)
{
	t_printf_arg	arg;
	const char		*s;

	s = *str;
	ft_memset(&arg, 0, sizeof(arg));
	arg.precflag = -1;
	ft_printf_parse_arg_flag(&s, &arg);
	if (*s == '\0')
		return (arg);
	arg.pad = ft_uatoi(s);
	while (ft_isdigit(*s))
		++s;
	if (*s == '\0')
		return (arg);
	ft_printf_parse_arg_prec(&s, &arg);
	ft_printf_parse_arg_conv(&s, &arg);
	*str = s;
	return (arg);
}
