/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:08:42 by bhajili           #+#    #+#             */
/*   Updated: 2025/01/02 12:31:11 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

//void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
//{
//	char	*dst;

//	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//	*(unsigned int*)dst = color;
//}

//static void	do_fdf(t_fdf fdf, char *win_name)
//{
//	void	*mlx;
//	int		i = -1;
//	void	*mlx_win;

//	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, 420, 360, win_name);
//	fdf.img.img = mlx_new_image(mlx, 420, 360);
//	fdf.img.addr = mlx_get_data_addr(fdf.img.img, \
//								&fdf.img.bits_per_pixel, \
//								&fdf.img.line_length, \
//								&fdf.img.endian);
//	while (++i < 100)
//		my_mlx_pixel_put(&(fdf.img), i, i, 0x00FF0000);

//	mlx_put_image_to_window(mlx, mlx_win, fdf.img.img, 0, 0);
//	mlx_loop(mlx);
//}
