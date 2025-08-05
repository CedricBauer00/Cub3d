/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:15:15 by bolcay            #+#    #+#             */
/*   Updated: 2025/08/05 13:49:04 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <unistd.h>
# include <stdbool.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>

# define TS 64
# define WIDTH 1024
# define HEIGHT 512

typedef enum e_dir {UP, DOWN, LEFT, RIGHT} t_dir;
typedef struct s_player
{
	int		x;
	int		y;
	t_dir	dir;
	mlx_image_t *image;
	mlx_instance_t *inst;
}	t_player;

typedef struct s_game
{
	mlx_t	*mlx;
	t_player *player;
}	t_game;

void	key(mlx_key_data_t keys, void *ptr);
int		paint_map(t_game *game, mlx_image_t *image);

// 2D movement
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);

void	draw_player(t_game *game, mlx_image_t *image);
void	initialize(t_game *game);

#endif