/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imiges.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:06:33 by rpodack           #+#    #+#             */
/*   Updated: 2024/02/26 14:53:21 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_images(t_map *env)
{
	load_sw(env);
	load_ww(env);
	load_nw(env);
	load_ew(env);
}

void	load_nw(t_map *env)
{
	env->tex[0] = mlx_load_png(env->no);
	if (!env->tex[0])
		free_load(env);
}

void	load_sw(t_map *env)
{
	env->tex[1] = mlx_load_png(env->so);
	if (!env->tex[1])
		free_load(env);
}

void	load_ww(t_map *env)
{
	env->tex[2] = mlx_load_png(env->we);
	if (!env->tex[2])
		free_load(env);
}

void	load_ew(t_map *env)
{
	env->tex[3] = mlx_load_png(env->ea);
	if (!env->tex[3])
		free_load(env);
}
