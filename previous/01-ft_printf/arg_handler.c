/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 07:12:22 by bhajili           #+#    #+#             */
/*   Updated: 2024/12/21 17:52:50 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	type_handler(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
		c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (c);
	else
		return ('\0');
}

static int	width_and_prec_handler(t_arg *arg, const char **str)
{
	int	num;

	num = 0;
	if (**str == '*')
	{
		num = va_arg(arg->value, int);
		(*str)++;
	}
	else if (ft_isdigit(**str))
	{
		while (ft_isdigit(**str))
		{
			num = 10 * num + **str - '0';
			(*str)++;
		}
	}
	return (num);
}

static t_unch	flags_handler(const char **str)
{
	t_unch	flags;

	flags = 0;
	while (1)
	{
		if (**str == '0')
			flags = flags | FLAG_ZERO;
		else if (**str == '-')
			flags = flags | FLAG_DASH;
		else if (**str == '+')
			flags = flags | FLAG_PLUS;
		else if (**str == '#')
			flags = flags | FLAG_SHRP;
		else if (**str == ' ')
			flags = flags | FLAG_SPCE;
		else
			break ;
		(*str)++;
	}
	return (flags);
}

int	arg_handler(t_arg *arg, const char **str)
{
	arg->flags = flags_handler(str);
	arg->width = width_and_prec_handler(arg, str);
	if (arg->width < 0)
	{
		arg->flags = arg->flags | FLAG_DASH;
		arg->width = -arg->width;
	}
	arg->prec = -1;
	if (**str == '.')
	{
		(*str)++;
		arg->prec = width_and_prec_handler(arg, str);
	}
	arg->type = type_handler(**str);
	return (arg->type != '\0');
}
