/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:08:42 by bhajili           #+#    #+#             */
/*   Updated: 2024/12/28 12:45:48 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_fdf(char *path)
{
	void	*mlx;
	void	*mlx_win;

	mlx= mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, path);
	mlx_loop(mlx);
}

void	fdf(int ac, char **av)
{
	if (is_valid_arg(ac, av))
		do_fdf(av[1]);
	else
		ft_printf("ARG is INvalid\n");
	return ;
}
