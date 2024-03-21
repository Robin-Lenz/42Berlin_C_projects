/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:46:53 by rpodack           #+#    #+#             */
/*   Updated: 2023/04/13 19:46:54 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putchar(char c, int client_pid)
{
	if (c == '\0')
	{
		kill(client_pid, SIGUSR2);
		write(1, "\n", 1);
	}
	else
		write(1, &c, 1);
}

void	receive(int sig, siginfo_t *info, void *ucontext)
{
	int				client_pid;
	static int		i;
	static char		c;

	(void)ucontext;
	client_pid = info->si_pid;
	usleep(80);
	if (i != 8)
	{
		if (sig == SIGUSR1)
			c = c << 1 | 1;
		else
			c = c << 1;
		i++;
	}
	if (i == 8)
	{
		ft_putchar(c, client_pid);
		i = 0;
		c = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	rec;

	pid = getpid();
	ft_printf("%i \n", pid);
	rec.sa_sigaction = &receive;
	rec.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&rec.sa_mask);
	sigaction(SIGUSR1, &rec, NULL);
	sigaction(SIGUSR2, &rec, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
