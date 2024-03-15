/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:47:16 by rpodack           #+#    #+#             */
/*   Updated: 2022/09/06 12:47:21 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 1;
	while (j < argc)
	{
		if (argv[j][i] < argv[j + 1][i])
		{
			while (argv[j][i] != '\0')
			{
				c = &argv[j][i];
				argv[j][i] = &argv[j + 1][i];
				argv[j + 1][i] = &c;
				write(1, &argv[j][i], 1);
				i++;
			}
			write(1, "\n", 1);
		}
		j++;
		i = 0;
	}
}
