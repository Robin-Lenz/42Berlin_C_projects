NAME := philo
CC := cc
CFLAGS := -Wextra -Wall -Werror #-fsanitize=thread -g
LIBFT := libft/libft.a
HEADER := -I ./header
SRC_DIR := ./src
OBJ_DIR := ./obj

# Recursive wildcard function to find all .c files in subdirectories
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

SRCS := $(call rwildcard,$(SRC_DIR)/,*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
OBJ_DIRS := $(sort $(dir $(OBJS)))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIRS)
	$(CC) $(CFLAGS) $< -c -o $@ $(HEADER)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -pthread -g -o $(NAME)

$(OBJ_DIRS):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)



re: clean all

.PHONY: all clean fclean re
