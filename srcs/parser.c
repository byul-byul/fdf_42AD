/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:12:55 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/16 22:17:07 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static int	parse_color(char *str)
{
	char	**num_color;
	int		color;

	color = DEFAULT_COLOR;
	num_color = ft_split(str, ',');
	if (num_color)
		if (2 == ft_arrsize(num_color))
			if (ft_strnstr(num_color[1], "0x", 2))
				color = ft_atoi_base(num_color[1] + 2, HEX_BASE);
	if (num_color)
		ft_freearr(num_color, ft_arrsize(num_color));
	return (color);
}

static int	parse_line(t_fdf *f, char *line, int y)
{
	char	**splits;
	int		x;

	if ('\n' == *line)
		return (ERR_CODE_INVALID_MAP_E);
	if (f->map->width != get_column_count(line))
		return (ERR_CODE_INVALID_MAP_R);
	splits = ft_split(line, ' ');
	if (!splits)
		return (ERR_CODE_MEMORY_FAIL);
	x = 0;
	while (splits[x] && x < f->map->width)
	{
		f->map->cells[y][x].z = ft_atoi(splits[x]);
		f->map->cells[y][x].x = x;
		f->map->cells[y][x].y = y;
		f->map->cells[y][x].color = parse_color(splits[x]);
		free(splits[x]);
		x++;
	}
	free(splits);
	return (0);
}

int	parse_arg(t_fdf *f, char *path)
{
	int		fd;
	int		i;
	int		error_code;
	char	*line;

	i = -1;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ERR_CODE_OPEN_FAIL);
	line = get_next_line(fd);
	if (!line)
		error_code = ERR_CODE_GNL;
	while (line)
	{
		error_code = parse_line(f, line, ++i);
		free(line);
		if (error_code)
			break ;
		line = get_next_line(fd);
	}
	close(fd);
	return (error_code);
}
