/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:36:41 by rpodack           #+#    #+#             */
/*   Updated: 2023/06/30 22:37:15 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_a(t_psl **a)
{
	t_psl	*tmp;

	if (!a || !(*a))
		return ;
	while (*a != NULL)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}

void	free_exit(t_psl **a)
{
	t_psl	*tmp;

    write(2, "Error\n", 6);
	while (*a != NULL)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	exit(1);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	error_after_init(t_psl **a, t_psl **tmp)
{
	write(2, "Error\n", 6);
	free_a(a);
	if (*tmp != NULL)
		free(*tmp);
	exit(1);
}

void	free_split(char **split, int i)
{
	if (i != -1)
	{
		while (i != 0)
		{
			free(split[i]);
			i--;
		}
		free(split[i]);
	}
	free(split);
	split = NULL;
}
