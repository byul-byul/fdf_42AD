/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:40:10 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/04 18:29:52 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	perspective_projection(t_fdf *f)
{
	int		x;
	int		y;
	double	scale_factor;


	y = -1;
	while (++y < f->map->height)
	{
		x = -1;
		while (++x < f->map->width)
		{
			scale_factor = FOCAL_LEN / (FOCAL_LEN + f->map->cells[y][x].z);
			f->map->cells[y][x].x = \
			((f->map->cells[y][x].original_x - WIN_WIDTH / 2) \
			* scale_factor + WIN_WIDTH / 2) * f->map->scale;
			f->map->cells[y][x].y = \
			((f->map->cells[y][x].original_y - WIN_WIDTH / 2) \
			* scale_factor + WIN_WIDTH / 2) * f->map->scale;
		}
	}
}

void	conic_projection(t_fdf *f)
{
	int		x;
	int		y;
	double	scale_factor;


	y = -1;
	while (++y < f->map->height)
	{
		x = -1;
		while (++x < f->map->width)
		{
			scale_factor = CONIC_FACTOR_02 / \
			(CONIC_FACTOR_02 + CONIC_FACTOR_01 * f->map->cells[y][x].z);
			f->map->cells[y][x].x = \
				f->map->cells[y][x].original_x * scale_factor * f->map->scale;
			f->map->cells[y][x].y = \
				f->map->cells[y][x].original_y * scale_factor * f->map->scale;
		}
	}
}

void	parallel_projection(t_fdf *f)
{
	int	x;
	int	y;

	y = -1;
	while (++y < f->map->height)
	{
		x = -1;
		while (++x < f->map->width)
		{
			f->map->cells[y][x].x = \
				f->map->cells[y][x].original_x * f->map->scale;
			f->map->cells[y][x].y = \
				f->map->cells[y][x].original_y * f->map->scale;
		}
	}
}

void	isometric_projection(t_fdf *f)
{
	int	x;
	int	y;

	y = -1;
	while (++y < f->map->height)
	{
		x = -1;
		while (++x < f->map->width)
		{
			f->map->cells[y][x].x = \
			((f->map->cells[y][x].original_x - f->map->cells[y][x].original_y) \
			* cos(f->map->angle_x)) * f->map->scale;
			f->map->cells[y][x].y = \
			((f->map->cells[y][x].original_x + f->map->cells[y][x].original_y) \
			* sin(f->map->angle_y) - f->map->cells[y][x].z) * f->map->scale;
		}
	}
}
