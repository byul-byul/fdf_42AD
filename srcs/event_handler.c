/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:58:06 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/03 15:36:56 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	apply_zoom(t_fdf *f, int keycode)
{
	if (PLUS_BUTTON_CODE == keycode)
		f->map->scale += ZOOM_STEP;
	if (MINUS_BUTTON_CODE == keycode)
		f->map->scale -= ZOOM_STEP;
	apply_projection(f);
}

static void	handle_zoom_event(t_fdf *f, int keycode)
{
	apply_zoom(f, keycode);
	draw_fdf(f);
}

static void	handle_projection_event(t_fdf *f)
{
	if (f->projection.type == ISOMETRIC)
		f->projection.type = PARALLEL;
	else if (f->projection.type == PARALLEL)
		f->projection.type = ISOMETRIC;
	//else if (f->projection.type == CONIC)
	//	f->projection.type = CAVALIER;
	//else if (f->projection.type == CAVALIER)
	//	f->projection.type = CABINET;
	//else if (f->projection.type == CABINET)
	//	f->projection.type = PERSPECTIVE;
	//else if (f->projection.type == PERSPECTIVE)
	//	f->projection.type = ISOMETRIC;
	//refresh_image(f);
	apply_projection(f);
	draw_fdf(f);
}

static int	is_rotation_event(int keycode)
{
	if (W_BUTTON_CODE == keycode)
		return (1);
	if (S_BUTTON_CODE == keycode)
		return (1);
	if (D_BUTTON_CODE == keycode)
		return (1);
	if (A_BUTTON_CODE == keycode)
		return (1);
	if (Q_BUTTON_CODE == keycode)
		return (1);
	if (E_BUTTON_CODE == keycode)
		return (1);
	return (0);
}

static void	handle_rotation_event(t_fdf *f, int keycode)
{
	apply_rotation(f, keycode);
	draw_fdf(f);
}

static void	handle_escape_event(t_fdf *f)
{
	clean_data(f);
	exit(0);
}

int	handle_event(int keycode, t_fdf *f)
{
	printf("keycode = %d\n", keycode);
	if (ESC_BUTTON_CODE == keycode)
		handle_escape_event(f);
	else if (PROJ_BUTTON_CODE == keycode)
		handle_projection_event(f);
	else if (is_rotation_event(keycode))
		handle_rotation_event(f, keycode);
	else if (PLUS_BUTTON_CODE == keycode ||
			MINUS_BUTTON_CODE == keycode)
		handle_zoom_event(f, keycode);
	return (0);
}