/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:24:18 by rpodack           #+#    #+#             */
/*   Updated: 2023/06/23 20:07:18 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_psl **x)
{
	int	tmp;
	int	tmp2;

	if (*x != NULL && (*x)->next != NULL)
	{
		tmp = (*x)->content;
		tmp2 = (*x)->index;
		(*x)->content = (*x)->next->content;
		(*x)->index = (*x)->next->index;
		(*x)->next->content = tmp;
		(*x)->next->index = tmp2;
	}
}

void	ft_push(t_psl **a, t_psl **b)
{
	t_psl	*tmp;

	if (*a == NULL)
		return ;
	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
}

void	ft_revrotate(t_psl **a)
{
	t_psl	*curr;
	t_psl	*prev;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	curr = *a;
	prev = NULL;
	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	curr->next = *a;
	*a = curr;
	prev->next = NULL;
}

void	ft_rotate(t_psl **a)
{
	t_psl	*curr;
	t_psl	*tmp;

	if (*a == NULL)
		return ;
	curr = *a;
	while (curr && curr->next != NULL)
		curr = curr->next;
	curr->next = *a;
	tmp = (*a)->next;
	(*a)->next = NULL;
	*a = tmp;
}
