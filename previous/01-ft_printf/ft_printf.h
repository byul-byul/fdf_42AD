/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:01:19 by bhajili           #+#    #+#             */
/*   Updated: 2024/12/29 12:20:35 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define LEN 21

# define FLAG_ZERO 0b00000001
# define FLAG_DASH 0b00000010
# define FLAG_PLUS 0b00000100
# define FLAG_SHRP 0b00001000
# define FLAG_SPCE 0b00010000
# define FLAG_PRNT 0b00100000

typedef unsigned long long	t_unll;
typedef unsigned char		t_unch;

typedef struct s_arg
{
	t_unch	flags;
	va_list	value;
	char	type;
	char	*prefix;
	char	sign;
	int		width;
	int		prec;
	int		is_up;
	int		base;
	int		res;
}				t_arg;

int		ft_printf(const char *str, ...);
int		arg_handler(t_arg *arg, const char **str);
void	arg_printer(t_arg *arg);
void	num_printer(t_arg *arg);
int		ft_isdigit(int c);
int		putchar_len_times(int len, char c);
int		ft_strlen(const char *s);
int		flag_check(t_arg *arg, t_unch flag);
t_unll	get_num_type(t_arg *arg);

#endif