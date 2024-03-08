/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunck_em_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:49:37 by rpodack           #+#    #+#             */
/*   Updated: 2023/06/24 20:05:15 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_em_up(t_psl **a, t_psl **b, int len_lst)
{
	int	i;
	int	chuncks;

	if (len_lst > 100)
		chuncks = 12;
	else if (len_lst > 50)
		chuncks = 6;
	else
		chuncks = 1;
	i = 1;
	while (ft_lstsize_p(*a) > 3)
	{
		if (((*a)->index <= (((len_lst - 3) / chuncks) * i)) && \
		(*a)->index <= len_lst - 3)
			ft_pb(a, b);
		else
			ft_ra(a);
		if (ft_lstsize_p(*a) <= ((((len_lst -3) / chuncks) * i) - len_lst) * -1)
			i++;
	}
}
