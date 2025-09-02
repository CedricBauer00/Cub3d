/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:34:41 by batuhan           #+#    #+#             */
/*   Updated: 2025/09/02 22:13:43 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	calculate_minimap_scale(int map_width, int map_height)
{
	int	potential_width;
	int	potential_height;
	int	scale;

	if (map_width <= 0 || map_height <= 0)
		return (MIN_MINIMAP_SCALE);
	
	scale = MIN_MINIMAP_SCALE;
	while (scale <= 50)
	{
		potential_width = (map_width * TS) / scale;
		potential_height = (map_height * TS) / scale;
		if (potential_width <= MAX_MINIMAP_WIDTH
			&& potential_height <= MAX_MINIMAP_HEIGHT)
			return (scale);
		scale++;
	}
	scale = (map_width * TS) / MAX_MINIMAP_WIDTH;
	if ((map_height * TS) / MAX_MINIMAP_HEIGHT > scale)
		scale = (map_height * TS) / MAX_MINIMAP_HEIGHT;
	
	if (scale < MIN_MINIMAP_SCALE)
		scale = MIN_MINIMAP_SCALE;
	
	return (scale + 1);
}

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

void	draw_character(t_game *game, mlx_image_t *minimap, int scale)
{
	int	minix;
	int	miniy;
	int	i;
	int	j;
	if (scale <= 0)
		return;

	double player_map_x = (double)game->player->x / TS;
	double player_map_y = (double)game->player->y / TS;
	minix = (int)((player_map_x * minimap->width) / game->mwidth);
	miniy = (int)((player_map_y * minimap->height) / game->mheight);
	in_bounds_check(minimap, &minix, &miniy);
	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			if (minix + i >= 0 && minix + i < (int)minimap->width
				&& miniy + j >= 0 && miniy + j < (int)minimap->height)
				mlx_put_pixel(minimap, minix + i, miniy + j, 0xFFFF00AA);
			j++;
		}
		i++;
	}
}

static int	check_minimap(t_game *game, int l, int k)
{
	if (game->map[l][k] == '0' || game->map[l][k] == 'N'
		|| game->map[l][k] == 'S' || game->map[l][k] == 'W'
		|| game->map[l][k] == 'E')
		return (1);
	return (0);
}

void	draw_minimap(t_game *game, mlx_image_t *minimap, int i, int l, int scale)
{
	int	k;
	int	j;
	int	scale_step;

	if (scale <= 0)
		scale = MIN_MINIMAP_SCALE;
	scale_step = TS / scale;
	if (scale_step <= 0)
		scale_step = 1;
	i = 0;
	while (i < (int)minimap->height)
	{
		j = 0;
		while (j < (int)minimap->width)
		{
			if (j == (int)minimap->width - 1)
				k = game->mwidth - 1;
			else
				k = (j * game->mwidth) / minimap->width;
			if (i == (int)minimap->height - 1)
				l = game->mheight - 1;
			else
				l = (i * game->mheight) / minimap->height;
			
			if (l >= 0 && k >= 0 && l < game->mheight && k < game->mwidth)
			{
				if (game->map[l][k] == '1')
					mlx_put_pixel(minimap, j, i, 0xFFFFFFAA);
				else if (check_minimap(game, l, k) == 1)
					mlx_put_pixel(minimap, j, i, 0x000000AA);
				else if (game->map[l][k] == 'D' || game->map[l][k] == '2')
					mlx_put_pixel(minimap, j, i, 0xFF00FFAA);
				else
					mlx_put_pixel(minimap, j, i, 0x808080AA);
			}
			else
				mlx_put_pixel(minimap, j, i, 0x808080AA);
			j++;
		}
		i++;
	}
	draw_character(game, minimap, scale);
}
