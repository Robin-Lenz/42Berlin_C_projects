/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:43:51 by rpodack           #+#    #+#             */
/*   Updated: 2022/11/30 12:48:38 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_isprint()
              checks for any printable character including space.
RETURN VALUE
       The  values  returned  are  nonzero if the character
        c falls into the tested class, and zero if
       not.
*/
#include <stdio.h>

int	ft_isprint(int c);

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	else
		return (0);
}
