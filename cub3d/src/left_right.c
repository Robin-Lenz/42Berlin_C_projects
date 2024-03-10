/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:31:10 by rpodack           #+#    #+#             */
/*   Updated: 2024/02/26 14:31:11 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_rotate_right(t_map *env)
{
	double	dir_x0;
	double	plane_x0;

	(void)dir_x0;
	(void)plane_x0;
	dir_x0 = env->pdir[0];
	env->pdir[0] = env->pdir[0] * cos(-env->rotate) - env->pdir[1] * \
	sin(-env->rotate);
	env->pdir[1] = dir_x0 * sin(-env->rotate) + env->pdir[1] * \
	cos(-env->rotate);
	plane_x0 = env->planex;
	env->planex = env->planex * cos(-env->rotate)
		- env->planey * sin(-env->rotate);
	env->planey = plane_x0 * sin(-env->rotate)
		+ env->planey * cos(-env->rotate);
}

void	ft_rotate_left(t_map *env)
{
	double	dir_x0;
	double	plane_x0;

	(void)dir_x0;
	(void)plane_x0;
	dir_x0 = env->pdir[0];
	env->pdir[0] = env->pdir[0] * cos(env->rotate) - env->pdir[1] * \
	sin(env->rotate);
	env->pdir[1] = dir_x0 * sin(env->rotate) + env->pdir[1] * \
	cos(env->rotate);
	plane_x0 = env->planex;
	env->planex = env->planex * cos(env->rotate)
		- env->planey * sin(env->rotate);
	env->planey = plane_x0 * sin(env->rotate)
		+ env->planey * cos(env->rotate);
}
