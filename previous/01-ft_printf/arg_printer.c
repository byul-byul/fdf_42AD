/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 07:46:51 by bhajili           #+#    #+#             */
/*   Updated: 2024/12/21 17:55:06 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	str_printer(t_arg *arg)
{
	int		i;
	int		len;
	char	*str;

	str = va_arg(arg->value, char *);
	if (NULL == str)
		str = "(null)";
	len = ft_strlen(str);
	if (arg->prec > -1 && arg->prec < len)
		len = arg->prec;
	i = len;
	if (!flag_check(arg, FLAG_DASH))
		arg->res += putchar_len_times(arg->width - len, ' ');
	while (*str && i-- > 0)
		arg->res += write(1, str++, 1);
	if (flag_check(arg, FLAG_DASH))
		arg->res += putchar_len_times(arg->width - len, ' ');
}

static void	char_printer(t_arg *arg)
{
	int	c;

	if (arg->type == '%')
		c = '%';
	else
		c = va_arg(arg->value, int);
	if (!flag_check(arg, FLAG_DASH) && flag_check(arg, FLAG_ZERO))
		arg->res += putchar_len_times(arg->width - 1, '0');
	else if (!flag_check(arg, FLAG_DASH))
		arg->res += putchar_len_times(arg->width - 1, ' ');
	arg->res += write(1, &c, 1);
	if (flag_check(arg, FLAG_DASH))
		arg->res += putchar_len_times(arg->width - 1, ' ');
}

void	arg_printer(t_arg *arg)
{
	if (arg->type == '%' || arg->type == 'c')
		char_printer(arg);
	else if (arg->type == 's')
		str_printer(arg);
	else
		num_printer(arg);
}