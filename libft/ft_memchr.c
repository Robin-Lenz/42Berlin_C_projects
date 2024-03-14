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

#include "libft.h"

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
