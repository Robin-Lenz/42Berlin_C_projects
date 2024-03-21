/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:50:10 by rpodack           #+#    #+#             */
/*   Updated: 2022/12/15 18:08:02 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
       The  memcmp()  function compares the first n byt
es (each interpreted as
       unsigned char) of the memory areas s1 and s2.

RETURN VALUE
       The memcmp() function returns  an  integer  less
  than,  equal  to,  or
       greater than zero if the first n bytes of s1 is 
found, respectively, to
       be less than, to match, or be greater than the first n bytes of s2.

       For a nonzero return value, the sign is determined by the sign  of  the
       difference  between  the  first  pair of bytes (interpreted as unsigned
       char) that differ in s1 and s2.

       If n is zero, the return value is zero.
*/

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*o;
	const unsigned char	*m;
	unsigned int		i;

	o = s1;
	m = s2;
	i = 0;
	if (n == 0)
		return (0);
	while (o[i] == m[i] && i < n - 1)
		i++;
	return (o[i] - m[i]);
}
