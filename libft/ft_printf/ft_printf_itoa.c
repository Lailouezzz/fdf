/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:26:00 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/27 21:30:00 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_conv.h"
#include "ft_printf_utils.h"

static size_t	ft_printf_uitoabase_len(unsigned long int n, const char *base,
					t_printf_arg *arg)
{
	size_t	k;

	k = 0;
	if (n == 0)
		k = 1;
	if (n == 0 && arg->precflag == 0)
		return (0);
	if (arg->altflag && n != 0)
		k += 2;
	while (n != 0)
	{
		n /= ft_strlen(base);
		++k;
	}
	if (arg->precflag > 0)
		k = max(k, (size_t) arg->precflag);
	else if (arg->pad > k && arg->zflag)
		k = arg->pad;
	return (k);
}

static void	ft_printf_itoabase_aux(int n, char *s, const char *base,
				size_t *nlen)
{
	unsigned int	nabs;

	nabs = abs(n);
	while (nabs != 0)
	{
		--*nlen;
		s[*nlen] = base[nabs % ft_strlen(base)];
		nabs /= ft_strlen(base);
	}
}

char	*ft_printf_uitoabase(unsigned long int n, const char *base,
			t_printf_arg *arg)
{
	char	*s;
	size_t	nlen;

	nlen = ft_printf_uitoabase_len(n, base, arg);
	s = malloc(nlen + 1);
	if (s == NULL)
		return (NULL);
	if (n == 0)
		arg->altflag = 0;
	s[nlen] = '\0';
	while (n != 0)
	{
		s[--nlen] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	while (nlen != 0)
		s[--nlen] = *base;
	if (arg->altflag && arg->convf == ft_print_hxm)
		ft_memcpy(s, "0x", 2);
	if (arg->altflag && arg->convf == ft_print_hxc)
		ft_memcpy(s, "0X", 2);
	return (s);
}

static size_t	ft_printf_itoabase_len(int n, const char *base,
					t_printf_arg *arg)
{
	size_t			k;
	unsigned int	nabs;

	if (arg->precflag == 0 && n == 0)
		return (0);
	nabs = abs(n);
	k = 0;
	if (n == 0)
		++k;
	while (nabs != 0)
	{
		nabs /= ft_strlen(base);
		++k;
	}
	if (arg->precflag > 0)
		k = max(k, (size_t) arg->precflag);
	if (n < 0 || arg->signflag || arg->spaceflag)
		++k;
	if (arg->pad > k && arg->zflag && arg->precflag <= 0)
		k = arg->pad;
	return (k);
}

char	*ft_printf_itoabase(int n, const char *base,
			t_printf_arg *arg)
{
	char	*s;
	size_t	nlen;

	nlen = ft_printf_itoabase_len(n, base, arg);
	s = malloc(nlen + 1);
	if (s == NULL)
		return (NULL);
	s[nlen] = '\0';
	if (nlen == 0)
		return (s);
	if (n == 0)
		s[nlen - 1] = *base;
	if (arg->zflag || arg->precflag > 0)
		*s = *base;
	if (arg->signflag && n >= 0)
		*s = '+';
	else if (arg->signflag || n < 0)
		*s = '-';
	else if (arg->spaceflag)
		*s = ' ';
	ft_printf_itoabase_aux(n, s, base, &nlen);
	while (nlen > 1)
		s[--nlen] = *base;
	return (s);
}
