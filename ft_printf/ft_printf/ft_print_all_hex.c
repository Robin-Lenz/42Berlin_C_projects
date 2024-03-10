/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:06:52 by rpodack           #+#    #+#             */
/*   Updated: 2023/01/17 14:56:57 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	k_ft_print_adress(va_list clients, int *k)
{
	unsigned long long	i;

	i = va_arg(clients, unsigned long long);
	if (i == 0)
	{
		*k += write(1, "(nil)", 5);
		return ;
	}
	else
	{
		*k += write(1, "0x", 2);
		k_ft_put_hex(i, k);
	}
}

void	k_ft_put_hex(uintptr_t	i, int *k)
{
	if (i >= 16)
	{
		k_ft_put_hex(i / 16, k);
		k_ft_put_hex(i % 16, k);
	}
	else if (i <= 9)
		k_ft_putchar_fd(i + '0', 1, k);
	else
		k_ft_putchar_fd(i - 10 + 'a', 1, k);
}

void	k_ft_print_hex_low(va_list clients, int *k)
{
	unsigned int	i;

	i = va_arg(clients, unsigned int);
	k_ft_put_hex(i, k);
}

void	k_ft_print_hex_cap(va_list clients, int *k)
{
	unsigned int		i;

	i = va_arg(clients, unsigned int);
	k_ft_put_hex_cap(i, k);
}

void	k_ft_put_hex_cap(uintptr_t	i, int *k)
{
	if (i >= 16)
	{
		k_ft_put_hex_cap(i / 16, k);
		k_ft_put_hex_cap(i % 16, k);
	}
	else if (i <= 9)
		k_ft_putchar_fd(i + '0', 1, k);
	else if (i < 16)
		k_ft_putchar_fd(i - 10 + 'A', 1, k);
}
