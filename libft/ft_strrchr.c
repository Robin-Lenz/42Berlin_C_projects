/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:20:40 by rpodack           #+#    #+#             */
/*   Updated: 2022/11/30 14:20:40 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		len;
	char	*p;
	char	a;

	p = (char *)s;
	a = (char) c;
	i = 0;
	len = ft_strlen(p);
	while (len - i >= 0)
	{
		if (p[len - i] == a)
		{
			return ((char *)(&p[len - i]));
		}
		i++;
	}
	return (NULL);
}
