/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:09:24 by rpodack           #+#    #+#             */
/*   Updated: 2023/05/16 22:19:55 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_copy(char **map_copy, map_params_t m_param)
{
	int	i;

	i = m_param.nb_of_lines - 1;
	if (i != -1)
	{
		while (i != 0)
		{
			free(map_copy[i]);
			i--;
		}
		free(map_copy[i]);
	}
	free(map_copy);
	map_copy = NULL;
}

map_params_t	free_mapfree(map_params_t m_param)
{
	int	i;

	i = m_param.nb_of_lines - 1;
	if (i != -1)
	{
		while (i != 0)
		{
			free(m_param.map[i]);
			i--;
		}
		free(m_param.map[i]);
	}
	free(m_param.map);
	free(m_param.map_line);
	m_param.map_line = NULL;
	m_param.map = NULL;
	return (m_param);
}

void	free_game(map_params_t m_param)
{
	ft_printf("Error\nsomething is wrong check load_images.c\n");
	free_mapfree(m_param);
	mlx_terminate(m_param.mlx);
	exit(1);
}

void	free_too_many_nl(map_params_t m_param)
{
	ft_printf("Error\nremove excessive new lines");
	free(m_param.map_line);
	m_param.map_line = NULL;
	exit(1);
}

void	free_init_game(map_params_t m_param)
{
	ft_printf("Error\ninit game failed\n");
	free_mapfree(m_param);
	mlx_terminate(m_param.mlx);
	exit(1);
}
