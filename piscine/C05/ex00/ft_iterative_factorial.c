/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:43:58 by rpodack           #+#    #+#             */
/*   Updated: 2022/09/04 21:44:00 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	n;
	int	i;

	n = 1;
	i = 0;
	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	while (i != nb)
	{
		n = n *(nb - i);
		i++;
	}
	return (n);
}
/*
int	main()
{
	printf("%i", ft_iterative_factorial(5));
}*/
