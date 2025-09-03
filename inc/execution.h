/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:15:15 by bolcay            #+#    #+#             */
/*   Updated: 2025/09/03 15:56:17 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# include "../src/libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <unistd.h>
# include <stdbool.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include "parsing.h"

# define TS 64
# define WIDTH 1024
# define HEIGHT 720
# define MOVE_S 3
# define SPEED 0.03
# define ROT_SPEED 0.003
# define PI 3.1415926535897932
# define RAY_N WIDTH
# define MAX_MINIMAP_WIDTH 200
# define MAX_MINIMAP_HEIGHT 150
# define MIN_MINIMAP_SCALE 3
# define MAX_MINIMAP_SCALE 10

typedef struct s_minimap
{
	int	i;
	int	j;
	int	k;
	int	l;
}	t_minimap;

typedef struct s_ray
{
	int		hit;
	int		hx;
	int		hy;
	double	hit_x;
	double	hit_y;
	int		line_h;
	int		draw_s;
	int		draw_e;
	double	angle_diff;
	int		side;
	double	wall_dist;
	double	raw_dist;
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
	double			x;
	double			y;
	double			angle;
	double			ray_dir_x;
	double			ray_dir_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				map_x;
	int				map_y;
	double			pos_x;
	double			pos_y;
	double			side_dist_x;
	double			side_dist_y;
	int				step_x;
	int				step_y;
	mlx_image_t		*image;
	mlx_image_t		*minimap;
	mlx_instance_t	*inst;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}	t_player;

typedef struct s_animation
{
	mlx_image_t		*gun_img;
	mlx_image_t		*fire_gun;
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
	int			show;
	int			minimap_scale;
}	t_game;

// ----------------------------------------------------------------------
//						   Execute_main.c
// ----------------------------------------------------------------------
void		draw_gun(t_game *g);
// the functions used in the beginning of the execution.
int			game_start(t_game *game, t_configs *data);
int			execute_main(t_configs *data);
void		init_texture(t_configs *d, t_game *g);

// ----------------------------------------------------------------------
//							   Utils.c
// ----------------------------------------------------------------------

// deletes the textures
void		delete_textures(t_game *g);
// a small initializing function
void		initialize(t_map *maps, t_game *game);
// fixes the angle if it's more than 2 PI's or less than 0.
double		normalised_angle(double angle);
// rotation functions.
void		rotate_right(t_game *game);
void		rotate_left(t_game *game);

// ----------------------------------------------------------------------
//								Hooks.c
// ----------------------------------------------------------------------

// movement

// this functions gets the signal of the keys you press and does something
// depending on which key was pressed.
void		key(mlx_key_data_t keys, void *ptr);
// cursor function
void		cursor(double xpos, double ypos, void *ptr);
void		check_rotation(t_game *game, bool move, char c);
// game loop for drawing and movement
void		update_frame(void *ptr);
void		choose_move(t_game *game, char c, int *new_x, int *new_y);

// ----------------------------------------------------------------------
//							  WallCheck.c
// ----------------------------------------------------------------------

void		check_move(t_game *game, bool move, char c);
int			wall_check_up(t_game *g);
int			wall_check_down(t_game *g);
int			wall_check_left(t_game *g);
int			wall_check_right(t_game *g);

// ----------------------------------------------------------------------
//							  Minimap.c
// ----------------------------------------------------------------------

void		draw_character(t_game *game, mlx_image_t *minimap,
				double player_x, double player_y);
// prints a 2d map.
void		draw_minimap(t_game *game, mlx_image_t *minimap, int i);

// ----------------------------------------------------------------------
//							  Minimap_utils.c
// ----------------------------------------------------------------------

void		in_bounds_check(mlx_image_t *minimap, int *miniX, int *miniY);
int			calculate_minimap_scale(int map_width, int map_height);
int			check_minimap(t_game *game, int l, int k);

// ----------------------------------------------------------------------
//							Mouse_button.c
// ----------------------------------------------------------------------

void		mouse_button(mouse_key_t button, action_t action,
				modifier_key_t modifier, void *ptr);

// ----------------------------------------------------------------------
//							Player_movement.c
// ----------------------------------------------------------------------

void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);

// ----------------------------------------------------------------------
//							Player.c
// ----------------------------------------------------------------------

// clears what was drawn when updating the image.
void		delete_image(mlx_image_t *image);
// where the first calculation stuff starts for the rays.
// also it's the start of the drawing process too.
void		draw_player(t_game *game);

// ----------------------------------------------------------------------
//								Ray.c
// ----------------------------------------------------------------------

// calculating the distance of the ray.
int			ray_loop(t_game *game, t_player *p);
// draw_ray function and its little helper are used to calculate
// the distance of the red ray.
void		draw_ray(t_game *game, int check, double angle);
// looping to draw the rays for RAY_N amount of times.
void		draw_multiple_ray(t_game *game);

// ----------------------------------------------------------------------
//							Ray_init.c
// ----------------------------------------------------------------------

// calculations used for the ray stuff.
void		ray_initializer_2(t_player *p);
// calculations used for the ray stuff.
void		ray_initializer(t_player *p, double angle);
// more calculations.
void		draw_ray_init(t_player *p, t_ray *r, double angle, int check);

//-----------------------------------------------------------------------
//							Rotation.c
// ----------------------------------------------------------------------

void		rotate_right(t_game *game);
void		rotate_left(t_game *game);

// ----------------------------------------------------------------------
//							Textures.c
// ----------------------------------------------------------------------

// gets the colour from the png depending on where the ray hits.
uint32_t	texture_colour(mlx_texture_t *img, int x, int y, int check);
// changes the colour to a bit of a darker version to
// create a more realistic scene.
uint32_t	shade_colour(uint32_t colour);
// this is where the actual drawing on the screen part starts.
void		draw_vertical(t_game *g, t_ray r, int check, int ray_i);

// ----------------------------------------------------------------------
//							Doors.c
// ----------------------------------------------------------------------

// this function checks if there is a door ahead of the character and
// opens/closes it.
void		open_door(t_game *g, int i);
// static void	door_handle(t_game *g, int x, int y); //UNUSED

// ----------------------------------------------------------------------
//							Animation.c
// ----------------------------------------------------------------------

int			init_animation(t_game *g);
void		move_gun(t_game *g);

#endif