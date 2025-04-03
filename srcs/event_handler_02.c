/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler_02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:58:06 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/03 19:26:38 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	handle_zoom_event(t_fdf *f, int keycode)
{
	apply_zoom(f, keycode);
}

void	handle_translation_event(t_fdf *f, int keycode)
{
	apply_translation(f, keycode);
}

void	handle_rotation_event(t_fdf *f, int keycode)
{
	apply_rotation(f, keycode);
}
