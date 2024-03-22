/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:05:29 by rpodack           #+#    #+#             */
/*   Updated: 2024/03/14 17:36:57 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	get_raydir(t_map *env, int x)
{
	env->camerax = 2 * x / (double)SCREENWIDTH - 1;
	env->camerax = -env->camerax;
	env->raydirx = env->pdir[0] + env->planex * env->camerax;
	env->raydiry = env->pdir[1] + env->planey * env->camerax;
}

void	collect_data_for_dda(t_map *env)
{
	if (env->raydirx == 0)
		env->deltadistx = 1e30;
	else
		env->deltadistx = fabs(1 / env->raydirx);
	if (env->raydiry == 0)
		env->deltadisty = 1e30;
	else
		env->deltadisty = fabs(1 / env->raydiry);
}

void	steps(t_map *env)
{
	if (env->raydirx < 0)
	{
		env->stepx = -1;
		env->sidedistx = (env->ppos[0] - env->mapx) * env->deltadistx;
	}
	else
	{
		env->stepx = 1;
		env->sidedistx = (env->mapx + 1.0 - env->ppos[0]) * env->deltadistx;
	}
	if (env->raydiry < 0)
	{
		env->stepy = -1;
		env->sidedisty = (env->ppos[1] - env->mapy) * env->deltadisty;
	}
	else
	{
		env->stepy = 1;
		env->sidedisty = (env->mapy + 1.0 - env->ppos[1]) * env->deltadisty;
	}
}

void	calc_draw_startend(t_map *env)
{
	env->drawstart = 0;
	env->drawend = 0;
	env->lineheight = SCREENHEIGHT / env->perpwalldist;
	env->drawstart = -env->lineheight / 2 + SCREENHEIGHT / 2 + 100;
	if (env->drawstart < 0)
		env->drawstart = 0;
	env->drawend = env->lineheight / 2 + SCREENHEIGHT / 2 + 100;
	if (env->drawend >= SCREENHEIGHT || env->drawend < 0)
		env->drawend = SCREENHEIGHT - 1;
}

void	calc_perpwalldist(t_map *env)
{
	if (env->side == 0)
		env->perpwalldist = (env->sidedistx - env->deltadistx);
	else
		env->perpwalldist = (env->sidedisty - env->deltadisty);
}
