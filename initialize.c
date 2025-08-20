/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:55:42 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/19 13:38:07 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	initialize(t_configs *data, t_game *game)
{
	printf("x = %f\n", data->map_info->x_pos);
	game->player->angle = PI / 2; 
	game->player->x = 10 * TS + 32; // Center of an open area in the new map
	game->player->y = 10 * TS + 32;
}
