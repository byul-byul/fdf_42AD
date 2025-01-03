/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:32:17 by bhajili           #+#    #+#             */
/*   Updated: 2024/12/27 12:47:08 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_intro(int pid)
{
	ft_putstr("\n\033[1;33m");
	ft_putstr("███████╗███████╗██████╗ ██╗   ██╗███████╗██████╗ \n");
	ft_putstr("██╔════╝██╔════╝██╔══██╗██║   ██║██╔════╝██╔══██╗\n");
	ft_putstr("███████╗█████╗  ██████╔╝██║   ██║█████╗  ██████╔╝\n");
	ft_putstr("╚════██║██╔══╝  ██╔══██╗╚██╗ ██╔╝██╔══╝  ██╔══██╗\n");
	ft_putstr("███████║███████╗██║  ██║ ╚████╔╝ ███████╗██║  ██║\n");
	ft_putstr("╚══════╝╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝╚═╝  ╚═╝\n");
	ft_putstr("Process ID: \033[1;34m");
	ft_putnbr(pid);
	ft_putstr("\033[0m\t\n");
}

static void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static t_unchr	c;
	static int		i;
	static int		client_pid;

	context += 0;
	if (0 == client_pid)
		client_pid = info->si_pid;
	c = c | (SIGUSR2 == sig);
	if (++i < BYTE_SIZE)
		c = c << 1;
	else
	{
		i = 0;
		if (0 == c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_putchar(c);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
}

static void	server(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (DEFAULT_WELCOME)
		ft_printf("%s %d\n", WELCOME_MESSAGE, getpid());
	else
		print_intro(getpid());
	while (1)
		pause();
}

int	main(void)
{
	if (is_valid_variables())
		server();
	return (0);
}
