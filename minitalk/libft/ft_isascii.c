/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:34:47 by rpodack           #+#    #+#             */
/*   Updated: 2022/11/30 12:41:08 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_isascii()
              checks whether c is a 7-bit unsigned char 
              value that fits into the ASCII character set.
 RETURN VALUE
       The  values  returned  are  nonzero if the character 
       c falls into the tested class, and zero if
       not.           
*/

#include <stdio.h>

int	ft_isascii(int c);

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
