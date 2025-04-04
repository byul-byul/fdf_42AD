/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:18:56 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/04 16:47:05 by bhajili          ###   ########.fr       */
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
	int	i;
	int	j;

	i = -1;
	f->map->scale = DEFAULT_SCALE;
	f->map->offset_x = WIN_WIDTH / 2 - f->map->center_x / 2 * f->map->scale;
	f->map->offset_y = WIN_HEIGHT / 2 - f->map->center_y / 2 * f->map->scale;
	f->map->offset_z = DEFAULT_OFFSET;
	f->map->angle_x = DEFAULT_ANGLE;
	f->map->angle_y = DEFAULT_ANGLE;
	f->map->angle_z = DEFAULT_ANGLE;
	while (++i < f->map->height)
	{
		j = -1;
		while (++j < f->map->width)
		{
			f->map->cells[i][j].x = f->map->cells[i][j].original_x;
			f->map->cells[i][j].y = f->map->cells[i][j].original_y;
			f->map->cells[i][j].z = f->map->cells[i][j].original_z;
		}
	}
}

void	apply_straightforward(t_fdf *f, int keycode)
{
	int	x;
	int	y;
	int	step;

	y = -1;
	if (keycode == H_BUTTON_CODE)
		step = STRAIGHTFORWARD_STEP;
	else if (keycode == L_BUTTON_CODE)
		step = -STRAIGHTFORWARD_STEP;
	else
		return ;
	while (++y < f->map->height)
	{
		x = -1;
		while (++x < f->map->width)
			if (0 != f->map->cells[y][x].original_z)
				f->map->cells[y][x].z += step;
	}
}
