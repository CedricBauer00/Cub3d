/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:33:53 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/27 10:22:13 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	we use this function to delete the drawn images whenever
	we want to draw something new.
*/

void	delete_image(mlx_image_t *image)
{
	size_t	len;

	len = image->width * image->height * sizeof(uint32_t);
	ft_memset(image->pixels, 0, len);
}

/*
	this here is draws the yellow square that stands for the player
	we have in the 2d map.
*/

// static void	draw_player_helper(t_game *game, mlx_image_t *img)
// {
// 	int	i;
// 	int	j;
// 	int	d_x;
// 	int	d_y;

// 	i = 0;
// 	d_x = game->player->x;
// 	d_y = game->player->y;
// 	while (i < 8)
// 	{
// 		j = 0;
// 		while (j < 8)
// 		{
// 			mlx_put_pixel(img, d_x + i - 4, d_y + j - 4, 0xFFFF00FF);
// 			j++;
// 		}
// 		i++;
// 	}
// }

/*
	draw multiple rays function is where we start calculating the rays and also
	drawing them on the 2d map.
	below it we see a while loop which is used to draw a yellow stick thingy to
	see the direction we're facing.

	the last one is explained above
*/

void	draw_player(t_game *game)
{
	// delete_image(image);
	draw_multiple_ray(game);
}
