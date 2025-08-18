/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:34:41 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/18 15:14:53 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_game *game)
{
    int i = 0;
    int j = 0;
    int k = -1;
    int l = -1;
    
    mlx_image_t *minimap = game->player->minimap;
    
    while (i < (int)minimap->height)
    {
        j = 0;
        while (j < (int)minimap->width)
        {
            mlx_put_pixel(minimap, j, i, 0x00000000);
            j++;
        }
        i++;
    }
    
    i = 0;
    l = -1;
    while (i < (int)minimap->height && l < 24)
    {
        j = 0;
        k = -1;
        if (i % (TS / 7) == 0)
        {
            if (l < 24)
                l++;
        }
        while (j < (int)minimap->width && k < 24)
        {
            if (j % (TS / 5) == 0)
            {
                if (k < 24)
                    k++;
            }
            if (l >= 0 && k >= 0 && l < 24 && k < 24)
            {
                if (game->map[l][k] == 1)
                    mlx_put_pixel(minimap, j, i, 0xFFFFFFAA);
                else if (game->map[l][k] == 0)
                    mlx_put_pixel(minimap, j, i, 0x000000AA);
            }
            j++;
        }
        i++;
    }
}
