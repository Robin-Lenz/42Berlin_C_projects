/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:35:13 by rpodack           #+#    #+#             */
/*   Updated: 2022/12/27 21:35:13 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst -> next)
			return (lst);
		lst = lst -> next ;
	}
	return (lst);
}
/*
t_list *ft_lstlast(t_list *lst)
{
    t_list  *curr;
    
	
    curr = lst;
    while (curr)
	{
		if (!curr -> next)
				return (curr);
        curr = curr -> next ;
	}
    return (curr);
}*/
