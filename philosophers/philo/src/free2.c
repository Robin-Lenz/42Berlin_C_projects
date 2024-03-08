/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:04:51 by rpodack           #+#    #+#             */
/*   Updated: 2023/10/17 17:04:52 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	free_first(t_ph *lst)
{
	free(lst->alive);
	free(lst->in->num_phil);
	free(lst->in->t_to_live);
	free(lst->in->t_to_eat);
	free(lst->in->t_to_sleep);
	if (lst->in->nb_meals)
		free(lst->in->nb_meals);
	free(lst->in);
	free(lst->nb);
	pthread_mutex_destroy(lst->live);
	free(lst->live);
	pthread_mutex_destroy(lst->write);
	free(lst->write);
	pthread_mutex_destroy(lst->mealnum);
	free(lst->mealnum);
	pthread_mutex_destroy(lst->meallock);
	free(lst->meallock);
	pthread_mutex_destroy(lst->fork);
	free(lst->fork);
	free(lst);
}

void	free_loc(t_input *in)
{
	if (in->num_phil)
		free(in->num_phil);
	if (in->t_to_live)
		free(in->t_to_live);
	if (in->t_to_eat)
		free(in->t_to_eat);
	if (in->t_to_sleep)
		free(in->t_to_sleep);
	if (in->nb_meals)
		free(in->nb_meals);
	if (in)
		free(in);
}

void	free_firstofall(t_ph *lst)
{
	free(lst->alive);
	free(lst->in->num_phil);
	free(lst->in->t_to_live);
	free(lst->in->t_to_eat);
	free(lst->in->t_to_sleep);
	if (lst->in->nb_meals)
		free(lst->in->nb_meals);
	free(lst->in);
	free(lst->nb);
	free(lst);
}
