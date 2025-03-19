/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:58:06 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/19 08:37:58 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static void	refresh_image(t_fdf *f)
{
	mlx_clear_window(f->mlx.mlx, f->mlx.win);
	if (f->mlx.img)
		mlx_destroy_image(f->mlx.mlx, f->mlx.img);
	f->mlx.img = mlx_new_image(f->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	f->mlx.addr = mlx_get_data_addr(f->mlx.img, &f->mlx.bpp, \
					&f->mlx.line_length, &f->mlx.endian);
}

static void	handle_projection_change(t_fdf *f)
{
	if (f->projection.type == ISOMETRIC)
		f->projection.type = PARALLEL;
	else if (f->projection.type == PARALLEL)
		f->projection.type = CONIC;
	else if (f->projection.type == CONIC)
		f->projection.type = CAVALIER;
	else if (f->projection.type == CAVALIER)
		f->projection.type = CABINET;
	else if (f->projection.type == CABINET)
		f->projection.type = PERSPECTIVE;
	else if (f->projection.type == PERSPECTIVE)
		f->projection.type = ISOMETRIC;
	refresh_image(f);
	apply_projection(f);
	draw_fdf(f);
}

static void	handle_escape_event(t_fdf *f)
{
	clean_data(f);
	exit(0);
}

int	handle_key(int keycode, t_fdf *f)
{
	if (ESC_BUTTON_CODE == keycode)
		handle_escape_event(f);
	else if (PROJ_BUTTON_CODE == keycode)
		handle_projection_change(f);
	return (0);
}
