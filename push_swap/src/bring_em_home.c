/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_em_home.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:01:08 by rpodack           #+#    #+#             */
/*   Updated: 2023/06/25 17:15:13 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_em_home(t_psl **a, t_psl **b, int len_lst)
{
	t_psl	*max_b;
	int		flag;

	(void)len_lst;
	while (*b)
	{
		flag = 0;
		max_b = find_max_index(b);
		set_curr_pos(b);
		if_elses(a, b, max_b, &flag);
	}
}

void	if_elses(t_psl **a, t_psl **b, t_psl *max_b, int *flag)
{
	t_psl	*last_a;

	last_a = NULL;
	last_a = get_last(a, last_a);
	if ((*b)->index == (*a)->index - 1)
		get_lines(a, b, flag, last_a);
	else if ((*b)->index > last_a->index)
	{
		ft_pa(a, b);
		ft_ra(a);
		*flag = 1;
	}
	else if (*flag == 0 && max_b->curr_pos <= ft_lstsize_p(*b) / 2)
	{
		while (max_b->index != (*b)->index)
			ft_rb(b);
	}
	else if (*flag == 0 && max_b->curr_pos > ft_lstsize_p(*b) / 2)
	{
		while (max_b->index != (*b)->index)
			ft_rrb(b);
	}
	if ((*a)->index - 1 == last_a->index)
		ft_rra(a);
}

t_psl	*get_last(t_psl **a, t_psl *last_a)
{
	last_a = *a;
	while (last_a->next != NULL)
		last_a = last_a->next;
	return (last_a);
}

void	get_lines(t_psl **a, t_psl **b, int *flag, t_psl *last_a)
{
	ft_pa(a, b);
	if ((*a)->index - 1 == last_a->index)
		ft_rra(a);
	*flag = 1;
}
