/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:29:23 by rpodack           #+#    #+#             */
/*   Updated: 2023/10/20 19:49:52 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	lock_fork_for_one(t_ph *phil)
{
	if (pthread_mutex_lock(phil->fork) == 0)
	{
		if (phil->flag_fork == 0)
		{
			(phil->flag_fork) = 1;
			print_out(phil, 3);
		}
		pthread_mutex_unlock(phil->fork);
	}
	if ((*phil->in->num_phil) != 1 && pthread_mutex_lock(phil->prev->fork) == 0)
	{
		if (phil->prev->flag_fork == 0)
		{
			(phil->prev->flag_fork) = 1;
			print_out(phil, 3);
		}
		pthread_mutex_unlock(phil->prev->fork);
	}
	unlock_forks(phil);
	return (1);
}

int	lock_first(t_ph *phil)
{
	int	a;

	a = 0;
	if (pthread_mutex_lock(phil->fork) == 0)
	{
		if (phil->flag_fork == 0)
		{
			(phil->flag_fork) = 1;
			a++;
		}
		pthread_mutex_unlock(phil->fork);
	}
	return (a);
}

int	who_gets_served(t_ph *phil)
{
	if (pthread_mutex_lock(phil->start->mealnum) == 0)
	{
		if (phil->meals == 0)
		{
			pthread_mutex_unlock(phil->start->mealnum);
			return (1);
		}
		if (phil->meals < phil->prev->meals && phil->meals < phil->next->meals)
		{
			pthread_mutex_unlock(phil->start->mealnum);
			return (1);
		}
		if (phil->last_meal < phil->prev->last_meal && phil->last_meal < \
		phil->next->last_meal)
		{
			pthread_mutex_unlock(phil->start->mealnum);
			return (1);
		}
	}
	pthread_mutex_unlock(phil->start->mealnum);
	return (0);
}

void	check_meals(t_ph *phil)
{
	if (phil->ac == 6 && phil->meals == (*phil->in->nb_meals))
	{
		if (pthread_mutex_lock(phil->start->meallock) == 0)
		{
			phil->start->fedup++;
			pthread_mutex_unlock(phil->start->meallock);
			all_fed_up(phil);
		}
	}
}
