/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:35:54 by rpodack           #+#    #+#             */
/*   Updated: 2022/08/23 19:35:59 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b);
void	ft_rev_int_tab(int *tab, int size);
/*
void	ft_rev_int_tab(int *tab, int size)
{
	int	tab2[1000000];
	int	i;
	int	j;

	i = 0;
	j = size -1;
	while (size != 0)
	{
		size--;
		tab2[i] = tab[size];
		i++;
	}
	while (j >= 0)
	{
		tab[j] = tab2[j];
		j--;
	}
}*/

int	main(void)
{	
	int	tab[3];

	tab[0] = 2;
	tab[1] = n;
	tab[2] = " ";
	printf("%i", tab[0]);
	printf("%i", tab[1]);
	printf("%i", tab[2]);
	ft_rev_int_tab(tab, 3);
	printf("%i", tab[0]);
	printf("%i", tab[1]);
	printf("%i", tab[2]);
}


void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size / 2)
	{
		ft_swap(tab + i, tab + size -1 - i);
		i++;
	}
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}
