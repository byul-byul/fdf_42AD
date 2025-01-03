/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:12:55 by bhajili           #+#    #+#             */
/*   Updated: 2025/01/03 19:41:53 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static int	get_row_size(char *row)
{
	int	size;

	size = 0;
	while (*row && *row != '\n')
	{
		while (ft_isspace(*row))
			row++;
		if (*row == '-' || *row == '+')
			row++;
		while (ft_isdigit(*row))
			row++;
		if (ft_isdigit(*(row - 1)))
			size++;
		if (ft_isspace(*row) || ft_isdigit(*row) \
			|| *row == '-' || *row == '+' \
			|| *row == '\n' || *row == '\0')
			continue ;
		else
			return (0);
	}
	return (size);
}

static int	parse_map_row(t_row	*map_row, char *row)
{
	int	i;

	i = -1;
	map_row->row_size = get_row_size(row);
	if (map_row->row_size == 0)
		return (0);
	map_row->row = (int *)malloc(sizeof(int) * map_row->row_size);
	if (!(map_row->row))
		return (0);
	while (++i < map_row->row_size)
	{
		map_row->row[i] = ft_atoi(row);
		while (ft_isspace(*row))
			row++;
		if (*row == '-' || *row == '+')
			row++;
		while (ft_isdigit(*row))
			row++;
	}
	return (map_row->row_size);
}

static int	parse_map(t_fdf *fdf, char *path)
{
	int		i;
	int		fd;
	char	*line;

	i = -1;
	line = path;
	fdf->map.scale = SCALE;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (fdf->error = 3, 0);
	fdf->map.rows = (t_row *)malloc(sizeof(t_row) * fdf->map.row_count);
	if (!(fdf->map.rows))
		return (fdf->error = 9, 0);
	while (++i < fdf->map.row_count && line)
	{
		line = get_next_line(fd);
		if (line)
		{
			if (parse_map_row(&(fdf->map.rows[i]), line))
				free(line);
			else
				return (close(fd), free(line), fdf->error = 6, \
						clean_rows(fdf->map.rows, i), 0);
		}
	}
	return (close(fd), 1);
}

static int	set_row_count(t_fdf *fdf, char *path)
{
	char	*line;
	int		fd;

	line = path;
	fdf->map.row_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (fdf->error = 3, 0);
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			if (line[0] == '\n')
				return (close(fd), free(line), fdf->error = 4, 0);
			fdf->map.row_count++;
			free(line);
		}
	}
	if (fdf->map.row_count == 0)
		fdf->error = 5;
	return (close(fd), fdf->map.row_count);
}

int	parse_arg(t_fdf *fdf, char *arg)
{
	int	i;

	i = 0;
	if (set_row_count(fdf, arg))
		if (parse_map(fdf, arg))
			return (1);
	return (0);
}
