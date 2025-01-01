/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:18:25 by bhajili           #+#    #+#             */
/*   Updated: 2025/01/01 20:43:36 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

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
		ft_printf(ERR_MSG_01);
	else if (error_code == 2)
		ft_printf(ERR_MSG_02);
	else if (error_code == 3)
		ft_printf(ERR_MSG_03);
	else if (error_code == 4)
		ft_printf(ERR_MSG_04);
	else if (error_code == 5)
		ft_printf(ERR_MSG_05);
	else if (error_code == 6)
		ft_printf(ERR_MSG_06);
	else if (error_code == 7)
		ft_printf(ERR_MSG_07);
	else if (error_code == 8)
		ft_printf(ERR_MSG_08);
	else if (error_code == 9)
		ft_printf(ERR_MSG_09);
}
