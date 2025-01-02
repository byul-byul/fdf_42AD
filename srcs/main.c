/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:49:39 by bhajili           #+#    #+#             */
/*   Updated: 2025/01/02 16:19:57 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void my_mlx_line(t_img *data, int x1, int y1, int x2, int y2, int color)
{
    int dx, dy, sx, sy, err, e2;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    sx = (x1 < x2) ? 1 : -1;  // Set the direction of step in x
    sy = (y1 < y2) ? 1 : -1;  // Set the direction of step in y
    err = dx - dy;  // Error term for the line

    while (1)
    {
        // Put the pixel on the image
        my_mlx_pixel_put(data, x1, y1, color);

        // If we've reached the end point, stop
        if (x1 == x2 && y1 == y2)
            break;

        e2 = 2 * err;
        
        // Move in the x direction if the error is too large in the x direction
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        // Move in the y direction if the error is too large in the y direction
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

// void	my_mlx_line(t_img *data, int x1, int y1, int x2, int y2, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

static void	transform_to_2D(int x, int y, int z, int *screenX, int *screenY)
{
	int	iso_x;
	int	iso_y;

	iso_x = (x - y) * cos(ISO_ANGLE * M_PI / 180.0);
	iso_y = (x + y) * sin(ISO_ANGLE * M_PI / 180.0) - z;
	*screenX = iso_x * SCALE;
	*screenY = iso_y * SCALE;
}

static void	draw_fdf(t_fdf fdf)
{
	int	x = -1;
	int	y = -1;
	int	screenX1;
	int	screenY1;
	int	screenX2;
	int	screenY2;

	while (++y < fdf.map.row_count - 1)
	{
		x = -1;
		while (++x < fdf.map.rows[y].row_size - 1)
		{
			transform_to_2D(x, y, fdf.map.rows[y].row[x], &screenX1, &screenY1);
			transform_to_2D(x + 1, y, fdf.map.rows[y].row[x + 1], &screenX2, &screenY2);
			// my_mlx_pixel_put(&fdf.mlx.img, screenX, screenY, 0x00FF0000);
			my_mlx_line(&fdf.mlx.img, screenX1, screenY1, screenX2, screenY2, 0x00FFFFFF);
			// mlx_line(&fdf.mlx.mlx, &fdf.mlx.win, screenX1, screenY1, screenX2, screenY2, 0x00FFFFFF);
			transform_to_2D(x, y + 1, fdf.map.rows[y + 1].row[x], &screenX2, &screenY2);
			my_mlx_line(&fdf.mlx.img, screenX1, screenY1, screenX2, screenY2, 0x00FF0000);
			// mlx_line(&fdf.mlx.mlx, &fdf.mlx.win, screenX1, screenY1, screenX2, screenY2, 0x00FFFFFF);
		}
	}
}

static int	do_fdf(t_fdf *fdf, char *path)
{
	// int	i = -1;

	fdf->mlx.mlx = mlx_init();
	fdf->mlx.win = mlx_new_window(fdf->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, path);
	fdf->mlx.img.img = mlx_new_image(fdf->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	fdf->mlx.img.addr = mlx_get_data_addr(fdf->mlx.img.img, \
											&fdf->mlx.img.bits_per_pixel, \
											&fdf->mlx.img.line_length, \
											&fdf->mlx.img.endian);
	draw_fdf(*fdf);
	// while (++i < 100)
	// 	my_mlx_pixel_put(&fdf->mlx.img, i, i, 0x00FF0000);
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.img.img, 100, 100);
	mlx_loop(fdf->mlx.mlx);
	return (1);
}

// static int	do_fdf(t_fdf *fdf, char *path)
// {
// 	int	i;
// 	int	j;

// 	path += 0;
// 	fdf += 0;
// 	i = -1;
// 	while (++i < fdf->map.row_count)
// 	{
// 		j = -1;
// 		while (++j < fdf->map.rows[i].row_size)
// 			ft_printf("%d, ", fdf->map.rows[i].row[j]);
// 		ft_printf("\n");
// 	}
// 	ft_printf("do_fdf() execution.\n");
// 	return (1);
// }

static int	check_row_sizes(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (++i < fdf->map.row_count)
		if (fdf->map.rows[0].row_size != fdf->map.rows[i].row_size)
			return (clean_rows(fdf->map.rows, fdf->map.row_count), \
					fdf->error = 8, 0);
	return (1);
}

static int	is_valid_arg(t_fdf *fdf, int ac, char **av)
{
	if (ac != 2)
		return (fdf->error = 1, 0);
	if (ft_strlen(ft_strstr(av[1], FILE_EXT)) != ft_strlen(FILE_EXT))
		return (fdf->error = 2, 0);
	return (1);
}

static void	fdf(int ac, char **av)
{
	t_fdf	fdf;

	if (is_valid_arg(&fdf, ac, av))
		if (parse_arg(&fdf, av[1]))
			if (check_row_sizes(&fdf))
				if (do_fdf(&fdf, av[1]))
					return ;
	print_error(fdf.error);
}

int	main(int ac, char **av)
{
	fdf(ac, av);
	return (0);
}
