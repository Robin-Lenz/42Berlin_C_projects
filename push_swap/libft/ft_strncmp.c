/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:21:17 by rpodack           #+#    #+#             */
/*   Updated: 2022/12/15 17:58:00 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
       The strcmp() function compares the two strings s1 and s2. 
        The locale is not
       taken into account (for a locale-aware comparison, see strcoll(3)). 
        It  re‐
       turns  an  integer less than, equal to, or greater than zero if 
       s1 is found,
       respectively, to be less than, to match, or be greater than s2.

       The strncmp() function is similar, except it compares  only 
        the  first  (at
       most) n bytes of s1 and s2.

RETURN VALUE
       The  strcmp() and strncmp() functions return an integer less than, 
       equal to,
       or greater than zero if s1 (or the first n bytes thereof) is found,
         respec‐
       tively, to be less than, to match, or be greater than s2.
*/

#include <string.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (s1[i] != s2[j])
			return ((unsigned char) s1[i] - (unsigned char) s2[j]);
		if (s2[j] == '\0' || s1[i] == '\0')
			return ((unsigned char) s1[i] - (unsigned char) s2[j]);
		i++;
		j++;
	}
	return (0);
}
