GREEN = \033[0;32m
DEFAULT = \033[0m

LDFLAGS = -L$(LIBFT_DIR) -lft
CFLAGS = -Ilibft -Wextra -Wall -Werror -I $(MLX_DIR)/include/ #-g -fsanitize=address #del 
MLX_FLAGS = -L./MLX/build -lmlx42 -lglfw -ldl -lm

RM = rm -f
CC = gcc

NAME = cub3d

LIBFT_DIR = libft

GC_DIR = gc

MLX_DIR = MLX

MLX = $(MLX_DIR)/build/libmlx42.a

GC = $(GC_DIR)/gc.a

LIBFT = $(LIBFT_DIR)/libft.a

SOURCES = src/main.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		src/main_utils.c \
		src/format_txtr.c \
		src/check_textures.c

OBJECTS := $(SOURCES:.c=.o)

vpath %.c	src/
vpath %.h	inc/


all: submodules $(NAME)

submodules:
	@if [ ! -f $(MLX_DIR)/CMakeLists.txt ]; then \
		echo "$(D_YELLOW)Initializing submodules...$(DEFAULT)"; \
		git submodule update --init --recursive; \
		echo "$(D_GREEN)Submodules initialized!$(DEFAULT)"; \
	fi

$(MLX): $(MLX_DIR)
	@echo "Building MLX..."
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build
	@cmake --build $(MLX_DIR)/build -j4
	@echo "...finished building MLX"

$(MLX_DIR):
	@git clone https://github.com/codam-coding-college/MLX42.git $@

$(NAME): $(LIBFT) $(OBJECTS) $(GC) $(MLX)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(MLX) $(GC) $(LIBFT) $(OBJECTS) -o $(NAME) $(LDFLAGS)
	@echo "$(GREEN)Cub3d is playable!$(DEFAULT)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --silent

$(GC):
	@$(MAKE) -C $(GC_DIR) --silent

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean --silent
	@$(MAKE) -C $(GC_DIR) clean --silent
	@$(RM) $(OBJECTS)
	@echo "$(GREEN)Cub3d cleaned successfully!$(DEFAULT)"

fclean: clean
	@$(RM) $(LIBFT)
	@$(RM) $(GC)
	@$(RM) $(NAME)
	@echo "$(GREEN)Cub3d cleaned successfully!$(DEFAULT)"

re: fclean all

debug: $(OBJECTS)
	@$(CC) $(CFLAGS) $^ -o debug
