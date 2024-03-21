/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:07:01 by rpodack           #+#    #+#             */
/*   Updated: 2023/01/16 20:38:17 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	k_ft_putchar_fd(char c, int fd, int *k)
{
	*k += write(fd, &c, 1);
}

void	k_ft_putstr_fd(char *s, int fd, int *k)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		*k += write(fd, &s[i], 1);
		i++;
	}
}

void	k_ft_print_string(va_list clients, int *k)
{
	int		i;
	char	*str;

	str = va_arg(clients, char *);
	i = 0;
	if (str == NULL)
	{
		*k += write(1, "(null)", 6);
		return ;
	}
	while (str[i] != '\0')
	{
		*k += write(1, &str[i], 1);
		i++;
	}
}

void	k_ft_print_char(va_list clients, int *k)
{
	char	c;

	c = va_arg(clients, int);
	*k += write(1, &c, 1);
}
