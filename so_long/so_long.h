/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:00:20 by rpodack           #+#    #+#             */
/*   Updated: 2023/05/16 22:09:01 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define TILE_WIDTH 32

typedef struct s_position_p
{
    int x;
    int y;
}   pos_t;

typedef struct s_errorstruct
{
    size_t width;
    int collectable;
    int exit;
    int player;
    int fail;
}error_t;

typedef struct s_mapstruct
{
    char    *file_name;
    int     len_total;
    int     nb_of_lines;
    int     fd;
    int     i;
    int     c_count;
    int     steps;
    int     c;
    int     d;
    char	*map_line;
    char    **map;
    error_t error;
    pos_t    p;
    pos_t    collect;
    pos_t    exit;
    mlx_t    *mlx;

    xpm_t* texture_p;
    mlx_image_t* image_p;

    xpm_t* texture_e;
    mlx_image_t* image_e;

    xpm_t* texture_w;
    mlx_image_t* image_w;

    xpm_t* texture_g;
    mlx_image_t* image_g;

    xpm_t* texture_c;
    mlx_image_t* image_c;
    
}map_params_t;

map_params_t	evaluate_map(map_params_t m_param);
int init_game(map_params_t m_param);
void    ft_hook(void* param);
void    my_key_func(mlx_key_data_t keydata, void* param);
map_params_t    load_exit(map_params_t m_param);
map_params_t    put_player(map_params_t m_param);
map_params_t    load_ground(map_params_t m_param);
map_params_t    load_collectable(map_params_t m_param);
map_params_t    load_wall(map_params_t m_param);
map_params_t    set_instances(map_params_t m_param);
int	    check_the_field_to_be_accessed(int x, int y, mlx_key_data_t keydata, map_params_t *m_param);
void	flood_fill(char **map_copy, int x, int y, int *fail, int *c_count);
void	my_key_func(mlx_key_data_t keydata, void* param);
void 	is_it_collectable(map_params_t *m_param, int erste, int zweite);
void    ft_hook(void *param);
void    free_map_copy(char **map_copy, map_params_t m_param);
map_params_t	free_mapfree(map_params_t m_param);
void 	free_game(map_params_t m_param);
map_params_t    check_for_consecutive(map_params_t m_param);
void 	free_too_many_nl(map_params_t m_param);
void    help_w(mlx_key_data_t keydata, map_params_t *m_param, int *steps);
void    help_s(mlx_key_data_t keydata, map_params_t *m_param, int *steps);
void            help_a(mlx_key_data_t keydata, map_params_t *m_param, int *steps);
void            help_d(mlx_key_data_t keydata, map_params_t *m_param, int *steps);
void            free_init_game(map_params_t m_param);
map_params_t	get_them(map_params_t m_param, int i, int j);
error_t         file_type(map_params_t m_param, error_t error);
void            print_err(error_t error);
map_params_t	check_pec(map_params_t m_param);

#endif