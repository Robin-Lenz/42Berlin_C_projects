/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:59:17 by rpodack           #+#    #+#             */
/*   Updated: 2022/11/30 12:18:09 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ft_isalpha()
              checks  for an alphabetic character; in the standard "C" locale,
              it is equivalent to (isupper(c) ||  islower(c)).   In  some  lo‐
              cales, there may be additional characters for which isalpha() is
              true—letters which are neither uppercase nor lowercase.
              
RETURN VALUE
       The  values  returned  are  nonzero  if  the character c falls into the
       tested class, and zero if not.

*/

#include <stdio.h>

int	ft_isalpha(int c);

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

/*
int	ft_isalpha(int c)
{
	return (1 ? ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) : 0);
}
this is forbiddden with norminette
*/
