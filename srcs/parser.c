/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:12:55 by bhajili           #+#    #+#             */
/*   Updated: 2024/12/30 09:03:32 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static void	clean_map(int **arr, int size)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	while (++i < size)
		if (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
		}
	free(arr);
	arr = NULL;
}

//static int	get_col_count(char *row)
//{
//	int	count;

//	count = 0;
//	while (*row && *row != '\n' && (ft_isspace(*row) || ft_isdigit(*row)))
//	{
//		while (ft_isspace(*row))
//			row++;
//		if (*row == '-' || *row == '+')
//			row++;
//		while (ft_isdigit(*row))
//			row++;
//		if (ft_isdigit(*(row - 1)))
//			count++;
//	}
//	return (count);
//}

//static int	parse_map_row(int *map_row, char *row)
//{
//	int	i;
//	int	col_count;

//	i = -1;
//	col_count = 0;
//	if (!row)
//		return (0);
//	col_count = get_col_count(row);
//	if (col_count <= 0)
//		return (0);
//	map_row = (int *)malloc(sizeof(int) * col_count);
//	if (map_row)
//	{
//		while (++i < col_count)
//		{
//			map_row[i] = ft_atoi(row);
//			while (ft_isspace(*row))
//				row++;
//			if (*row == '-' || *row == '+')
//				row++;
//			while (ft_isdigit(*row))
//				row++;
//		}
//		return (col_count);
//	}
//	return (0);
//}
static int	parse_map_row(t_fdf *fdf, char *row, int i)
{
	fdf += 0;
	row += 0;
	i += 0;
	ft_printf("row was parsed.\n");
	return (1);
}

static int	parse_map(t_fdf *fdf, int fd)
{
	int		i;
	char	*line;

	i = -1;
	fdf->map.map = (int **)malloc(sizeof(int *) * fdf->map.row_count);
	if (!(fdf->map.map))
		return (fdf->error = 3, 0);
	while (++i < fdf->map.row_count)
	{
		line = get_next_line(fd);
		if (line)
		{
			if (parse_map_row(fdf, line, i))
			{
				free(line);
				continue ;
			}
			return (free(line), clean_map(fdf->map.map, i), fdf->error = 5, 0);
		}
	}
	return (1);
}

static int	get_row_count(t_fdf *fdf, int fd)
{
	char	*line;

	line = NULL;
	fdf->map.row_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			if (line[0] == '\n')
				return (free(line), fdf->error = 4, 0);
			fdf->map.row_count++;
			free(line);
		}
		else
			break ;
	}
	if (fdf->map.row_count == 0)
		fdf->error = 3;
	return (fdf->map.row_count);
}

int	parse_arg(t_fdf *fdf, char *arg)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (fdf->error = 3, 0);
	if (get_row_count(fdf, fd))
	{
		close(fd);
		fd = open(arg, O_RDONLY);
		if (fd < 0)
			return (fdf->error = 3, 0);
		if (parse_map(fdf, fd))
			return (close(fd), 1);
	}
	return (close(fd), 0);
}
