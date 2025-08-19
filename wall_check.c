/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:08:52 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/19 17:10:49 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_check_up(t_game *g, int x, int y)
{
	int		i;
	int		j;
	int		new_x;
	int		new_y;
	double	angle;

	angle = g->player->angle;
	i = 1;
	while (i <= MOVE_S + 3)
	{
		new_x = g->player->x + (int)round(cos(angle) * i);
		new_y = g->player->y - (int)round(sin(angle) * i);
		if (g->map[new_y / TS][new_x / TS] == '1')
			return (-1);
		i++;
	}
	if (g->map[new_y / TS][new_x / TS] == '1')
		return (-1);
	return (0);
}

int	wall_check_down(t_game *g, int x, int y)
{
	int		i;
	int		j;
	int		new_x;
	int		new_y;
	double	angle;

	angle = g->player->angle;
	i = 1;
	while (i <= MOVE_S + 3)
	{
		new_x = g->player->x - (int)round(cos(angle) * i);
		new_y = g->player->y + (int)round(sin(angle) * i);
		if (g->map[new_y / TS][new_x / TS] == '1')
			return (-1);
		i++;
	}
	if (g->map[new_y / TS][new_x / TS] == '1')
		return (-1);
	return (0);
}

int	wall_check_left(t_game *g, int x, int y)
{
	int		i;
	int		j;
	int		new_x;
	int		new_y;
	double	angle;

	angle = g->player->angle;
	i = 1;
	while (i <= MOVE_S + 3)
	{
		new_x = g->player->x - (int)round(sin(angle) * i);
		new_y = g->player->y - (int)round(cos(angle) * i);
		if (g->map[new_y / TS][new_x / TS] == '1')
			return (-1);
		i++;
	}
	if (g->map[new_y / TS][new_x / TS] == '1')
		return (-1);
	return (0);
}

int	wall_check_right(t_game *g, int x, int y)
{
	int		i;
	int		j;
	int		new_x;
	int		new_y;
	double	angle;

	angle = g->player->angle;
	i = 1;
	while (i <= MOVE_S + 3)
	{
		new_x = g->player->x + (int)round(sin(angle) * i);
		new_y = g->player->y + (int)round(cos(angle) * i);
		if (g->map[new_y / TS][new_x / TS] == '1')
			return (-1);
		i++;
	}
	if (g->map[new_y / TS][new_x / TS] == '1')
		return (-1);
	return (0);
}
