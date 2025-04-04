/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:57:59 by bhajili           #+#    #+#             */
/*   Updated: 2025/04/04 19:43:24 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

static void	print_error_02(int error_code)
{
	if (ERR_CODE_MLX_WIN == error_code)
		ft_putstr(ERR_MSG_11);
	else if (ERR_CODE_MLX_IMG == error_code)
		ft_putstr(ERR_MSG_12);
	else if (ERR_CODE_MLX_ADDR == error_code)
		ft_putstr(ERR_MSG_13);
}

static void	print_error_01(int error_code)
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
}

void	print_error(int error_code)
{
	if (0 == error_code)
		return ;
	ft_putstr(ERR_MSG_00);
	if (ERR_MSG_ENABLED == TRUE)
	{
		print_error_01(error_code);
		print_error_02(error_code);
	}
}

void	define_offset(t_fdf *f)
{
	f->map->offset_x -= f->map->center_x / 2 * f->map->scale;
	f->map->offset_y -= f->map->center_y / 2 * f->map->scale;
	f->map->offset_z -= f->map->center_z / 2 * f->map->scale;
}

void	define_map_constants(t_fdf *f)
{
	int	x;
	int	y;

	f->map->max_z = INT_MIN;
	f->map->max_y = f->map->height;
	f->map->max_x = f->map->width;
	f->map->min_z = INT_MAX;
	f->map->min_y = 0;
	f->map->min_x = 0;
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
	f->map->center_z = f->map->max_z - f->map->min_z;
	f->map->center_y = f->map->max_y - f->map->min_y;
	f->map->center_x = f->map->max_x - f->map->min_x;
}
