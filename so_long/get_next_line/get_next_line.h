/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:52:53 by rpodack           #+#    #+#             */
/*   Updated: 2023/04/25 19:48:31 by rpodack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <stddef.h>
# include "../libft/libft.h"

char	*ft_strchr(const char *s, int c);
char	*ft_read_and_copy(char *stay, int fd, int *size_red);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*get_next_line(int fd);
char	*ft_get_line(char *stay);
char	*update_stay(char	*stay);
char	*need_even_more(char *stay, char *tmp, int i);

#endif
