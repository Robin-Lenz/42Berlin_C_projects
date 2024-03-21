/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:06:57 by rpodack           #+#    #+#             */
/*   Updated: 2023/01/12 20:06:57 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	k_ft_print_int(va_list clients, int *k)
{
	int	j;

	j = va_arg(clients, int);
	k_ft_putnbr_fd(j, 1, k);
}

void	k_ft_putnbr_fd(int n, int fd, int *k)
{
	if (n < 0)
	{
		if (n == -2147483648)
			k_ft_putstr_fd("-2147483648", fd, k);
		else
		{
			k_ft_putchar_fd('-', fd, k);
			n = n * (-1);
		}
	}
	if (n >= 10)
	{
		k_ft_putnbr_fd(n / 10, fd, k);
		k_ft_putchar_fd((n % 10) + '0', fd, k);
	}
	if (n < 10 && n >= 0)
		k_ft_putchar_fd((n % 10) + '0', fd, k);
}
