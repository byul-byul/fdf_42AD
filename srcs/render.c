/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:08:42 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/03 12:34:51 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static void	refresh_image(t_fdf *f)
{
	mlx_clear_window(f->mlx.mlx, f->mlx.win);
	if (f->mlx.img)
		mlx_destroy_image(f->mlx.mlx, f->mlx.img);
	f->mlx.img = mlx_new_image(f->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	f->mlx.addr = mlx_get_data_addr(f->mlx.img, &f->mlx.bpp, \
					&f->mlx.line_length, &f->mlx.endian);
}

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
	line->dx = ft_abs(b.x - a.x);
	line->dy = ft_abs(b.y - a.y);
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

void	draw_fdf(t_fdf *f)
{
	int	x;
	int	y;

	y = -1;
	refresh_image(f);
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
