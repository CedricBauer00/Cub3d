/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:13:43 by batuhan           #+#    #+#             */
/*   Updated: 2025/09/03 14:34:41 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_game *game)
{
	double	angle;
	int		new_x;
	int		new_y;

	angle = game->player->angle;
	new_x = game->player->x + (int)round(cos(angle) * MOVE_S);
	new_y = game->player->y - (int)round(sin(angle) * MOVE_S);
	if (wall_check_up(game) == -1)
	{
		printf("x = %d, y = %d\n", new_x, new_y);
		printf("x = %d, y = %d\n", new_x / TS, new_y / TS);
		printf("can't go that way\n");
		return ;
	}
	game->player->x = new_x;
	game->player->y = new_y;
}

void	move_down(t_game *game)
{
	double	angle;
	int		new_x;
	int		new_y;

	angle = game->player->angle;
	new_x = game->player->x - (int)round(cos(angle) * MOVE_S);
	new_y = game->player->y + (int)round(sin(angle) * MOVE_S);
	if (wall_check_down(game) == -1)
	{
		printf("x = %d, y = %d\n", new_x, new_y);
		printf("x = %d, y = %d\n", new_x / TS, new_y / TS);
		printf("can't go that way\n");
		return ;
	}
	game->player->x = new_x;
	game->player->y = new_y;
}

void	move_left(t_game *game)
{
	double	angle;
	int		new_x;
	int		new_y;

	angle = game->player->angle;
	new_x = game->player->x - (int)round(sin(angle) * MOVE_S);
	new_y = game->player->y - (int)round(cos(angle) * MOVE_S);
	if (wall_check_left(game) == -1)
	{
		printf("x = %d, y = %d\n", new_x, new_y);
		printf("x = %d, y = %d\n", new_x / TS, new_y / TS);
		printf("can't go that way\n");
		return ;
	}
	game->player->x = new_x;
	game->player->y = new_y;
}

void	move_right(t_game *game)
{
	double	angle;
	int		new_x;
	int		new_y;

	angle = game->player->angle;
	new_x = game->player->x + (int)round(sin(angle) * MOVE_S);
	new_y = game->player->y + (int)round(cos(angle) * MOVE_S);
	if (wall_check_right(game) == -1)
	{
		printf("x = %d, y = %d\n", new_x, new_y);
		printf("x = %d, y = %d\n", new_x / TS, new_y / TS);
		printf("can't go that way\n");
		return ;
	}
	game->player->x = new_x;
	game->player->y = new_y;
}
