/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:40:10 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/19 11:01:59 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	perspective_projection(t_cell *c)
{
	double	scale_factor;

	scale_factor = (double)FOCAL_LENGTH / (FOCAL_LENGTH + c->z);
	c->x = ((c->original_x - WIN_WIDTH / 2) * scale_factor + WIN_WIDTH / 2) * SCALE + OFFSET_X;
	c->y = ((c->original_y - WIN_HEIGHT / 2) * scale_factor + WIN_HEIGHT / 2) * SCALE + OFFSET_Y;
}


void	cabinet_projection(t_cell *c)
{
	c->x = c->original_x * SCALE + OFFSET_X;
	c->y = (c->original_y - (int)(c->z * CABINET_FACTOR)) * SCALE + OFFSET_Y;
}

void	cavalier_projection(t_cell *c)
{
	c->x = c->original_x * SCALE + OFFSET_X;
	c->y = (c->original_y - (int)(c->z * CAVALIER_FACTOR)) *SCALE + OFFSET_Y;
}

void	conic_projection(t_cell *c)
{
	double	scale_factor;
	
	scale_factor = 1.0 / (1.0 + CONIC_FACTOR * c->z);
	c->x = (int)(c->original_x * scale_factor * SCALE + OFFSET_X);
	c->y = (int)(c->original_y * scale_factor * SCALE + OFFSET_Y);
}

static void	parallel_projection(t_cell *c)
{
	c->x = c->original_x * SCALE + OFFSET_X;
	c->y = c->original_y * SCALE + OFFSET_Y;
}

static void	isometric_projection(t_cell *c, double iso_angle_x, double iso_angle_y)
{
	int	prev_x;
	int	prev_y;

	prev_x = c->x;
	prev_y = c->y;
	c->x = ((prev_x - prev_y) * cos(iso_angle_x)) * SCALE + OFFSET_X;
	c->y = ((prev_x + prev_y) * sin(iso_angle_y) - c->z) * SCALE + OFFSET_Y;
}

void	apply_projection(t_fdf *f)
{
	int	x;
	int	y;

	y = -1;
	refresh_cells(f);
	while (++y < f->map->height)
	{
		x = -1;
		while (++x < f->map->width)
		{
			if (f->projection.type == ISOMETRIC)
				isometric_projection(&f->map->cells[y][x], ISO_ANGLE_X, ISO_ANGLE_Y);
			else if (f->projection.type == PARALLEL)
				parallel_projection(&f->map->cells[y][x]);
			else if (f->projection.type == CONIC)
				conic_projection(&f->map->cells[y][x]);
			else if (f->projection.type == CAVALIER)
				cavalier_projection(&f->map->cells[y][x]);
			else if (f->projection.type == CABINET)
				cabinet_projection(&f->map->cells[y][x]);
			else if (f->projection.type == PERSPECTIVE)
				perspective_projection(&f->map->cells[y][x]);
		}
	}
}
