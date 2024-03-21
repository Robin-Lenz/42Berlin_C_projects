#include "so_long.h"

map_params_t	get_them(map_params_t m_param, int i, int j)
{
	if (m_param.map[i][j] == 'P')
	{
		m_param.error.player++;
		m_param.p.x = i;
		m_param.p.y = j;
	}
	else if (m_param.map[i][j] == 'E')
	{
		m_param.error.exit++;
		m_param.exit.x = i;
		m_param.exit.y = j;
	}
	else if (m_param.map[i][j] == 'C')
	{
		m_param.error.collectable++;
	}
	return (m_param);
}

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

error_t	file_type(map_params_t m_param, error_t error)
{
	int	f;

	f = ft_strncmp_mod(m_param.file_name, ".ber", 4);
	if (f != 0)
		error.fail = -3;
	return (error);
}

map_params_t	check_pec(map_params_t m_param)
{
	if (m_param.error.player != 1)
		m_param.error.fail = -4;
	else if (m_param.error.exit != 1)
		m_param.error.fail = -5;
	else if (m_param.error.collectable < 1)
		m_param.error.fail = -6;
	return (m_param);
}

void	print_err(error_t error)
{
	if (error.fail == -1)
		ft_printf("Error\nmap is not a rectangle\n");
	if (error.fail == -2)
		ft_printf("Error\nwall not enclosed\n");
	if (error.fail == -3)
		ft_printf("Error\nfile is not a .ber file\n");
	if (error.fail == -4)
		ft_printf("Error\nEither no or too many player in the game\n");
	if (error.fail == -5)
		ft_printf("Error\nEither no or too many exit in the game\n");
	if (error.fail == -6)
		ft_printf("Error\nno collectable\n");
	if (error.fail == -7)
		ft_printf("Error\nunknown character in map\n");
	if (error.fail == -8)
		ft_printf("Error\nflood fill failed\n");
}
