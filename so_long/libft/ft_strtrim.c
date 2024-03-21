/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:52:14 by rpodack           #+#    #+#             */
/*   Updated: 2022/12/27 19:56:03 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char			*ft_strtrim(char const *s1, char const *set);
static int		ft_strskip(const char *s1, const char *s2);
static int		ft_strskipend(const char *s1, const char *s2, int lentotal);
char			*checksub(void);

char	*checksub(void)
{
	char	*x;

	x = malloc(sizeof(char));
	x[0] = '\0';
	return (x);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		lentotal;
	int		skipstart;
	int		skipend;
	int		i;
	char	*x;

	i = 0;
	lentotal = ft_strlen(s1);
	skipstart = ft_strskip(s1, set);
	skipend = ft_strskipend(s1, set, lentotal);
	if (lentotal - skipstart - skipend <= 0)
		return (checksub());
	x = malloc(lentotal - skipstart - skipend + 1);
	if (!x)
		return (NULL);
	while (i < lentotal - skipstart - skipend && s1[i] != '\0')
	{
		x[i] = s1[skipstart + i];
		i++;
	}
	x[i] = '\0';
	return (x);
}

static int	ft_strskip(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[j] != '\0' || s1[i] != '\0')
	{
		j = 0;
		while (s1[i] == set[j])
		{
			i++;
		}
		while (s1[i] != set[j] && set[j] != '\0')
		{
			j++;
		}
		if (set[j] == '\0')
			return (i);
		i++;
		j++;
	}
	return (i);
}

static int	ft_strskipend(char const *s1, char const *set, int lentotal)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[j] != '\0' || s1[lentotal - 1 - i] != '\0')
	{
		j = 0;
		while (s1[lentotal - 1 - i] == set[j])
		{
			i++;
		}
		while (s1[lentotal - 1 - i] != set[j] && set[j] != '\0')
		{
			j++;
		}
		if (set[j] == '\0')
			return (i);
		i++;
		j++;
	}
	return (i);
}
/*
int	main(void)
{
	char const		to_find[] = " x";
	char const		str[] = "   xxx   xxx";

	printf("%s\n", ft_strtrim(str, to_find));
}*/
