/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:58:35 by batuhan           #+#    #+#             */
/*   Updated: 2025/09/01 11:56:12 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key(mlx_key_data_t keys, void *ptr)
{
	int		signal;
	t_game	*game;

	game = (t_game *)ptr;
	signal = keys.key;
	if (signal == MLX_KEY_ESCAPE && keys.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keys.key == MLX_KEY_E && keys.action == MLX_PRESS)
		open_door(game);
	if (keys.key == MLX_KEY_W)
		game->w = keys.action != MLX_RELEASE;
	if (keys.key == MLX_KEY_A)
		game->a = keys.action != MLX_RELEASE;
	if (keys.key == MLX_KEY_S)
		game->s = keys.action != MLX_RELEASE;
	if (keys.key == MLX_KEY_D)
		game->d = keys.action != MLX_RELEASE;
	if (keys.key == MLX_KEY_LEFT)
		game->l = keys.action != MLX_RELEASE;
	else if (keys.key == MLX_KEY_RIGHT)
		game->r = keys.action != MLX_RELEASE;
}

void	cursor(double xpos, double ypos, void *ptr)
{
	t_game	*game;
	double	old_x;
	double	diff;
	double	old_plane_x;

	(void)ypos;
	game = (t_game *)ptr;
	diff = (xpos - game->mlx->width / 2) * ROT_SPEED;
	old_x = game->player->dir_x;
	old_plane_x = game->player->plane_x;
	game->player->dir_x = old_x * cos(diff) - game->player->dir_y * sin(diff);
	game->player->dir_y = old_x * sin(diff) + game->player->dir_y * cos(diff);
	game->player->plane_x = old_plane_x * cos(diff)
		- game->player->plane_y * sin(diff);
	game->player->plane_y = old_plane_x * sin(diff)
		+ game->player->plane_y * cos(diff);
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	game->player->angle -= diff;
}

void	check_rotation(t_game *game, bool move, char c)
{
	if (!move)
		return ;
	if (c == 'r')
	{
		game->player->angle -= SPEED;
		if (game->player->angle < 0)
			game->player->angle += 2 * PI;
	}
	if (c == 'l')
	{
		game->player->angle += SPEED;
		if (game->player->angle > 2 * PI)
			game->player->angle -= 2 * PI;
	}
}

// update position of player accordingly to the key input
//update raycasting
//update floor
//update wall
//update ceiling
// ->> updates frame continously

void	update_frame(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	game->move = game->w || game->a || game->s || game->d; // if one of those are true it sets the boolian to true; if one or more are true
	check_move(game, game->w, 'w');
	check_move(game, game->a, 'a');
	check_move(game, game->s, 's');
	check_move(game, game->d, 'd');
	check_rotation(game, game->l, 'l');
	check_rotation(game, game->r, 'r');
	move_gun(game);
	draw_player(game);
	draw_minimap(game, game->player->minimap, 0, -1);
	// draw_gun(game);
}

void	choose_move(t_game *game, char c, int *new_x, int *new_y)
{
	double	a;

	a = game->player->angle;
	if (c == 'w')
	{
		*new_x = game->player->x + (int)round(cos(a) * MOVE_S);
		*new_y = game->player->y - (int)round(sin(a) * MOVE_S);
	}
	if (c == 's')
	{
		*new_x = game->player->x - (int)round(cos(a) * MOVE_S);
		*new_y = game->player->y + (int)round(sin(a) * MOVE_S);
	}
	if (c == 'a')
	{
		*new_x = game->player->x - (int)round(sin(a) * MOVE_S);
		*new_y = game->player->y - (int)round(cos(a) * MOVE_S);
	}
	if (c == 'd')
	{
		*new_x = game->player->x + (int)round(sin(a) * MOVE_S);
		*new_y = game->player->y + (int)round(cos(a) * MOVE_S);
	}
}
