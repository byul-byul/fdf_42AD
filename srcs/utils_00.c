/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:57:59 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/19 11:45:59 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int	ft_abs(int a)
{
	if (a > 0)
		return (a);
	return (-a);
}

void	refresh_cells(t_fdf *f)
{
	int	y;
	int	x;

	y = -1;
	while (++y < f->map->height)
	{
		x = -1;
		while (++x < f->map->width)
		{
			f->map->cells[y][x].x = f->map->cells[y][x].original_x;
			f->map->cells[y][x].y = f->map->cells[y][x].original_y;
		}
	}
}

void	define_min_max_z(t_fdf *f)
{
	int	x;
	int	y;

	f->map->min_z = INT_MAX;
	f->map->max_z = INT_MIN;

	y = -1;
	while (++y < f->map->height)
	{
		x = -1;
		while (++x < f->map->width)
		{
			if (f->map->cells[y][x].z < f->map->min_z)
				f->map->min_z = f->map->cells[y][x].z;
			if (f->map->cells[y][x].z > f->map->max_z)
				f->map->max_z = f->map->cells[y][x].z;
		}
	}
}

int	get_column_count(char *row)
{
	int	size;

	size = 0;
	while (*row && *row != '\n')
	{
		while (ft_isspace(*row))
			row++;
		if (*row == '-' || *row == '+')
			row++;
		if (ft_isdigit(*row))
		{
			while (ft_isdigit(*row))
				row++;
			if (*row == ',')
			{
				while (*row == ',')
					row++;
				if (ft_strnstr(row, "0x", 2))
					row += 2;
				while (ft_isxdigit(*row))
					row++;
			}
			size++;
		}
		else if (*row != '\0')
			return (-1);
	}
	return (size);
}

size_t	ft_arrsize(char **arr)
{
	size_t	size;

	size = 0;
	while (arr[size])
		size++;
	return (size);
}

int	get_file_line_count(char *path)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	int		count;
	char	last_char;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	last_char = '\n';
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		for (int i = 0; i < bytes_read; i++)
		{
			if (buffer[i] == '\n')
				count++;
			last_char = buffer[i];
		}
	}
	if (last_char != '\n')
		count++;
	close(fd);
	return (count);
}

void	print_error(int error_code)
{
	if (0 == error_code)
		return ;
	if (ERR_MSG_ENABLED == TRUE)
	{
		if (ERR_CODE_ARG_COUNT == error_code)
			ft_putstr(ERR_MSG_01);
		else if (ERR_CODE_INVALID_FILE == error_code)
			ft_putstr(ERR_MSG_02);
		else if (ERR_CODE_MEMORY_FAIL == error_code)
			ft_putstr(ERR_MSG_03);
		else if (ERR_CODE_OPEN_FAIL == error_code)
			ft_putstr(ERR_MSG_04);
		else if (ERR_CODE_INVALID_MAP_H == error_code)
			ft_putstr(ERR_MSG_05);
		else if (ERR_CODE_INVALID_MAP_E == error_code)
			ft_putstr(ERR_MSG_06);
		else if (ERR_CODE_INVALID_MAP_R == error_code)
			ft_putstr(ERR_MSG_07);
		else if (ERR_CODE_INVALID_MAP_W == error_code)
			ft_putstr(ERR_MSG_08);
		else if (ERR_CODE_GNL == error_code)
			ft_putstr(ERR_MSG_09);
		else if (ERR_CODE_MLX_INIT == error_code)
			ft_putstr(ERR_MSG_10);
		else if (ERR_CODE_MLX_WIN == error_code)
			ft_putstr(ERR_MSG_11);
		else if (ERR_CODE_MLX_IMG == error_code)
			ft_putstr(ERR_MSG_12);
		else if (ERR_CODE_MLX_ADDR == error_code)
			ft_putstr(ERR_MSG_13);
		else
			ft_putstr(ERR_MSG_00);
	}
	else
		ft_putstr(ERR_MSG_00);
}
