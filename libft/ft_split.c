/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:58:07 by rpodack           #+#    #+#             */
/*   Updated: 2022/12/27 20:01:44 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		countwords(char const *s, char c);
static int		sizeofword(const char *s, char c, int i);
static void		ft_free(char **strs, int j);

char	**ft_split(char const *s, char c)
{
	size_t		i;
	char		**strs;
	int			size;
	int			j;

	i = 0;
	j = -1;
	strs = (char **)malloc((countwords(s, c) + 1) * sizeof(char *));
	if (!strs || !s)
		return (NULL);
	while (++j < countwords(s, c) && i < ft_strlen(s))
	{
		while (s[i] == c)
			i++;
		size = sizeofword(s, c, i);
		strs[j] = ft_substr(s, i, size);
		if (!strs[j])
		{
			ft_free(strs, j);
			return (NULL);
		}
		i += size;
	}
	strs[j] = '\0';
	return (strs);
}

static int	countwords(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		i++;
	}
	return (j);
}

static int	sizeofword(const char *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}
