/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:32:15 by bhajili           #+#    #+#             */
/*   Updated: 2024/12/27 12:47:12 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_printf("%d\n", received);
		exit(0);
	}
}

static void	send_message(int pid, char *str)
{
	int				i;
	unsigned char	c;

	while (*str)
	{
		i = BYTE_SIZE;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(MICROSECONDS);
		}
	}
	i = BYTE_SIZE;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(MICROSECONDS);
	}
}

static int	client(int ac, char **av)
{
	if (ac != 2 || !ft_strlen(av[1]))
		return (1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	ft_printf("%s\t\t%d\n", REQUEST_MESSAGE, ft_strlen(av[1]));
	ft_printf("%s\t", RESPONSE_MESSAGE);
	send_message(ft_atoi(av[0]), av[1]);
	while (1)
		pause();
}

int	main(int ac, char **av)
{
	if (is_valid_variables())
		client(ac - 1, av + 1);
	return (0);
}
