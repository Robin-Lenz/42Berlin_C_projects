# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpodack <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 18:25:47 by rpodack           #+#    #+#              #
#    Updated: 2023/01/13 19:07:06 by rpodack          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC	= cc

RM 	= rm -f

CFLAGS	= -Wall -Wextra -Werror

SRCS = ft_printf.c\
		ft_print_int.c\
		ft_print_c_str.c\
		ft_print_all_hex.c

OBJS = ${SRCS:.c=.o}

${NAME}:	$(OBJS) 
	ar -rcs $(NAME) $(OBJS)


all:	${NAME}

clean: 
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}
		
re:		fclean all

.PHONY: all clean fclean re
