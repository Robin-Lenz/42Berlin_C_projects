/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fills.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:16:20 by rpodack           #+#    #+#             */
/*   Updated: 2023/05/12 00:13:02 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map_copy, int x, int y, int *fail, int *c_count)
{
	if (map_copy[x][y] == 'F' || map_copy[x][y] == '1')
		return ;
	if (map_copy[x][y] == 'E')
	{
		*fail = 0;
		return ;
	}
	if (map_copy[x][y] == 'C')
		*c_count = *c_count + 1;
	map_copy[x][y] = 'F';
	flood_fill(map_copy, x + 1, y, fail, c_count);
	flood_fill(map_copy, x - 1, y, fail, c_count);
	flood_fill(map_copy, x, y + 1, fail, c_count);
	flood_fill(map_copy, x, y - 1, fail, c_count);
}
