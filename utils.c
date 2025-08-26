/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:09:42 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/26 16:30:49 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	here we have the normalised angle function. it's used to make sure
	the angle is between 0 and 2pi
*/

double	normalised_angle(double angle)
{
	if (angle < 0)
		angle += 2.0 * PI;
	if (angle >= 2.0 * PI)
		angle -= 2.0 * PI;
	return (angle);
}

void	initialize(t_map *maps, t_game *game)
{
	game->map = maps->map;
	game->mwidth = maps->width;
	game->mheight = maps->hight;
	game->player->angle = PI / 2;
	game->player->x = 10 * TS + 32;
	game->player->y = 10 * TS + 32;
	game->player->dir_x = cos(game->player->angle);
	game->player->dir_y = sin(game->player->angle);
	game->player->plane_x = -game->player->dir_y * 0.66;
	game->player->plane_y = game->player->dir_x * 0.66;
}

/*
	these two functions blow are used to both rotate the players angle and
	to correct the angle if it goes out of bounds.
*/

void	rotate_right(t_game *game)
{
	game->player->angle -= SPEED;
	if (game->player->angle < 0)
		game->player->angle += 2 * PI;
}

void	rotate_left(t_game *game)
{
	game->player->angle += SPEED;
	if (game->player->angle > 2 * PI)
		game->player->angle -= 2 * PI;
}
