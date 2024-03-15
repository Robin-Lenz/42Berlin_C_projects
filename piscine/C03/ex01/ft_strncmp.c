/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:44:05 by rpodack           #+#    #+#             */
/*   Updated: 2022/08/30 18:44:08 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				x;

	i = 0;
	x = 0;
	while (i < n)
	{
		if ((s1[i] == s2[i]) && (s1[i] != '\0'))
		{
			i++;
		}
		else
		{
			x = s1[i] - s2[i];
			return (x);
		}
	}
	return (x);
}
/*
int	main(void)
{
	char	s1[] = "hallo";
	char	s2[] = "aallo";
	unsigned int	b = 1;
	//ft_strncmp(s1, s2);
	//ft_strncmp(s1, s2, b);
	//printf("%d\n", ft_strncmp(s1, s2, b));
	printf("%i", ft_strncmp(s1, s2, b));
	printf("%i\n", strncmp(s1, s2, b));
}*/
