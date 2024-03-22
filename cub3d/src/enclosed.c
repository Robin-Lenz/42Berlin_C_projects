/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enclosed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:38:09 by rpodack           #+#    #+#             */
/*   Updated: 2024/03/22 16:48:29 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include <string.h>

void	check_first_char(t_map *env, char *str)
{
	while (ft_strchr(" ", *str))
		str++;
	if (*str == '0')
		err_msg(env, 3);
}

void	check_lines(t_map *env)
{
	int		i;
	int		j;

	i = -1;
	while (env->map[++i])
	{
		j = 0;
		check_first_char(env, env->map[i]);
		while (env->map[i][j])
		{
			if (env->map[i][j] == ' ' && env->map[i][j + 1] == '0')
				err_msg(env, 3);
			else if (env->map[i][j] == '0' && env->map[i][j + 1] == ' ')
				err_msg(env, 3);
			else if (env->map[i][j] == '0' && env->map[i][j + 1] == '\0')
				err_msg(env, 3);
			else
				j++;
		}
	}
}

void	check_columns1(t_map *env, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (map[i][++j])
	{
		i = 0;
		if (map[i][j] == '0')
			enclosed_error(env, map);
		while (map[i] && map[i + 1] != NULL)
		{
			if (map[i][j] == ' ' && map[i + 1][j] == '0')
				enclosed_error(env, map);
			else if (map[i][j] == '0' && map[i + 1][j] == ' ')
				enclosed_error(env, map);
			else
				i++;
		}
		if (map[i][j] == '0' || (map[i][j] == ' ' && map[i - 1][j] == '0'))
			enclosed_error(env, map);
	}
	free_2d(map);
}

void	check_columns(t_map *env)
{
	char	**map;
	int		i;
	int		j;

	i = -1;
	map = ft_calloc(env->height_map + 1, sizeof(char *));
	if (!map)
		err_msg(env, 3);
	while (++i < env->height_map)
	{
		j = -1;
		map[i] = ft_calloc(env->longest_line + 1, sizeof(char));
		if (!map[i])
		{
			free_2d(map);
			err_msg(env, 3);
		}
		while (env->map[i][++j])
			map[i][j] = env->map[i][j];
		while (j < env->longest_line)
			map[i][j++] = ' ';
	}
	check_columns1(env, map);
}

void	is_enclosed(t_map *env)
{
	check_lines(env);
	check_columns(env);
}
