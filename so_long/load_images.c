/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:36:03 by rpodack           #+#    #+#             */
/*   Updated: 2023/05/15 21:06:52 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

map_params_t	load_exit(map_params_t m_param)
{
	mlx_t	*m;

	m = m_param.mlx;
	m_param.texture_e = mlx_load_xpm42("./textures/exit.xpm42");
	if (!m_param.texture_e)
		free_game(m_param);
	m_param.image_e = mlx_texture_to_image(m, &m_param.texture_e->texture);
	if (!m_param.image_e)
		free_game(m_param);
	mlx_delete_xpm42(m_param.texture_e);
	return (m_param);
}

map_params_t	load_wall(map_params_t m_param)
{
	mlx_t	*m;

	m = m_param.mlx;
	m_param.texture_w = mlx_load_xpm42("./textures/wall.xpm42");
	if (!m_param.texture_w)
		free_game(m_param);
	m_param.image_w = mlx_texture_to_image(m, &m_param.texture_w->texture);
	if (!m_param.image_w)
		free_game(m_param);
	mlx_delete_xpm42(m_param.texture_w);
	return (m_param);
}

map_params_t	load_ground(map_params_t m_param)
{
	mlx_t	*m;

	m = m_param.mlx;
	m_param.texture_g = mlx_load_xpm42("./textures/ground.xpm42");
	if (!m_param.texture_g)
		free_game(m_param);
	m_param.image_g = mlx_texture_to_image(m, &m_param.texture_g->texture);
	if (!m_param.image_g)
		free_game(m_param);
	mlx_delete_xpm42(m_param.texture_g);
	return (m_param);
}

map_params_t	load_collectable(map_params_t m_param)
{
	mlx_t	*m;

	m = m_param.mlx;
	m_param.texture_c = mlx_load_xpm42("./textures/collectable.xpm42");
	if (!m_param.texture_c)
		free_game(m_param);
	m_param.image_c = mlx_texture_to_image(m, &m_param.texture_c->texture);
	if (!m_param.image_c)
		free_game(m_param);
	mlx_delete_xpm42(m_param.texture_c);
	return (m_param);
}

map_params_t	put_player(map_params_t m_param)
{
	mlx_t	*m;

	m = m_param.mlx;
	m_param.texture_p = mlx_load_xpm42("./textures/player.xpm42");
	if (!m_param.texture_p)
		free_game(m_param);
	m_param.image_p = mlx_texture_to_image(m, &m_param.texture_p->texture);
	if (!m_param.image_p)
		free_game(m_param);
	mlx_delete_xpm42(m_param.texture_p);
	return (m_param);
}
