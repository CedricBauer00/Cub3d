/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:33:53 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/03 12:42:52 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_game *game, mlx_image_t *image)
{
    int i;
    int j;
    int d_x;
    int d_y;

    i = 0;
    j = 0;
    d_x = 0;
    d_y = 0;
    // image = mlx_new_image(game->mlx, 1024, 512);
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			mlx_put_pixel(image, 253 + i, 253 - j, 0x40E0D0);
			j++;
		}
		if (i == 3 || i == 4 || i == 5)
		{
			if (i == 4)
			{
				j = 0;
				while (j < 150)
				{
					mlx_put_pixel(image, 253 + i, 253 + j + 1, 0xFF0000FF);
					j++;
				}
			}
			j = 0;
			while (j < 20)
			{
                if (game->player->dir == LEFT)
                
				mlx_put_pixel(image, 253 + i, 253 + j + 1,0xFFFF00FF);
				j++;
			}
		}
		i++;
	}
}
