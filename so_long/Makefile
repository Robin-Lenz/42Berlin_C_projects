# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpodack <rpodack@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 18:09:10 by rpodack           #+#    #+#              #
#    Updated: 2023/05/11 21:17:26 by rpodack          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	:= so_long
CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror #-Wunreachable-code -Ofast
LIBMLX	:= ./MLX42/build

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
GNL		:= ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
LIBFT	:= libft/libft.a
FT_PRINTF	:= ft_printf/libftprintf.a
SRCS	:= main.c error.c game.c load_images.c flood_fills.c  moves.c frees.c key_func_helpers.c error2.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	if  [ ! -d "./MLX42" ] ; then \
        git clone https://github.com/codam-coding-college/MLX42.git; \
        cd ./MLX42 && cmake -B build && cmake --build build -j4; \
	fi
	make -C libft
	make -C ft_printf
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) $(GNL) -I include $(LIBFT) $(FT_PRINTF) -o $(NAME)

clean:
	make clean -C libft
	make clean -C ft_printf
	@rm -f $(OBJS)
	@rm -f $(LIBMLX)/build/libmlx42.a
	@rm -rf MLX42

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
