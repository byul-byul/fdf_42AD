/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer_00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:18:56 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/03 19:31:30 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	apply_rotation(t_fdf *f, int keycode)
{
	if (keycode == W_BUTTON_CODE)
		rotate_x(f, POSITIVE_ROTATION);
	else if (keycode == S_BUTTON_CODE)
		rotate_x(f, NEGATIVE_ROTATION);
	else if (keycode == D_BUTTON_CODE)
		rotate_y(f, POSITIVE_ROTATION);
	else if (keycode == A_BUTTON_CODE)
		rotate_y(f, NEGATIVE_ROTATION);
	else if (keycode == Q_BUTTON_CODE)
		rotate_z(f, POSITIVE_ROTATION);
	else if (keycode == E_BUTTON_CODE)
		rotate_z(f, NEGATIVE_ROTATION);
}

void	apply_projection(t_fdf *f)
{
	if (f->projection.type == ISOMETRIC)
		isometric_projection(f);
	else if (f->projection.type == PARALLEL)
		parallel_projection(f);
	apply_offset(f);
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
