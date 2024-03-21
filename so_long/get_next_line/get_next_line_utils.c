/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:52:59 by rpodack           #+#    #+#             */
/*   Updated: 2023/04/25 19:48:22 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;
	size_t	i;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < nmemb)
	{
		p[i] = '\0';
		i++;
	}
	return (p);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;
	char	a;

	p = (char *)s;
	a = (char) c;
	i = 0;
	if (!s)
		return (NULL);
	if (a == '\0')
		return (&p[ft_strlen(s)]);
	while (p[i] != '\0' )
	{
		if (p[i] == a)
			return (&p[i]);
		i++;
	}
	if (p[i] == a)
	{
		return (&p[i]);
	}
	return (NULL);
}

char	*need_even_more(char *stay, char *tmp, int i)
{
	int	j;

	j = 0;
	while (stay[i] != '\0')
	{
		tmp[j] = stay[i];
		i++;
		j++;
	}
	return (tmp);
}
