/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:46:03 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/27 21:29:43 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <stdint.h>

typedef union u_printf_data
{
	char			c;
	const char		*str;
	uintptr_t		ptr;
	int				nb;
	unsigned int	unb;
}	t_printf_data;

typedef struct s_printf_arg
{
	int				zflag;
	int				leftflag;
	int				signflag;
	int				spaceflag;
	int				altflag;
	int				precflag;
	unsigned int	pad;
	int				(*convf)(struct s_printf_arg *);
	t_printf_data	d;
}	t_printf_arg;

t_printf_arg	ft_printf_parse_arg(const char **str);
void			ft_print_pad(unsigned int n, char c);
char			*ft_printf_uitoabase(unsigned long int n, const char *base,
					t_printf_arg *arg);
char			*ft_printf_itoabase(int n, const char *base,
					t_printf_arg *arg);
int				min(int a, int b);
int				max(int a, int b);
int				abs(int a);

#endif
