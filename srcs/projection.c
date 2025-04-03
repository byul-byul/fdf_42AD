/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:40:10 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/03 19:20:17 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

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
			f->map->cells[y][x].x = f->map->cells[y][x].original_x * f->map->scale;
			f->map->cells[y][x].y = f->map->cells[y][x].original_y * f->map->scale;
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
