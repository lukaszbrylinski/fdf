CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Executable Name
NAME = fdf

# Source Files
SRCS = line_drawing.c ft_split.c gnl_utils.c gnl.c main.c parse_data_utils.c parse_data.c printf_utils.c printf.c utils.c

# Object Files
OBJS = $(SRCS:.c=.o)

# Headers
HEADERS = fdf.h

# MiniLibX (Linux)
MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a -lX11 -lXext -lm
MLX_INC = -I$(MLX_DIR)

# Default target
all: $(MLX_DIR)/libmlx_Linux.a $(NAME)

# Build the executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_LIB) $(MLX_INC)

# Compile source files into object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

# Build MiniLibX
$(MLX_DIR)/libmlx_Linux.a:
	make -C $(MLX_DIR)

# Clean object files
clean:
	rm -f $(OBJS)
	@make -C $(MLX_DIR) clean || true

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild all
re: fclean all

# Phony targets
.PHONY: all clean fclean re
