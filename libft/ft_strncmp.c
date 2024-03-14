/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:21:17 by rpodack           #+#    #+#             */
/*   Updated: 2022/12/15 17:58:00 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (s1[i] != s2[j])
			return ((unsigned char) s1[i] - (unsigned char) s2[j]);
		if (s2[j] == '\0' || s1[i] == '\0')
			return ((unsigned char) s1[i] - (unsigned char) s2[j]);
		i++;
		j++;
	}
	return (0);
}
