/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:33:53 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/11 20:07:56 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	delete_image(mlx_image_t *image)
{
	ft_memset(image->pixels, 0, image->width * image->height * sizeof(uint32_t));
}

static void	draw_player_helper(t_game *game, mlx_image_t *img)
{
	int	i;
	int	j;
	int	d_x;
	int	d_y;

	i = 0;
	d_x = game->player->x;
	d_y = game->player->y;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			mlx_put_pixel(img, d_x + i, d_y + j, 0xFFFF00FF);
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *game, mlx_image_t *image)
{
	int i;
    int d_x;
    int d_y;
	int	p_x;
	int	p_y;

    i = 0;
    d_x = game->player->x;
    d_y = game->player->y;
	delete_image(image);
	// draw_ray(game, game->player, image, 0);
	draw_multiple_ray(game, image);
	while (i < 20)
	{
		p_x = d_x + 4 + (int)round(cos(game->player->angle) * i);
		p_y = d_y + 4 - (int)round(sin(game->player->angle) * i);
		mlx_put_pixel(image, p_x, p_y, 0xFFFF00FF);
		i++;
	}
	draw_player_helper(game, image);
}
