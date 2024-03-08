/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:04:44 by rpodack           #+#    #+#             */
/*   Updated: 2023/10/17 19:56:50 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	clean_up(t_ph *lst)
{
	t_ph	*curr;
	t_ph	*tmp;

	tmp = lst->next;
	destroy_mutexes(lst);
	lst->prev->next = NULL;
	while (tmp)
	{
		curr = tmp;
		tmp = tmp->next;
		clean_stuff(curr);
		pthread_mutex_destroy(curr->fork);
		free(curr->fork);
		pthread_mutex_destroy(curr->meallock);
		free(curr->meallock);
		free(curr);
	}
	free_firstofall(lst);
	return ;
}

void	destroy_mutexes(t_ph *lst)
{
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
}

int	clean_first_node(t_ph *lst)
{
	if (lst->alive)
		free(lst->alive);
	if (lst->nb)
		free(lst->alive);
	if (lst->fork)
		free(lst->fork);
	if (lst->live)
		free(lst->live);
	if (lst->mealnum)
		free(lst->mealnum);
	if (lst->write)
		free(lst->write);
	if (lst->meallock)
		free(lst->meallock);
	return (0);
}

void	clean_tmp(t_ph *tmp)
{
	pthread_mutex_destroy(tmp->fork);
	pthread_mutex_destroy(tmp->meallock);
	if (tmp->nb)
		free(tmp->nb);
	if (tmp->fork)
		free(tmp->fork);
	if (tmp->meallock)
		free(tmp->meallock);
	if (tmp)
		free(tmp);
}

void	clean_stuff(t_ph *curr)
{
	if (curr->in->num_phil)
		free(curr->in->num_phil);
	if (curr->in->t_to_live)
		free(curr->in->t_to_live);
	if (curr->in->t_to_eat)
		free(curr->in->t_to_eat);
	if (curr->in->t_to_sleep)
		free(curr->in->t_to_sleep);
	if (curr->in->nb_meals)
		free(curr->in->nb_meals);
	if (curr->in)
		free(curr->in);
	if (curr->nb)
		free(curr->nb);
}
