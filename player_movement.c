/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:13:43 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/06 13:39:14 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate_right(t_game *game)
{
	game->player->angle -= SPEED;
	if (game->player->angle < 0)
		game->player->angle += 2 * PI;
	draw_player_ex(game, game->player->image);
}

static void	rotate_left(t_game *game)
{
	game->player->angle += SPEED;
	if (game->player->angle > 2 * PI)
		game->player->angle -= 2 * PI;
	draw_player_ex(game, game->player->image);
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

void	move_up(t_game *game)
{
	double	angle;
	int		x;
	int		y;

	angle = game->player->angle;
	x = game->player->x;
	y = game->player->y;
	x += (int)round(sin(angle) * 5);
	y -= (int)round(cos(angle) * 5);
	if (game->map[y / 32][x / 32] == 1)
	{
		printf("x = %d, y = %d\n", x, y);
		printf("x = %d, y = %d\n", x / 32, y / 32);
		printf("can't go that way\n");
		return ;
	}
	game->player->dir = UP;
	game->player->inst = &game->player->image->instances[0];
	game->player->inst->x += (int)round(cos(angle) * 5);
	game->player->x += (int)round(cos(angle) * 5);
	game->player->inst->y -= (int)round(sin(angle) * 5);
	game->player->y -= (int)round(sin(angle) * 5);
	printf("x = %d, y = %d\n", game->player->x, game->player->y);
	draw_player_ex(game, game->player->image);
}

void	move_down(t_game *game)
{
	double	angle;
	int		x;
	int		y;

	angle = game->player->angle;
	x = game->player->x;
	y = game->player->y;
	x -= (int)round(cos(angle) * 5);
	y += (int)round(sin(angle) * 5);
	if (game->map[y / 32][x / 32] == 1)
	{
		printf("x = %d, y = %d\n", x, y);
		printf("x = %d, y = %d\n", x / 32, y / 32);
		printf("can't go that way\n");
		return ;
	}
	game->player->dir = DOWN;
	game->player->inst = &game->player->image->instances[0];
	game->player->inst->x -= (int)round(cos(angle) * 5);
	game->player->x -= (int)round(cos(angle) * 5);
	game->player->inst->y += (int)round(sin(angle) * 5);
	game->player->y += (int)round(sin(angle) * 5);
	printf("x = %d, y = %d\n", game->player->x, game->player->y);
	draw_player_ex(game, game->player->image);
}

void	move_right(t_game *game)
{
	double	angle;
	int		x;
	int		y;

	angle = game->player->angle;
	x = game->player->x;
	y = game->player->y;
	x += (int)round(sin(angle) * 5);
	y += (int)round(cos(angle) * 5);
	if (game->map[y / 32][x / 32] == 1)
	{
		printf("x = %d, y = %d\n", x, y);
		printf("x = %d, y = %d\n", x / 32, y / 32);
		printf("can't go that way\n");
		return ;
	}
	game->player->dir = RIGHT;
	game->player->inst = &game->player->image->instances[0];
	game->player->inst->x += (int)round(sin(angle) * 5);
	game->player->x += (int)round(sin(angle) * 5);
	game->player->inst->y += (int)round(cos(angle) * 5);
	game->player->y += (int)round(cos(angle) * 5);
	// printf("x = %d, y = %d\n", game->player->x, game->player->y);
	draw_player_ex(game, game->player->image);
}

void	move_left(t_game *game)
{
	double	angle;
	int		x;
	int		y;

	angle = game->player->angle;
	x = game->player->x;
	y = game->player->y;
	x -= (int)round(sin(angle) * 5);
	y -= (int)round(cos(angle) * 5);
	if (game->map[y / 32][x / 32] == 1)
	{
		printf("x = %d, y = %d\n", x, y);
		printf("x = %d, y = %d\n", x / 32, y / 32);
		printf("can't go that way\n");
		return ;
	}
	game->player->dir = LEFT;
	game->player->inst = &game->player->image->instances[0];
	game->player->inst->x -= (int)round(sin(angle) * 5);
	game->player->x -= (int)round(sin(angle) * 5);
	game->player->inst->y -= (int)round(cos(angle) * 5);
	game->player->y -= (int)round(cos(angle) * 5);
	printf("x = %d, y = %d\n", game->player->x, game->player->y);
	draw_player_ex(game, game->player->image);
}
