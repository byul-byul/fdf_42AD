/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:57:59 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/16 00:14:48 by bhajili          ###   ########.fr       */
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

int	get_file_line_count(char *path)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	int		count;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read)
	{
		i = -1;
		while (++i < bytes_read)
			if (buffer[i] == '\n')
				count++;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
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
		else if (error_code == 3)
			ft_putstr(ERR_MSG_03);
		else if (error_code == 4)
			ft_putstr(ERR_MSG_04);
		else if (error_code == 5)
			ft_putstr(ERR_MSG_05);
		else if (error_code == 6)
			ft_putstr(ERR_MSG_06);
		else
			ft_putstr(ERR_MSG_00);
	}
	else
		ft_putstr(ERR_MSG_00);
}
