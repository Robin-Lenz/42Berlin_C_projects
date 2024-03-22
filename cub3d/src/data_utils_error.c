/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:06:16 by rpodack           #+#    #+#             */
/*   Updated: 2024/03/14 17:41:49 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	error_get_data(char *error_msg, t_map *args, bool sys_func)
{
	if (sys_func == true)
		perror(error_msg);
	else
		ft_putstr_fd(error_msg, 2);
	free(args->map_line);
	free_2d(args->map);
	free_2d(args->map_copy);
	if (args->no)
		free(args->no);
	if (args->so)
		free(args->so);
	if (args->we)
		free(args->we);
	if (args->ea)
		free(args->ea);
	free(args);
	exit(-77);
}

void	get_and_calc_color2(t_color var, t_map *args, uint32_t res)
{
	if (var == CEILING)
	{
		if (args->ceiling_color == 1)
			args->ceiling_color = (res << 8) | 0xFF;
		else
			error_get_data("RGBA Error\n", args, false);
	}
	else
	{
		if (args->floor_color == 1)
			args->floor_color = (res << 8) | 0xFF;
		else
			error_get_data("RGBA Error\n", args, false);
	}
}

void	error_path(char *path, t_map *args)
{
	free(path);
	error_get_data("Path Error!!!\n", args, false);
}

void	assign_path(char *path, t_map *args, t_direction direction)
{
	if (direction == NO)
	{
		if (args->no != NULL)
			error_path(path, args);
		args->no = path;
	}
	else if (direction == SO)
	{
		if (args->so != NULL)
			error_path(path, args);
		args->so = path;
	}
	else if (direction == WE)
	{
		if (args->we != NULL)
			error_path(path, args);
		args->we = path;
	}
	else if (direction == EA)
	{
		if (args->ea != NULL)
			error_path(path, args);
		args->ea = path;
	}
}

void	enclosed_error(t_map *env, char **map)
{
	free_2d(map);
	err_msg(env, 3);
}
