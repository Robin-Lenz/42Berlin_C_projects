/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:26:28 by rpodack           #+#    #+#             */
/*   Updated: 2023/06/23 20:04:54 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_psl **a)
{
	t_psl	*tmp;

	tmp = find_max_index(a);
	if ((*a)->index == tmp->index)
		ft_ra(a);
	else if ((*a)->next->index == tmp->index)
		ft_rra(a);
	if ((*a)->index > (*a)->next->index)
		ft_sa(a);
}

void	sort(t_psl **a, t_psl **b)
{
	int	len_lst;

	len_lst = ft_lstsize_p(*a);
	if (len_lst == 2)
		ft_sa(a);
	else if (len_lst == 3)
		sort_three(a);
	else
	{
		chunk_em_up(a, b, len_lst);
		sort_three(a);
		bring_em_home(a, b, len_lst);
		while (is_sorted(*a) == 0)
			ft_rra(a);
	}
	free_a(a);
	free_a(b);
}
