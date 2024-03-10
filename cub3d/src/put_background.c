/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:06:41 by rpodack           #+#    #+#             */
/*   Updated: 2024/02/26 14:33:38 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_pixel(uint8_t *pixel, uint32_t color)
{
	*(pixel++) = (uint8_t)(color >> 24);
	*(pixel++) = (uint8_t)(color >> 16);
	*(pixel++) = (uint8_t)(color >> 8);
	*(pixel++) = (uint8_t)(color & 0xFF);
}

void	put_pixel(mlx_image_t *image, uint32_t x, uint32_t y, uint32_t color)
{
	uint8_t	*pixelstart;

	pixelstart = &image->pixels[(y * image->width + x) * sizeof(int32_t)];
	draw_pixel(pixelstart, color);
}

void	draw_floor_ceiling(t_map *env, int x)
{
	int	y;

	y = 0;
	while (y < env->drawstart)
	{
		put_pixel(env->image, x, y, env->ceiling_color);
		y++;
	}
	y = env->drawend;
	while (y < SCREENHEIGHT)
	{
		put_pixel(env->image, x, y, env->floor_color);
		y++;
	}
}

void	clear_image(t_map *env)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < SCREENHEIGHT)
	{
		x = 0;
		while (x < SCREENWIDTH)
		{
			put_pixel(env->image, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}
