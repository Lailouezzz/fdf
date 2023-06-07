/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:44:32 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/24 17:46:36 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_CONV_H
# define FT_PRINTF_CONV_H

# include "ft_printf_utils.h"

int	ft_print_chr(t_printf_arg *arg);
int	ft_print_str(t_printf_arg *arg);
int	ft_print_ptr(t_printf_arg *arg);
int	ft_print_dec(t_printf_arg *arg);
int	ft_print_uns(t_printf_arg *arg);
int	ft_print_hxm(t_printf_arg *arg);
int	ft_print_hxc(t_printf_arg *arg);
int	ft_print_prc(t_printf_arg *arg);

#endif
