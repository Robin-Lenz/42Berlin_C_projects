/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:56:03 by rpodack           #+#    #+#             */
/*   Updated: 2023/06/30 22:58:39 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_psl **a)
{
	t_psl	*curr;
	int		min_value;
	int		len;

	len = ft_lstsize_p(*a) - 1;
	min_value = find_min(a);
	while (len)
	{
		curr = *a;
		find_max(&curr, &len, min_value);
		len--;
	}
	set_curr_pos(a);
}

void	set_curr_pos(t_psl **a)
{
	t_psl	*tmp;
	int		curr_pos;

	tmp = *a;
	curr_pos = 0;
	while (tmp)
	{
		tmp->curr_pos = curr_pos;
		curr_pos++;
		tmp = tmp->next;
	}
}

t_psl	*find_max_index(t_psl **a)
{
	t_psl	*curr;
	t_psl	*tmp;

	curr = *a;
	tmp = NULL;
	while (curr)
	{
		if (tmp == NULL || tmp->index < curr->index)
			tmp = curr;
		curr = curr->next;
	}
	return (tmp);
}

t_psl	*lowest_index(t_psl *a)
{
	t_psl	*curr;
	t_psl	*tmp;

	curr = a;
	tmp = NULL;
	while (curr)
	{
		if (tmp == NULL || tmp->index > curr->index)
			tmp = curr;
		curr = curr->next;
	}
	return (tmp);
}

long long int	ft_atoi(const char *nptr, t_psl **a, t_psl **tmp)
{
	long long int	res;
	int				i;
	long long int				schalter;

	res = 0;
	schalter = 1;
	i = 0;
	while ((nptr[i] <= '\r' && nptr[i] >= '\t') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			schalter = schalter * (-1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
        // res *= schalter;
        //printf("res:%lld\n", res);
		if ((res * schalter > 2147483647) || (res * schalter < -2147483648))
        {
            //printf("boy\n");
            //printf("res:%lld\n", res);
			error_after_init(a, tmp);
        }
	}
	return (res * schalter);
}
