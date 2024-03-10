/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:06:38 by rpodack           #+#    #+#             */
/*   Updated: 2024/02/26 14:32:11 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move(t_map *env)
{
	double	dir_x0;
	double	plane_x0;

	(void)dir_x0;
	(void)plane_x0;
	if (env->key_s_pressed == 1)
		move_backwards(env);
	if (env->key_a_pressed == 1)
		move_left(env);
	if (env->key_w_pressed == 1)
		move_forward(env);
	if (env->key_d_pressed == 1)
		move_right(env);
	if (env->key_left_pressed == 1)
		ft_rotate_left(env);
	if (env->key_right_pressed == 1)
		ft_rotate_right(env);
}

void	move_backwards(t_map *env)
{
	double	x;

	x = -0.1;
	if (env->pdir[0] < 0)
		x = -x;
	if (env->map[(int)((env->ppos[0]) - env->pdir[0] * env->speed + x)][(int) \
	(env->ppos[1])] == '0' )
		env->ppos[0] -= env->speed * env->pdir[0];
	x = -0.1;
	if (env->pdir[1] < 0)
		x = -x;
	if (env->map[(int)(env->ppos[0])][(int)(env->ppos[1] - env->pdir[1] * \
	env->speed + x)] == '0')
		env->ppos[1] -= env->speed * env->pdir[1];
}

void	move_forward(t_map *env)
{
	double	x;

	x = 0.1;
	if (env->pdir[0] < 0)
		x = -x;
	if (env->map[(int)(env->ppos[0] + env->pdir[0] * env->speed + x)][(int) \
	(env->ppos[1])] == '0')
		env->ppos[0] += env->speed * env->pdir[0];
	x = 0.1;
	if (env->pdir[1] < 0)
		x = -x;
	if (env->map[(int)(env->ppos[0])][(int)(env->ppos[1] + env->pdir[1] * \
	env->speed + x)] == '0')
		env->ppos[1] += env->speed * env->pdir[1];
}

void	move_left(t_map *env)
{
	double	x;

	x = -0.1;
	if (env->pdir[1] < 0)
		x = -x;
	if (env->map[(int)(env->ppos[0] + -env->pdir[1] * env->speed + x)][(int) \
	(env->ppos[1])] == '0' )
		env->ppos[0] += env->speed * -env->pdir[1];
	x = -0.1;
	if (env->pdir[0] < 0)
		x = -x;
	if (env->map[(int)(env->ppos[0])][(int)(env->ppos[1] + env->pdir[0] * \
	env->speed - x)] == '0')
		env->ppos[1] += env->speed * env->pdir[0];
}

void	move_right(t_map *env)
{
	double	x;

	x = 0.1;
	if (env->pdir[1] < 0)
		x = -x;
	if (env->map[((int)(env->ppos[0] + env->pdir[1] * env->speed + x))][(int) \
	(env->ppos[1])] == '0' )
		env->ppos[0] += env->speed * env->pdir[1];
	x = 0.1;
	if (env->pdir[0] < 0)
		x = -x;
	if (env->map[(int)(env->ppos[0])][(int)(env->ppos[1] + -env->pdir[0] * \
	env->speed - x)] == '0')
		env->ppos[1] += env->speed * -env->pdir[0];
}
