/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:39:33 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/16 00:30:07 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static int	init_cell_rows(t_fdf *f)
{
	int	i;

	i = -1;
	f->allocated_cell_count = 0;
	while (++i < f->map->height)
	{
		f->map->cells[i] = (t_cell *)malloc(sizeof(t_cell) * f->map->width);
		if (!f->map->cells[i])
			return (ERR_CODE_MEMORY_FAIL);
		f->allocated_cell_count++;
	}
	return (0);
}

static int	init_cells(t_fdf *f, char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ERR_CODE_OPEN_FAIL);
	f->map->cells = (t_cell **)malloc(sizeof(t_cell *) * f->map->height);
	if (!f->map->cells)
		return (ERR_CODE_MEMORY_FAIL);
	f->has_allocated_cells = 1;
	line = get_next_line(fd);
	if (NULL == line)
		return (ERR_CODE_GNL);
	f->map->width = get_column_count(line);
	free(line);
	if (0 >= f->map->width)
		return (ERR_CODE_INVALID_MAP_W);
	return (init_cell_rows(f));
}

static int	init_map(t_fdf *f, char *path)
{
	f->map = (t_map *)malloc(sizeof(t_map));
	if (!f->map)
		return (ERR_CODE_MEMORY_FAIL);
	f->has_allocated_map = 1;
	f->map->file_path = path;
	f->map->height = get_file_line_count(path);
	if (0 >= f->map->height)
		return (ERR_CODE_INVALID_MAP_H);
	return (0);
}

int	init_data(t_fdf *f, char *path)
{
	int	error_code;

	f->has_allocated_map = 0;
	f->has_allocated_cells = 0;
	error_code = init_map(f, path);
	if (0 == error_code)
		error_code = init_cells(f, path);
	return (error_code);
}
