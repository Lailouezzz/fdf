/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 01:49:29 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/16 16:58:42 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FDF_UTILS_H
# define FDF_UTILS_H

void	*ft_realloc(void *src, size_t size, size_t newsize);
int		fdf_abs(int n);
int		fdf_getchar(int fd);
int		fdf_read_nb(int fd, int *nb);

#endif
