/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:58:06 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/03 19:26:48 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	handle_reset_event(t_fdf *f)
{
	f->map->scale = DEFAULT_SCALE;
	f->map->offset_x = DEFAULT_OFFSET;
	f->map->offset_y = DEFAULT_OFFSET;
	f->map->angle_x = DEFAULT_ANGLE;
	f->map->angle_y = DEFAULT_ANGLE;
	f->map->angle_z = DEFAULT_ANGLE;
	apply_projection(f);
}

void	handle_projection_event(t_fdf *f)
{
	if (f->projection.type == ISOMETRIC)
		f->projection.type = PARALLEL;
	else if (f->projection.type == PARALLEL)
		f->projection.type = ISOMETRIC;
	apply_projection(f);
}

void	handle_escape_event(t_fdf *f)
{
	clean_data(f);
	exit(0);
}
