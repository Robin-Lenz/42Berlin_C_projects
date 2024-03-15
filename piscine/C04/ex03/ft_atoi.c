/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:18:44 by rpodack           #+#    #+#             */
/*   Updated: 2022/08/31 21:18:48 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	cases(int *a, int *b, char *str)
{
	int	i;
	int	count_minus;

	i = *a;
	count_minus = *b;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			count_minus++;
		}
		i++;
	}
	*a = i;
	*b = count_minus;
}

int	ft_atoi(char *str)
{
	int	res;
	int	i;
	int	count_minus;
	int	*a;
	int	*b;

	res = 0;
	i = 0;
	count_minus = 0;
	a = &i;
	b = &count_minus;
	cases(a, b, str);
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (count_minus % 2 == 1)
	{
		return (res * (-1));
	}
	else
		return (res);
}
/*
int	main(int argc, char *argv[])
{
	argc++;
	printf("%i\n", ft_atoi(argv[1]));
	printf("%i\n", atoi(argv[1]));
}*/
