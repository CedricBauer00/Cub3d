/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:55:42 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/26 15:10:33 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
