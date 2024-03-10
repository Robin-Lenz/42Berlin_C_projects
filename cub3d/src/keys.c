/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:06:30 by rpodack           #+#    #+#             */
/*   Updated: 2024/02/10 19:06:31 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	keys_ws(mlx_key_data_t keydata, t_map *env)
{
	if (keydata.key == MLX_KEY_W)
	{
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
			env->key_w_pressed = 1;
		if (keydata.action == MLX_RELEASE)
			env->key_w_pressed = 0;
	}
	if (keydata.key == MLX_KEY_S)
	{
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
			env->key_s_pressed = 1;
		if (keydata.action == MLX_RELEASE)
			env->key_s_pressed = 0;
	}
}

void	keys_ad(mlx_key_data_t keydata, t_map *env)
{
	if (keydata.key == MLX_KEY_A)
	{
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
			env->key_a_pressed = 1;
		if (keydata.action == MLX_RELEASE)
			env->key_a_pressed = 0;
	}
	if (keydata.key == MLX_KEY_D)
	{
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
			env->key_d_pressed = 1;
		if (keydata.action == MLX_RELEASE)
			env->key_d_pressed = 0;
	}
}

void	keys_left_right(mlx_key_data_t keydata, t_map *env)
{
	if (keydata.key == MLX_KEY_LEFT)
	{
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
			env->key_left_pressed = 1;
		if (keydata.action == MLX_RELEASE)
			env->key_left_pressed = 0;
	}
	if (keydata.key == MLX_KEY_RIGHT)
	{
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
			env->key_right_pressed = 1;
		if (keydata.action == MLX_RELEASE)
			env->key_right_pressed = 0;
	}
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*env;

	(void)env;
	env = (t_map *)param;
	keys_ws(keydata, param);
	keys_ad(keydata, param);
	keys_left_right(keydata, param);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		free_all(env);
		exit(0);
	}
}
