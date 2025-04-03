/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:17:12 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/03 09:08:02 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static int	interpolate_color(double ratio)
{
	int	r;
	int	g;
	int	b;

	r = ((COLOR_MAX >> 16) & COLOR_MASK) * ratio + \
		((COLOR_MIN >> 16) & COLOR_MASK) * (1 - ratio);
	g = ((COLOR_MAX >> 8) & COLOR_MASK) * ratio + \
		((COLOR_MIN >> 8) & COLOR_MASK) * (1 - ratio);
	b = (COLOR_MAX & COLOR_MASK) * ratio + \
		(COLOR_MIN & COLOR_MASK) * (1 - ratio);
	return ((r << 16) | (g << 8) | b);
}

void	apply_gradient(t_fdf *f)
{
	int		x;
	int		y;
	double	ratio;

	y = -1;
	while (++y < f->map->height)
	{
		x = -1;
		while (++x < f->map->width)
		{
			if (f->map->cells[y][x].color != 0)
				continue ;
			if (f->map->max_z == f->map->min_z)
				ratio = 0;
			else
				ratio = (double)(f->map->cells[y][x].z - f->map->min_z) / \
						(f->map->max_z - f->map->min_z);
			f->map->cells[y][x].color = \
					interpolate_color(ratio);
		}
	}
}
