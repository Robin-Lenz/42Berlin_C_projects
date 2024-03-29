/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:49:42 by mwurch            #+#    #+#             */
/*   Updated: 2022/11/29 11:49:45 by mwurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;

	if (!s)
		return ;
	tmp = s;
	while (n--)
		*(tmp++) = '\0';
}
