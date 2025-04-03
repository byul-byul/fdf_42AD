/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:10:14 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/03 09:11:21 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int	validate_data(t_fdf *f)
{
	if (0 >= f->map->width)
		return (ERR_CODE_INVALID_MAP_W);
	if (0 >= f->map->height)
		return (ERR_CODE_INVALID_MAP_H);
	return (0);
}

static int	is_valid_fdf_file(char *path)
{
	return (ft_strlen(FILE_EXT) == ft_strlen(ft_strstr(path, FILE_EXT)));
}

int	validate_arg(int ac, char **av)
{
	if (ac != 1)
		return (ERR_CODE_ARG_COUNT);
	if (0 == is_valid_fdf_file(av[0]))
		return (ERR_CODE_INVALID_FILE);
	return (0);
}
