/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:18:22 by rpodack           #+#    #+#             */
/*   Updated: 2022/11/30 14:18:22 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
       The ft_strdup() function returns a pointer to a new string which is a
        duplicate
       of the string s.  Memory for the new string is obtained with malloc(3),
         and
       can be freed with free(3).
RETURN VALUE
       On  success,  the  ft_strdup()  function  returns  a  pointer to the 
       duplicated
       string.  It returns NULL if insufficient memory was  available,  with 
        errno
       set to indicate the cause of the error.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;
	int		srclen;

	srclen = ft_strlen(src)+1;
	dest = malloc(srclen);
	if (!dest)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
//memory is not freed
//is here too much memory used by creating dest instead of changing 
//the memory that is initaly used by src
