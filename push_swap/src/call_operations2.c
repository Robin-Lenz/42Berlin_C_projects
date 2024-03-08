/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_operations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:25:44 by rpodack           #+#    #+#             */
/*   Updated: 2023/06/23 20:40:02 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_psl **a)
{
	write(1, "ra\n", 3);
	ft_rotate(a);
}

void	ft_rb(t_psl **b)
{
	write(1, "rb\n", 3);
	ft_rotate(b);
}

void	ft_rr(t_psl **a, t_psl **b)
{
	write(1, "rr\n", 3);
	ft_rotate(a);
	ft_rotate(b);
}

void	ft_rra(t_psl **a)
{
	write(1, "rra\n", 4);
	ft_revrotate(a);
}

void	ft_rrb(t_psl **b)
{
	write(1, "rrb\n", 4);
	ft_revrotate(b);
}
