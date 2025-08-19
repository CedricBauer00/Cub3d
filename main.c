/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbauer < cbauer@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:28:17 by bolcay            #+#    #+#             */
/*   Updated: 2025/08/19 12:07:28 by cbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av) //t_textures // t_map
{
	(void)ac;
	(void)av;
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		return (0);
	game->ray = malloc(sizeof(t_ray));
	if (!game->ray)
		return (0);
	game->mlx = mlx_init(WIDTH, HEIGHT, "game", true);
	if (!game->mlx)
		return (0);
	initialize(game);
	// paint_map(game, game->player->image);
	game->player->image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->player->minimap = mlx_new_image(game->mlx, WIDTH / 3, HEIGHT / 3);
	paint_map(game, game->player->image);
	draw_player(game, game->player->image);
	draw_minimap(game);
	mlx_image_to_window(game->mlx, game->player->image, 0, 0);
	mlx_image_to_window(game->mlx, game->player->minimap, 10, 10);
	mlx_key_hook(game->mlx, key, game);
	// mlx_cursor_hook(game->mlx, cursor, game); will be added for the bonus part
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}
