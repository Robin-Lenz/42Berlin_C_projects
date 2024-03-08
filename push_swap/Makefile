# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 15:26:21 by rpodack           #+#    #+#              #
#    Updated: 2023/06/23 17:37:25 by rpodack          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
CC := cc
CFLAGS := -Wextra -Wall -Werror
LIBFT := libft/libft.a
FT_PRINTF := ft_printf/libftprintf.a
SRCS := $(shell find ./src -iname "*.c")
OBJS := ${SRCS:.c=.o}

all: $(NAME)
	
%.o: %.c
	@$(CC) $(CFLAGS) $< -c -o $@ && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	make -C libft
	@$(CC) $(CFLAGS) $(OBJS) -I include $(LIBFT) -o $(NAME)

clean:
	make clean -C libft
	@rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	@rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re