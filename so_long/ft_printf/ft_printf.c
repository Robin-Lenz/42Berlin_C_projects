/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:11:42 by rpodack           #+#    #+#             */
/*   Updated: 2023/01/12 20:11:42 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_printf(const char *format, ...)
{
	va_list		clients;
	int			i;
	int			bytesprinted;
	int			*k;

	bytesprinted = 0;
	k = &bytesprinted;
	i = 0;
	va_start(clients, format);
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			k_ft_call(format, clients, i, k);
			i++;
		}
		else
			k_ft_putchar_fd(format[i], 1, k);
		i++;
	}
	va_end(clients);
	return (bytesprinted);
}

void	k_ft_call(const char *format, va_list clients, int i, int *k)
{
	if (format[i + 1] == 'i' || format[i + 1] == 'd')
		k_ft_print_int(clients, k);
	if (format[i + 1] == 's')
		k_ft_print_string(clients, k);
	if (format[i + 1] == 'c')
		k_ft_print_char(clients, k);
	if (format[i + 1] == 'p')
		k_ft_print_adress(clients, k);
	if (format[i + 1] == '%')
		k_ft_print_perc(k);
	if (format[i + 1] == 'x')
		k_ft_print_hex_low(clients, k);
	if (format[i + 1] == 'X')
		k_ft_print_hex_cap(clients, k);
	if (format[i + 1] == 'u')
		k_ft_print_unsigned(clients, k);
}

/*int	main(void)
{
	//char	*str = NULL;
	//char	c = '0';
	//int i = 16;
	//int	*b;

	//b = &i;
	//ft_printf("hallo %s %x", INT_MAX, INT_MIN);
	write(1, "\n", 1);
	ft_printf(" %x %x %x %x %x %x %x ", INT_MAX, INT_MIN, LONG_MAX,
	 LONG_MIN, ULONG_MAX, 0, -42);
	write(1, "\n", 1);
	return 0;
}*/

void	k_ft_print_perc(int *k)
{
	*k += write(1, "%", 1);
}

void	k_ft_print_unsigned(va_list clients, int *k)
{
	unsigned int	i;

	i = va_arg(clients, unsigned int);
	k_ft_putnbr_unsigned(i, k);
}

void	k_ft_putnbr_unsigned(unsigned int n, int *k)
{
	if (n >= 10)
	{
		k_ft_putnbr_fd(n / 10, 1, k);
		k_ft_putchar_fd((n % 10) + '0', 1, k);
	}
	if (n < (unsigned) 10)
		k_ft_putchar_fd((n % 10) + '0', 1, k);
}
