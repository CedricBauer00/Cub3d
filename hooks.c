/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:58:35 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/20 12:41:56 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key(mlx_key_data_t keys, void *ptr)
{
	int		signal;
	t_game	*game;

	game = (t_game *)ptr;
	signal = keys.key;
	if (keys.action == MLX_PRESS || keys.action == MLX_REPEAT)
	{
		if (signal == MLX_KEY_ESCAPE)
			exit(1);
		else if (signal == MLX_KEY_W)
			move_up(game);
		else if (signal == MLX_KEY_A)
			move_left(game);
		else if (signal == MLX_KEY_S)
			move_down(game);
		else if (signal == MLX_KEY_D)
			move_right(game);
		else if (signal == MLX_KEY_LEFT)
			rotate_left(game);
		else if (signal == MLX_KEY_RIGHT)
			rotate_right(game);
		// printf("x = %d, y = %d, angle = %f\n", game->player->x, game->player->y, game->player->angle);
	}
}

void	cursor(double xpos, double ypos, void *ptr)
{
	t_game	*game;
	double	old_x;
	double	diff;
	double	old_plane_x;

	(void)ypos;
	game = (t_game *)ptr;
	diff = (xpos - game->mlx->width / 2) * ROT_SPEED; // maybe 2.0
	old_x = game->player->rayDirX;
	
}
