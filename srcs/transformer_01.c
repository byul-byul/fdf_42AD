/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:18:56 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/03 20:09:23 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

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

void	apply_reset(t_fdf *f)
{
	f->map->scale = DEFAULT_SCALE;
	f->map->offset_x = DEFAULT_OFFSET;
	f->map->offset_y = DEFAULT_OFFSET;
	f->map->angle_x = DEFAULT_ANGLE;
	f->map->angle_y = DEFAULT_ANGLE;
	f->map->angle_z = DEFAULT_ANGLE;
}
