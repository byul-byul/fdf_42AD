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

// static void	show_data(t_fdf f)
// {
// 	int	y;
// 	int	x;

// 	y = -1;
// 	ft_printf("f.has_allocated_map = %d\n", f.has_allocated_map);
// 	ft_printf("f.has_allocated_cells = %d\n", f.has_allocated_cells);
// 	ft_printf("f.allocated_cellrow_count = %d\n", f.allocated_cellrow_count);
// 	ft_printf("f.map->file_path = %s\n", f.map->file_path);
// 	ft_printf("f.map->width = %d\n", f.map->width);
// 	ft_printf("f.map->height = %d\n", f.map->height);
// 	while (++y < f.map->height)
// 	{
// 		x = -1;
// 		while (++x < f.map->width)
// 			ft_printf("%02d,%02d,%02d(%08d) ", f.map->cells[y][x].x, f.map->cells[y][x].y, f.map->cells[y][x].z, f.map->cells[y][x].color);
// 		ft_printf("\n");
// 	}
// }

static void	isometric_projection(t_cell *c)
{
	int prev_x = c->x;
	int prev_y = c->y;

	c->x = (prev_x - prev_y) * cos(0.523599);
	c->y = (prev_x + prev_y) * sin(0.523599) - c->z;

	// printf("Projected: (%d, %d, %d) -> (%d, %d)\n",
		// prev_x, prev_y, c->z, c->x, c->y);
}

void	apply_projection(t_fdf *f)
{
	int	x;
	int	y;
	int	offset_x;
	int	offset_y;

	offset_x = WIN_WIDTH / 50;
	offset_y = WIN_HEIGHT / 50;

	y = -1;
	while (++y < f->map->height)
	{
		x = -1;
		while (++x < f->map->width)
		{
			if (f->projection.type == ISOMETRIC)
				isometric_projection(&f->map->cells[y][x]);
			// else if (f->projection.type == PARALLEL)
			// 	parallel_projection(&f->map->cells[y][x]); // Добавим позже

			f->map->cells[y][x].x += offset_x;
			f->map->cells[y][x].y += offset_y;
		}
	}
}

// static void	put_pixel(t_fdf *f, int x, int y, int color)
// {
// 	char	*dst;

// 	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
// 		return;
// 	dst = f->mlx.addr + (y * f->mlx.line_length + x * (f->mlx.bpp / 8));
// 	*(unsigned int *)dst = color;
// }

// static void	bresenham(t_fdf *f, t_cell a, t_cell b)
// {
// 	int	dx;
// 	int	dy;
// 	int	sx;
// 	int	sy;
// 	int	err;
// 	int	e2;

// 	// Масштабируем точки перед расчетами
// 	a.x *= SCALE;
// 	a.y *= SCALE;
// 	b.x *= SCALE;
// 	b.y *= SCALE;

// 	dx = abs(b.x - a.x);
// 	dy = -abs(b.y - a.y);
// 	sx = (a.x < b.x) ? 1 : -1;
// 	sy = (a.y < b.y) ? 1 : -1;
// 	err = dx + dy;

// 	while (1)
// 	{
// 		put_pixel(f, a.x, a.y, a.color);
// 		if (a.x == b.x && a.y == b.y)
// 			break;
// 		e2 = 2 * err;
// 		if (e2 >= dy)
// 		{
// 			err += dy;
// 			a.x += sx;
// 		}
// 		if (e2 <= dx)
// 		{
// 			err += dx;
// 			a.y += sy;
// 		}
// 	}
// }

// void	draw_line(t_fdf *f, t_cell a, t_cell b)
// {
// 	bresenham(f, a, b);
// }

static void	my_mlx_pixel_put(t_fdf *f, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return;
	dst = f->mlx.addr + (y * f->mlx.line_length + x * (f->mlx.bpp / 8));
	*(unsigned int *)dst = color;
}

static void	draw_line(t_fdf *f, t_cell a, t_cell b)
{
	int	dx = abs(b.x - a.x);
	int	dy = abs(b.y - a.y);
	int	sx = (a.x < b.x) ? 1 : -1;
	int	sy = (a.y < b.y) ? 1 : -1;
	int	err = dx - dy;
	int	e2;

	while (1)
	{
		my_mlx_pixel_put(f, a.x * SCALE, a.y * SCALE, a.color); // Используем цвет из `a`
		if (a.x == b.x && a.y == b.y)
			break;
		e2 = err * 2;
		if (e2 > -dy)
		{
			err -= dy;
			a.x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			a.y += sy;
		}
	}
}

void	draw_fdf(t_fdf *f)
{
	int	x;
	int	y;

	y = -1;
	apply_projection(f);
	while (++y < f->map->height)
	{
		x = -1;
		while (++x < f->map->width)
		{
			if (x < f->map->width - 1)
				draw_line(f, f->map->cells[y][x], f->map->cells[y][x + 1]); // Горизонтальные линии
			if (y < f->map->height - 1)
				draw_line(f, f->map->cells[y][x], f->map->cells[y + 1][x]); // Вертикальные линии
		}
	}
	mlx_put_image_to_window(f->mlx.mlx, f->mlx.win, f->mlx.img, 0, 0);
}

// int	do_fdf(t_fdf *f)
// {
// 	apply_projection(f); // Применяем проекцию к карте
// 	draw_fdf(f); // Рисуем карту
// 	mlx_loop(f->mlx.mlx); // Запускаем цикл обработки событий MiniLibX
// 	return (0);
// }

void	fdf(int ac, char **av)
{
	t_fdf	f;
	int		error_code;

	error_code = validate_arg(ac, av);
	if (0 == error_code)
		error_code = init_data(&f, av[0]);
	if (0 == error_code)
		error_code = parse_arg(&f, av[0]);
	if (0 == error_code)
		error_code = validate_data(&f);
	draw_fdf(&f);
	mlx_loop(f.mlx.mlx);
	print_error(error_code);
	clean_data(&f);
}
