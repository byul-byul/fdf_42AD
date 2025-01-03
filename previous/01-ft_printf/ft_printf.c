/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:01:22 by bhajili           #+#    #+#             */
/*   Updated: 2024/12/21 17:51:01 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_print(t_arg *arg, const char *str)
{
	arg->res = 0;
	while (*str)
	{
		if (*str != '%')
			arg->res += write(1, str, 1);
		else
		{
			str++;
			if (!*str || !arg_handler(arg, &str))
			{
				arg->res = -1;
				break ;
			}
			arg_printer(arg);
		}
		str++;
	}
}

int	ft_printf(const char *str, ...)
{
	t_arg	arg;

	va_start(arg.value, str);
	do_print(&arg, str);
	va_end(arg.value);
	return (arg.res);
}
