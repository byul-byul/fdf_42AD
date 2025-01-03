/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:02:08 by bhajili           #+#    #+#             */
/*   Updated: 2024/12/21 17:24:50 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_check(t_arg *arg, t_unch flag)
{
	return (arg->flags & flag);
}

int	putchar_len_times(int len, char c)
{
	int	res;

	res = 0;
	while (len-- > 0)
		res += write(1, &c, 1);
	return (res);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_strlen(const char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
