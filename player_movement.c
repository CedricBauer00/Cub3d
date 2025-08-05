/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:13:43 by batuhan           #+#    #+#             */
/*   Updated: 2025/08/05 13:37:55 by bolcay           ###   ########.fr       */
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
		{
			move_up(game);
		}
		else if (signal == MLX_KEY_A)
		{
			move_left(game);
		}
		else if (signal == MLX_KEY_S)
		{
			move_down(game);
		}
		else if (signal == MLX_KEY_D)
		{
			move_right(game);
		}
		else if (signal == MLX_KEY_LEFT)
		{
		}
		else if (signal == MLX_KEY_RIGHT)
		{
		}
	}
}

void	move_up(t_game *game)
{
	game->player->dir = UP;
	game->player->inst = &game->player->image->instances[0];
	game->player->inst->y -= 5;
	game->player->y -= 5;
	draw_player(game, game->player->image);
}

void	move_down(t_game *game)
{
	game->player->dir = DOWN;
	game->player->inst = &game->player->image->instances[0];
	game->player->inst->y += 5;
	game->player->y += 5;
	draw_player(game, game->player->image);
}

void	move_right(t_game *game)
{
	game->player->dir = RIGHT;
	game->player->inst = &game->player->image->instances[0];
	game->player->inst->x += 5;
	game->player->x += 5;
	draw_player(game, game->player->image);
}

void	move_left(t_game *game)
{
	game->player->dir = LEFT;
	game->player->x -= 5;
	// draw_player(game, game->player->image);
	game->player->inst = &game->player->image->instances[0];
	game->player->inst->x -= 5;
	draw_player(game, game->player->image);
	// int	x;
	// int	y;
	// int	i;
	// int	j;

	// i = 0;
	// x = game->player->x - 5;
	// y = game->player->y;
	// mlx_delete_image(game->mlx, game->player->image);
	// game->player->image = mlx_new_image(game->mlx, 8, 151);
	// while (i < 8)
	// {
	// 	printf("bitch wtf\n");
	// 	j = 0;
	// 	while (j < 8)
	// 	{
	// 		mlx_put_pixel(game->player->image, x + i, y - j, 0x40E0D0);
	// 		j++;
	// 	}
	// 	if (i == 3 || i == 4 || i == 5)
	// 	{
	// 		if (i == 4)
	// 		{
	// 			j = 0;
	// 			while (j < 150)
	// 			{
	// 				mlx_put_pixel(game->player->image, x + i, y + j + 1, 0xFF0000FF);
	// 				j++;
	// 			}
	// 		}
	// 		j = 0;
	// 		while (j < 20)
	// 		{
	// 			mlx_put_pixel(game->player->image, x + i, y + j + 1,0xFFFF00FF);
	// 			j++;
	// 		}
	// 	}
	// 	i++;
	// }
	// mlx_image_to_window(game->mlx, game->player->image, 0, 0);
}
