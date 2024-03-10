/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:06:13 by rpodack           #+#    #+#             */
/*   Updated: 2024/02/10 19:06:13 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	alloc_path1(t_direction direction, t_map *args, char *str)
{
	char	*path;

	path = ft_substr(str, 0, arg_len(str));
	if (!path)
		error_get_data("malloc", args, true);
	assign_path(path, args, direction);
}

void	alloc_path(int i, t_map *args, char **str)
{
	t_direction	direction;
	char		*s;

	s = *str;
	if (i < 0 || i > 3)
		error_get_data("rgba syntax err\n", args, false);
	direction = i;
	while (s && !ft_strchr(WHITESPACE, *s))
		s++;
	while (s && ft_strchr(WHITESPACE, *s))
		s++;
	alloc_path1(direction, args, s);
	while (s && !ft_strchr(WHITESPACE, *s))
		s++;
	while (s && ft_strchr(WHITESPACE, *s))
		s++;
	*str = s;
}

void	get_texture_path(char **str, t_map *args)
{
	char		**tmp_directions;
	int			i;
	int			j;

	i = -1;
	j = -1;
	tmp_directions = ft_split("NO:SO:WE:EA", ':');
	if (!tmp_directions)
		error_get_data("malloc", args, true);
	while (tmp_directions[++i] && ft_strncmp(tmp_directions[i], *str, 2) != 0)
		;
	while (tmp_directions[++j])
		free(tmp_directions[j]);
	free(tmp_directions);
	alloc_path(i, args, str);
}

void	extract_texture(char **str, t_map *args)
{
	char	*s;

	s = *str;
	if (arg_len(s) == 2)
		get_texture_path(&s, args);
	else
		error_get_data("error\n", args, false);
	*str = s;
}
