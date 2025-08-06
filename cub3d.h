/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:15:15 by bolcay            #+#    #+#             */
/*   Updated: 2025/08/06 11:41:24 by bolcay           ###   ########.fr       */
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
# define SPEED 0.05
# define PI 3.1415926535897932

typedef enum e_dir {UP, DOWN, LEFT, RIGHT} t_dir;
typedef struct s_player
{
	int		x;
	int		y;
	double	angle;
	t_dir	dir;
	mlx_image_t *image;
	mlx_instance_t *inst;
}	t_player;

typedef struct s_game
{
	int	map[8][8];
	mlx_t	*mlx;
	t_player *player;
}	t_game;

// printing stuff on the map
int		paint_map(t_game *game, mlx_image_t *image);
void	draw_player_ex(t_game *game, mlx_image_t *image);

// 2D movement
void	key(mlx_key_data_t keys, void *ptr);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);

// void	draw_player_updown(t_game *game, mlx_image_t *image);
// void	draw_player_sides(t_game *game, mlx_image_t *image);
void	initialize(t_game *game);

#endif