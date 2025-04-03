/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:58:06 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/03 20:56:18 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	handle_reset_event(t_fdf *f)
{
	apply_reset(f);
	apply_projection(f);
	apply_offset(f);
}

void	handle_projection_event(t_fdf *f)
{
	if (f->projection.type == ISOMETRIC)
		f->projection.type = PARALLEL;
	else if (f->projection.type == PARALLEL)
		f->projection.type = ISOMETRIC;
	apply_projection(f);
	apply_offset(f);
}

void	handle_escape_event(t_fdf *f)
{
	clean_data(f);
	exit(0);
}
