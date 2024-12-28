/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:16:23 by bhajili           #+#    #+#             */
/*   Updated: 2024/12/28 13:24:55 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"


int	is_valid_arg(int ac, char **av)
{
	if (ac != 2)
		return (ft_printf("Error: invalid arg count\n"), 0);
	if (NULL == av[1])
		return (ft_printf("Error: please provide a map-file\n"), 0);
	if (NULL == av[1])
		return (ft_printf("Error: please provide a map-file\n"), 0);
	if (ft_strlen(ft_strstr(av[1], FILE_EXT)) != ft_strlen(FILE_EXT))
		return (ft_printf("Error: invalid file extension ('file.fdf')\n"), 0);
	return (1);
}
