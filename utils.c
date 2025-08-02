/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:09:42 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/02 14:05:16 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	paint_map(t_game *game, mlx_image_t *image)
{
	int	i;
	int	j;
	int	k;
	int	l;

	int	map[8][8] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1},
	};
	i = 0;
	k = 0;
	l = 0;
	image = mlx_new_image(game->mlx, 1024, 512);
	while (i < 512)
	{
		j = 0;
		k = 0;
		if (i % 64 == 0)
		{
			i++;
			if (l < 7)
				l++;
			continue ;
		}
		while (j < 512)
		{
			if (j % 64 == 0)
			{
				j++;
				if (k < 7)
					k++;
				continue;
			}
			else
			{
				if (map[l][k] == 1)
				{
					mlx_put_pixel(image, i, j, 0xFFFFFFFF);
				}
				else if (map[l][k] == 0)
				{
					mlx_put_pixel(image, i, j, 0x000000FF);
				}
				j++;
			}
		}
		i++;
	}
	mlx_image_to_window(game->mlx, image, 0, 0);
	return (0);
}
