/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:38:07 by rpodack           #+#    #+#             */
/*   Updated: 2022/09/05 17:38:11 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	n;

	n = nb;
	i = 1;
	if (power < 0)
	{
		return (0);
	}
	else if (nb == 0 && power == 0)
	{
		return (1);
	}
	while (power != i)
	{
		nb = nb * n;
		i++;
	}
	return (nb);
}
/*
int	main()
{
	printf("%i", ft_iterative_power(46340, 2));
}*/
