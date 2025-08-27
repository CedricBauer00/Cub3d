/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:08:52 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/27 15:44:53 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_move(t_game *game, bool move, char c)
{
	int	new_x;
	int	new_y;

	if (!move)
		return ;
	choose_move(game, c, &new_x, &new_y);
	if (c == 'a' && wall_check_left(game) == -1)
		return ;
	if (c == 'd' && wall_check_right(game) == -1)
		return ;
	if (c == 'w' && wall_check_up(game) == -1)
		return ;
	if (c == 's' && wall_check_down(game) == -1)
		return ;
	game->player->x = new_x;
	game->player->y = new_y;
}

int	wall_check_up(t_game *g)
{
	int		i;
	int		new_x;
	int		new_y;
	double	angle;

	angle = g->player->angle;
	i = 1;
	while (i <= MOVE_S + 20)
	{
		new_x = g->player->x + (int)round(cos(angle) * i);
		new_y = g->player->y - (int)round(sin(angle) * i);
		if (g->map[new_y / TS][new_x / TS] == '1' || g->map[new_y / TS][new_x / TS] == '2')
			return (-1);
		i++;
	}
	if (g->map[new_y / TS][new_x / TS] == '1' || g->map[new_y / TS][new_x / TS] == '2')
		return (-1);
	return (0);
}

int	wall_check_down(t_game *g)
{
	int		i;
	int		new_x;
	int		new_y;
	double	angle;

	angle = g->player->angle;
	i = 1;
	while (i <= MOVE_S + 20)
	{
		new_x = g->player->x - (int)round(cos(angle) * i);
		new_y = g->player->y + (int)round(sin(angle) * i);
		if (g->map[new_y / TS][new_x / TS] == '1' || g->map[new_y / TS][new_x / TS] == '2')
			return (-1);
		i++;
	}
	if (g->map[new_y / TS][new_x / TS] == '1' || g->map[new_y / TS][new_x / TS] == '2')
		return (-1);
	return (0);
}

int	wall_check_left(t_game *g)
{
	int		i;
	int		new_x;
	int		new_y;
	double	angle;

	angle = g->player->angle;
	i = 1;
	while (i <= MOVE_S + 20)
	{
		new_x = g->player->x - (int)round(sin(angle) * i);
		new_y = g->player->y - (int)round(cos(angle) * i);
		if (g->map[new_y / TS][new_x / TS] == '1' || g->map[new_y / TS][new_x / TS] == '2')
			return (-1);
		i++;
	}
	if (g->map[new_y / TS][new_x / TS] == '1' || g->map[new_y / TS][new_x / TS] == '2')
		return (-1);
	return (0);
}

int	wall_check_right(t_game *g)
{
	int		i;
	int		new_x;
	int		new_y;
	double	angle;

	angle = g->player->angle;
	i = 1;
	while (i <= MOVE_S + 20)
	{
		new_x = g->player->x + (int)round(sin(angle) * i);
		new_y = g->player->y + (int)round(cos(angle) * i);
		if (g->map[new_y / TS][new_x / TS] == '1' || g->map[new_y / TS][new_x / TS] == '2')
			return (-1);
		i++;
	}
	if (g->map[new_y / TS][new_x / TS] == '1' || g->map[new_y / TS][new_x / TS] == '2')
		return (-1);
	return (0);
}
