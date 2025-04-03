/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer_00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:18:56 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/03 20:59:13 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	apply_offset(t_fdf *f)
{
	int	x;
	int	y;

	y = -1;
	while (++y < f->map->height)
	{
		x = -1;
		while (++x < f->map->width)
		{
			f->map->cells[y][x].x += \
				f->map->offset_x - f->map->center_x / 2 * f->map->scale;
			f->map->cells[y][x].y += \
				f->map->offset_y - f->map->center_y / 2 * f->map->scale;
		}
	}
}

void	apply_zoom(t_fdf *f, int keycode)
{
	if (PLUS_BUTTON_CODE == keycode)
		f->map->scale += ZOOM_STEP;
	if (MINUS_BUTTON_CODE == keycode)
		f->map->scale -= ZOOM_STEP;
}

void	apply_translation(t_fdf *f, int keycode)
{
	if (UP_BUTTON_CODE == keycode)
		f->map->offset_y -= TRANSLATION_STEP;
	if (DOWN_BUTTON_CODE == keycode)
		f->map->offset_y += TRANSLATION_STEP;
	if (RIGHT_BUTTON_CODE == keycode)
		f->map->offset_x += TRANSLATION_STEP;
	if (LEFT_BUTTON_CODE == keycode)
		f->map->offset_x -= TRANSLATION_STEP;
}

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
}
