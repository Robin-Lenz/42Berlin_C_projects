/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:17:04 by rpodack           #+#    #+#             */
/*   Updated: 2022/08/31 21:17:07 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	n;

	n = nb;
	if (n < 0)
	{	
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
		}
		else
		{
			ft_putchar('-');
			n = -n;
		}
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	if (n < 10 && n >= 0)
	{
		ft_putchar(n + '0');
	}
}
/*
int	main(void)
{
	ft_putnbr(10);
}*/
