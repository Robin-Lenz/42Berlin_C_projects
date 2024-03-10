/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:07:35 by rpodack           #+#    #+#             */
/*   Updated: 2024/02/26 15:27:26 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdlib.h>
# include "../src/libft/libft.h"
# include "../src/get_next_line/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define TILE_WIDTH 25
# define SQRS_PER_SEC 2.0
# define SCREENWIDTH 1200
# define SCREENHEIGHT 800
# define TEXWIDTH 256
# define TEXHEIGHT 256
# define WHITESPACE "\f\n\r\t\v "

typedef struct s_map
{
/*mapdata*/
	char			*map_line;
	char			**map;
	char			**map_copy;
	int				fd;
	int				height_map;
	int				longest_line;

/*playerdata*/
	int				player;
	double			ppos[2];// posX und posY in guide
	double			pdir[2];

/*screen*/
	double			planex;
	double			planey;

/*time*/
	double			time;
	double			oldtime;
	double			frametime;

/*start DDA*///maby init all of them to 0
	double			camerax;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;

//length of ray from current position to next x or y-side
	double			sidedistx;
	double			sidedisty;

	double			deltadistx;
	double			deltadisty;

//what direction to step in x or y-direction (either +1 or -1)
	int				stepx;
	int				stepy;

	int				hit; //was there a wall hit?
	int				side; //was a NS or a EW wall hit?
	int				wall_direction;

	double			perpwalldist;
	int				lineheight;
	double			h;
	int				drawstart;
	int				drawend;

	/*window*/
	mlx_image_t		*image;
	mlx_texture_t	*tex[4];
	mlx_t			*mlx;

	/*keys*/
	bool			key_w_pressed;
	bool			key_s_pressed;
	bool			key_d_pressed;
	bool			key_a_pressed;
	bool			key_left_pressed;
	bool			key_right_pressed;

	double			speed;
	double			rotate;

	uint32_t		ceiling_color;
	uint32_t		floor_color;

	char			*no;
	char			*so;
	char			*we;
	char			*ea;
}t_map;

typedef enum s_color
{
	FLOOR,
	CEILING
}	t_color;

typedef enum s_direction
{
	NO,
	SO,
	WE,
	EA
}	t_direction;

t_map				*init_map(char **av);
void				check_dimensions(t_map *env);
void				init_doubles(t_map *env);
void				init_pathptr(t_map *env);
void				init_keypressed(t_map *env);
void				logg_s_util(t_map *env);
int					longest_line(char **map);
void				check_for_chars(char **place, t_map *env, int i, int j);
void				get_map_line(t_map *env, char **av);

/*error handling*/
void				err_msg(t_map *env, int flag);
void				ft_err(t_map *env);
void				enclosed(t_map *env, int x, int y);
void				allowed_characters(t_map *env);
void				logg_dir(t_map *env, char place);
void				init_game(t_map *env);

/*main game loop*/
void				game_loop(void *en);
void				get_raydir(t_map *env, int x);
void				steps(t_map *env);
void				collect_data_for_dda(t_map *env);
void				dda_exec(t_map *env);
void				next_square(t_map *env, int *hit, int *side);
void				handle_wall_hit(t_map *env, int *side);
void				calc_perpwalldist(t_map *env);
void				calc_draw_startend(t_map *env);

/*put background*/
void				draw_floor_ceiling(t_map *env, int x);
void				clear_image(t_map *env);
void				draw_pixel(uint8_t *pixel, uint32_t color);
void				put_pixel(mlx_image_t *image, uint32_t x, uint32_t y, \
uint32_t color);

/*put textures*/
void				put_image(t_map *env, int x);
void				put_it(t_map *env, int x, int texX);

/*load images*/
void				init_images(t_map *env);
void				load_ww(t_map *env);
void				load_sw(t_map *env);
void				load_nw(t_map *env);
void				load_ew(t_map *env);

/*movement*/
void				keyhook(mlx_key_data_t keydata, void *param);
void				move(t_map *env);
void				ft_rotate_left(t_map *env);
void				ft_rotate_right(t_map *env);
void				move_forward(t_map *env);
void				move_backwards(t_map *env);
void				move_right(t_map *env);
void				move_left(t_map *env);

/*utils*/
int					ft_strlen_int(char *str);

/*parse map data*/
int					arg_len(char *str);
int					get_map_data(t_map *args);
int					extract_color(char **str, t_map *args);
void				find_arg(char **str);
void				get_texture_path(char **str, t_map *args);
void				extract_texture(char **str, t_map *args);
void				get_and_calc_color2(t_color var, t_map *args, uint32_t res);
void				error_path(char *path, t_map *args);
void				assign_path(char *path, t_map *args, \
t_direction direction);

/*free*/
void				free_all(t_map *env);
void				free_2d(char **map);
void				error_get_data(char *error_msg, t_map *args, bool sys_func);
void				free_notfound(t_map *env);
void				free_image_path(t_map *env);
void				free_tex(t_map *env);
void				free_load(t_map *env);

#endif
