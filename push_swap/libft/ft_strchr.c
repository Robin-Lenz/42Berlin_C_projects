/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:16:04 by rpodack           #+#    #+#             */
/*   Updated: 2022/11/30 14:16:04 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
DESCRIPTION
       The  strchr() function returns a pointer to the first occurrence of the
       character c in the string s.

RETURN VALUE
       The strchr() and strrchr() functions return a pointer  to  the  matched
       character  or NULL if the character is not found.  The terminating null
       byte is considered part of the string, so that if  c  is  specified  as
       '\0', these functions return a pointer to the terminator.
*/

#include <stdio.h>

char	*ft_strchr(const char *s, int c);

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;
	char	a;

	p = (char *)s;
	a = (char) c;
	i = 0;
	while (p[i] != '\0' )
	{
		if (p[i] == a)
			return (&p[i]);
		i++;
	}
	if (p[i] == a)
		return (&p[i]);
	return (NULL);
}
