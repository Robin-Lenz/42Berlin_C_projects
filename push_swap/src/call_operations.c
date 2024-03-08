/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:27:35 by rpodack           #+#    #+#             */
/*   Updated: 2023/06/23 20:26:09 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_psl **a)
{
	write(1, "sa\n", 3);
	ft_swap(a);
}

void	ft_sb(t_psl **b)
{
	write(1, "sb\n", 3);
	ft_swap(b);
}

void	ft_ss(t_psl **a, t_psl **b)
{
	write(1, "ss\n", 3);
	ft_swap(a);
	ft_swap(b);
}

void	ft_pa(t_psl **a, t_psl **b)
{
	write(1, "pa\n", 3);
	ft_push(b, a);
}

void	ft_pb(t_psl **a, t_psl **b)
{
	write(1, "pb\n", 3);
	ft_push(a, b);
}
