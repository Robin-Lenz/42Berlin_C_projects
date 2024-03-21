/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:53:58 by rpodack           #+#    #+#             */
/*   Updated: 2023/05/16 18:30:51 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

map_params_t	check_for_consecutive(map_params_t m_param)
{
	int	i;

	i = 0;
	if (m_param.map_line[i] == '\n')
	{
		m_param.error.fail = -9;
		return (m_param);
	}
	while (m_param.map_line[i])
	{
		if (m_param.map_line[i] == '\n' && m_param.map_line[i +1] == '\n')
		{
			m_param.error.fail = -9;
			return (m_param);
		}
		if (m_param.map_line[i] == '\n' && m_param.map_line[i + 1] == '\0')
		{
			m_param.error.fail = -9;
			return (m_param);
		}
		i++;
	}
	return (m_param);
}

map_params_t	coords(map_params_t m_param)
{
	int	i;
	int	j;

	i = 0;
	while (m_param.map[i])
	{
		j = 0;
		while (m_param.map[i][j])
		{
			m_param = get_them(m_param, i, j);
			if (m_param.map[i][j] == '1' || m_param.map[i][j] == '0'
			|| m_param.map[i][j] == 'E' || m_param.map[i][j] == 'P'
			|| m_param.map[i][j] == 'C')
				;
			else
				m_param.error.fail = -7;
			j++;
		}
		i++;
	}
	m_param = check_pec(m_param);
	return (m_param);
}

error_t	enclosed(map_params_t m_param, error_t err)
{
	int	i;
	int	j;
	int	width;

	width = err.width - 1;
	i = m_param.nb_of_lines - 1;
	while (i >= 0)
	{
		if (i == m_param.nb_of_lines - 1 || i == 0)
		{
			j = -1;
			while (m_param.map[i][++j])
			{
				if (m_param.map[i][j] != '1')
					err.fail = -2;
			}
		}
		else if (i < m_param.nb_of_lines - 1 && i != 0)
		{
			if (m_param.map[i][0] != '1' || m_param.map[i][width] != '1')
				err.fail = -2;
		}
		i--;
	}
	return (err);
}

error_t	rectangle(map_params_t m_param, error_t error)
{
	int	j;

	error.collectable = 0;
	error.exit = 0;
	error.player = 0;
	error.fail = 0;
	j = m_param.nb_of_lines - 1;
	while (j >= 0)
	{
		if (j == m_param.nb_of_lines - 1)
		{
			error.width = ft_strlen(m_param.map[0]);
			if (!(ft_strlen(m_param.map[j]) == error.width))
				error.fail = -1;
		}
		else if (j < m_param.nb_of_lines - 1)
		{
			if (!(ft_strlen(m_param.map[j]) == error.width))
				error.fail = -1;
		}
		j--;
	}
	return (error);
}

map_params_t	evaluate_map(map_params_t m_param)
{
	char	**map_copy;
	int		*fail;

	m_param.error = rectangle(m_param, m_param.error);
	m_param.error = enclosed(m_param, m_param.error);
	m_param.error = file_type(m_param, m_param.error);
	m_param = coords(m_param);
	map_copy = ft_split(m_param.map_line, '\n');
	fail = &m_param.error.fail;
	if (m_param.error.fail == 0)
	{
		m_param.error.fail = -8;
		flood_fill(map_copy, m_param.p.x, m_param.p.y, fail, &m_param.c_count);
	}
	free_map_copy(map_copy, m_param);
	if (m_param.c_count != m_param.error.collectable)
		m_param.error.fail = -8;
	if (m_param.error.fail < 0)
	{
		print_err(m_param.error);
		return (m_param);
	}
	return (m_param);
}
