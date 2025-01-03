/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:45:27 by bhajili           #+#    #+#             */
/*   Updated: 2024/12/27 12:48:50 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_valid_variables(void)
{
	if (BYTE_SIZE != 8 && BYTE_SIZE != 16 && BYTE_SIZE != 32)
		return (ft_printf("ERROR: BYTE_SIZE should be: 8, 16, 32.\n"), 0);
	if (MICROSECONDS <= 0 || MICROSECONDS >= 10000)
		return (ft_printf("ERROR: MICROSECONDS should be: 1 - 10000\n"), 0);
	if (NULL == WELCOME_MESSAGE || \
		NULL == REQUEST_MESSAGE || \
		NULL == RESPONSE_MESSAGE)
		return (ft_printf("ERROR: provide correct message value.\n"), 0);
	if (TRUE != 1)
		return (ft_printf("ERROR: TRUE can be only 1.\n"), 0);
	if (FALSE != 0)
		return (ft_printf("ERROR: TRUE can be only 0.\n"), 0);
	if (DEFAULT_WELCOME != TRUE && DEFAULT_WELCOME != FALSE)
		return (ft_printf("ERROR: DEFAULT_WELCOME can be TRUE/FALSE.\n"), 0);
	return (1);
}
