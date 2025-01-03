/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   fdf.c											  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bhajili <bhajili@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/28 12:08:42 by bhajili		   #+#	#+#			 */
/*   Updated: 2025/01/03 19:42:45 by bhajili		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../incl/fdf.h"

static void	my_mlx_pixel_put(t_img *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void draw_line(int x0, int y0, int x1, int y1, t_img *image)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;
	int err = dx - dy;

	while (1)
	{
		my_mlx_pixel_put(image, x0, y0, 0xFFFFFF);  // Draw white pixels (or any color)
		if (x0 == x1 && y0 == y1)
			break;
		int e2 = err * 2;
		if (e2 > -dy) {
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx) {
			err += dx;
			y0 += sy;
		}
	}
}

static void	draw_fdf_on_image(t_img *image, t_map map)
{
	int	x = -1;
	int	y = -1;
	int	screen_x;
	int	screen_y;
	int	screen_x1;
	int	screen_y1;

	while (++y < map.row_count)
	{
		x = -1;
		while (++x < map.rows[y].row_size)
		{
			if (x < map.rows[y].row_size - 1)
			{
				convert_3D_to_2D(x, y, map.rows[y].row[x], &screen_x, &screen_y, map.scale);
				convert_3D_to_2D(x + 1, y, map.rows[y].row[x + 1], &screen_x1, &screen_y1, map.scale);
				draw_line(screen_x, screen_y, screen_x1, screen_y1, image);
			}
			if (y < map.row_count - 1)
			{
				convert_3D_to_2D(x, y, map.rows[y].row[x], &screen_x, &screen_y, map.scale);
				convert_3D_to_2D(x, y + 1, map.rows[y + 1].row[x], &screen_x1, &screen_y1, map.scale);
				draw_line(screen_x, screen_y, screen_x1, screen_y1, image);
			}
		}
	}
}


static void	init_mlx(t_mlx *mlx, char *path)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, path);
	mlx->img.img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, \
											&mlx->img.bits_per_pixel, \
											&mlx->img.line_length, \
											&mlx->img.endian);
}

static int	draw_fdf(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx.mlx, fdf->mlx.win);
	mlx_destroy_image(fdf->mlx.mlx, fdf->mlx.img.img);
	fdf->mlx.img.img = mlx_new_image(fdf->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	draw_fdf_on_image(&fdf->mlx.img, fdf->map);
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.img.img, 0, 0);
	return (1);
}

static void	fdf_exit(t_fdf *fdf)
{
	clean_rows(fdf->map.rows, fdf->map.row_count);
	mlx_destroy_image(fdf->mlx.mlx, fdf->mlx.img.img);
	mlx_destroy_window(fdf->mlx.mlx, fdf->mlx.win);
	exit(0);
}

static void zoom(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_PLUS)
		if (fdf->map.scale + ZOOM_SPEED <= ZOOM_MAX)
			fdf->map.scale += ZOOM_SPEED;
	if (keycode == KEY_MINUS)
		if (fdf->map.scale - ZOOM_SPEED >= ZOOM_MIN)
			fdf->map.scale -= ZOOM_SPEED;
	draw_fdf(fdf);
}

static int	key_handler(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		zoom(keycode, fdf);
	else if (keycode == KEY_ESCAPE)
		fdf_exit(fdf);
	return (1);
}

int	do_fdf(t_fdf *fdf, char *path)
{
	init_mlx(&fdf->mlx, path);
	draw_fdf(fdf);
	mlx_key_hook(fdf->mlx.win, key_handler, fdf);
	mlx_loop(fdf->mlx.mlx);
	return (1);
}
