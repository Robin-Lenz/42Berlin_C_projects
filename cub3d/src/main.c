/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:06:35 by rpodack           #+#    #+#             */
/*   Updated: 2024/02/10 19:06:36 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_map	*env;

	if (ac != 2)
	{
		printf("wrong entry\n");
		return (1);
	}
	env = init_map(av);
	get_map_data(env);
	init_game(env);
	free_all(env);
	return (0);
}
