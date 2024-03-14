/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:23:08 by rpodack           #+#    #+#             */
/*   Updated: 2022/11/30 14:23:08 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		l;

	i = 0;
	j = 0;
	if (!*little)
		return ((char *)&big[0]);
	while (big[i] != '\0' && (i < len))
	{
		j = 0;
		if (big[i] == little[j])
		{
			l = i;
			while (big[l] == little[j] && (i + j) < len)
			{
				l++;
				j++;
				if (little[j] == '\0')
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (NULL);
}
