/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:28:17 by bolcay            #+#    #+#             */
/*   Updated: 2025/08/21 10:45:59 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int execute_main(t_configs *data)
{
	t_game	*game;

	game = gc_malloc(sizeof(t_game), EXEC);
	if (!game)
		return (0);
	game->player = gc_malloc(sizeof(t_player), EXEC);
	if (!game->player)
		return (0);
	game->ray = gc_malloc(sizeof(t_ray), EXEC);
	if (!game->ray)
		return (0);
	game->mlx = mlx_init(WIDTH, HEIGHT, "game", true);
	if (!game->mlx)
		return (0);
	initialize(data->map_info, game);
	game->player->image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->player->minimap = mlx_new_image(game->mlx, WIDTH / 3, HEIGHT / 3);
	draw_player(game, game->player->image);
	draw_minimap(game, game->player->minimap, 0, -1);
	mlx_image_to_window(game->mlx, game->player->image, 0, 0);
	mlx_image_to_window(game->mlx, game->player->minimap, 10, 10);
	mlx_key_hook(game->mlx, key, game);
	mlx_cursor_hook(game->mlx, cursor, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}
