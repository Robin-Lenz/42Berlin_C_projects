/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:20:40 by rpodack           #+#    #+#             */
/*   Updated: 2022/11/30 14:20:40 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
       The strchr() function returns a pointer to the first occurrence of 
       the char‐
       acter c in the string s.

       The strrchr() function returns a pointer to the last occurrence of 
       the char‐
       acter c in the string s.
RETURN VALUE
       The strchr() and strrchr() functions return a pointer to the matched 
       charac‐
       ter  or  NULL  if  the character is not found.  The terminating null
        byte is
       considered part of the string, so that if c  is  specified  as  '\0', 
        these
       functions return a pointer to the terminator.

*/

#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		len;
	char	*p;
	char	a;

	p = (char *)s;
	a = (char) c;
	i = 0;
	len = ft_strlen(p);
	while (len - i >= 0)
	{
		if (p[len - i] == a)
		{
			return ((char *)(&p[len - i]));
		}
		i++;
	}
	return (NULL);
}
