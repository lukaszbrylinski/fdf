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
       utils.c \
       ft_split.c \
       printf.c \
       printf_utils.c \
       parsing.c \
       parsing_utils.c \
	   parsing_utils2.c \
	   window_init.c \
	   isometric.c \
	   render_map.c \
	   ft_atoi_base.c

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
