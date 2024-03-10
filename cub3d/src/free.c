/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:06:22 by rpodack           #+#    #+#             */
/*   Updated: 2024/02/26 15:10:57 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_2d(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_all(t_map *env)
{
	if (env->map_line)
		free(env->map_line);
	free_image_path(env);
	if (env->map)
		free_2d(env->map);
	if (env->map_copy)
		free_2d(env->map_copy);
	free_tex(env);
	if (env->mlx)
		mlx_terminate(env->mlx);
	free(env);
}

void	free_tex(t_map *env)
{
	if (env->tex[0])
		mlx_delete_texture(env->tex[0]);
	if (env->tex[1])
		mlx_delete_texture(env->tex[1]);
	if (env->tex[2])
		mlx_delete_texture(env->tex[2]);
	if (env->tex[3])
		mlx_delete_texture(env->tex[3]);
}

void	free_image_path(t_map *env)
{
	if (env->we)
		free(env->we);
	if (env->ea)
		free(env->ea);
	if (env->so)
		free(env->so);
	if (env->no)
		free(env->no);
}

void	free_notfound(t_map *env)
{
	free(env);
}
