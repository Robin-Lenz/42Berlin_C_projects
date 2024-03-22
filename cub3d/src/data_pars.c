/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:06:06 by rpodack           #+#    #+#             */
/*   Updated: 2024/03/14 17:37:47 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	find_arg(char **str)
{
	char	*s;

	s = *str;
	while (ft_strchr(WHITESPACE, *s) && str)
		s++;
	*str = s;
}

int	extract_data(char **str, t_map *args)
{
	if (arg_len(*str) == 2)
		extract_texture(str, args);
	else if (arg_len(*str) == 1)
		extract_color(str, args);
	else
		error_get_data("wrong argument name\n", args, false);
	return (0);
}

int	get_data(char *line, t_map *args)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		find_arg(&line);
		extract_data(&line, args);
	}
	find_arg(&line);
	if (*line != '1' && *line != '0')
		error_get_data("Invalid char between Map and map info\n", args, false);
	while (*line)
	{
		if ((*line == '\n' && *(line +1) == '\n') || \
		(*line == '\n' && *(line +1) == '\0'))
			error_get_data("detected multiple newlines in map\n", args, false);
		line++;
	}
	return (0);
}

int	get_map_data(t_map *args)
{
	char	*tmp;

	tmp = args->map_line;
	if (get_data(tmp, args) == -1)
		return (-1);
	return (1);
}
