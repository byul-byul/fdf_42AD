/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:18:25 by bhajili           #+#    #+#             */
/*   Updated: 2025/01/03 19:43:42 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	convert_3D_to_2D(int x, int y, int z, int *screen_x, int *screen_y, int scale)
{
	*screen_x = OFFSET_X + scale * ((x - y) * cos(ISO_ANGLE));
	*screen_y = OFFSET_Y + scale * ((x + y) * sin(ISO_ANGLE) - z);
}

void	clean_rows(t_row *rows, int size)
{
	int	i;

	i = -1;
	if (!rows)
		return ;
	while (++i < size)
		free(rows[i].row);
	free(rows);
}

void	print_error(int error_code)
{
	if (error_code == 1)
		ft_putstr(ERR_MSG_01);
	else if (error_code == 2)
		ft_putstr(ERR_MSG_02);
	else if (error_code == 3)
		ft_putstr(ERR_MSG_03);
	else if (error_code == 4)
		ft_putstr(ERR_MSG_04);
	else if (error_code == 5)
		ft_putstr(ERR_MSG_05);
	else if (error_code == 6)
		ft_putstr(ERR_MSG_06);
	else if (error_code == 7)
		ft_putstr(ERR_MSG_07);
	else if (error_code == 8)
		ft_putstr(ERR_MSG_08);
	else if (error_code == 9)
		ft_putstr(ERR_MSG_09);
}
