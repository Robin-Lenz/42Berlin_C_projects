# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 21:44:38 by rpodack           #+#    #+#              #
#    Updated: 2023/04/13 21:48:38 by rpodack          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc

CFLAGS	= -Wall -Wextra -Werror


NAME_C = client

NAME_S = server

SRCS_C	= client.c

OBJS_C	= ${SRCS_C:.c=.o}

SRCS_S	= server.c

OBJS_S	= ${SRCS_S:.c=.o}


BONUS_C = client_bonus

BONUS_S = server_bonus

SRCS_BC	= client_bonus.c

OBJS_BC	= ${SRCS_BC:.c=.o}

SRCS_BS	= server_bonus.c

OBJS_BS	= ${SRCS_BS:.c=.o}

all:	$(NAME_C) $(NAME_S)

$(NAME_S) : $(OBJS_S)
		@make -C ft_printf
		$(CC) $(CFLAGS) $(OBJS_S) -I include ft_printf/libftprintf.a -o $(NAME_S)

$(NAME_C) : $(OBJS_C)
		@make -C ft_printf
		@make -C libft
		$(CC) $(CFLAGS) $(OBJS_C) -I include ft_printf/libftprintf.a libft/libft.a -o $(NAME_C)

bonus:	$(BONUS_C) $(BONUS_S)

$(BONUS_S) : $(OBJS_BS)
		make -C ft_printf
		$(CC) $(CFLAGS) $(OBJS_BS) -I include ft_printf/libftprintf.a -o $(BONUS_S)

$(BONUS_C) : $(OBJS_BC)
		@make -C ft_printf
		@make -C libft
		$(CC) $(CFLAGS) $(OBJS_BC) -I include ft_printf/libftprintf.a libft/libft.a -o $(BONUS_C)

clean: 
		make clean -C libft
		make clean -C ft_printf
		rm -f ${OBJS_S} ${OBJS_C} ${OBJS_BS} ${OBJS_BC}

fclean:	clean
		make fclean -C libft
		make fclean -C ft_printf
		rm -f client server client_bonus server_bonus
		
re:		fclean all

.PHONY: all clean fclean re
