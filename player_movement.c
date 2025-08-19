/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:13:43 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/19 17:11:07 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	int		new_x;
	int		new_y;
	int		buffer;

	buffer = 8;
	angle = game->player->angle;
	new_x = game->player->x + (int)round(cos(angle) * MOVE_S);
	new_y = game->player->y - (int)round(sin(angle) * MOVE_S);
	if (wall_check_up(game, game->player->x, game->player->y) == -1)
	{
		printf("x = %d, y = %d\n", new_x, new_y);
		printf("x = %d, y = %d\n", new_x / TS, new_y / TS);
		printf("can't go that way\n");
		return ;
	}
	game->player->x = new_x;
	game->player->y = new_y;
	draw_player(game, game->player->image);
	draw_minimap(game);
}

void	move_down(t_game *game)
{
	double	angle;
	int		new_x;
	int		new_y;
	int		buffer;

	buffer = 8;
	angle = game->player->angle;
	new_x = game->player->x - (int)round(cos(angle) * MOVE_S);
	new_y = game->player->y + (int)round(sin(angle) * MOVE_S);
	if (wall_check_down(game, game->player->x, game->player->y) == -1)
	{
		printf("x = %d, y = %d\n", new_x, new_y);
		printf("x = %d, y = %d\n", new_x / TS, new_y / TS);
		printf("can't go that way\n");
		return ;
	}
	game->player->x = new_x;
	game->player->y = new_y;
	draw_player(game, game->player->image);
	draw_minimap(game);
}

void	move_left(t_game *game)
{
	double	angle;
	int		new_x;
	int		new_y;
	int		buffer;

	buffer = 8;
	angle = game->player->angle;
	new_x = game->player->x - (int)round(sin(angle) * MOVE_S);
	new_y = game->player->y - (int)round(cos(angle) * MOVE_S);
	if (wall_check_left(game, game->player->x, game->player->y) == -1)
	{
		printf("x = %d, y = %d\n", new_x, new_y);
		printf("x = %d, y = %d\n", new_x / TS, new_y / TS);
		printf("can't go that way\n");
		return ;
	}
	game->player->x = new_x;
	game->player->y = new_y;
	draw_player(game, game->player->image);
	draw_minimap(game);
}

void	move_right(t_game *game)
{
	double	angle;
	int		new_x;
	int		new_y;
	int		buffer;

	buffer = 8;
	angle = game->player->angle;
	new_x = game->player->x + (int)round(sin(angle) * MOVE_S);
	new_y = game->player->y + (int)round(cos(angle) * MOVE_S);
	if (wall_check_right(game, game->player->x, game->player->y) == -1)
	{
		printf("x = %d, y = %d\n", new_x, new_y);
		printf("x = %d, y = %d\n", new_x / TS, new_y / TS);
		printf("can't go that way\n");
		return ;
	}
	game->player->x = new_x;
	game->player->y = new_y;
	draw_player(game, game->player->image);
	draw_minimap(game);
}
