/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:58:35 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/22 12:59:19 by cbauer           ###   ########.fr       */
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
		if (keys.key == MLX_KEY_W)
			game->w = keys.action != MLX_RELEASE;
		if (keys.key == MLX_KEY_A)
			game->a = keys.action != MLX_RELEASE;
		if (keys.key == MLX_KEY_S)
			game->s = keys.action != MLX_RELEASE;
		if (keys.key == MLX_KEY_D)
			game->d = keys.action != MLX_RELEASE;
		if (signal == MLX_KEY_LEFT && (keys.action == MLX_PRESS
			|| keys.action == MLX_REPEAT))
			rotate_left(game);
		else if (signal == MLX_KEY_RIGHT && (keys.action == MLX_PRESS
			|| keys.action == MLX_REPEAT))
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
}

void	update_frame(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	check_move(game, game->w, 'w');
	check_move(game, game->a, 'a');
	check_move(game, game->s, 's');
	check_move(game, game->d, 'd');
	draw_player(game, game->player->image);
	draw_minimap(game, game->player->minimap, 0 , -1);
	// update position of player accordingly to the key input
	//update raycasting
	//update floor
	//update wall
	//update ceiling
	// ->> updates frame continously
}

void	choose_move(t_game *game, char c, int *new_x, int *new_y)
{
	if (c == 'w')
	{
		*new_x = game->player->x + (int)round(cos(game->player->angle) * MOVE_S);
		*new_y = game->player->y - (int)round(sin(game->player->angle) * MOVE_S);
	}
	if (c == 's')
	{
		*new_x = game->player->x - (int)round(cos(game->player->angle) * MOVE_S);
		*new_y = game->player->y + (int)round(sin(game->player->angle) * MOVE_S);
	}
	if (c == 'a')
	{
		*new_x = game->player->x - (int)round(sin(game->player->angle) * MOVE_S);
		*new_y = game->player->y - (int)round(cos(game->player->angle) * MOVE_S);
	}
	if (c == 'd')
	{
		*new_x = game->player->x + (int)round(sin(game->player->angle) * MOVE_S);
		*new_y = game->player->y + (int)round(cos(game->player->angle) * MOVE_S);
	}
}

void	check_move(t_game *game, bool move, char c)
{
	int	new_x;
	int	new_y;

	if (!move)
		return ;
	choose_move(game, c, &new_x, &new_y);
	if (c == 'a' && wall_check_left(game, game->player->x, game->player->y) == -1)
		return ;
	if (c == 'd' && wall_check_right(game, game->player->x, game->player->y) == -1)
		return ;
	if (c == 'w' && wall_check_up(game, game->player->x, game->player->y) == -1)
		return ;
	if (c == 's' && wall_check_down(game, game->player->x, game->player->y) == -1)
		return ;
	game->player->x = new_x;
	game->player->y = new_y;
}
