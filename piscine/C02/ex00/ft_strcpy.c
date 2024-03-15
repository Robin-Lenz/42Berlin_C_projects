/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:56:25 by rpodack           #+#    #+#             */
/*   Updated: 2022/08/25 11:56:31 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h> 

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	delta[4];

	char quelle[4] = "tada";
	ft_strcpy(delta, quelle);
	printf("%s", delta);
}*/
