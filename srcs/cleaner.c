/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:00:07 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/03 09:07:13 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static void	clean_mlx(t_fdf *f)
{
	if (f->mlx.img)
		mlx_destroy_image(f->mlx.mlx, f->mlx.img);
	if (f->mlx.win)
		mlx_destroy_window(f->mlx.mlx, f->mlx.win);
	if (f->mlx.mlx)
		free(f->mlx.mlx);
}

void	clean_cells(t_cell **cells, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		free(cells[i]);
}

void	clean_data(t_fdf *f)
{
	int	i;

	i = -1;
	while (++i < f->allocated_cellrow_count)
		free(f->map->cells[i]);
	if (f->has_allocated_cells)
		free(f->map->cells);
	if (f->has_allocated_map)
		free(f->map);
	clean_mlx(f);
}
