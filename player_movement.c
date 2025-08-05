/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:13:43 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/05 15:06:15 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		{
			move_up(game);
		}
		else if (signal == MLX_KEY_A)
		{
			move_left(game);
		}
		else if (signal == MLX_KEY_S)
		{
			move_down(game);
		}
		else if (signal == MLX_KEY_D)
		{
			move_right(game);
		}
		else if (signal == MLX_KEY_LEFT)
		{
		}
		else if (signal == MLX_KEY_RIGHT)
		{
		}
	}
}

void	move_up(t_game *game)
{
	game->player->dir = UP;
	game->player->inst = &game->player->image->instances[0];
	game->player->inst->y -= 5;
	game->player->y -= 5;
	draw_player_updown(game, game->player->image);
}

void	move_down(t_game *game)
{
	game->player->dir = DOWN;
	game->player->inst = &game->player->image->instances[0];
	game->player->inst->y += 5;
	game->player->y += 5;
	draw_player_updown(game, game->player->image);
}

void	move_right(t_game *game)
{
	game->player->dir = RIGHT;
	game->player->inst = &game->player->image->instances[0];
	game->player->inst->x += 5;
	game->player->x += 5;
	draw_player_sides(game, game->player->image);
}

void	move_left(t_game *game)
{
	game->player->dir = LEFT;
	game->player->x -= 5;
	// draw_player(game, game->player->image);
	game->player->inst = &game->player->image->instances[0];
	game->player->inst->x -= 5;
	draw_player_sides(game, game->player->image);
}
