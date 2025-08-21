/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:58:35 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/21 11:11:30 by cbauer           ###   ########.fr       */
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
	old_x = game->player->dir_x;
	old_plane_x = game->player->plane_x;
	game->player->dir_x = old_x * cos(diff) - game->player->dir_y * sin(diff);
	game->player->dir_y = old_x * sin(diff) + game->player->dir_y * cos(diff);
	game->player->plane_x = old_plane_x * cos(diff) - game->player->plane_y * sin(diff);
	game->player->plane_y = old_plane_x * sin(diff) + game->player->plane_y * cos(diff);
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
	if (diff > 0)
		rotate_right(game);
	else if (diff < 0)
		rotate_left(game);
}

// double plane_x = -dir_y * 0.66;
// double plane_y = dir_x * 0.66;

// void    mouse_move(double xpos, double ypos, void *param)
// {
//     t_game  *g;
//     float   delta_x;
//     float   theta;
//     float   old_dir_x;
//     float   old_plane_x;
//     (void)ypos;
//     g = (t_game *)param;
//     ypos = 0;
//     delta_x = (float)xpos - g->mlx->width / 2.0f;
//     theta = delta_x * ROT_SPEED;
//     old_dir_x = g->player.dir_x;
//     old_plane_x = g->player.plane_x;
//     g->player.dir_x = g->player.dir_x * cos(theta) - g->player.dir_y * sin(theta);
//     g->player.dir_y = old_dir_x * sin(theta) + g->player.dir_y * cos(theta);
//     g->player.plane_x = g->player.plane_x * cos(theta) - g->player.plane_y * sin(theta);
//     g->player.plane_y = old_plane_x * sin(theta) + g->player.plane_y * cos(theta);
//     mlx_set_mouse_pos(g->mlx, WIDTH / 2, HEIGHT / 2);
// }
