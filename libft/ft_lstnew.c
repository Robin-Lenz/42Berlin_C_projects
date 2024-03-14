/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:36:13 by rpodack           #+#    #+#             */
/*   Updated: 2022/12/27 21:36:13 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newelement;

	newelement = malloc(sizeof(t_list));
	if (!newelement)
		return (NULL);
	newelement->content = content;
	newelement->next = NULL;
	return (newelement);
}
/*
int		main(void)
{
	char	str[] = "lorem ipsum dolor sit";

	t_list	*lst;
    t_list  *lst1;
    t_list  *lst2;

	lst = ft_lstnew((void *)str);
	printf("\n%s\n", lst->content);

    lst1 = ft_lstlast(lst);
    printf("\n%s\n", lst1->content);

    lst2 = ft_lstlast(lst1);
    printf("\n%s\n", lst2->content);   
}*/
