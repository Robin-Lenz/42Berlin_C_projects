/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:08:47 by rpodack           #+#    #+#             */
/*   Updated: 2022/08/31 17:08:50 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	dest_len(char *dest);

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	dest_leni;

	i = 0;
	dest_leni = dest_len(dest);
	while (src[i] != '\0' && i < nb)
	{
		dest[dest_leni + i] = src[i];
		i++;
	}
	dest[dest_leni + i] = '\0';
	return (dest);
}

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
/*
int	main(void)
{
	char	src[] = "duda";
	char	dest[20]= "hallo";
	
	ft_strncat(dest, src, 2);
	printf("%s\n", dest);
}*/
