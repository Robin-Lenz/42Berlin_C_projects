/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:05:32 by rpodack           #+#    #+#             */
/*   Updated: 2022/08/22 19:05:39 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int main (void)
{
	int a;
	int b;
	int pointedby_div;
	int pointedby_mod;
	int *div;
	int *mod;
	
	pointedby_div;
	pointedby_mod;
	a = 9;
	b = 3;
	div = &pointedby_div;
	mod = &pointedby_mod;
	
	printf("%i", a);
	printf("%i", b);
	printf("\n");
	
	printf("\n");
	
	ft_div_mod(a, b, div, mod);
	
	printf("%i", pointedby_div);
	printf("\n");
	printf("%i", pointedby_mod);
}
*/
