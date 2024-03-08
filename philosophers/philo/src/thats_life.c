/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thats_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:05:17 by rpodack           #+#    #+#             */
/*   Updated: 2023/10/17 20:40:27 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	*life_of_a_thinker(void *curr)
{
	t_ph	*phil;

	phil = (t_ph *)curr;
	if ((*phil->in->num_phil) == 1)
	{
		lock_fork_for_one(phil);
		eat(phil);
		while (ft_starve(phil) == 0)
			continue ;
		die_of_hunger(phil);
		return (NULL);
	}
	if ((*phil->nb) % 2 == 0)
		usleep(5000);
	usleep(((*phil->nb) - (*phil->in->num_phil)) * (-100));
	while (check(phil) == 1)
	{
		if (cycle_of_life(phil) != 0)
			break ;
	}
	return (NULL);
}

int	cycle_of_life(t_ph *phil)
{
	if (why_we_die(phil) != 0)
		return (1);
	print_out(phil, 2);
	while (1)
	{
		if (why_we_die(phil) != 0)
			break ;
		if (who_gets_served(phil) != 0 && check_forks(phil) == 0)
			break ;
		usleep(100);
	}
	eat(phil);
	if (why_we_die(phil) != 0)
		return (1);
	ft_sleep(phil);
	return (0);
}

int	why_we_die(t_ph *phil)
{
	int	why_we_die;

	why_we_die = ft_starve(phil);
	if (check(phil) != 1)
		return (1);
	if (why_we_die == 2)
	{
		finish_meal(phil);
		return (1);
	}
	if (why_we_die == 1)
	{
		die_of_hunger((phil));
		return (1);
	}
	return (0);
}
