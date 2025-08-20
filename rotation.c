/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:00:48 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/19 17:42:15 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	these two functions blow are used to both rotate the players angle and to correct the angle if it goes out of bounds.
*/

void	rotate_right(t_game *game)
{
	game->player->angle -= SPEED;
	if (game->player->angle < 0)
		game->player->angle += 2 * PI;
	draw_player(game, game->player->image);
	draw_minimap(game, game->player->minimap, 0, -1);
}

void	rotate_left(t_game *game)
{
	game->player->angle += SPEED;
	if (game->player->angle > 2 * PI)
		game->player->angle -= 2 * PI;
	draw_player(game, game->player->image);
	draw_minimap(game, game->player->minimap, 0, -1);
}
