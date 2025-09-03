/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:33:53 by batuhan           #+#    #+#             */
/*   Updated: 2025/09/03 14:34:35 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	delete_image(mlx_image_t *image)
{
	size_t	len;

	len = image->width * image->height * sizeof(uint32_t);
	ft_memset(image->pixels, 0, len);
}

void	draw_player(t_game *game)
{
	draw_multiple_ray(game);
}
