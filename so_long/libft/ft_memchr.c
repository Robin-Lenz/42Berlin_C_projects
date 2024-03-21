/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:52:58 by rpodack           #+#    #+#             */
/*   Updated: 2022/12/16 20:34:27 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
       The  memchr()  function scans the initial n bytes of 
       the memory area pointed
       to by s for the first instance of c.  Both c and the  
       bytes  of  the  memory
       area pointed to by s are interpreted as unsigned char.

       The  memrchr()  function  is  like  the  memchr()  function, 
        except that it
       searches backward from the end of the n bytes pointed to  by 
        s  instead  of
       forward from the beginning.
RETURN VALUE
       The  memchr()  and memrchr() functions return a pointer to the 
       matching byte
       or NULL if the character does not occur in the given memory area.

       The rawmemchr() function returns a pointer to the matching byte,
        if  one  is
       found.  If no matching byte is found, the result is unspecified.
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*p;
	char		a;

	p = (char *) s;
	a = (char) c;
	i = 0;
	while (i < n)
	{
		if (p[i] == a)
		{
			return (&p[i]);
		}
		i++;
		s++;
	}
	return (NULL);
}
