/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:51:17 by rpodack           #+#    #+#             */
/*   Updated: 2022/09/06 15:51:20 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power (nb, power - 1));
}
/*
int	main(void)
{
	int	nb;
	int	power;

	nb = 46341;
	power = 2;
	printf("%i", ft_recursive_power(nb, power));
}*/
