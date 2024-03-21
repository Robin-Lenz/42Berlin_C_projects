/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:11:07 by rpodack           #+#    #+#             */
/*   Updated: 2022/12/27 21:11:07 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (lst && *lst)
	{
		ptr = *lst;
		while (ptr -> next)
			ptr = ptr -> next;
		ptr -> next = new;
	}
	else if (lst)
		*lst = new;
}
/*
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	curr = *lst;
	while (curr -> next != NULL)
		curr = curr -> next;
	curr -> next = new;
	new -> next = NULL;
}
*/