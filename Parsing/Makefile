GREEN = \033[0;32m
DEFAULT = \033[0m

LDFLAGS = -L$(LIBFT_DIR) -lft
CFLAGS = -Ilibft -Wextra -Wall -Werror #-lm #-g -fsanitize=address #del 

RM = rm -f
CC = gcc

NAME = cub3d

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

SOURCES = src/main.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJECTS := $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJECTS) $(INC) -o $(NAME) $(LDFLAGS)
	@echo "$(GREEN)Cub3d is playable!$(DEFAULT)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --silent

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean --silent
	@$(RM) $(OBJECTS)
	@echo "$(GREEN)Cub3d cleaned successfully!$(DEFAULT)"

fclean: clean
	@$(RM) $(LIBFT)
	@$(RM) $(NAME)
	@echo "$(GREEN)Cub3d cleaned successfully!$(DEFAULT)"

re: fclean all

debug: $(OBJECTS)
	@$(CC) $(CFLAGS) $^ -o debug


# GREEN = \033[0;32m
# DEFAULT = \033[0m

# LDFLAGS = -L$(LIBFT_DIR) -lft
# CFLAGS = -Ilibft -Wextra -Wall -Werror #-lm #-g -fsanitize=address #del 

# RM = rm -f
# CC = gcc

# NAME = cub3d

# LIBFT_DIR = libft
# LIBFT = $(LIBFT_DIR)/libft.a

# SOURCES = src/main.c \
# 		get_next_line/get_next_line.c \
# 		get_next_line/get_next_line_utils.c

# OBJ_DIR = obj

# # Ersetze Pfad von .c durch obj/*.o
# OBJECTS = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(filter src/%.c,$(SOURCES))) \
# 		  $(patsubst get_next_line/%.c,$(OBJ_DIR)/get_next_line/%.o,$(filter get_next_line/%.c,$(SOURCES)))

# all: $(NAME)

# # Stelle sicher, dass der obj/ und obj/get_next_line/ Ordner existiert
# $(OBJ_DIR):
# 	mkdir -p $(OBJ_DIR)

# $(OBJ_DIR)/get_next_line:
# 	mkdir -p $(OBJ_DIR)/get_next_line

# # Linken
# $(NAME): $(LIBFT) $(OBJECTS)
# 	$(CC) $(CFLAGS) $(LIBFT) $(OBJECTS) $(INC) -o $(NAME) $(LDFLAGS)
# 	@echo "$(GREEN)Cub3d is playable!$(DEFAULT)"

# # Libft kompilieren
# $(LIBFT):
# 	@$(MAKE) -C $(LIBFT_DIR) --silent

# # Kompilieren: Je nachdem ob Datei in src/ oder get_next_line/ liegt, passende Regel
# $(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_DIR)/get_next_line/%.o: get_next_line/%.c | $(OBJ_DIR)/get_next_line
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	@$(MAKE) -C $(LIBFT_DIR) clean --silent
# 	@$(RM) -r $(OBJ_DIR)
# 	@echo "$(GREEN)Cub3d cleaned successfully!$(DEFAULT)"

# fclean: clean
# 	@$(RM) $(LIBFT)
# 	@$(RM) $(NAME)
# 	@echo "$(GREEN)Cub3d fully cleaned successfully!$(DEFAULT)"

# re: fclean all

# debug: $(OBJECTS)
# 	$(CC) $(CFLAGS) $^ -o debug