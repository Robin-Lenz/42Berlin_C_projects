NAME := cub3d
CC := cc
CFLAGS := -Wextra -Wall -Werror -g #-fsanitize=leak
LIBFT := src/libft/libft.a
HEADER := -I ./header
SRC_DIR := ./src
OBJ_DIR := ./obj
LIBMLX	:= ./MLX42/build
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

# Recursive wildcard function to find all .c files in subdirectories
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

SRCS := $(call rwildcard,$(SRC_DIR)/,*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
OBJ_DIRS := $(sort $(dir $(OBJS)))

all: libmlx $(NAME)

libmlx:
	if  [ ! -d "./MLX42" ] ; then \
        git clone https://github.com/codam-coding-college/MLX42.git; \
        cd ./MLX42 && cmake -B build && cmake --build build -j4; \
	fi
#	make -C libft
#	make -C ft_printf
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIRS)
	$(CC) $(CFLAGS) $< -c -o $@ $(HEADER)

$(NAME): $(OBJS)
	make -C src/libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -I include $(LIBFT) -g -o $(NAME) -lreadline $(HEADER)

$(OBJ_DIRS):
	mkdir -p $@

clean:
	make clean -C src/libft
	rm -rf $(OBJ_DIR)
	@rm -f $(LIBMLX)/build/libmlx42.a
	@rm -rf MLX42
	

fclean: clean
	make fclean -C src/libft
	rm -f $(NAME)



re: clean all

.PHONY: all clean fclean re