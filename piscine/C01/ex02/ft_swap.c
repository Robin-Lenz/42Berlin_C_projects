/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:50:09 by rpodack           #+#    #+#             */
/*   Updated: 2022/08/22 17:50:13 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

/*
int	main(void)
{
	int	*a;
	int	*b;
	int 	num1;
	int	num2;
	
	num1 = 1;
	num2 = 2; 
	
	a = &num1;
	b = &num2;
	printf("%p\n", a);
	printf("%p\n", b);
	printf("\n");
	printf("%i", *a);
	printf("%i", *b);
	printf("\n");
	ft_swap(a, b);
	printf("\n");
	printf("%i", num1);
	printf("%i", num2);
	
	
}
*/
