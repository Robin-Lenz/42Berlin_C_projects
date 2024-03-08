/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:04:58 by rpodack           #+#    #+#             */
/*   Updated: 2023/10/17 17:04:59 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

t_input	*init_input(char **av, int ac)
{
	t_input	*input;

	input = loc_in(av);
	if (ac == 6)
	{
		input->nb_meals = malloc(sizeof(int));
		(*input->nb_meals) = ft_check_arg(av[5]);
	}
	else
		input->nb_meals = NULL;
	return (input);
}

t_input	*loc_in(char **av)
{
	t_input	*input;

	input = malloc(sizeof(t_input));
	if (!input)
		return (NULL);
	input->num_phil = malloc(sizeof(int));
	if (!input->num_phil)
		free_loc(input);
	(*input->num_phil) = ft_check_arg(av[1]);
	input->t_to_live = malloc(sizeof(int));
	if (!input->t_to_live)
		free_loc(input);
	(*input->t_to_live) = ft_check_arg(av[2]);
	input->t_to_eat = malloc(sizeof(int));
	if (!input->t_to_eat)
		free_loc(input);
	(*input->t_to_eat) = ft_check_arg(av[3]);
	input->t_to_sleep = malloc(sizeof(int));
	if (!input->t_to_sleep)
		free_loc(input);
	(*input->t_to_sleep) = ft_check_arg(av[4]);
	return (input);
}
