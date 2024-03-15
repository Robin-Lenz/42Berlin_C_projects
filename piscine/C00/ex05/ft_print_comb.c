/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   versuch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:45:23 by rpodack           #+#    #+#             */
/*   Updated: 2022/08/18 20:45:26 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	output(char f_d, char s_d, char t_d)
{
	write(1, &f_d, 1);
	write(1, &s_d, 1);
	write(1, &t_d, 1);
	if (f_d < '7')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	first_digit;
	int	second_digit;
	int	third_digit;

	first_digit = '0';
	while (first_digit <= '7')
	{
		second_digit = first_digit + 1;
		while (second_digit <= '8')
		{
			third_digit = second_digit + 1;
			while (third_digit <= '9')
			{
				output(first_digit, second_digit, third_digit);
				third_digit++;
			}
			second_digit++;
		}	
		first_digit++;
	}
}
