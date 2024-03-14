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

#include "libft.h"

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
