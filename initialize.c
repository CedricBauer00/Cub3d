/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:55:42 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/14 10:19:18 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	initialize(t_game *game)
{
	game->player->angle = PI / 2; 
	game->player->x = 254; //map_info.player_x
	game->player->y = 254; //map_info.player_y
}
