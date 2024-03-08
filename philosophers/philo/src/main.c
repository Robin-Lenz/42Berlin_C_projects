/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:05:07 by rpodack           #+#    #+#             */
/*   Updated: 2023/10/17 17:16:24 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	create_threads(t_ph *lst)
{
	int			i;
	int			j;
	pthread_t	th[200];
	t_ph		*curr;

	i = 0;
	curr = lst;
	while ((*curr->in->num_phil) > i)
	{
		if (pthread_create(&th[i], NULL, &life_of_a_thinker, (void *)curr) != 0)
			printf("error creating threads %i\n", i);
		i++;
		curr = curr->next;
	}
	j = 0;
	while (j < (*lst->in->num_phil))
	{
		if (pthread_join(th[j], NULL) != 0)
			printf("error joining threads %i\n", j);
		j++;
	}
}

int	main(int ac, char **av)
{
	t_ph	*lst;

	if (!(ac == 5 || ac == 6) || errorcheck(ac, av) != 0)
	{
		printf("wrong entry\n");
		return (1);
	}
	lst = init_list(av, ac);
	create_threads(lst);
	if ((*lst->in->num_phil) == 1)
		free_first(lst);
	else
		clean_up(lst);
	return (0);
}

int	errorcheck(int ac, char **av)
{
	if (ft_check_arg(av[1]) < 0)
		return (1);
	if (ft_check_arg(av[2]) < 0)
		return (1);
	if (ft_check_arg(av[3]) < 0)
		return (1);
	if (ft_check_arg(av[4]) < 0)
		return (1);
	if (ac == 6)
	{
		if (ft_check_arg(av[5]) < 0)
			return (1);
	}
	return (0);
}

void	finish_meal(t_ph *phil)
{
	long long	time;
	int			meals;

	if (pthread_mutex_lock(phil->start->live) == 0)
	{
		if ((*phil->start->alive) == 1)
		{
			(*phil->start->alive) = 0;
			pthread_mutex_unlock(phil->start->live);
			meals = (*phil->in->nb_meals);
			time = ft_gettime(phil);
			printf("%lld %i was last eating %i meals\n", time, (*phil->nb), \
			meals);
			return ;
		}
		pthread_mutex_unlock(phil->start->live);
	}
}

void	die_of_hunger(t_ph *phil)
{
	long long	time;

	if (pthread_mutex_lock(phil->start->live) == 0)
	{
		if ((*phil->start->alive) == 1)
		{
			(*phil->start->alive) = 0;
			pthread_mutex_unlock(phil->start->live);
			time = ft_gettime(phil);
			printf("%lld %i died ahhhhhhhhhhhhhh\n", time, (*phil->nb));
			return ;
		}
		pthread_mutex_unlock(phil->start->live);
	}
}

// 1 philo has to lock fork
