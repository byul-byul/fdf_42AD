/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:57:59 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/04 20:33:42 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static void	handle_color(char **row)
{
	while (**row == ',')
		(*row)++;
	if (ft_strnstr(*row, "0x", 2))
		*row += 2;
	while (ft_isxdigit(**row))
		(*row)++;
}

int	get_column_count(char *row)
{
	int	size;

	size = 0;
	while (*row && *row != '\n')
	{
		while (ft_isspace(*row))
			row++;
		if (ft_issign(*row))
			row++;
		if (ft_isdigit(*row))
		{
			while (ft_isdigit(*row))
				row++;
			if (*row == ',')
				handle_color(&row);
			size++;
		}
		else if (*row != '\0')
			return (-1);
	}
	return (size);
}

static int	count_lines_in_buffer(char *buffer, int bytes_read)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < bytes_read)
		if (buffer[i] == '\n')
			count++;
	return (count);
}

int	get_file_line_count(char *path)
{
	int		fd;
	int		count;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		count += count_lines_in_buffer(buffer, bytes_read);
	}
	close(fd);
	return (count);
}
