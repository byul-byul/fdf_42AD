/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializator_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:39:33 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/04 20:22:38 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static int	init_mlx(t_fdf *f)
{
	f->mlx.mlx = mlx_init();
	if (!f->mlx.mlx)
		return (ERR_CODE_MLX_INIT);
	f->mlx.win = mlx_new_window(f->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (!f->mlx.win)
		return (ERR_CODE_MLX_WIN);
	f->mlx.img = mlx_new_image(f->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!f->mlx.img)
		return (ERR_CODE_MLX_IMG);
	f->mlx.addr = mlx_get_data_addr(f->mlx.img, &f->mlx.bpp, \
									&f->mlx.line_length, &f->mlx.endian);
	if (!f->mlx.addr)
		return (ERR_CODE_MLX_ADDR);
	return (0);
}

static int	init_cell_rows(t_fdf *f)
{
	int	i;

	i = -1;
	while (++i < f->map->height)
	{
		f->map->cells[i] = (t_cell *)malloc(sizeof(t_cell) * f->map->width);
		if (!f->map->cells[i])
			return (ERR_CODE_MEMORY_FAIL);
		f->allocated_cellrow_count++;
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
	f->map->scale = DEFAULT_SCALE;
	f->map->angle_z = DEFAULT_ANGLE;
	f->map->angle_y = DEFAULT_ANGLE;
	f->map->angle_x = DEFAULT_ANGLE;
	f->map->offset_x = WIN_WIDTH / 2;
	f->map->offset_y = WIN_HEIGHT / 2;
	f->map->offset_z = DEFAULT_OFFSET;
	f->map->height = get_file_line_count(path);
	if (0 >= f->map->height)
		return (ERR_CODE_INVALID_MAP_H);
	return (0);
}

int	init_data(t_fdf *f, char *path)
{
	int	error_code;

	f->projection.type = ISOMETRIC;
	error_code = init_map(f, path);
	if (0 == error_code)
		error_code = init_cells(f, path);
	if (0 == error_code)
		error_code = init_mlx(f);
	return (error_code);
}
