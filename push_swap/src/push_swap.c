/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:58:58 by rpodack           #+#    #+#             */
/*   Updated: 2023/06/24 20:03:51 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_psl	*a;
	t_psl	*b;
	t_psl	*tmp_max;
	char	**split;

	a = NULL;
	b = NULL;
	tmp_max = NULL;
	if (ac < 2)
		exit(1);
	if (ac == 2 && handle_quotes(av, a, tmp_max) == 1)
	{
		split = ft_split(av[1], ' ');
		a = init_stack_split(split, &a);
		tmp_max = find_max_index(&a);
		free_split(split, tmp_max->index);
	}
	else if (ac > 2)
		a = init_stack(av, &a);
	sort(&a, &b);
	return (0);
}

int	handle_quotes(char **av, t_psl *a, t_psl *tmp_max)
{
	long long int	first_num;

	(void)first_num;
	first_num = ft_atoi(av[1], &a, &tmp_max);
	return (1);
}

void	printlist(t_psl *a)
{
	t_psl	*t;

	t = a;
	while (t != NULL)
	{
		printf("is index %i", t -> index);
		printf(" curr pos  %i", t ->curr_pos);
		printf(" content %i\n", t -> content);
		t = t->next;
	}
	write(1, "\n", 1);
}

	//printf("a\n");
	//printlist(a);
	//printf("b\n");
	//printlist(b);
