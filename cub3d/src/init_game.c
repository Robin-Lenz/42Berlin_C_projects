/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:05:56 by rpodack           #+#    #+#             */
/*   Updated: 2024/03/14 17:39:23 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	game_loop(void *en)
{
	int		x;
	t_map	*env;

	env = (t_map *)en;
	move(env);
	clear_image(env);
	x = 0;
	while (x < SCREENWIDTH)
	{
		env->mapx = env->ppos[0];
		env->mapy = env->ppos[1];
		get_raydir(env, x);
		collect_data_for_dda(env);
		steps(env);
		dda_exec(env);
		calc_perpwalldist(env);
		calc_draw_startend(env);
		draw_floor_ceiling(env, x);
		put_image(env, x);
		x++;
	}
}

void	handle_wall_hit(t_map *env, int *side)
{
	env->side = *side;
	if (*side == 0)
	{
		if (env->stepx < 0)
			env->wall_direction = 0;
		else
			env->wall_direction = 1;
	}
	else
	{
		if (env->stepy < 0)
			env->wall_direction = 2;
		else
			env->wall_direction = 3;
	}
}

void	dda_exec(t_map *env)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
		next_square(env, &hit, &side);
}

void	next_square(t_map *env, int *hit, int *side)
{
	if (env->sidedistx < env->sidedisty)
	{
		env->sidedistx += env->deltadistx;
		env->mapx += env->stepx;
		*side = 0;
	}
	else
	{
		env->sidedisty += env->deltadisty;
		env->mapy += env->stepy;
		*side = 1;
	}
	if (env->map[env->mapx][env->mapy] != '0')
	{
		*hit = 1;
		handle_wall_hit(env, side);
	}
}

void	init_game(t_map *env)
{
	init_images(env);
	mlx_set_setting(MLX_STRETCH_IMAGE, false);
	env->mlx = mlx_init(SCREENWIDTH, SCREENHEIGHT, "cub3D", false);
	if (!env->mlx)
		return ;
	env->image = mlx_new_image(env->mlx, SCREENWIDTH, SCREENHEIGHT);
	if (!env->image)
	{
		free_all(env);
		exit(-1);
	}
	if (mlx_image_to_window(env->mlx, env->image, 0, 0) < 0)
	{
		free_all(env);
		exit(-1);
	}
	mlx_loop_hook(env->mlx, game_loop, env);
	mlx_key_hook(env->mlx, &keyhook, env);
	mlx_loop(env->mlx);
}
