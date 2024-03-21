/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:17:24 by rpodack           #+#    #+#             */
/*   Updated: 2023/05/16 22:09:11 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

map_params_t	read_file(map_params_t m_param)
{
	int		flag;
	char	*tmp;

	flag = 0;
	m_param.i = 0;
	m_param.map_line = NULL;
	while (flag != 1)
	{
		tmp = get_next_line(m_param.fd);
		if (tmp != NULL)
			m_param.map_line = ft_strjoin(m_param.map_line, tmp);
		if (tmp == NULL)
			flag = 1;
		free(tmp);
		tmp = NULL;
		(m_param.i)++;
	}
	if (m_param.map_line == NULL)
	{
		ft_printf("Error\nempty map");
		exit(1);
	}
	close(m_param.fd);
	return (m_param);
}

map_params_t	init_m_param(char *file_name)
{
	map_params_t	m_param;

	m_param.error.fail = 0;
	m_param.fd = open(file_name, O_RDONLY);
	if (m_param.fd == -1)
	{
		ft_printf("file does not exist");
		exit(1);
	}
	m_param.file_name = file_name;
	m_param = read_file(m_param);
	m_param.len_total = ft_strlen(m_param.map_line);
	m_param.nb_of_lines = m_param.i - 1;
	m_param = check_for_consecutive(m_param);
	if (m_param.error.fail == -9)
		free_too_many_nl(m_param);
	m_param.map = ft_split(m_param.map_line, '\n');
	m_param.c_count = 0;
	m_param = evaluate_map(m_param);
	return (m_param);
}

int	main(int ac, char **av)
{
	map_params_t	m_param;

	if (ac != 2)
	{
		ft_printf("Error\njust enter the filename of one! "
			"valid map it's not that hard...\n");
		return (-1);
	}
	m_param = init_m_param(av[1]);
	if (m_param.error.fail < 0)
	{
		m_param = free_mapfree(m_param);
		return (-1);
	}
	init_game(m_param);
	m_param = free_mapfree(m_param);
	return (0);
}
