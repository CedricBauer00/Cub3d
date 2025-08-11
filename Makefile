# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/01 12:14:05 by bolcay            #+#    #+#              #
#    Updated: 2025/08/11 16:40:58 by batuhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c player_movement.c utils.c initialize.c player.c 

CC = cc
CFLAGS = -Werror -Wextra -Wall $(INCLUDE)
RM = rm -f
RM_DIR = rm -rf
NAME = cub3D
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT_LIB = ${LIBFT_DIR}/libft.a

MLX42_DIR = MLX42
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a

INCLUDE     = -I$(MLX42_DIR)/include -I header -I libft
LDINCLUDE   = -L$(MLX42_DIR)/build -lmlx42 -L$(LIBFT_DIR) -lft -lglfw MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

all: ${NAME}

$(LIBFT_LIB):
	make -C $(LIBFT_DIR) && make clean -C $(LIBFT_DIR)

$(NAME): $(MLX42_LIB) $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDINCLUDE) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM_DIR) $(OBJS)

fclean: clean
		$(RM) $(NAME)
		make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re