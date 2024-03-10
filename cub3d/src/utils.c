/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:06:47 by rpodack           #+#    #+#             */
/*   Updated: 2024/02/10 19:06:48 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/cub3d.h"

int	ft_strlen_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_lenarr(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	check_dimensions(t_map *env)
{
	env->height_map = ft_lenarr(env->map);
	env->longest_line = longest_line(env->map);
}

// void	check_for_wall_hit(t_map *env, int hit, int side)
// {
// 	(void)hit;
// 	// check_for_wall_hit(env, hit, side);
// 	//Check if ray has hit a wall
// 	if (env->map[env->mapx][env->mapy] != '0')
// 	{
// 		hit = 1;
// 		handle_wall_hit(env, side);
// 	}
// }
