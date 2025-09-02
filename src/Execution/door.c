/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:32:32 by bolcay            #+#    #+#             */
/*   Updated: 2025/09/02 09:49:54 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	door_handle(t_game *g, int x, int y) //UNUSED
{
	if (g->map[y][x] == 'D')
		g->map[y][x] = '2';
	else if (g->map[y][x] == '2')
		g->map[y][x] = 'D';
}

void	open_door(t_game *g)
{
	int		i;
	int		new_x;
	int		new_y;
	double	angle;

	angle = g->player->angle;
	i = 1;
	if (g->map[(int)g->player->y / TS][(int)g->player->x / TS] == '1'
		|| g->map[(int)g->player->y / TS][(int)g->player->x / TS] == '2'
		|| g->map[(int)g->player->y / TS][(int)g->player->x / TS] == 'D')
		return ;
	while (i <= MOVE_S + 60)
	{
		new_x = g->player->x + (int)round(cos(angle) * i);
		new_y = g->player->y - (int)round(sin(angle) * i);
		if (g->map[new_y / TS][new_x / TS] == 'D' || g->map[new_y / TS][new_x / TS] == '2')
		{
			door_handle(g, new_x / TS, new_y / TS);
			return ;
		}
		i++;
	}
	if (g->map[new_y / TS][new_x / TS] == 'D' || g->map[new_y / TS][new_x / TS] == '2')
		door_handle(g, new_x / TS, new_y / TS);
}
