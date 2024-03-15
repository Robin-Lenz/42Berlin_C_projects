/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:34:58 by rpodack           #+#    #+#             */
/*   Updated: 2022/08/23 15:35:26 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	t1;
	int	t2;

	t1 = *a;
	t2 = *b;
	*a = t1 / t2;
	*b = t1 % t2;
}
/*
int main (void)
{
	//int *a;
	//int *b;
	
	int x;
	int y;
	
	
	x = 9;
	y = 3;
	//a = &x;
	//b = &y;
	
	printf("\n");
	printf("%i", x);
	printf("\n");
	printf("%i", y);
	
	ft_ultimate_div_mod(&x, &y);
	
	
	
	printf("\n");
	printf("%i", x);
	printf("\n");
	printf("%i", y);
	
}
*/
