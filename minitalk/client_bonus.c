/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:16:03 by rpodack           #+#    #+#             */
/*   Updated: 2023/04/14 17:38:05 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

struct s_gunit		g_g = {.flag = 1, .next = 7};

void	sendend(int i)
{
	while (i < 8)
	{
		if (g_g.flag == 1)
		{
			kill(g_g.pid, SIGUSR2);
			g_g.flag = 0;
			i++;
		}
	}
}

void	ft_flag(int sig)
{
	if (sig == SIGUSR1)
		g_g.flag = 1;
	if (sig == SIGUSR2)
	{
		write(1, "message received", 16);
		g_g.flag = 2;
		exit(0);
	}
}

void	bitwise(int sig)
{
	static int	i;

	(void)sig;
	while (g_g.str[i])
	{
		while (g_g.next >= 0)
		{
			if (g_g.flag == 1)
			{
				if ((g_g.str[i] >> g_g.next) & 1)
					kill(g_g.pid, SIGUSR1);
				else
					kill(g_g.pid, SIGUSR2);
				g_g.flag = 0;
				g_g.next--;
			}
		}
		g_g.next = 7;
		i++;
	}
	if (g_g.str[i] == '\0')
		sendend(0);
}

void	ft_not_valid(void)
{
	write(1, "No valid entry", 14);
	exit(0);
}

int	main(int ac, char **av)
{
	struct sigaction	sig_c;
	struct sigaction	sig_s;

	sig_c.sa_handler = &ft_flag;
	sig_c.sa_flags = 0;
	sig_s.sa_handler = &ft_flag;
	sig_s.sa_flags = 0;
	sigemptyset(&sig_c.sa_mask);
	sigemptyset(&sig_s.sa_mask);
	sigaction(SIGUSR1, &sig_s, NULL);
	sigaction(SIGUSR2, &sig_c, NULL);
	if (ac == 3)
	{
		g_g.pid = ft_atoi(av[1]);
		g_g.str = av[2];
		bitwise(1);
	}
	else
		ft_not_valid();
	while (g_g.flag != 2)
	{
		usleep(1000);
		continue ;
	}
	return (0);
}
