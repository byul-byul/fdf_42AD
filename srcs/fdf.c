/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:08:42 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/18 11:49:48 by bhajili          ###   ########.fr       */
/*                                                                            */
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

static void	my_mlx_pixel_put(t_fdf *f, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = f->mlx.addr + (y * f->mlx.line_length + x * (f->mlx.bpp / 8));
	*(unsigned int *)dst = color;
}

static void	init_line_vars(t_cell a, t_cell b, t_line *line)
{
	line->dx = abs(b.x - a.x);
	line->dy = abs(b.y - a.y);
	line->sx = a.x < b.x;
	line->sy = a.y < b.y;
	if (0 == line->sx)
		line->sx = -1;
	if (0 == line->sy)
		line->sy = -1;
	line->err = line->dx - line->dy;
}

static void	draw_line(t_fdf *f, t_cell a, t_cell b)
{
	t_line	line;
	int		e2;

	init_line_vars(a, b, &line);
	while (1)
	{
		my_mlx_pixel_put(f, a.x, a.y, a.color);
		if (a.x == b.x && a.y == b.y)
			break ;
		e2 = line.err * 2;
		if (e2 > -line.dy)
		{
			line.err -= line.dy;
			a.x += line.sx;
		}
		if (e2 < line.dx)
		{
			line.err += line.dx;
			a.y += line.sy;
		}
	}
}

static void	draw_fdf(t_fdf *f)
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
				draw_line(f, f->map->cells[y][x], f->map->cells[y][x + 1]);
			if (y < f->map->height - 1)
				draw_line(f, f->map->cells[y][x], f->map->cells[y + 1][x]);
		}
	}
	mlx_put_image_to_window(f->mlx.mlx, f->mlx.win, f->mlx.img, 0, 0);
}

void	fdf(int ac, char **av)
{
	t_fdf	f;
	int		error_code;

	error_code = validate_arg(ac, av);
	if (0 == error_code)
		error_code = init_data(&f, av[0]);
	if (0 == error_code)
		error_code = parse_arg(&f, av[0]);
	// show_data(f);
	if (0 == error_code)
		error_code = validate_data(&f);
	if (0 == error_code)
	{
		define_min_max_z(&f);
		apply_gradient(&f);
		draw_fdf(&f);
		mlx_loop(f.mlx.mlx);
	}
	print_error(error_code);
	clean_data(&f);
}
