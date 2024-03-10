/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:07:29 by rpodack           #+#    #+#             */
/*   Updated: 2023/01/16 21:39:48 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

void	k_ft_print_string(va_list clients, int *k);
void	k_ft_print_char(va_list clients, int *k);
void	k_ft_put_hex(uintptr_t	i, int *k);
void	k_ft_print_adress(va_list clients, int *k);
void	k_ft_print_perc(int *k);
void	k_ft_print_hex_low(va_list clients, int *k);
void	k_ft_print_hex_cap(va_list clients, int *k);
void	k_ft_print_unsigned(va_list clients, int *k);
void	k_ft_putnbr_unsigned(unsigned int n, int *k);
void	k_ft_call(const char *format, va_list clients, int i, int *k);
void	k_ft_print_int(va_list clients, int *k);
int		ft_printf(const char *format, ...);
void	k_ft_putchar_fd(char c, int fd, int *k);
void	k_ft_putstr_fd(char *s, int fd, int *k);
void	k_ft_put_hex_cap(uintptr_t	i, int *k);
void	k_ft_putnbr_fd(int n, int fd, int *k);

#endif
