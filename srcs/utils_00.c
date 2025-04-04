/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:57:59 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/04 19:43:21 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

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
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
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
