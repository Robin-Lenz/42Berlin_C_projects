/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:30:59 by rpodack           #+#    #+#             */
/*   Updated: 2024/03/14 18:38:01 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_doubles(t_map *env)
{
	env->time = 0.0;
	env->oldtime = 0.0;
	env->camerax = 0.0;
	env->speed = 5.0 / 100;
	env->rotate = 2.0 / 100;
}

void	init_keypressed(t_map *env)
{
	env->key_w_pressed = 0;
	env->key_s_pressed = 0;
	env->key_a_pressed = 0;
	env->key_d_pressed = 0;
	env->key_left_pressed = 0;
	env->key_right_pressed = 0;
}

void	init_pathptr(t_map *env)
{
	env->no = NULL;
	env->so = NULL;
	env->we = NULL;
	env->ea = NULL;
	env->ceiling_color = 1;
	env->floor_color = 1;
}

int	longest_line(char **map)
{
	int	len;
	int	i;
	int	tmp;

	len = 0;
	i = 0;
	while (map[i])
	{
		tmp = ft_strlen(map[i]);
		if (tmp > len)
			len = tmp;
		i++;
	}
	return (len);
}

void	logg_s_util(t_map *env)
{
	env->pdir[0] = 1;
	env->pdir[1] = 0;
	env->planex = 0;
	env->planey = 0.66;
}
