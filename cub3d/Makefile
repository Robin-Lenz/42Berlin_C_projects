NAME	:= cub3D
CC 		:= cc
CFLAGS	:= -Wextra -Wall -Werror
LIBMLX	:= ./MLX42/build

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT	:= ./src/libft/libft.a

SRCS	:= ./src/calculation.c\
	./src/data_texture.c\
	./src/error.c\
	./src/init_utils.c\
    ./src/put_to_screen.c\
	./src/data_pars2.c\
	./src/data_utils_error.c\
	./src/free.c\
	./src/init.c\
	./src/keys.c\
	./src/load_imiges.c\
	./src/move.c\
	./src/utils.c\
	./src/data_pars.c\
	./src/enclosed.c\
	./src/init_game.c\
	./src/left_right.c\
	./src/main.c\
	./src/put_background.c\
	./src/get_next_line/get_next_line.c\
	./src/get_next_line/get_next_line_utils.c\
	./src/get_next_line/helper.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	if  [ ! -d "./MLX42" ] ; then \
        git clone https://github.com/codam-coding-college/MLX42.git; \
        cd ./MLX42 && cmake -B build && cmake --build build -j4; \
	fi
	make -C src/libft
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -I include $(LIBFT) -o $(NAME)

clean:
	make clean -C src/libft
	@rm -f $(OBJS)
	@rm -f $(LIBMLX)/build/libmlx42.a
	@rm -rf MLX42

fclean: clean
	make fclean -C src/libft
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
