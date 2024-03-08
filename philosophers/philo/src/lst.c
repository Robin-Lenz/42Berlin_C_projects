/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:05:04 by rpodack           #+#    #+#             */
/*   Updated: 2023/10/17 17:05:05 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

t_ph	*ft_lstnew_p(void)
{
	t_ph	*newelement;

	newelement = malloc(sizeof(t_ph));
	if (!newelement)
		return (NULL);
	newelement->next = newelement;
	newelement->prev = newelement;
	return (newelement);
}

void	ft_lstadd_back_p(t_ph **lst, t_ph *new)
{
	t_ph	*ptr;

	if (lst && *lst)
	{
		ptr = *lst;
		while (ptr->next != *lst)
			ptr = ptr->next;
		ptr->next = new;
		new->prev = ptr;
		(*lst)->prev = new;
	}
	else if (lst)
		*lst = new;
	new->next = *lst;
}
