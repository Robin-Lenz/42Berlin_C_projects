/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:02:39 by rpodack           #+#    #+#             */
/*   Updated: 2023/11/05 15:02:40 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	ft_pwd(t_envl *env)
{
	char	path[PATH_MAX];

	printf("%s\n", getcwd(path, PATH_MAX));
	*(env->exit) = 0;
}
