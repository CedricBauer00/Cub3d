/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:00:09 by bolcay            #+#    #+#             */
/*   Updated: 2025/09/03 14:09:01 by bolcay           ###   ########.fr       */
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

void	in_bounds_check(mlx_image_t *minimap, int *miniX, int *miniY)
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

int	check_minimap(t_game *game, int l, int k)
{
	if (game->map[l][k] == '0' || game->map[l][k] == 'N'
		|| game->map[l][k] == 'S' || game->map[l][k] == 'W'
		|| game->map[l][k] == 'E')
		return (1);
	return (0);
}
