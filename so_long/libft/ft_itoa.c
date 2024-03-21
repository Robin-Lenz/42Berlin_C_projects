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

#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int n);
int		ft_lenint(int n);
char	*ft_slice(int n, int i, int len, char *str);

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		len;

	len = ft_lenint(n);
	if (n == 0)
	{
		str = malloc(sizeof(char) * (2));
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = 0;
	str = ft_slice(n, i, len, str);
	return (str);
}

char	*ft_slice(int n, int i, int len, char *str)
{	
	if (n < 0)
	{
		str[0] = '-';
		while (n != 0)
		{
			str[len - 1 - i] = (n % 10) * (-1) + 48 ;
			n = n / 10;
			i++;
		}
	}
	if (n > 0)
	{
		while (n != 0)
		{
			str[len - 1 - i] = (n % 10) + 48 ;
			n = n / 10;
			i++;
		}
	}
	return (str);
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(0));
}*/

int	ft_lenint(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}
