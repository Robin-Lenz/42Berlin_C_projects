/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:39:14 by rpodack           #+#    #+#             */
/*   Updated: 2023/06/23 20:03:16 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_psl	*ft_lstnew_p(int content)
{
	t_psl	*newelement;

	newelement = malloc(sizeof(t_psl));
	if (!newelement)
		return (NULL);
	newelement->content = content;
	newelement->index = -1;
	newelement->curr_pos = -1;
	newelement->next = NULL;
	return (newelement);
}

void	ft_lstadd_back_p(t_psl **lst, t_psl *new)
{
	t_psl	*testnode;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			testnode = *lst;
			while (testnode->next != NULL)
				testnode = testnode->next;
			testnode->next = new;
			new->index = -1;
			new->curr_pos = -1;
			new->next = NULL;
		}
	}
}

int	ft_lstsize_p(t_psl *lst)
{
	t_psl	*curr;
	int		i;

	i = 0;
	curr = lst;
	while (curr != NULL)
	{
		curr = curr -> next ;
		i++;
	}
	return (i);
}
