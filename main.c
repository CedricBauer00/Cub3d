/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:28:17 by bolcay            #+#    #+#             */
/*   Updated: 2025/08/14 14:47:57 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
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
	paint_map(game, game->player->image);
	game->player->image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	draw_player(game, game->player->image);
	mlx_image_to_window(game->mlx, game->player->image, 0, 0); // this one is only used for the 2d map.
	mlx_key_hook(game->mlx, key, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}
