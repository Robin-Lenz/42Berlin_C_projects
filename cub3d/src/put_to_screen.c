/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:06:44 by rpodack           #+#    #+#             */
/*   Updated: 2024/02/10 19:06:45 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	put_image(t_map *env, int x)
{
	int		texnum;
	int		texx;
	double	wallx; //where exactly the wall was hit
	//texturing calculations
	texnum = env->map[env->mapx][env->mapy] - 1;
	(void)texnum;
	//calculate value of wallX
	if (env->side == 0)
		wallx = env->ppos[1] + env->perpwalldist * env->raydiry;
	else
		wallx = env->ppos[0] + env->perpwalldist * env->raydirx;
	wallx -= floor((wallx));
	//x coordinate on the texture
	texx = (int)(wallx * env->tex[env->wall_direction]->width);// tex width
	if (env->side == 0 && env->raydirx > 0)
		texx = env->tex[env->wall_direction]->width - texx - 1;
	if (env->side == 1 && env->raydiry < 0)
		texx = env->tex[env->wall_direction]->width - texx - 1;
	put_it(env, x, texx);
}

void	put_it(t_map *env, int x, int texx)
{
	double		step;
	double		tex_pos;
	int			y;
	uint8_t		*pixel;
	int			tex_y;

	step = 1.0 * env->tex[env->wall_direction]->height / env->lineheight;
	tex_pos = (env->drawstart - 100 - SCREENHEIGHT / 2 \
		+ env->lineheight / 2) * step ;
	y = env->drawstart;
	while (y < env->drawend)
	{
		tex_y = (int)tex_pos & (env->tex[env->wall_direction]->height - 1);
		tex_pos += step;
		pixel = &(env->tex[env->wall_direction]->pixels[(texx + tex_y * \
		(env->tex[env->wall_direction]->width)) * \
		(env->tex[env->wall_direction]->bytes_per_pixel)]);
		put_pixel(env->image, x, y, pixel[0] << 24 | pixel[1] << 16 | \
		pixel[2] << 8 | pixel[3]);
		y++;
	}
}
