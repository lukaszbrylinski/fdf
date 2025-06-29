# Project name
NAME := fdf

# Compiler and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror

# Directories
MLX_DIR := ../minilibx-linux
INCLUDES := -I$(MLX_DIR)

# Libraries
MLX_LIB := $(MLX_DIR)/libmlx_Linux.a
LIBS := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

# Source and object files
SRC := main.c \
       gnl.c \
       gnl_utils.c \
       parse_to_int.c \
       parse_to_int_utils.c \
       line_drawing.c \
       utils.c \
       ft_split.c \
       printf.c \
       printf_utils.c \
       new_parsing.c \
       new_parsing_utils.c

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(MLX_LIB) $(LIBS)

$(MLX_LIB):
	@echo "Building MiniLibX..."
	@$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
