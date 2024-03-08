/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:36:33 by rpodack           #+#    #+#             */
/*   Updated: 2023/06/24 19:13:02 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_psl *a)
{
	t_psl	*curr;

	curr = a;
	while (curr->next)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	is_duplicate(t_psl *tmp, t_psl *a)
{
	t_psl	*curr;

	curr = a;
	while (curr != NULL)
	{
		if (curr->content == tmp->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	is_all_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] == '+' || av[i][j] == '-')
			j++;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
