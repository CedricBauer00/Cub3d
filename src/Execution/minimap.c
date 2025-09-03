/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:34:41 by batuhan           #+#    #+#             */
/*   Updated: 2025/09/03 14:02:55 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_character(t_game *game, mlx_image_t *minimap, int scale)
{
	int	minix;
	int	miniy;
	int	i;
	int	j;
	double	player_map_x;
	double	player_map_y;

	if (scale <= 0)
		return ;
	player_map_x = (double)game->player->x / TS;
	player_map_y = (double)game->player->y / TS;
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

void	draw_minimap_check(t_game *g, t_minimap *m, int i, int j)
{
	if (j == (int)g->player->minimap->width - 1)
		m->k = g->mwidth - 1;
	else
		m->k = (j * g->mwidth) / g->player->minimap->width;
	if (i == (int)g->player->minimap->height - 1)
		m->l = g->mheight - 1;
	else
		m->l = (i * g->mheight) / g->player->minimap->height;
}

void	put_pixel(t_game *g, t_minimap m, int i, int j)
{
	mlx_image_t *minimap;

	minimap = g->player->minimap;
	if (m.l >= 0 && m.k >= 0 && m.l < g->mheight && m.k < g->mwidth)
	{
		if (g->map[m.l][m.k] == '1')
			mlx_put_pixel(minimap, j, i, 0xFFFFFFAA);
		else if (check_minimap(g, m.l, m.k) == 1)
			mlx_put_pixel(minimap, j, i, 0x000000AA);
		else if (g->map[m.l][m.k] == 'D' || g->map[m.l][m.k] == '2')
			mlx_put_pixel(minimap, j, i, 0xFF00FFAA);
		else
			mlx_put_pixel(minimap, j, i, 0x808080AA);
	}
	else
		mlx_put_pixel(minimap, j, i, 0x808080AA);
}

void	draw_minimap(t_game *game, mlx_image_t *minimap, int i)
{
	int			j;
	t_minimap	m;

	i = 0;
	while (i < (int)minimap->height)
	{
		j = 0;
		while (j < (int)minimap->width)
		{
			draw_minimap_check(game, &m, i, j);
			put_pixel(game, m, i, j);
			j++;
		}
		i++;
	}
	draw_character(game, minimap, game->minimap_scale);
}
