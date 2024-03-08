/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:05:10 by rpodack           #+#    #+#             */
/*   Updated: 2023/10/17 17:16:45 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	print_out(t_ph *phil, int flag)
{
	long long	time;

	if (check(phil) == 1)
	{
		if (pthread_mutex_lock(phil->start->write) == 0)
		{
			time = ft_time() - phil->birthtime;
			if (flag == 0 && check(phil) == 1)
				printf("%lld %i is eating\n", time, (*phil->nb));
			else if (flag == 3 && check(phil) == 1)
				printf("%lld %i has taken a fork \n", time, (*phil->nb));
			else if (flag == 1 && check(phil) == 1)
				printf("%lld %i is sleeping\n", time, (*phil->nb));
			else if (flag == 2 && check(phil) == 1)
				printf("%lld %i is thinking\n", time, (*phil->nb));
			pthread_mutex_unlock(phil->start->write);
		}
	}
}
