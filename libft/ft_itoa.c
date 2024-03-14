/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:28:49 by rpodack           #+#    #+#             */
/*   Updated: 2022/12/20 00:40:14 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int	i;
	int	tmp;
	char	*res;

	i = 1;
	tmp = n;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		i++;
	}
	res = malloc(sizeof(char) * i + 1);
	res[i] = '\0';
	while (i > 0)
	{
		tmp = n % 10;
		res[i-1] = tmp + '0';
		n = n / 10;
		i--;
	}
	return (res);
}
