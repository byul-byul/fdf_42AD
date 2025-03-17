/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:40:10 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/17 14:26:33 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static void	isometric_projection(t_cell *c)
{
	int	prev_x;
	int	prev_y;

	prev_x = c->x;
	prev_y = c->y;
	c->x = ((prev_x - prev_y) * cos(ISO_ANGLE_X)) * SCALE + OFFSET_X;
	c->y = ((prev_x + prev_y) * sin(ISO_ANGLE_Y) - c->z) * SCALE + OFFSET_Y;
}

void	apply_projection(t_fdf *f)
{
	int	x;
	int	y;

	y = -1;
	while (++y < f->map->height)
	{
		x = -1;
		while (++x < f->map->width)
		{
			if (f->projection.type == ISOMETRIC)
				isometric_projection(&f->map->cells[y][x]);
		}
	}
}
