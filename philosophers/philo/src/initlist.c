/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:15:59 by rpodack           #+#    #+#             */
/*   Updated: 2023/10/17 19:57:50 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

t_ph	*init_list(char **av, int ac)
{
	t_ph	*lst;
	t_ph	*tmp;
	int		i;

	i = 1;
	lst = ft_lstnew_p();
	init_first_node(lst);
	keep_on_initing(lst, ac, av);
	while (i < (*lst->in->num_phil))
	{
		i++;
		tmp = init_tmp();
		(*tmp->nb) = i;
		tmp->av = av;
		tmp->ac = ac;
		tmp->in = init_input(av, ac);
		tmp->birthtime = lst->birthtime;
		tmp->start = lst;
		tmp->meals = 0;
		tmp->last_meal = ft_gettime(tmp);
		ft_lstadd_back_p(&lst, tmp);
	}
	return (lst);
}

long long	ft_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

t_ph	*init_tmp(void)
{
	t_ph	*tmp;

	tmp = malloc(sizeof(t_ph));
	if (!tmp)
		clean_tmp(tmp);
	tmp->nb = malloc(sizeof(int));
	if (!tmp->nb)
		clean_tmp(tmp);
	tmp->fork = malloc(sizeof(pthread_mutex_t));
	if (!tmp->fork)
		clean_tmp(tmp);
	tmp->meallock = malloc(sizeof(pthread_mutex_t));
	if (!tmp->meallock)
		clean_tmp(tmp);
	pthread_mutex_init(tmp->fork, NULL);
	pthread_mutex_init(tmp->meallock, NULL);
	tmp->live = NULL;
	tmp->mealnum = NULL;
	tmp->alive = NULL;
	tmp->flag_fork = 0;
	tmp->meals = 0;
	return (tmp);
}

int	init_first_node(t_ph *lst)
{
	lst->alive = (int *)malloc(sizeof(int));
	if (!lst->alive)
		return (clean_first_node(lst));
	lst->nb = malloc(sizeof(int));
	if (!lst->nb)
		return (clean_first_node(lst));
	lst->fork = malloc(sizeof(pthread_mutex_t));
	if (!lst->fork)
		return (clean_first_node(lst));
	lst->live = malloc(sizeof(pthread_mutex_t));
	if (!lst->live)
		return (clean_first_node(lst));
	lst->mealnum = malloc(sizeof(pthread_mutex_t));
	if (!lst->mealnum)
		return (clean_first_node(lst));
	lst->write = malloc(sizeof(pthread_mutex_t));
	if (!lst->write)
		return (clean_first_node(lst));
	lst->meallock = malloc(sizeof(pthread_mutex_t));
	if (!lst->meallock)
		return (clean_first_node(lst));
	return (1);
}

void	keep_on_initing(t_ph *lst, int ac, char **av)
{
	pthread_mutex_init(lst->mealnum, NULL);
	pthread_mutex_init(lst->live, NULL);
	pthread_mutex_init(lst->fork, NULL);
	pthread_mutex_init(lst->write, NULL);
	pthread_mutex_init(lst->meallock, NULL);
	(*lst->nb) = 1;
	(*lst->alive) = 1;
	lst->av = av;
	lst->ac = ac;
	lst->in = init_input(av, ac);
	lst->start = lst;
	lst->birthtime = ft_time();
	lst->flag_fork = 0;
	lst->meals = 0;
	lst->last_meal = ft_gettime(lst);
	lst->fedup = 0;
}
