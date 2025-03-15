/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:12:55 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/15 23:51:46 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int	parse_arg(t_fdf *f, char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ERR_CODE_OPEN_FAIL);
	line = get_next_line(fd);
	while (line)
	{
		if ('\n' == *line || f->map->width != get_column_count(line))
		{
			free(line);
			close(fd);
			if ('\n' == *line)
				return (ERR_CODE_INVALID_MAP_E);
			return (ERR_CODE_INVALID_MAP_R);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
