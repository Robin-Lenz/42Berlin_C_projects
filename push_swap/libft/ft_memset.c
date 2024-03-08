/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:48:20 by rpodack           #+#    #+#             */
/*   Updated: 2022/11/28 12:48:20 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
DESCRIPTION
       The  ft_memset()  function  fills  the  first  n  bytes of the memory area
       pointed to by s with the constant byte c.

RETURN VALUE
       The ft_memset() function returns a pointer to the memory area s.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n);

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	char			*p;

	p = s;
	i = 0;
	while (i < n)
	{
		*p = c;
		i++;
		p++;
	}
	return (s);
}
