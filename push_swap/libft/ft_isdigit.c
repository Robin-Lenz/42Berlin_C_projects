/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:20:15 by rpodack           #+#    #+#             */
/*   Updated: 2023/06/01 14:06:59 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
isdigit()
              checks for a digit (0 through 9).
RETURN VALUE
       The  values  returned  are  nonzero if the character c falls into 
       the tested class, and zero if
       not.
*/

#include <stdio.h>

int	ft_isdigit(int c);

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
