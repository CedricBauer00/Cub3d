/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:15:15 by bolcay            #+#    #+#             */
/*   Updated: 2025/08/14 13:35:05 by batuhan          ###   ########.fr       */
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
# define HEIGHT 720
# define MOVE_S 5
# define SPEED 0.05
# define PI 3.1415926535897932
# define RAY_N WIDTH

typedef struct s_ray
{
	int		hit;
	int		hx;
	int		hy;
	int		side;
	double	wall_dist;
	double	raw_dist;  // Original distance for 2D ray drawing
}	t_ray;

typedef struct s_player
{
	int		x; // player coordinates.
	int		y;
	double	angle; // direction we're looking at.
	double	rayDirX; // the directions of the ray is being casted.
	double	rayDirY;
	double	deltaDistX; // amount of movement we need to do for the ray
	double	deltaDistY;
	int		mapX; // these 2 is used when we are calculating the rays and therefore changing the location of where we are.
	int		mapY;
	double	posX; // this is also normal player coordinates but divided by the tile size.
	double	posY;
	double	sideDistX; // determines which one to increase, x or y.
	double	sideDistY;
	int		stepX; // determines the direction of the ray. up-down or left-right.
	int		stepY;
	mlx_image_t *image;
	mlx_instance_t *inst;
}	t_player;

typedef struct s_game
{
	int	map[24][24];
	t_ray	*ray;
	mlx_t	*mlx;
	t_player *player;
}	t_game;

// printing stuff on the map

// prints a 2d map to do some tests
int		paint_map(t_game *game, mlx_image_t *image);
// this one is being used every time the character moves.
// it prints the body of the character, the direction showing stick thing and the red ray that stops when it hits a wall.
// i will add more rays to it to get a proper field of view.
void	draw_player(t_game *game, mlx_image_t *image);
// draw_ray function and its little helper are used to calculate the distance of the red ray.
t_ray	draw_ray(t_game *game, t_player *p, mlx_image_t *image, int check, double angle, int i);
void	draw_ray_helper(t_game *game, mlx_image_t *image, int hx, int hy);
int		ray_loop(t_game *game, t_player *p);
void	ray_initializer(t_player *p, double angle);
void    ray_initializer_2(t_player *p);
void	draw_multiple_ray(t_game *game, mlx_image_t *img);
double	normalised_angle(double angle);
void	draw_vertical(int drawS, int drawE, int check, mlx_image_t *img, int ray_i);

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