/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:06:27 by rpodack           #+#    #+#             */
/*   Updated: 2024/03/14 15:45:21 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	logg_dir(t_map *env, char place)
{
	if (place == 'N')
	{
		env->pdir[0] = -1.0;
		env->pdir[1] = 0.0;
		env->planex = 0;
		env->planey = -0.66;
	}
	else if (place == 'S')
		logg_s_util(env);
	else if (place == 'E')
	{
		env->pdir[0] = 0;
		env->pdir[1] = 1;
		env->planex = -0.66;
		env->planey = 0;
	}
	else if (place == 'W')
	{
		env->pdir[0] = 0;
		env->pdir[1] = -1;
		env->planex = 0.66;
		env->planey = 0;
	}
}

int	find_start(char *line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			i++;
			while (line[i] == '\n')
				i++;
			j = i;
			while (line[j] != '\n')
			{
				if (line[j] != ' ' && line[j] != '1' && line[j] != '0')
					break ;
				j++;
			}
			if (line[j] == '\n')
				return (i);
		}
		i++;
	}
	return (1);
}

t_map	*init_map(char **av)
{
	t_map	*env;

	env = NULL;
	env = ft_calloc(sizeof(t_map), 1);
	if (!env)
		return (NULL);
	file_type(env, av[1]);
	get_map_line(env, av);
	env->map = ft_split(&env->map_line[find_start(env->map_line)], '\n');
	allowed_characters(env);
	if (env->player != 1)
		err_msg(env, 2);
	check_dimensions(env);
	env->map_copy = ft_split(&env->map_line[find_start(env->map_line)], '\n');
	is_enclosed(env);
	init_doubles(env);
	init_keypressed(env);
	init_pathptr(env);
	return (env);
}

void	get_map_line(t_map *env, char **av)
{
	int		flag;
	char	*tmp;

	flag = 1;
	tmp = NULL;
	env->map_line = NULL;
	env->fd = open(av[1], O_RDONLY);
	if (env->fd > 0)
	{
		while (flag != 0)
		{
			tmp = get_next_line(env->fd);
			if (!tmp)
			{
				flag = 0;
				break ;
			}
			env->map_line = ft_strjoin(env->map_line, tmp);
			free(tmp);
		}
	}
	else
		ft_err(env);
	close(env->fd);
}

void	free_load(t_map *env)
{
	free_image_path(env);
	free_2d(env->map);
	free_2d(env->map_copy);
	free(env->map_line);
	free_tex(env);
	free(env);
	exit(1);
}
