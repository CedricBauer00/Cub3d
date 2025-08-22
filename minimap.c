/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:34:41 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/22 12:40:47 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	in_bounds_check(mlx_image_t *minimap, int *miniX, int *miniY)
{
	if (*miniX < 0)
		*miniX = 0;
    if (*miniY < 0)
		*miniY = 0;
    if (*miniX >= (int)minimap->width)
		*miniX = minimap->width - 1;
    if (*miniY >= (int)minimap->height)
		*miniY = minimap->height - 1;
}

void	draw_character(t_game *game, mlx_image_t *minimap)
{
    int miniX;
    int miniY;
	int	i;
	int	j;

	miniX = (game->player->x * (TS / 5)) / TS;
    miniY = (game->player->y * (TS / 7)) / TS;
	in_bounds_check(minimap, &miniX, &miniY);
    i = -2;
    while (i <= 2)
    {
        j = -2;
        while (j <= 2)
        {
            if (miniX + i >= 0 && miniX + i < (int)minimap->width && 
                miniY + j >= 0 && miniY + j < (int)minimap->height)
                mlx_put_pixel(minimap, miniX + i, miniY + j, 0xFFFF00AA);
            j++;
        }
        i++;
    }
}

void	draw_minimap(t_game *game, mlx_image_t *minimap, int i, int l)
{
    int k;
	int	j;
	
    while (i < (int)minimap->height && l < game->mheight)
    {
        j = 0;
        k = -1;
        if (i % (TS / 7) == 0 && l < game->mheight)
            l++;
        while (j < (int)minimap->width && k < game->mwidth)
        {
            if (j % (TS / 5) == 0 && k < game->mwidth)
                k++;
            if (l >= 0 && k >= 0 && l < game->mheight && k < game->mwidth)
            {
                if (game->map[l][k] == '1')
                    mlx_put_pixel(minimap, j, i, 0xFFFFFFAA);
                else if (game->map[l][k] == '0' || game->map[l][k] == 'N')
                    mlx_put_pixel(minimap, j, i, 0x000000AA);
            }
            j++;
        }
        i++;
    }
	draw_character(game, minimap);
}
