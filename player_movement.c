/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:13:43 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/14 14:01:37 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	these two functions blow are used to both rotate the players angle and to correct the angle if it goes out of bounds.
*/

static void	rotate_right(t_game *game)
{
	game->player->angle -= SPEED;
	if (game->player->angle < 0)
		game->player->angle += 2 * PI;
	draw_player(game, game->player->image);
}

static void	rotate_left(t_game *game)
{
	game->player->angle += SPEED;
	if (game->player->angle > 2 * PI)
		game->player->angle -= 2 * PI;
	draw_player(game, game->player->image);
}

void	key(mlx_key_data_t keys, void *ptr)
{
	int		signal;
	t_game	*game;

	game = (t_game *)ptr;
	signal = keys.key;
	if (keys.action == MLX_PRESS || keys.action == MLX_REPEAT)
	{
		if (signal == MLX_KEY_ESCAPE)
			exit(1);
		else if (signal == MLX_KEY_W)
			move_up(game);
		else if (signal == MLX_KEY_A)
			move_left(game);
		else if (signal == MLX_KEY_S)
			move_down(game);
		else if (signal == MLX_KEY_D)
			move_right(game);
		else if (signal == MLX_KEY_LEFT)
			rotate_left(game);
		else if (signal == MLX_KEY_RIGHT)
			rotate_right(game);
		// printf("x = %d, y = %d, angle = %f\n", game->player->x, game->player->y, game->player->angle);
	}
}

/*
	here at first we increase local x and y variables to check if the character will be out of bounds of the map.
	if this happens, we get an error message and it prevents us from moving in that direction. if that's not the case
	we move the player in that direction.

	normally in the so_long project we had to increase/decrease x or y by 1 but here we want to be able to move in the direction
	of the angle, therefore we calculate both cos and sin of the angle to get the correct direction and then multiply it by the
	amount of movement we want to make.

	draw player function is there to both draw the player in the 2d map and to go into the ray calculation/drawing progress.
*/

void	move_up(t_game *game)
{
	double	angle;
	int		x;
	int		y;

	angle = game->player->angle;
	x = game->player->x;
	y = game->player->y;
	x += (int)round(sin(angle) * MOVE_S);
	y -= (int)round(cos(angle) * MOVE_S);
	if (game->map[y / TS][x / TS] == 1)
	{
		printf("x = %d, y = %d\n", x, y);
		printf("x = %d, y = %d\n", x / TS, y / TS);
		printf("can't go that way\n");
		return ;
	}
	game->player->x += (int)round(cos(angle) * MOVE_S);
	game->player->y -= (int)round(sin(angle) * MOVE_S);
	// printf("x = %d, y = %d\n", game->player->x, game->player->y);
	draw_player(game, game->player->image);
}

void	move_down(t_game *game)
{
	double	angle;
	int		x;
	int		y;

	angle = game->player->angle;
	x = game->player->x;
	y = game->player->y;
	x -= (int)round(cos(angle) * MOVE_S);
	y += (int)round(sin(angle) * MOVE_S);
	if (game->map[y / TS][x / TS] == 1)
	{
		printf("x = %d, y = %d\n", x, y);
		printf("x = %d, y = %d\n", x / TS, y / TS);
		printf("can't go that way\n");
		return ;
	}
	game->player->x -= (int)round(cos(angle) * MOVE_S);
	game->player->y += (int)round(sin(angle) * MOVE_S);
	// printf("x = %d, y = %d\n", game->player->x, game->player->y);
	draw_player(game, game->player->image);
}

void	move_right(t_game *game)
{
	double	angle;
	int		x;
	int		y;

	angle = game->player->angle;
	x = game->player->x;
	y = game->player->y;
	x += (int)round(sin(angle) * MOVE_S);
	y += (int)round(cos(angle) * MOVE_S);
	if (game->map[y / TS][x / TS] == 1)
	{
		printf("x = %d, y = %d\n", x, y);
		printf("x = %d, y = %d\n", x / TS, y / TS);
		printf("can't go that way\n");
		return ;
	}
	game->player->x += (int)round(sin(angle) * MOVE_S);
	game->player->y += (int)round(cos(angle) * MOVE_S);
	// printf("x = %d, y = %d\n", game->player->x, game->player->y);
	draw_player(game, game->player->image);
}

void	move_left(t_game *game)
{
	double	angle;
	int		x;
	int		y;

	angle = game->player->angle;
	x = game->player->x;
	y = game->player->y;
	x -= (int)round(sin(angle) * MOVE_S);
	y -= (int)round(cos(angle) * MOVE_S);
	if (game->map[y / TS][x / TS] == 1)
	{
		printf("x = %d, y = %d\n", x, y);
		printf("x = %d, y = %d\n", x / TS, y / TS);
		printf("can't go that way\n");
		return ;
	}
	game->player->x -= (int)round(sin(angle) * MOVE_S);
	game->player->y -= (int)round(cos(angle) * MOVE_S);
	// printf("x = %d, y = %d\n", game->player->x, game->player->y);
	draw_player(game, game->player->image);
}
