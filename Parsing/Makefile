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

OBJ_DIR = obj

MLX = $(MLX_DIR)/build/libmlx42.a

GC = $(GC_DIR)/gc.a

LIBFT = $(LIBFT_DIR)/libft.a

SOURCES = main.c \
		get_next_line.c \
		get_next_line_utils.c \
		main_utils.c \
		format_txtr.c \
		check_textures.c \
		init_map.c \
		player.c \
		flood_fill.c
		

OBJECTS := $(SOURCES:%.c=$(OBJ_DIR)/%.o)

vpath %.c	src/ \
			get_next_line/
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

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean --silent
	@$(MAKE) -C $(GC_DIR) clean --silent
	@$(RM) $(OBJECTS) 
	@$(RM) -r $(OBJ_DIR)
	@echo "$(GREEN)Cub3d cleaned successfully!$(DEFAULT)"

fclean: clean
	@$(RM) $(LIBFT)
	@$(RM) $(GC)
	@$(RM) $(NAME)
	@echo "$(GREEN)Cub3d cleaned successfully!$(DEFAULT)"

re: fclean all

debug: $(OBJECTS)
	@$(CC) $(CFLAGS) $^ -o debug
