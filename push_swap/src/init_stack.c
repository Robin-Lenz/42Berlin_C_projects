/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:38:26 by rpodack           #+#    #+#             */
/*   Updated: 2023/06/24 19:53:14 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_max(t_psl **a, int *len, int min_value)
{
	t_psl	*curr;
	t_psl	*tmp;

	if (a == NULL || *a == NULL)
		free_exit(a);
	curr = *a;
	tmp = curr;
	while (curr)
	{
		if (curr->content > min_value && curr->index == -1)
		{
			tmp = curr;
			min_value = curr->content;
		}
		curr = curr->next;
	}
	tmp->index = *len + 1;
}

int	find_min(t_psl **a)
{
	t_psl	*curr;
	t_psl	*tmp;
	int		min;

	if (a == NULL || *a == NULL)
		free_exit(a);
	curr = *a;
	tmp = curr;
	min = curr->content;
	while (curr)
	{
		if (curr->content < min && curr->index == -1)
		{
			tmp = curr;
			min = tmp->content;
		}
		curr = curr->next;
	}
	tmp->index = 1;
	return (tmp->content);
}

t_psl	*init_stack(char **av, t_psl **a)
{
	int		i;
	t_psl	*tmp;

	tmp = NULL;
	i = 1;
	if (is_all_digit(av) == 0)
		free_exit(a);
	(*a) = ft_lstnew_p(ft_atoi(av[i], a, &tmp));
	if (!*a)
		free_exit(a);
	while (av[++i])
	{
		allocate_em(a, tmp, av, i);
	}
	if (is_sorted(*a) == 1)
		free_exit(a);
	set_index(a);
	return (*a);
}

t_psl	*init_stack_split(char **av, t_psl **a)
{
	int		i;
	t_psl	*tmp;

	tmp = NULL;
	i = 0;
	if (is_all_digit(av) == 0)
		free_double(av);
	(*a) = ft_lstnew_p(ft_atoi(av[i], a, &tmp));
	if (!*a)
		free_exit(a);
	while (av[++i])
		allocate_em(a, tmp, av, i);
	if (ft_lstsize_p(*a) == 1)
	{
		free(*a);
		free_double(av);
	}
	if (is_sorted(*a) == 1)
		free_sorted_split(av, a);
	set_index(a);
	return (*a);
}

void	allocate_em(t_psl **a, t_psl *tmp, char **av, int i)
{
	tmp = malloc(sizeof(t_psl));
	if (!tmp)
		error_after_init(a, &tmp);
	tmp->content = ft_atoi(av[i], a, &tmp);
	tmp->curr_pos = -1;
	if (is_duplicate(tmp, *a) == 1)
		ft_lstadd_back_p(a, tmp);
	else
		error_after_init(a, &tmp);
}
