/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   profession.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:05:13 by rpodack           #+#    #+#             */
/*   Updated: 2023/10/17 17:54:59 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	check_forks(t_ph *phil)
{
	if (pthread_mutex_lock(phil->fork) == 0)
	{
		if (phil->flag_fork != 0)
		{
			pthread_mutex_unlock(phil->fork);
			return (1);
		}
		pthread_mutex_unlock(phil->fork);
	}
	if (pthread_mutex_lock(phil->prev->fork) == 0)
	{
		if (phil->prev->flag_fork == 0)
		{
			pthread_mutex_unlock(phil->prev->fork);
			return (0);
		}
		pthread_mutex_unlock(phil->prev->fork);
	}
	return (1);
}

void	eat(t_ph *phil)
{
	int	start;

	start = ft_gettime(phil);
	if (lock_forks(phil) == 0)
	{
		print_out(phil, 0);
		while ((ft_gettime(phil) - start) < (*phil->in->t_to_eat))
		{
			if (why_we_die(phil) != 0)
				break ;
			usleep(100);
		}
		unlock_forks(phil);
		if (pthread_mutex_lock(phil->start->mealnum) == 0)
		{
			phil->meals++;
			phil->last_meal = ft_gettime(phil);
			pthread_mutex_unlock(phil->start->mealnum);
		}
		check_meals(phil);
	}
}

void	ft_sleep(t_ph *phil)
{
	int	start;

	start = ft_gettime(phil);
	if (check(phil) == 0)
		return ;
	print_out(phil, 1);
	while ((ft_gettime(phil) - start) < (*phil->in->t_to_sleep))
	{
		if (why_we_die(phil) != 0)
			break ;
		usleep(100);
	}
}

int	lock_forks(t_ph *phil)
{
	int	a;

	a = lock_first(phil);
	if ((*phil->in->num_phil) != 1 && pthread_mutex_lock(phil->prev->fork) == 0)
	{
		if (phil->prev->flag_fork == 0)
		{
			(phil->prev->flag_fork) = 1;
			a++;
		}
		pthread_mutex_unlock(phil->prev->fork);
	}
	if (a == 2)
	{
		print_out(phil, 3);
		print_out(phil, 3);
		return (0);
	}
	unlock_forks(phil);
	return (1);
}

void	unlock_forks(t_ph *phil)
{
	if (pthread_mutex_lock(phil->fork) == 0)
	{
		if (phil->flag_fork == 1)
			(phil->flag_fork) = 0;
		pthread_mutex_unlock(phil->fork);
	}
	if (pthread_mutex_lock(phil->prev->fork) == 0)
	{
		if (phil->prev->flag_fork == 1)
			(phil->prev->flag_fork) = 0;
		pthread_mutex_unlock(phil->prev->fork);
	}
}
