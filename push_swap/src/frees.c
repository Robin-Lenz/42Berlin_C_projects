/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:05:58 by rpodack           #+#    #+#             */
/*   Updated: 2023/06/24 20:07:55 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_double(char **split)
{
	int	i;

	write(2, "Error\n", 6);
	i = 0;
	while (split[i])
	{
		i++;
	}
	while (i != 0)
	{
		free(split[i]);
		i--;
	}
	free(split[i]);
	free(split);
	split = NULL;
	exit(1);
}

void	free_sorted_split(char **split, t_psl **a)
{
	int	i;

	write(2, "Error\n", 6);
	i = 0;
	while (split[i])
	{
		i++;
	}
	while (i != 0)
	{
		free(split[i]);
		i--;
	}
	free(split[i]);
	free(split);
	split = NULL;
	free_a(a);
	exit(1);
}
