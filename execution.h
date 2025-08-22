/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:15:15 by bolcay            #+#    #+#             */
/*   Updated: 2025/08/22 11:09:16 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
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
# include "Parsing/inc/parsing.h"

# define TS 64
# define WIDTH 1024
# define HEIGHT 720
# define MOVE_S 5
# define SPEED 0.05
# define ROT_SPEED 0.003
# define PI 3.1415926535897932
# define RAY_N WIDTH

typedef struct s_ray
{
	int		hit;	   // if the ray hits a wall.
	int		hx;		   // the x coordinate of the wall we're looking at.
	int		hy;		   // the y coordinate of the wall we're looking at.
	double	hitX;
	double	hitY;
	int		lineH;
	int		drawS;
	int		drawE;
	double	angleDiff;
	int		side;	   // the side of the wall we're looking at.
	double	wallDist; // the distance for the 3d drawing so that it won't have the fish eye effect.
	double	rawDist;  // original distance for 2D ray drawing
}	t_ray;

typedef struct s_player
{
	double	x; // player coordinates.
	double	y;
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
	mlx_image_t *minimap;
	mlx_instance_t *inst;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_game
{
	// int	map[24][24];
	char	**map;
	int		mwidth;
	int		mheight;
	t_ray	*ray;
	mlx_t	*mlx;
	t_player *player;
}	t_game;

// printing stuff on the map

// prints a 2d map to do some tests
void	draw_minimap(t_game *game, mlx_image_t *minimap, int i, int l);
// int		paint_map(t_game *game, mlx_image_t *image);
int		paint_map(t_map *map_info, t_game *game, mlx_image_t *image);

void	delete_image(mlx_image_t *image);
// this one is being used every time the character moves.
// it prints the body of the character, the direction showing stick thing and the red ray that stops when it hits a wall.
// i will add more rays to it to get a proper field of view.
void	draw_player(t_game *game, mlx_image_t *image);
// draw_ray function and its little helper are used to calculate the distance of the red ray.
t_ray	draw_ray(t_game *game, t_player *p, mlx_image_t *image, int check, double angle, int i);
void	draw_ray_helper(t_game *game, mlx_image_t *image, int hx, int hy);
void	draw_ray_init(t_player *p, t_ray *r, double angle, int check);
int		ray_loop(t_game *game, t_player *p);
void	ray_initializer(t_player *p, double angle);
void    ray_initializer_2(t_player *p);
void	draw_multiple_ray(t_game *game, mlx_image_t *img);
double	normalised_angle(double angle);
void	draw_vertical(int drawS, int drawE, int check, mlx_image_t *img, int ray_i);

// movement

// this functions takes gets the signal of the keys you press and does something depending on which key was pressed.
void	key(mlx_key_data_t keys, void *ptr);

// movement functions.
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

// wall collision check for the movement functions.
int		wall_check_up(t_game *g, int x, int y);
int		wall_check_down(t_game *g, int x, int y);
int		wall_check_left(t_game *g, int x, int y);
int		wall_check_right(t_game *g, int x, int y);

// rotation functions.
void	rotate_right(t_game *game);
void	rotate_left(t_game *game);

// a small initializing function
void	initialize(t_map *maps, t_game *game);
int		execute_main(t_configs *data);
void	cursor(double xpos, double ypos, void *ptr);
void	update_frame(void *ptr);

#endif