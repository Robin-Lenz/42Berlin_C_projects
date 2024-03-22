/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:06:47 by rpodack           #+#    #+#             */
/*   Updated: 2024/03/14 17:38:26 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_strlen_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_lenarr(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	check_dimensions(t_map *env)
{
	env->height_map = ft_lenarr(env->map);
	env->longest_line = longest_line(env->map);
}

// void	check_for_wall_hit(t_map *env, int hit, int side)
// {
// 	(void)hit;
// 	// check_for_wall_hit(env, hit, side);
// 	//Check if ray has hit a wall
// 	if (env->map[env->mapx][env->mapy] != '0')
// 	{
// 		hit = 1;
// 		handle_wall_hit(env, side);
// 	}
// }

int	ft_strncmp_mod(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = ft_strlen(s1) - 4;
	j = 0;
	while (j < n)
	{
		if (s1[i] != s2[j])
			return ((unsigned char) s1[i] - (unsigned char) s2[j]);
		if (s2[j] == '\0' || s1[i] == '\0')
			return ((unsigned char) s1[i] - (unsigned char) s2[j]);
		i++;
		j++;
	}
	return (0);
}

void	file_type(t_map *env, char *map_name)
{
	int	f;

	f = ft_strncmp_mod(map_name, ".cub", 4);
	if (f != 0)
		err_msg(env, 4);
}
