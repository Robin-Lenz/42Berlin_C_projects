#include "so_long.h"

int	check_the_field_to_be_accessed(int x, int y, mlx_key_data_t keydata, map_params_t *m_param)
{
	int	flag;

	flag = 0;
	if (keydata.key == MLX_KEY_W)
	{
		if (m_param->map[y - 1][x] == '1')
			flag = 1;
	}
	if (keydata.key == MLX_KEY_S)
	{
		if (m_param->map[y + 1][x] == '1')
			flag = 1;
	}
	if (keydata.key == MLX_KEY_A)
	{
		if (m_param->map[y][x - 1] == '1')
			flag = 1;
	}
	if (keydata.key == MLX_KEY_D)
	{
		if (m_param->map[y][x + 1] == '1')
			flag = 1;
	}
	return (flag);
}

void	my_key_func(mlx_key_data_t keydata, void *param)
{
	map_params_t	*m_param;
	int				erste;
	int				zweit;

	m_param = (map_params_t *)param;
	erste = m_param->image_p->instances[0].y / TILE_WIDTH;
	zweit = m_param->image_p->instances[0].x / TILE_WIDTH;
	if (keydata.key == MLX_KEY_W)
		help_w(keydata, m_param, &m_param->steps);
	if (keydata.key == MLX_KEY_S)
		help_s(keydata, m_param, &m_param->steps);
	if (keydata.key == MLX_KEY_A)
		help_a(keydata, m_param, &m_param->steps);
	if (keydata.key == MLX_KEY_D)
		help_d(keydata, m_param, &m_param->steps);
	is_it_collectable(m_param, erste, zweit);
}

void	ft_hook(void *param)
{
	map_params_t	*m_param;

	m_param = (map_params_t *) param;
	mlx_key_hook(m_param->mlx, my_key_func, param);
	if (mlx_is_key_down(m_param->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(m_param->mlx);
}
