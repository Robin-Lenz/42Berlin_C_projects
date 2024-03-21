/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:41:21 by rpodack           #+#    #+#             */
/*   Updated: 2023/05/16 22:08:54 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	help_w(mlx_key_data_t keydata, map_params_t *m_param, int *steps)
{
	int	a;
	int	b;

	a = m_param->image_p->instances[0].x / TILE_WIDTH;
	b = m_param->image_p->instances[0].y / TILE_WIDTH;
	if (keydata.key == MLX_KEY_W && keydata.action == 1)
	{
		if (check_the_field_to_be_accessed(a, b, keydata, m_param) == 0)
		{
			m_param->image_p->instances[0].y -= TILE_WIDTH;
			*steps += 1;
			ft_printf("%i\n", m_param->steps);
		}
	}
}

void	help_s(mlx_key_data_t keydata, map_params_t *m_param, int *steps)
{
	int	a;
	int	b;

	a = m_param->image_p->instances[0].x / TILE_WIDTH;
	b = m_param->image_p->instances[0].y / TILE_WIDTH;
	if (keydata.key == MLX_KEY_S && keydata.action == 1)
	{
		if (check_the_field_to_be_accessed(a, b, keydata, m_param) == 0)
		{
			m_param->image_p->instances[0].y += TILE_WIDTH;
			*steps += 1;
			ft_printf("%i\n", m_param->steps);
		}
	}
}

void	help_a(mlx_key_data_t keydata, map_params_t *m_param, int *steps)
{
	int	a;
	int	b;

	a = m_param->image_p->instances[0].x / TILE_WIDTH;
	b = m_param->image_p->instances[0].y / TILE_WIDTH;
	if (keydata.key == MLX_KEY_A && keydata.action == 1)
	{
		if (check_the_field_to_be_accessed(a, b, keydata, m_param) == 0)
		{
			m_param->image_p->instances[0].x -= TILE_WIDTH;
			*steps += 1;
			ft_printf("%i\n", m_param->steps);
		}
	}
}

void	help_d(mlx_key_data_t keydata, map_params_t *m_param, int *steps)
{
	int	a;
	int	b;

	a = m_param->image_p->instances[0].x / TILE_WIDTH;
	b = m_param->image_p->instances[0].y / TILE_WIDTH;
	if (keydata.key == MLX_KEY_D && keydata.action == 1)
	{
		if (check_the_field_to_be_accessed(a, b, keydata, m_param) == 0)
		{
			m_param->image_p->instances[0].x += TILE_WIDTH;
			*steps += 1;
			ft_printf("%i\n", m_param->steps);
		}
	}
}
