/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:34:41 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/18 14:45:36 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_game *game, mlx_image_t *image)
{
    int i = 0;
    int j = 0;
    int k = -1;
    int l = -1;

    while (i < HEIGHT / 10)
    {
        j = 0;
        k = -1;
        if (i % (TS / 10) == 0)
        {
            i++;
            if (l < 23)
                l++;
            continue ;
        }
        while (j < WIDTH / 10)
        {
            if (j % (TS / 10) == 0)
            {
                j++;
                if (k < 23)
                    k++;
                continue ;
            }
            if (game->map[l][k] == 1)
                mlx_put_pixel(image, j, i, 0xFFFFFF80);
            else if (game->map[l][k] == 0)
                mlx_put_pixel(image, j, i, 0x00000080);
            j++;
        }
        i++;
    }
}
