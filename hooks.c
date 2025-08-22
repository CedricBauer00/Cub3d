/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:58:35 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/22 11:27:22 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key(mlx_key_data_t keys, void *ptr)
{
	int		signal;
	t_game	*game;

	game = (t_game *)ptr;
	signal = keys.key;
	// if (keys.action == MLX_PRESS || keys.action == MLX_REPEAT)
	// {
		if (signal == MLX_KEY_ESCAPE && keys.action == MLX_PRESS)
			exit(1);
		if (signal == MLX_KEY_W && (keys.action == MLX_PRESS || keys.action == MLX_REPEAT))
			move_up(game);
		if (signal == MLX_KEY_A && (keys.action == MLX_PRESS || keys.action == MLX_REPEAT))
			move_left(game);
		if (signal == MLX_KEY_S && (keys.action == MLX_PRESS || keys.action == MLX_REPEAT))
			move_down(game);
		if (signal == MLX_KEY_D && (keys.action == MLX_PRESS || keys.action == MLX_REPEAT))
			move_right(game);
		if (signal == MLX_KEY_LEFT && (keys.action == MLX_PRESS || keys.action == MLX_REPEAT))
			rotate_left(game);
		else if (signal == MLX_KEY_RIGHT && (keys.action == MLX_PRESS || keys.action == MLX_REPEAT))
			rotate_right(game);
		// printf("x = %d, y = %d, angle = %f\n", game->player->x, game->player->y, game->player->angle);
	// }
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
	game->player->angle -= diff;

	// if (diff > 0)
	// 	game->player->angle -= diff;
	// else if (diff < 0)
	// 	game->player->angle += diff;
}

void	update_frame(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	
	draw_player(game, game->player->image);
	draw_minimap(game, game->player->minimap, 0 , -1);
	mlx_image_to_window(game->mlx, game->player->image, 0, 0);
	mlx_image_to_window(game->mlx, game->player->minimap, 10, 10);
	// update position of player accordingly to the key input
	//update raycasting
	//update floor
	//update wall
	//update ceiling
	// updates frame continously
}