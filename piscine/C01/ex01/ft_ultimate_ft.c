/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:39:42 by rpodack           #+#    #+#             */
/*   Updated: 2022/08/22 14:39:45 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}
/*
int	main(void)
{
	int	a;
	int	*p1;
	int	**p2;
	int	***p3;
	int	****p4;
	int	*****p5;
	int	******p6;
	int	*******p7;
	int	********p8;
	int	*********p9;
	
	
	
	a = 45;
	ft_putnbr(a);
	p1 = &a;
	p2 = &p1;
	p3 = &p2;
	p4 = &p3;
	p5 = &p4;
	p6 = &p5;
	p7 = &p6;
	p8 = &p7;
	p9 = &p8;
	
	ft_ultimate_ft(p9);
}

void	ft_putnbr(int nb)
{
	int	n;

	n = nb;
	if (n < 0)
	{	
		ft_putchar('-');
		n = -n;
	}
	if (n > 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
	{
		ft_putchar(n + '0');
	}	
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
*/
