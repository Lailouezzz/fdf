/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 01:49:29 by ale-boud          #+#    #+#             */
/*   Updated: 2023/09/06 17:22:44 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_UTILS_H
# define FDF_UTILS_H

# include <stdlib.h>

void	*ft_realloc(void *src, size_t size, size_t newsize);
int		fdf_abs(int n);
int		fdf_getchar(int fd);
int		fdf_read_nb(int fd, int *nb);

#endif
