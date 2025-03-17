/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:10:14 by bhajili           #+#    #+#             */
/*   Updated: 2025/03/16 22:33:17 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

// static int	is_valid_row_size(t_fdf *fdf)
// {
// 	int		i;

// 	i = 0;
// 	while (++i < fdf->map.row_count)
// 		if (fdf->map.rows[i].row_size != fdf->map.rows[0].row_size)
// 			return (clean_rows(fdf->map.rows, fdf->map.row_count), 
// 					fdf->error = 8, 0);
// 	return (1);
// }

int	validate_data(t_fdf *f)
{
	if (0 >= f->map->width)
		return (ERR_CODE_INVALID_MAP_W);
	if (0 >= f->map->height)
		return (ERR_CODE_INVALID_MAP_H);
	return (0);
}

static int	is_valid_file(char *path)
{
	return (ft_strlen(FILE_EXT) == ft_strlen(ft_strstr(path, FILE_EXT)));
}

int	validate_arg(int ac, char **av)
{
	if (ac != 1)
		return (ERR_CODE_ARG_COUNT);
	if (0 == is_valid_file(av[0]))
		return (ERR_CODE_INVALID_FILE);
	return (0);
}
