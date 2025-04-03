/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:18:56 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/03 19:31:49 by bhajili          ###   ########.fr       */
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
			f->map->cells[y][x].x += f->map->offset_x;
			f->map->cells[y][x].y += f->map->offset_y;
		}
	}
}

void	apply_zoom(t_fdf *f, int keycode)
{
	if (PLUS_BUTTON_CODE == keycode)
		f->map->scale += ZOOM_STEP;
	if (MINUS_BUTTON_CODE == keycode)
		f->map->scale -= ZOOM_STEP;
	apply_projection(f);
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
	apply_projection(f);
}
