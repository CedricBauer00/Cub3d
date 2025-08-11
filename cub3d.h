/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:15:15 by bolcay            #+#    #+#             */
/*   Updated: 2025/08/11 16:04:05 by batuhan          ###   ########.fr       */
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

typedef struct s_player
{
	int		x;
	int		y;
	double	angle;
	double	rayDirX;
	double	rayDirY;
	double	deltaDistX;
	double	deltaDistY;
	int		mapX;
	int		mapY;
	double	posX;
	double	posY;
	double	sideDistX;
	double	sideDistY;
	int		stepX;
	int		stepY;
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

// prints a 2d map to do some tests
int		paint_map(t_game *game, mlx_image_t *image);
// this one is being used every time the character moves.
// it prints the body of the character, the direction showing stick thing and the red ray that stops when it hits a wall.
// i will add more rays to it to get a proper field of view.
void	draw_player_ex(t_game *game, mlx_image_t *image);
// draw_ray function and its little helper are used to calculate the distance of the red ray.
void	draw_ray(t_game *game, mlx_image_t *image);
void	draw_ray_helper(t_game *game, mlx_image_t *image, int hx, int hy);

// 2D movement

// this functions takes gets the signal of the keys you press and does something depending on which key was pressed.
void	key(mlx_key_data_t keys, void *ptr);

// movement functions.
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);

// a small initializing function
void	initialize(t_game *game);

#endif