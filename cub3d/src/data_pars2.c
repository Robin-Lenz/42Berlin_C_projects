/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_pars2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:06:09 by rpodack           #+#    #+#             */
/*   Updated: 2024/02/10 19:06:10 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	arg_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (!ft_strchr(WHITESPACE, *str) && str)
	{
		str++;
		i++;
	}
	return (i);
}

int	num_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (!ft_strchr(WHITESPACE, *str) && str && ft_isdigit(*str))
	{
		str++;
		i++;
	}
	return (i);
}

int	go_to_next_number(char **str, int i, t_map *args)
{
	char	*s;

	s = *str;
	while (s && ft_isdigit(*s))
		s++;
	if (*s == ',')
		s++;
	else if (s && i > 1)
		error_get_data("wrong rgba format\n", args, false);
	*str = s;
	return (0);
}

void	get_and_calc_color(t_color var, t_map *args, char **str)
{
	uint32_t	res;
	uint32_t	i;
	uint32_t	nbr;
	char		*tmp;

	res = 0;
	i = 3;
	while (i)
	{
		tmp = ft_substr(*str, 0, num_len(*str));
		if (!tmp)
			error_get_data("malloc", args, true);
		nbr = (uint32_t) ft_atoi(tmp);
		free(tmp);
		if (nbr > 255)
			error_get_data("max rgb [255]\n", args, false);
		res = (res << 8) | nbr;
		go_to_next_number(str, i, args);
		i--;
	}
	get_and_calc_color2(var, args, res);
}

int	extract_color(char **str, t_map *args)
{
	char	*s;
	t_color	var;

	s = *str;
	if (*s == 'F')
		var = FLOOR;
	else if (*s == 'C')
		var = CEILING;
	else
		error_get_data("check C or F in map\n", args, false);
	s++;
	while (s && ft_strchr(WHITESPACE, *s))
		s++;
	get_and_calc_color(var, args, &s);
	find_arg(&s);
	*str = s;
	return (0);
}
