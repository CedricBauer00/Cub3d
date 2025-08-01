GREEN = \033[0;32m
DEFAULT = \033[0m

LDFLAGS = -L$(LIBFT_DIR) -lft -L$(GET_NEXT_LINE_DIR)
CFLAGS = -Ilibft -Wextra -Wall -Werror -lm #-g -fsanitize=address #del 

RM = rm -f
CC = gcc

NAME = cub3d

LIBFT_DIR = libft

GET_NEXT_LINE_DIR = ../get_next_line

GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/get_next_line.a

LIBFT = $(LIBFT_DIR)/libft.a

SOURCES = /src/main.c

OBJECTS := $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJECTS) $(INC) -o $(NAME) $(LDFLAGS)
	@echo "$(GREEN)Cub3d is playable!$(DEFAULT)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --silent

$(GET_NEXT_LINE):
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) --silent
%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@$(MAKE) -C $(LIBFT_DIR) $(GET_NEXT_LINE) clean --silent
	@$(RM) $(OBJECTS)
	@echo "$(GREEN)Cub3d cleaned successfully!$(DEFAULT)"

fclean: clean
	@$(RM) $(LIBFT)
	@$(RM) $(NAME)
	@echo "$(GREEN)Cub3d cleaned successfully!$(DEFAULT)"

re: fclean all

debug: $(OBJECTS)
	@$(CC) $(CFLAGS) $^ -o debug
