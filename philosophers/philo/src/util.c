/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:05:20 by rpodack           #+#    #+#             */
/*   Updated: 2023/10/17 17:15:35 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	ft_check_arg(char *str)
{
	long long	res;
	int			i;

	i = 0;
	res = 0;
	if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = (res * 10) + (str[i] - '0');
			i++;
		}
		else
			return (-1);
	}
	if (res > INT_MAX || res == 0)
		return (-1);
	return ((int)res);
}

long long	ft_gettime(t_ph*phil)
{
	long long	time;

	time = ft_time() - phil->birthtime;
	return (time);
}

int	ft_starve(t_ph *phil)
{
	long long	time;
	int			doa;

	time = ft_gettime(phil);
	doa = time - phil->last_meal;
	if (doa >= (*phil->in->t_to_live))
		return (1);
	if ((*phil->in->num_phil) != 1 && all_fed_up(phil) != 0)
		return (2);
	return (0);
}

int	all_fed_up(t_ph *phil)
{
	if (phil->ac < 6)
		return (0);
	if (pthread_mutex_lock(phil->start->meallock) == 0)
	{
		if (phil->start->fedup == (*phil->in->num_phil))
		{
			pthread_mutex_unlock(phil->start->meallock);
			finish_meal(phil);
			return (1);
		}
		pthread_mutex_unlock(phil->start->meallock);
	}
	return (0);
}

int	check(t_ph *phil)
{
	if (pthread_mutex_lock(phil->start->live) == 0)
	{
		if ((*phil->start->alive) == 0)
		{
			pthread_mutex_unlock(phil->start->live);
			return (0);
		}
		else
		{
			pthread_mutex_unlock(phil->start->live);
			return (1);
		}
	}
	else
		printf("locking live in check failed\n");
	return (1);
}
