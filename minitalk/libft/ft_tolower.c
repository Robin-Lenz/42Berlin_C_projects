/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:03:16 by rpodack           #+#    #+#             */
/*   Updated: 2022/11/30 17:05:25 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
       These functions convert lowercase letters to uppercase, and vice versa.

       If c is a lowercase letter, toupper() returns its uppercase equivalent,
       if an uppercase representation exists in the  current  locale.   Other‐
       wise,  it  returns c.

       If c is an uppercase letter, tolower() returns  its  lowercase  equiva‐
       lent, if a lowercase representation exists in the current locale.  Oth‐
       erwise, it returns c.

       If  c  is neither an unsigned char value nor EOF, the behavior of these
       functions is undefined.


RETURN VALUE
       The value returned is that of the converted letter, or c if the conver‐
       sion was not possible.

*/

#include <stdio.h>

int	ft_tolower(int c);

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
