/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:00:07 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/16 00:00:04 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	clean_cells(t_cell **cells, int count)
{
	int i;

	i = -1;
	while (++i < count)
		free(cells[i]);
}

void	clean_data(t_fdf *f)
{
	int	i;

	i = -1;
	while (++i < f->allocated_cell_count)
		free(f->map->cells[i]);
	if (f->has_allocated_cells)
		free(f->map->cells);
	if (f->has_allocated_map)
		free(f->map);
}
