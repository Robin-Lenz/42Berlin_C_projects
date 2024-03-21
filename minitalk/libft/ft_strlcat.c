/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:14:10 by rpodack           #+#    #+#             */
/*   Updated: 2022/12/13 20:50:44 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The strlcpy() and strlcat() functions copy and concatenate strings respec‐
     tively.  They are designed to be safer, more consistent, and less error 
     prone
     replacements for strncpy(3) and strncat(3).  Unlike those functions, 
     strlcpy()
     and strlcat() take the full size of the buffer (not just the length)
      and guar‐
     antee to NUL-terminate the result (as long as size is larger than 0 or,
      in the
     case of strlcat(), as long as there is at least one byte free in dst).  
     Note
     that a byte for the NUL should be included in size.  Also note that 
     strlcpy()
     and strlcat() only operate on true “C” strings.  This means that for 
     strlcpy()
     src must be NUL-terminated and for strlcat() both src and dst must be 
     NUL-ter‐
     minated.

     The strlcpy() function copies up to size - 1 characters from the NUL-termi‐
     nated string src to dst, NUL-terminating the result.

     The strlcat() function appends the NUL-terminated string src to the end of
     dst.  It will append at most size - strlen(dst) - 1 bytes, 
     NUL-terminating the
     result.

RETURN VALUES
     The strlcpy() and strlcat() functions return the total length of the string
     they tried to create.  For strlcpy() that means the length of src.  For
     strlcat() that means the initial length of dst plus the length of src.  
     While
     this may seem somewhat confusing, it was done to make truncation detection
     simple.

     Note, however, that if strlcat() traverses size characters 
     without finding a
     NUL, the length of the string is considered to be size and the destination
     string will not be NUL-terminated (since there was no space for the NUL).
     This keeps strlcat() from running off the end of a string.  
     In practice this
     should not happen (as it means that either size is incorrect or that dst is
     not a proper “C” string).  The check exists to prevent potential security
     problems in incorrect code.
*/

#include <stdio.h>
#include <string.h>

size_t			ft_strlcat(char *dst, const char *src, size_t size);
static size_t	ft_strlen(const char *str);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	m;
	char	*s;

	s = (char *)src;
	k = ft_strlen(dst);
	j = ft_strlen(s);
	m = k + j;
	i = 0;
	if (size < k + 1)
		return (j + size);
	while (s[i] != '\0' && k + 1 < size)
	{
		dst[k] = src[i];
		i++;
		k++;
	}
	dst[k] = '\0';
	return (m);
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
