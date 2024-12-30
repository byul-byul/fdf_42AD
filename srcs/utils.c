/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:18:25 by bhajili           #+#    #+#             */
/*   Updated: 2024/12/30 15:21:26 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	free_int_arr(int **arr, int size)
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
}
