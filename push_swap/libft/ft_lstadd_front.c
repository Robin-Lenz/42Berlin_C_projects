/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:41:55 by rpodack           #+#    #+#             */
/*   Updated: 2022/12/29 16:41:55 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Return: The new node

Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with
the value of the parameter ’content’. The variable
’next’ is initialized to NULL.
*/

/*
lst: The address of a pointer to the first link of
a list.
new: The address of a pointer to the node to be
added to the list.

Adds the node ’new’ at the beginning of the list.
*/
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
/*
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	change_content(void *pn);
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void change_content_again(void *pn);
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new -> next = *lst;
	*lst = new;
}
/*
int main()
{
    
    char t1[] = "one";
    char t2[] = "two";
    char t3[] = "three";
    char t0[] = "zero";
    char t4[] = "a";
    char t5[] = "five";
    

    

	t_list	*lst;
    t_list  *elem1;
    t_list  *elem2;
    void *del;
    del = change_content;

    void *f;
    f = change_content_again;

    lst = ft_lstnew(t1);
    lst -> next = malloc(sizeof(t_list));
    lst -> next -> content = t2;
    lst->next -> next = malloc(sizeof(t_list));
    lst -> next -> next -> content = (void *) t3;
    
    lst->next -> next -> next = NULL;

    t_list *curr1 = lst;
    while (curr1 != NULL)
    {
        printf("%s\n",(char *) curr1 ->  content);
        curr1 = curr1 -> next;
    }

    elem1 = malloc(sizeof(t_list));
    elem1 -> content = (void *) t0;
    ft_lstadd_front(&lst, elem1); 

     t_list *curr = lst;
    while (curr != NULL)
    {
        printf("%s\n",(char *) curr ->  content);
        curr = curr -> next;
    }

    elem1 = malloc(sizeof(t_list));
    elem1 -> content = (void *) t4;
    ft_lstadd_front(&lst, elem1); 

    t_list *curr2 = lst;
    while (curr2 != NULL)
    {
        printf("%p\n", (char *) curr2 ->  content);
        curr2= curr2 -> next;
    }
    printf("%i\n", ft_lstsize(lst));
    elem2 = ft_lstlast(lst);
    printf("%s\n", (char *) elem2 ->  content);

    elem1 = malloc(sizeof(t_list));
    elem1 -> content = (void *) t5;
    
    ft_lstadd_back(&lst, elem1);

    t_list *curr3 = lst;
    while (curr3 != NULL)
    {
        printf("%s\n", (char *) curr3 ->  content);
        curr3 = curr3 -> next;
    }

    ft_lstdelone(lst -> next, del);

    t_list *curr4 = lst;
    while (curr4 != NULL)
    {
        printf("%s\n", (char *) curr4 ->  content);
        curr4 = curr4 -> next;
    }
    
    ft_lstmap(lst, f, del);

    t_list *curr5 = lst;
    while (curr5 != NULL)
    {
        printf("%s\n", (char *) curr5 ->  content);
        curr5 = curr5 -> next;
    }    
}


t_list *ft_lstnew(void *content)
{
    t_list  *newelement;

    newelement = malloc(sizeof(t_list));
    if (!newelement)
        return (NULL);
    newelement->content = content;
    newelement->next = NULL;

    return (newelement);

}

int ft_lstsize(t_list *lst)
{
    t_list  *curr;
    int i;

    i = 0;
    curr = lst;
    while (curr != NULL)
    {
        curr = curr -> next ;
        i++;
    }
    return (i);
}

t_list *ft_lstlast(t_list *lst)
{
    t_list  *curr;
    
    curr = lst;
    while (curr->next != NULL)
        curr = curr -> next ;
    return (curr);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *curr;

    curr = *lst;
    while ( curr -> next != NULL)
        curr = curr -> next;
    curr -> next = new;
    new -> next = NULL;
}

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
    del(lst -> content);
    free(lst);
}

void change_content(void *pn)
{
    int i;
    char str[] = "$$$";
    char *txt;

    txt = pn;
    i = 0;
    while (txt[i] != '\0' && str[i] != '\0')
    {
        txt[i]  = str[i];
        i++;
    }
    txt[i] = '\0';
}

void change_content_again(void *pn)
{
    int i;
    char str[] = "Dollar";
    char *txt;

    txt = pn;
    i = 0;
    while (txt[i] != '\0' && str[i] != '\0')
    {
        txt[i]  = str[i];
        i++;
    }
    txt[i] = '\0';
}

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *ptr;

    ptr = *lst;
    while (ptr -> next)
    {
        del(ptr);
        ptr = ptr -> next;
    }
    *lst = NULL;
}

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *ptr;

    ptr = lst;
    while (ptr -> next)
    {
        f(ptr ->content);
        ptr = ptr -> next;
    }
}*/
