/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:55:42 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/20 10:07:53 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize(t_map *maps, t_game *game)
{
	game->map = maps->map;
	game->mwidth = maps->width;
	game->mheight = maps->hight;
	game->player->angle = PI / 2; 
	game->player->x = 10 * TS + 32; // Center of an open area in the new map
	game->player->y = 10 * TS + 32;
}
