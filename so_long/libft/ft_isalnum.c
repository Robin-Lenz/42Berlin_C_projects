/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:27:40 by rpodack           #+#    #+#             */
/*   Updated: 2022/12/13 21:58:08 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
isalnum()
              checks for an alphanumeric character;
               it is equivalent to (isalpha(c) || isdigit(c)).
RETURN VALUE
    
    The  values  returned  are  nonzero 
    if the character c falls into the tested class, 
    and zero if
       not.           
              */
#include <stdio.h>

int	ft_isalnum(int c);

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
