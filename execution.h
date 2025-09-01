/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:15:15 by bolcay            #+#    #+#             */
/*   Updated: 2025/09/01 11:41:19 by cbauer           ###   ########.fr       */
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
# define SPEED 0.03
# define ROT_SPEED 0.003
# define PI 3.1415926535897932
# define RAY_N WIDTH

typedef struct s_ray
{
	int		hit;	   // if the ray hits a wall.
	int		hx;		   // the x coordinate of the wall we're looking at.
	int		hy;		   // the y coordinate of the wall we're looking at.
	double	hit_x;
	double	hit_y;
	int		line_h;
	int		draw_s;
	int		draw_e;
	double	angle_diff;
	int		side;	   // the side of the wall we're looking at.
	double	wall_dist; // the distance for the 3d drawing so that it won't have the fish eye effect.
	double	raw_dist;  // original distance for 2D ray drawing
}	t_ray;

typedef struct s_tex
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
	mlx_texture_t	*door;

	mlx_image_t		*no_tex;
	mlx_image_t		*so_tex;
	mlx_image_t		*we_tex;
	mlx_image_t		*ea_tex;
	uint32_t		sky;
	uint32_t		floor;
	int				tex_x;
	int				tex_y;
	double			wall_x;
	double			step;
	double			tex_pos;
}	t_tex;

typedef struct s_player
{
	double			x; // player coordinates.
	double			y;
	double			angle; // direction we're looking at.
	double			ray_dir_x; // the directions of the ray is being casted.
	double			ray_dir_y;
	double			delta_dist_x; // amount of movement we need to do for the ray
	double			delta_dist_y;
	int				map_x; // these 2 is used when we are calculating the rays and therefore changing the location of where we are.
	int				map_y;
	double			pos_x; // this is also normal player coordinates but divided by the tile size.
	double			pos_y;
	double			side_dist_x; // determines which one to increase, x or y.
	double			side_dist_y;
	int				step_x; // determines the direction of the ray. up-down or left-right.
	int				step_y;
	mlx_image_t		*image;
	mlx_image_t		*minimap;
	mlx_instance_t	*inst;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}	t_player;

typedef struct	s_animation
{
	mlx_image_t		*gun_img;
	int				gun_offset;
	bool			gun_movement;
}	t_aniamtion;

typedef struct s_game
{
	char		**map;
	int			mwidth;
	int			mheight;
	int			ray_i;
	t_ray		*ray;
	t_tex		*tex;
	mlx_t		*mlx;
	t_player	*player;
	bool		w;
	bool		a;
	bool		s;
	bool		d;
	bool		r;
	bool		l;
	t_aniamtion	*gun_anim;
	int			timer;
	bool		move;
	bool		std;
}	t_game;

// prints a 2d map.
void		draw_minimap(t_game *game, mlx_image_t *minimap, int i, int l);
// clears what was drawn when updating the image.
void		delete_image(mlx_image_t *image);
// where the first calculation stuff starts for the rays.
// also it's the start of the drawing process too.
void		draw_player(t_game *game);
// draw_ray function and its little helper are used to calculate
// the distance of the red ray.
t_ray		draw_ray(t_game *game, int check, double angle);
// it was used to draw the rays of the other 2d map we had before.
void		draw_ray_helper(t_game *game, mlx_image_t *image, int hx, int hy);
// more calculations.
void		draw_ray_init(t_player *p, t_ray *r, double angle, int check);
// calculating the distance of the ray.
int			ray_loop(t_game *game, t_player *p);
// calculations used for the ray stuff.
void		ray_initializer(t_player *p, double angle);
// calculations used for the ray stuff.
void		ray_initializer_2(t_player *p);
// looping to draw the rays for RAY_N amount of times.
void		draw_multiple_ray(t_game *game);
// fixes the angle if it's more than 2 PI's or less than 0.
double		normalised_angle(double angle);
// this is where the actual drawing on the screen part starts.
void		draw_vertical(t_game *g, t_ray r, int check, int ray_i);

// texture 

// deletes the textures
void	delete_textures(t_game *g);

// initialises the pngs
void		init_texture(t_configs *d, t_game *g);
// gets the colour from the png depending on where the ray hits.
uint32_t	texture_colour(mlx_texture_t *img, int x, int y, int check);
// changes the colour to a bit of a darker version to
// create a more realistic scene.
uint32_t	shade_colour(uint32_t colour);

// movement

// this functions gets the signal of the keys you press and does something
// depending on which key was pressed.
void		key(mlx_key_data_t keys, void *ptr);

// movement functions.
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);

// wall collision check for the movement functions.
int			wall_check_up(t_game *g);
int			wall_check_down(t_game *g);
int			wall_check_left(t_game *g);
int			wall_check_right(t_game *g);

// rotation functions.
void		rotate_right(t_game *game);
void		rotate_left(t_game *game);

// this function checks if there is a door ahead of the character and opens/closes it.
void		open_door(t_game *g);

// cursor function
void		cursor(double xpos, double ypos, void *ptr);

// game loop for drawing and movement
void		update_frame(void *ptr);
void		check_move(t_game *game, bool move, char c);
void		choose_move(t_game *game, char c, int *new_x, int *new_y);

// a small initializing function
void		initialize(t_map *maps, t_game *game);

// the functions used in the beginning of the execution.
int			game_start(t_game *game, t_configs *data);
int			execute_main(t_configs *data);

// ----------------------------------------------------------------------
//							Animation.c
// ----------------------------------------------------------------------

int			init_animation(t_game *g);
void		move_gun(t_game *g);
void		draw_gun(t_game *g);

#endif