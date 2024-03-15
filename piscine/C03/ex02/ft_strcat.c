/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:11:56 by rpodack           #+#    #+#             */
/*   Updated: 2022/08/30 21:11:58 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	dest_len(char *dest)
{
	int	x;

	x = 0;
	while (dest[x] != '\0')
	{
		x++;
	}
	return (x);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_leni;

	i = 0;
	dest_leni = dest_len(dest);
	while (src[i] != '\0')
	{
		dest[dest_leni + i] = src[i];
		i++;
	}
	dest[dest_leni + i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "du";
	char	dest[20] = "hallo";

	ft_strcat(dest, src);
	printf("%s\n", dest);
}*/
