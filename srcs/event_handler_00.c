/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:58:06 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/04 19:35:59 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

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

static int	is_translation_event(int keycode)
{
	if (UP_BUTTON_CODE == keycode)
		return (1);
	if (DOWN_BUTTON_CODE == keycode)
		return (1);
	if (RIGHT_BUTTON_CODE == keycode)
		return (1);
	if (LEFT_BUTTON_CODE == keycode)
		return (1);
	return (0);
}

static int	is_zoom_event(int keycode)
{
	if (PLUS_BUTTON_CODE == keycode)
		return (1);
	if (MINUS_BUTTON_CODE == keycode)
		return (1);
	return (0);
}

static int	is_straightforward_event(int keycode)
{
	if (H_BUTTON_CODE == keycode)
		return (1);
	if (L_BUTTON_CODE == keycode)
		return (1);
	return (0);
}

int	handle_event(int keycode, t_fdf *f)
{
	if (ESC_BUTTON_CODE == keycode)
		handle_escape_event(f);
	else if (PROJ_BUTTON_CODE == keycode)
		handle_projection_event(f);
	else if (RESET_BUTTON_CODE == keycode)
		handle_reset_event(f);
	else if (is_rotation_event(keycode))
		handle_rotation_event(f, keycode);
	else if (is_translation_event(keycode))
		handle_translation_event(f, keycode);
	else if (is_zoom_event(keycode))
		handle_zoom_event(f, keycode);
	else if (is_straightforward_event(keycode))
		handle_straightforward_event(f, keycode);
	draw_fdf(f);
	return (0);
}
