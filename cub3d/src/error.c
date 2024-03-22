/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:06:20 by rpodack           #+#    #+#             */
/*   Updated: 2024/03/14 17:43:19 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	err_msg(t_map *env, int flag)
{
	if (flag == 1)
		printf("invalid character in map\n");
	else if (flag == 2)
		printf("one player !\n");
	else if (flag == 3)
	{
		printf("not enclosed\n");
		free_2d(env->map);
		free_2d(env->map_copy);
		free(env->map_line);
		free(env);
		exit(1);
	}
	else if (flag == 4)
	{
		printf("not a valid filename\n");
		free(env);
		exit(1);
	}
	free_all(env);
	exit(1);
}

void	allowed_characters(t_map *env)
{
	int		i;
	int		j;
	char	**place;

	(void)env;
	env->player = 0;
	place = env->map;
	i = 0;
	while (place[i])
	{
		j = 0;
		while (place[i][j])
		{
			check_for_chars(place, env, i, j);
			j++;
		}
		i++;
	}
}

void	check_for_chars(char **place, t_map *env, int i, int j)
{
	if (place[i][j] != ' ' && place[i][j] != '1' && place[i][j] != '0' \
	&& place[i][j] != 'N' && place[i][j] != 'S' && place[i][j] != 'E' \
	&& place[i][j] != 'W')
		err_msg(env, 1);
	if (place[i][j] == 'N' || place[i][j] == 'S' || place[i][j] == 'E' \
	|| place[i][j] == 'W')
	{
		env->player++;
		env->ppos[0] = (double)i + 0.5;
		env->ppos[1] = (double)j + 0.5;
		logg_dir(env, place[i][j]);
		place[i][j] = '0';
	}
}

void	ft_err(t_map *env)
{
	printf("file not found\n");
	free_notfound(env);
	exit(1);
}
