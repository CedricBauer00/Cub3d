/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:33:53 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/05 14:17:46 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	delete_image(mlx_image_t *image)
{
	ft_memset(image->pixels, 0, image->width * image->height * sizeof(uint32_t));
}

void	draw_player(t_game *game, mlx_image_t *image)
{
    int i;
    int j;
	int	x;
	int	y;
    int d_x;
    int d_y;

    i = 0;
    j = 0;
    d_x = game->player->x;
    d_y = game->player->y;
	x = game->player->inst->x;
	y = game->player->inst->y;
	delete_image(image);
	while (i < 8)
	{
		// printf("1\n");
		d_x = game->player->x;
		d_y = game->player->y;
		if (game->player->dir == LEFT)
			d_x -= i;
		if (game->player->dir == RIGHT)
			d_x += i;
		if (i == 3 || i == 4 || i == 5)
		{
			// // printf("2\n");
			// if (i == 4)
			// {
			// 	// printf("3\n");
			// 	j = 0;
			// 	while (j < 150)
			// 	{
			// 		mlx_put_pixel(image, d_x, d_y + j + 1, 0xFF0000FF);
			// 		j++;
			// 	}
			// }
			j = 0;
			// printf("3\n");
			while (j < 20)
			{
				// if (game->player->dir == LEFT)
				// {
				// 	d_y += j;
				// }
				// if (game->player->dir == RIGHT)
				// {
				// 	d_y += j;
				// }
				if (game->player->dir == UP)
				{
					d_y -= j;
				}
				if (game->player->dir == DOWN)
				{
					d_y += j;
				}
				// printf("before pixel\n");
				mlx_put_pixel(game->player->image, d_x, d_y, 0xFFFF00FF);
				// printf("after pixel\n");
				// d_x = game->player->x;
				d_y = game->player->y;
				j++;
			}
			// d_x = game->player->x;
			// d_y = game->player->y;
			// printf("4\n");
		}
		j = 0;
		while (j < 8)
		{
			mlx_put_pixel(image, d_x, d_y + j, 0x40E0D0);
			j++;
		}
		i++;
		// printf("5\n");
	}
}
