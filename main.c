/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:07:55 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/07 00:29:30 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <mlx.h>

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
}	t_vars;

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 200, 200, "Hello wolrd");
	if (vars.mlx_win == NULL)
		return (-1);
	mlx_loop(vars.mlx);
	return (0);
}
