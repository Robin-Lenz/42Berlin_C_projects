/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:27:52 by rpodack           #+#    #+#             */
/*   Updated: 2022/12/13 20:10:32 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
       The  ft_memcpy()  function  copies  n bytes from memory area src to memory
       area dest.  The memory areas must not overlap.  Use memmove(3)  if  the
       memory areas do overlap.

RETURN VALUE
       The ft_memcpy() function returns a pointer to dest.
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*x;
	char			*y;

	x = dest;
	y = (char *) src;
	i = 0;
	if (!src && !dest)
		return (0);
	while (i < n)
	{
		x[i] = y[i];
		i++;
	}
	return (x);
}
