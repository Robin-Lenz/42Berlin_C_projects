/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:48:23 by rpodack           #+#    #+#             */
/*   Updated: 2023/05/16 22:03:20 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_it_collectable(map_params_t *m_param, int erste, int zweite)
{
	size_t	i;
	int	a;
	int	b;

	i = 0;
	if (m_param->map[erste][zweite] == 'C')
	{
		while (i != m_param->image_c->count)
		{
			a = m_param->image_c->instances[i].y / TILE_WIDTH;
			b = m_param->image_c->instances[i].x / TILE_WIDTH;
			if (a == erste && b == zweite)
			{
				m_param->image_c->instances[i].z = 0;
				m_param->map[erste][zweite] = '0';
				m_param->error.collectable--;
			}
			i++;
		}
	}
	if (m_param->error.collectable == 0)
	{
		if (m_param->map[erste][zweite] == 'E')
			mlx_close_window(m_param->mlx);
	}
}

void	render_map(map_params_t m_param)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	a = TILE_WIDTH;
	while (m_param.map[i])
	{
		j = 0;
		while (m_param.map[i][j])
		{
			mlx_image_to_window(m_param.mlx, m_param.image_g, j * a, i * a);
			if (m_param.map[i][j] == '1')
				mlx_image_to_window(m_param.mlx, m_param.image_w, j * a, i * a);
			else if (m_param.map[i][j] == 'C')
				mlx_image_to_window(m_param.mlx, m_param.image_c, j * a, i * a);
			else if (m_param.map[i][j] == 'E')
				mlx_image_to_window(m_param.mlx, m_param.image_e, j * a, i * a);
			else if (m_param.map[i][j] == 'P')
				mlx_image_to_window(m_param.mlx, m_param.image_p, j * a, i * a);
			j++;
		}
		i++;
	}
}

map_params_t	load_images(map_params_t m_param)
{
	m_param = load_ground(m_param);
	m_param = load_collectable(m_param);
	m_param = load_wall(m_param);
	m_param = put_player(m_param);
	m_param = load_exit(m_param);
	render_map(m_param);
	m_param = set_instances(m_param);
	m_param.steps = 0;
	return (m_param);
}

int	init_game(map_params_t m_param)
{
	mlx_image_t	*image;
	void		*param;
	int			c;
	int			d;

	d = TILE_WIDTH;
	c = m_param.nb_of_lines;
	m_param.mlx = mlx_init(m_param.error.width * d, c * d, "MLX42", true);
	image = mlx_new_image(m_param.mlx, TILE_WIDTH, TILE_WIDTH);
	if (!m_param.mlx)
		free_init_game(m_param);
	if (!image)
		free_init_game(m_param);
	if (mlx_image_to_window(m_param.mlx, image, 0, 0) == -1)
		free_init_game(m_param);
	m_param = load_images(m_param);
	param = (void *)&m_param;
	mlx_loop_hook(m_param.mlx, ft_hook, param);
	mlx_loop(m_param.mlx);
	mlx_terminate(m_param.mlx);
	return (EXIT_SUCCESS);
}

map_params_t	set_instances(map_params_t m_param)
{
	size_t	i;

	i = 0;
	m_param.image_p->instances->z = 5;
	m_param.image_e->instances->z = 3;
	while (i != m_param.image_g->count)
	{
		m_param.image_g->instances[i].z = 1;
		i++;
	}
	i = 0;
	while (i != m_param.image_w->count)
	{
		m_param.image_w->instances[i].z = 2;
		i++;
	}
	i = 0;
	while (i != m_param.image_c->count)
	{
		m_param.image_c->instances[i].z = 4;
		i++;
	}
	return (m_param);
}
