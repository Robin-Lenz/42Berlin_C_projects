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

#include "libft.h"

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
