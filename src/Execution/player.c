/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:33:53 by batuhan           #+#    #+#             */
/*   Updated: 2025/09/03 13:05:21 by bolcay           ###   ########.fr       */
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
	draw multiple rays function is where we start calculating the rays and also
	drawing them on the 2d map.
	below it we see a while loop which is used to draw a yellow stick thingy to
	see the direction we're facing.

	the last one is explained above
*/

void	draw_player(t_game *game)
{
	draw_multiple_ray(game);
}
