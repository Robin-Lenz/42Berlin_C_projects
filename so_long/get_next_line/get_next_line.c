/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:53:05 by rpodack           #+#    #+#             */
/*   Updated: 2023/05/15 22:30:30 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*i_need_lines(char *rline, char *stay, int i, int *pflag)
{
	int	j;

	j = 0;
	while (j < i)
	{
		rline[j] = stay[j];
		j++;
	}
	if (*pflag == 1)
		rline[j] = '\n';
	return (rline);
}

char	*update_stay(char	*stay)
{
	char	*tmp;
	int		i;

	i = 0;
	while (stay[i] != '\n' && stay[i] != '\0')
		i++;
	if (!stay[i])
	{
		free(stay);
		return (NULL);
	}
	i++;
	tmp = ft_calloc((sizeof(char) * ft_strlen(stay) - i) + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	tmp = need_even_more(stay, tmp, i);
	free(stay);
	stay = NULL;
	return (tmp);
}

char	*ft_get_line(char *stay)
{
	int		i;
	int		flag;
	char	*rline;

	flag = 1;
	i = 0;
	if (!stay)
		return (NULL);
	while (stay[i] != '\n')
	{
		if (stay[i] == '\0')
		{
			flag = 0;
			break ;
		}
		i++;
	}
	rline = ft_calloc(i + 1 + flag, sizeof(char));
	if (!rline)
		return (NULL);
	rline = i_need_lines(rline, stay, i, &flag);
	return (rline);
}

char	*ft_read_and_copy(char *stay, int fd, int *size_red)
{
	char	*buffer;

	while (!ft_strchr(stay, '\n') && *size_red != 0)
	{
		buffer = ft_calloc(sizeof(char) * BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		*size_red = read(fd, buffer, BUFFER_SIZE);
		if (*size_red == -1)
		{
			free(stay);
			free(buffer);
			return (NULL);
		}
		stay = ft_strjoin(stay, buffer);
		if (!stay)
			return (NULL);
		if (*size_red == 0 && stay[0] == '\0')
		{
			free(stay);
			stay = NULL;
		}
		free(buffer);
	}
	return (stay);
}

char	*get_next_line(int fd)
{
	static char		*stay;
	char			*rline;
	int				size_red;

	size_red = -2;
	if (fd < 0)
		return (NULL);
	stay = ft_read_and_copy(stay, fd, &size_red);
	if (!stay)
		return (NULL);
	rline = ft_get_line(stay);
	if (!rline)
		return (NULL);
	stay = update_stay(stay);
	return (rline);
}

/* int	main(void)
{
	int		i;
	char	*b;
	int		k = 10;

	i = open("./test_text.txt", O_RDONLY);
	while (k-- != 0)
	{
		b = get_next_line(i);
		printf("%s", b);
		free(b);
	}
	return (0);
} */