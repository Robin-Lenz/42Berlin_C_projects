/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:52:49 by rpodack           #+#    #+#             */
/*   Updated: 2022/08/29 18:52:51 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	x;

	i = 0;
	while ((s1[i] != '\0') || (s2[i] != '\0'))
	{
		if ((s1[i] == s2[i]) && (s1[i] != '\0'))
		{
			i++;
		}
		else if (s1[i] == s2[i] && s1[i] == '\0')
		{
			return (0);
		}
		else
		{
			x = s1[i] - s2[i];
			return (x);
		}
	}
	return (0);
}
/*
int	main(void)
{
	char	s1[] = "f";
	char	s2[] = "f";

	//ft_strcmp(s1, s2);
	printf("%d\n", ft_strcmp(s1, s2));
	//printf("%i\n", strcmp("hallo54564", "hallo54564"));
	//printf("%i\n", strcmp(s1, s2));
}*/
