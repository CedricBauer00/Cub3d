/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:09:42 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/11 15:08:33 by batuhan          ###   ########.fr       */
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
		{1, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1},
	};
	i = 0;
	j = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			game->map[i][j] = map[i][j];
			// printf("%d", game->map[i][j]);
			j++;
		}
		// printf("\n");
		i++;
	}
	i = 0;
	j = 0;
	k = -1;
	l = -1;
	image = mlx_new_image(game->mlx, 512, 512);
	while (i < 512)
	{
		// k = i / 64;
		// j = 0;
		// while (j < 512)
		// {
		// 	l = j / 64;
		// 	if (map[k][l] == 1)
		// 		mlx_put_pixel(image, j, i, 0xFFFFFFFF);
		// 	else
		// 		mlx_put_pixel(image, j, i, 0x000000FF);
		// 	j++;
		// }
		j = 0;
		k = -1;
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
					mlx_put_pixel(image, j, i, 0xFFFFFFFF);
				}
				else if (map[l][k] == 0)
				{
					mlx_put_pixel(image, j, i, 0x000000FF);
				}
				j++;
			}
		}
		i++;
	}
	mlx_image_to_window(game->mlx, image, 0, 0);
	return (0);
}
