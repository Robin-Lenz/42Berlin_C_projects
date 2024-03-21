/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:09:20 by rpodack           #+#    #+#             */
/*   Updated: 2022/12/29 16:41:03 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.

The substring.
NULL if the allocation fails
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	*check_sub(void)
{
	char	*dest;

	dest = malloc(sizeof(char) * 1);
	if (!dest)
		return (NULL);
	dest[0] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;
	unsigned int	s_len;

	s_len = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	if (ft_strlen(s) < start)
		return (check_sub());
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	if (start < s_len)
	{
		while (i < len && s[i] != '\0')
		{
			dest[i] = s[start + i];
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

/*
int main(void)
{
    char str[] = "tripouille";
    printf("%s\n", str);
    printf("%s\n", ft_substr(str, 1, 1));
    return 0;
}*/