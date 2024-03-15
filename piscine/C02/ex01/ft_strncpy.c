/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:19:29 by rpodack           #+#    #+#             */
/*   Updated: 2022/08/25 15:19:32 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	unsigned int	n;
	n = 9;
	char	dest[15] = "tada";

	char quelle[12] = {"tadaewewewe"};
	char	dest2[15] = "tada";

	char quelle2[12] = {"tadaewewewe"};
	ft_strncpy(dest, quelle, n);
	printf("%s\n", dest);
	
	strncpy(dest2, quelle2, n);
	printf("%s", dest);
}*/
