/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:34:01 by rpodack           #+#    #+#             */
/*   Updated: 2022/12/02 18:28:04 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	signed char	operation;
	size_t		end;
	size_t		current;

	if (dest != src)
	{
		if (dest < src)
		{
			operation = 1;
			current = 0;
			end = n;
		}
		else
		{
			operation = -1;
			current = n - 1;
			end = -1;
		}
		while (current != end)
		{
			*(((char *)dest) + current) = *(((char *)src) + current);
			current = current + operation;
		}
	}
	return (dest);
}
