/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:18:18 by rpodack           #+#    #+#             */
/*   Updated: 2022/08/24 15:18:20 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int	tab[5];

	tab[0] = -12;
	tab[1] = -103;
	tab[2] = 15;
	tab[3] = 12;
	tab[4] = 1;
	printf("%i\n", tab[0]);
	printf("%i\n", tab[1]);
	printf("%i\n", tab[2]);
	printf("%i\n", tab[3]);
	printf("%i\n", tab[4]);
	ft_sort_int_tab(tab, 5);
	printf("%i\n", tab[0]);
	printf("%i\n", tab[1]);
	printf("%i\n", tab[2]);
	printf("%i\n", tab[3]);
	printf("%i\n", tab[4]);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
