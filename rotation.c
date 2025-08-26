/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:00:48 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/26 15:01:40 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
