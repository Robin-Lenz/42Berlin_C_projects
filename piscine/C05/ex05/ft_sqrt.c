/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:52:30 by rpodack           #+#    #+#             */
/*   Updated: 2022/09/06 19:52:34 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	root;

	root = 0;
	while (root * root <= nb && root < 46341)
	{
		if (nb == (root * root))
			return (root);
		root++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%i", ft_sqrt(4));
}*/
