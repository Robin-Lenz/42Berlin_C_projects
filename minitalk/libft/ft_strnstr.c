/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:23:08 by rpodack           #+#    #+#             */
/*   Updated: 2022/11/30 14:23:08 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The strnstr() function locates the first occurrence of the null-terminated
     string little in the string big, where not more than len characters are
     searched.  Characters that appear after a ‘\0’ character are not searched.
     Since the strnstr() function is a FreeBSD specific API,
      it should only be used
     when portability is not a concern.

RETURN VALUES
     If little is an empty string, big is returned; if little occurs nowhere in
     big, NULL is returned; otherwise a pointer to the 
     first character of the first
     occurrence of little is returned.

*/
#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		l;

	i = 0;
	j = 0;
	if (!*little)
		return ((char *)&big[0]);
	while (big[i] != '\0' && (i < len))
	{
		j = 0;
		if (big[i] == little[j])
		{
			l = i;
			while (big[l] == little[j] && (i + j) < len)
			{
				l++;
				j++;
				if (little[j] == '\0')
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char		to_find[] = "aabc";
	char	str[] = "aaabcabcd";

	printf("%s", ft_strnstr(str, to_find, -1));
}*/
